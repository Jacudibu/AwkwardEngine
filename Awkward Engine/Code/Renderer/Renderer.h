#pragma once

#include <SDL.h>
#include "..\Core\Component.h"
#include "RenderLayer.h"

class RenderLayer;

class Renderer : public Component
{
public:
	// The Anchor of the Texture.
	Vector3 Offset;

	// Current SDL Flipmode of the Image. //TODO: Provide functions, make private. 
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	// Draws the Texture associated to the Renderer on the current RenderLayer.
	virtual void draw() = 0;

	// Update has no function.
	void Update();

	// Sets the RenderLayer of our Renderer.
	void setLayer(RenderLayer* layer);


protected:
	RenderLayer* Layer;

};