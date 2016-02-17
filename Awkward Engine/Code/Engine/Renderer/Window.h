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

	SDL_Renderer* renderer = nullptr;

	int ScreenWidth;
	int ScreenHeight;
	std::string Title;

	// Send the Render command to all Cameras attached to the window.
	void Render();

	// Adds a Camera to the list.
	void addCamera(Camera* cam);

	// Removes a Camera from the list.
	void removeCamera(Camera* cam);

private:
	SDL_Window* window = nullptr;
	std::list<Camera*> cameraList;
};