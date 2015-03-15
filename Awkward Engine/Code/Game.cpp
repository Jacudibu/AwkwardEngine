#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <stdio.h> // Used for printf
#include <string> // Used for filenames
#include <cmath> // ????
#include <sstream> // Used for FPS

#include "Input/Input.h"
#include "Renderer/Texture.h"
#include "Renderer/SpriteRenderer.h"
#include "Renderer/TextRenderer.h"
#include "Renderer/Camera.h"
#include "Renderer/Window.h"
#include "Utility/Time.h"
#include "Utility/ResourceManager.h"
#include "Utility/Config.h"
#include "Audio/Music.h"
#include "Audio/Sound.h"

Window*  gWindow = nullptr;
TTF_Font* gFont = nullptr;

RenderLayer* renderLayer;
GameObject* mousePointer;
GameObject* arrowObject;
GameObject* fpsObject;
GameObject* soundObject;
Camera* cam;

Config* config;

bool quit;

SDL_GameController* GameController = NULL;

bool init()
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC) < 0)
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

	// Load config
	config = new Config();
	config->load();

	// Initialize Controllers
	Input::Init();

	gWindow = new Window(config->getScreenWidth(),
						 config->getScreenHeight(),
						 "Awkward Engine Version " + config->query("version"),
						 SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/);

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


	mousePointer = new GameObject();
	arrowObject = new GameObject();
	fpsObject = new GameObject();
	soundObject = new GameObject();

	soundObject->addComponent(new Sound("resources/testsounds/low.wav", 10));
	mousePointer->addComponent(new SpriteRenderer("resources/cursor.png", renderLayer, 1, 2, 1));
	
	arrowObject->addComponent(new SpriteRenderer("resources/alphaArrow.png", renderLayer));
	arrowObject->transform->Position = { (float) config->getScreenWidth() / 2, (float) config->getScreenHeight() / 2, 0 };

	fpsObject->addComponent(new TextRenderer("", renderLayer, { 0x0, 0x0, 0x0, 0xFF }));
	fpsObject->transform->Position = { (float) config->getScreenWidth() / 2, (float) config->getScreenHeight() / 2, 0 };

	return success;
}

void close()
{
	// Delete Game Objects
	delete mousePointer;
	delete arrowObject;
	delete fpsObject;
	delete soundObject;

	// Close Controllers
	Input::Shutdown();

	// Free global font
	TTF_CloseFont(gFont);
	gFont = nullptr;

	// Destroy window
	delete gWindow;
	gWindow   = nullptr;

	// Destroy Config
	delete config;
	config = nullptr;

	// Quit SDL subysystems
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void handleEvents()
{
	// Handle events on queue
	// Reset Input first.
	Input::RemoveKeyUpDownFlags();
	SDL_Event e;

	while (SDL_PollEvent(&e) != NULL)
	{
		switch (e.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		default:	// No Event thats handled by the Game Loop, most likely Input. So let's send it to Input.
			Input::HandleEvent(e);
			break;
		}
	}

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
		
		quit = false;

		float degrees = 0;
		float degreeOffset = 0;
		SDL_RendererFlip flipType = SDL_FLIP_NONE;

		float mousePointerStep = 0.0f;
		Input::displayMouseCursor(false);

		// Variables for FPS
		std::stringstream timeText;

		while (!quit)
		{
			// Update Time
			Time::Update();

			handleEvents();

			if (Input::getKey(SDL_SCANCODE_A) || Input::getMouse(Input::MouseButton::Left))
				degreeOffset -= 1 * Time::getDeltaTime() * 100.0f;
			if (Input::getKey(SDL_SCANCODE_D) || Input::getMouse(Input::MouseButton::Right))
				degreeOffset += 1 * Time::getDeltaTime() * 100.0f;
			if (Input::getKeyDown(SDL_SCANCODE_Q))
				flipType = SDL_FLIP_HORIZONTAL;
			if (Input::getKeyDown(SDL_SCANCODE_W))
				flipType = SDL_FLIP_NONE;
			if (Input::getKeyDown(SDL_SCANCODE_E))
				flipType = SDL_FLIP_VERTICAL;
			if (Input::getKeyDown(SDL_SCANCODE_U))
				((Sound*)soundObject->getComponent("Sound"))->Play();
			if (Input::getKey(SDL_SCANCODE_DOWN))
				cam->transform->Position.y--;
			if (Input::getKey(SDL_SCANCODE_UP))
				cam->transform->Position.y++;
			if (Input::getKey(SDL_SCANCODE_RIGHT))
				cam->transform->Position.x--;
			if (Input::getKey(SDL_SCANCODE_LEFT))
				cam->transform->Position.x++;

			// Set text to be rendered
			timeText.str("");
			timeText << "FPS: " << Time::getFPS();

			// Adjust fps text
			((TextRenderer*)fpsObject->getComponent("TextRenderer"))->setText(timeText.str());

			// Change mouse cursor
			mousePointer->transform->Position = { (float)Input::getMousePositionX(), (float)Input::getMousePositionY(), 0.0f };
			mousePointer->transform->Position -= cam->transform->Position;

			mousePointerStep += Time::getDeltaTime();

			((SpriteRenderer*)mousePointer->getComponent("SpriteRenderer"))->setCurrentClip(((int)mousePointerStep % 2) + 1);

			// Rotate Objects
			((SpriteRenderer*)arrowObject->getComponent("SpriteRenderer"))->flip = flipType;
			((TextRenderer*)fpsObject->getComponent("TextRenderer"))->flip = flipType;

			degrees = Vector3::Angle2D({cam->transform->Position.x + config->getScreenWidth() / 2,
									 		cam->transform->Position.y + config->getScreenHeight() / 2,
									 		cam->transform->Position.z
											}, mousePointer->transform->Position);
			//printf("Angle: %f\n", degrees);
			
			fpsObject->transform->Rotation = degrees + degreeOffset;
			arrowObject->transform->Rotation = degrees + degreeOffset;

			// Render current frame

			gWindow->Render();
		}
	}

	// Wait a second before Exiting. Makes pressing that red X more dramatic.
	SDL_Delay(1000);

	// Free resources
	close();

	return 0;
}