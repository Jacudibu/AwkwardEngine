#pragma once

#include <SDL.h>
#include "Renderer.h"
#include "Camera.h"

class Renderer;
class Camera;

class RenderLayer
{
public:
	bool enabled;
	int layer;
	SDL_Renderer* renderer;

	void Render();
	void addRenderer(Renderer* object);
	void removeRenderer(Renderer* object);


private:
	std::list<Renderer*> renderList;
	Camera* camera;
};