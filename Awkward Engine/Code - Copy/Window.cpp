#include "Headers\Window.h"

Window::Window(int width, int height, std::string title, Uint32 SDL_RENDERER_FLAGS_GOOGLE_IT)
{
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_FLAGS_GOOGLE_IT);
	if (renderer == nullptr)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}

	ScreenHeight = height;
	ScreenWidth = width;
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Window::Render()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	for (Camera* cam : cameraList)
	{
		cam->Render();
	}
}

void Window::addCamera(Camera* cam)
{
	// #TODO: Sort them somehow. I don't care how. Just. Sort. Them.
	cameraList.push_back(cam);
}

void Window::removeCamera(Camera* cam)
{
	cameraList.remove(cam);
}