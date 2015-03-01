#pragma once

#include <SDL.h>
#include <string>
#include <list>
#include "Camera.h"

class Camera;

class Window
{
public:
	Window(int width, int height, std::string title, Uint32 SDL_RENDERER_FLAGS_GOOGLE_IT);
	~Window();

	SDL_Renderer* renderer;

	int ScreenWidth;
	int ScreenHeight;
	std::string Title;

	void Render();
	void addCamera(Camera* cam);
	void removeCamera(Camera* cam);

private:
	SDL_Window* window;
	std::list<Camera*> cameraList;
};