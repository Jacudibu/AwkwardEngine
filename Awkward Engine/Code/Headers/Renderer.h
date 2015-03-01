#pragma once

#include <SDL.h>
#include "Component.h"
#include "RenderLayer.h"

class RenderLayer;

class Renderer : public Component
{
public:
	Vector3 Offset;
	virtual void draw() = 0;

	void Update();
	void setLayer(RenderLayer* layer);

	SDL_RendererFlip flip = SDL_FLIP_NONE;

protected:
	RenderLayer* Layer;

};