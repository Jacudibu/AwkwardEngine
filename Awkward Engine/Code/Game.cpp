#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <stdio.h> // Used for printf
#include <string> // Used for filenames
#include <cmath> // ????
#include <sstream> // Used for FPS

#include "Headers/Input.h"
#include "Headers/Texture.h"
#include "Headers/Time.h"
#include "Headers/Music.h"
#include "Headers/Sound.h"
#include "Headers/SpriteRenderer.h"
#include "Headers/Camera.h"
#include "Headers/Window.h"

// Screen dimension constants - #TODO: Put these into superfancy config files!
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Window*  gWindow = nullptr;
//SDL_Renderer* gRenderer = nullptr;
TTF_Font* gFont = nullptr;

Texture gTextTexture;
SpriteRenderer* gArrowTexture;

Sound gSound;

RenderLayer* renderLayer;
GameObject* gameObject;
GameObject* arrowObject;
Camera* cam;

SpriteRenderer* spriteRenderer;

bool init()
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Initialize SDL_Image
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	// Initialize SDL_TTF
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	// Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	gWindow = new Window(SCREEN_WIDTH, SCREEN_HEIGHT, "Awkward Engine Version 0.0.0.0.0.0.0.0.1e", SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	cam = new Camera(gWindow, nullptr);
	renderLayer = new RenderLayer();
	cam->addLayer(renderLayer);
	/*
	// Create Window
	gWindow = SDL_CreateWindow("Awkward Engine Version 0.0.0.0.0.0.0.0.1d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == nullptr)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	*/


	return true;
}

bool loadMedia()
{
	// Loading success flag
	bool success = true;

	// open Font
	gFont = TTF_OpenFont("resources/arial.ttf", 28);
	if (gFont == nullptr)
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}


	gArrowTexture = new SpriteRenderer("resources/alphaArrow.png", renderLayer);

	gSound.loadSoundFromFile("resources/testsounds/low.wav");
	gSound.setVolume(10);

	gameObject = new GameObject();
	arrowObject = new GameObject();

	spriteRenderer = new SpriteRenderer("resources/sprites.png", renderLayer, 2, 2, 3);
	gameObject->addComponent(spriteRenderer);
	arrowObject->addComponent(gArrowTexture);
	arrowObject->transform->Position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0 };

	printf("%d", gameObject->GetComponents().size());

	return success;
}

void close()
{
	// Free loaded image
	gArrowTexture->~SpriteRenderer();
	gTextTexture.free();
	gSound.free();

	// Free global font
	TTF_CloseFont(gFont);
	gFont = nullptr;

	// Destroy window
	gWindow->~Window();
	gWindow   = nullptr;

	// Quit SDL subysystems
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	// Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
			return -1;
		}
		
		bool quit = false;
		SDL_Event e;

		double degrees = 0;
		SDL_RendererFlip flipType = SDL_FLIP_NONE;

		// Variables for FPS
		std::stringstream timeText;

		while (!quit)
		{
			// Update Time
			Time::Update();

			// Handle events on queue
			while (SDL_PollEvent(&e) != NULL)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEWHEEL)
				{
					Input::updateMouse();
				}
			}
			
			if (Input::getKeyDown(SDL_SCANCODE_A) || Input::mouse.LButton)
				degrees -= 1;
			if (Input::getKeyDown(SDL_SCANCODE_D) || Input::mouse.RButton)
				degrees += 1;
			if (Input::getKeyDown(SDL_SCANCODE_Q))
				flipType = SDL_FLIP_HORIZONTAL;
			if (Input::getKeyDown(SDL_SCANCODE_W))
				flipType = SDL_FLIP_NONE;
			if (Input::getKeyDown(SDL_SCANCODE_E))
				flipType = SDL_FLIP_VERTICAL;
			if (Input::getKeyDown(SDL_SCANCODE_U))
				gSound.Play();
			if (Input::getKeyDown(SDL_SCANCODE_DOWN))
				cam->transform->Position.y--;
			if (Input::getKeyDown(SDL_SCANCODE_UP))
				cam->transform->Position.y++;
			if (Input::getKeyDown(SDL_SCANCODE_RIGHT))
				cam->transform->Position.x--;
			if (Input::getKeyDown(SDL_SCANCODE_LEFT))
				cam->transform->Position.x++;

			gameObject->transform->Position = { (float)Input::mouse.posX, (float)Input::mouse.posY, 0.0f };

			// Set text to be rendered
			timeText.str("");
			timeText << "FPS: " << Time::getFPS();

			// Render Text
			gTextTexture.loadTextureFromRenderedText(timeText.str(), { 0, 0, 0, 255 }, gFont, gWindow->renderer);

			// Render current frame
			gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2, gWindow->renderer, nullptr, degrees, nullptr, flipType);
			arrowObject->transform->Rotation = degrees;

			gWindow->Render();

			// Update Surface
			//SDL_RenderPresent(gRenderer);
		}
	}

	SDL_Delay(1000);
	// Free resources
	close();

	return 0;
}