#pragma once

#include <SDL.h>
#include "../Transform.h"
#include "RenderLayer.h"
#include "Window.h"

class RenderLayer;
class Window;

class Camera
{
public:
	Camera(Window* win, SDL_Rect* viewport);
	~Camera();

	bool enabled = true;
	Transform* transform;

	// Sets the ViewPort of the current Camera. If nullptr, the camera will draw on the whole screen.
	void setViewPort(SDL_Rect* port);

	// Send a Render() command to every RenderLayer in our list. 
	void Render();

	// Adds a RenderLayer to our list.
	void addLayer(RenderLayer* layer);

	// Removes a RenderLayer from our list.
	void removeLayer(RenderLayer* layer);

	// Set the Window this Camera is attached to.
	void setWindow(Window* win);

private:
	SDL_Rect* viewPort;
	std::list<RenderLayer*> renderLayer;
	Window* window;
};