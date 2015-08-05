#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <stdio.h> // Used for printf
#include <string> // Used for filenames
#include <cmath> // ????

#include "Engine/Scene.h"

#include "Engine/Input/Input.h"

#include "Engine/Renderer/Texture.h"
#include "Engine/Renderer/SpriteRenderer.h"
#include "Engine/Renderer/TextRenderer.h"
#include "Engine/Renderer/Camera.h"
#include "Engine/Renderer/Window.h"

#include "Engine/Utility/Time.h"
#include "Engine/Utility/ResourceManager.h"
#include "Engine/Utility/Config.h"

#include "Engine/Audio/Music.h"
#include "Engine/Audio/Sound.h"

#include "Testing/TestingScene.h"

Window*  gWindow = nullptr;
TTF_Font* gFont = nullptr;

RenderLayer* renderLayer;
Camera* cam;

Scene* currentScene;

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
	Mix_Init(MIX_INIT_MP3);

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
						 SDL_RENDERER_ACCELERATED );//| SDL_RENDERER_PRESENTVSYNC/**/);

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

	return success;
}

void close()
{
	// Destroy Scene
	delete currentScene;

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

		Input::displayMouseCursor(false);

		// Load starting Scene
		currentScene = new TestingScene(cam, config, renderLayer);

		while (!quit)
		{
			Time::Update();
			handleEvents();

			// Update Calls
			currentScene->Update();

			cam->Update();

			// Render current frame
			gWindow->Render();
		}
	}

	// Wait a millisecond before Exiting. Makes pressing that red X more dramatic.
	SDL_Delay(100);

	// Free resources
	close();

	return 0;
}