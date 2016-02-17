#pragma once

#include <SDL.h>
#include "Renderer.h"
#include "Camera.h"

class Renderer;
class Camera;

class RenderLayer
{
public:
	bool enabled = true;
	int layer;
	SDL_Renderer* renderer = nullptr;
	Camera* camera = nullptr;

	// Sends a draw()-Command to all Renderer inside the renderList.
	void Render();

	// Adds a Renderer to our renderList.
	void addRenderer(Renderer* object);

	// Removes a Renderer from our renderList.
	void removeRenderer(Renderer* object);

	// Sets the camera associated with our renderLayer.
	void setCamera(Camera* cam) { camera = cam; }

private:
	std::list<Renderer*> renderList;
};