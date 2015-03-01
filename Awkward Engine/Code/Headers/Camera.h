#pragma once

#include <SDL.h>
#include "Transform.h"
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

	void setViewPort(SDL_Rect* port);

	void Render();

	void addLayer(RenderLayer* layer);
	void removeLayer(RenderLayer* layer);
	void setWindow(Window* win);

private:
	SDL_Rect* viewPort;
	std::list<RenderLayer*> renderLayer;
	Window* window;
};