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
#include "Headers/TextRenderer.h"
#include "Headers/Camera.h"
#include "Headers/Window.h"

// Screen dimension constants - #TODO: Put these into superfancy config files!
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Window*  gWindow = nullptr;
TTF_Font* gFont = nullptr;

TextRenderer* gFPSRenderer;
SpriteRenderer* gArrowTexture;

Sound gSound;

RenderLayer* renderLayer;
GameObject* mousePointer;
GameObject* arrowObject;
GameObject* fpsObject;
Camera* cam;

SpriteRenderer* cursorRenderer;

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

	gWindow = new Window(SCREEN_WIDTH, SCREEN_HEIGHT, "Awkward Engine Version 0.0.0.0.0.0.0.0.1e", SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/);
	cam = new Camera(gWindow, nullptr);
	renderLayer = new RenderLayer();
	cam->addLayer(renderLayer);

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
	TextRenderer::font = gFont;


	gSound.loadSoundFromFile("resources/testsounds/low.wav");
	gSound.setVolume(10);

	mousePointer = new GameObject();
	arrowObject = new GameObject();
	fpsObject = new GameObject();

	cursorRenderer = new SpriteRenderer("resources/cursor.png", renderLayer, 1, 2, 1);
	mousePointer->addComponent(cursorRenderer);
	
	gArrowTexture = new SpriteRenderer("resources/alphaArrow.png", renderLayer);
	arrowObject->addComponent(gArrowTexture);
	arrowObject->transform->Position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0 };

	gFPSRenderer = new TextRenderer("", renderLayer, {0x0, 0x0, 0x0, 0xFF});
	fpsObject->addComponent(gFPSRenderer);
	fpsObject->transform->Position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0 };

	return success;
}

void close()
{
	// Free loaded image
	gArrowTexture->~SpriteRenderer();
	gFPSRenderer->~TextRenderer();
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

		float degrees = 0;
		SDL_RendererFlip flipType = SDL_FLIP_NONE;

		float mousePointerStep = 0.0f;
		Input::displayMouseCursor(false);

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

			mousePointer->transform->Position = { (float)Input::mouse.posX, (float)Input::mouse.posY, 0.0f };
			mousePointer->transform->Position -= cam->transform->Position;

			mousePointerStep += Time::getDeltaTime();
			cursorRenderer->setCurrentClip(((int)mousePointerStep % 2) + 1);

			// Set text to be rendered
			timeText.str("");
			timeText << "FPS: " << Time::getFPS();

			// Render Text
			gFPSRenderer->setText(timeText.str());

			// Render current frame
			fpsObject->transform->Rotation = degrees;
			arrowObject->transform->Rotation = degrees;

			gWindow->Render();

			// Update Surface
			//SDL_RenderPresent(gRenderer);
		}
	}

	//SDL_Delay(1000);
	// Free resources
	close();

	return 0;
}