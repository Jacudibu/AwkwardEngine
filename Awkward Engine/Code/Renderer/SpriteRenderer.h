#pragma once

#include "Renderer.h"
#include "Texture.h"

class SpriteRenderer : public Renderer
{
public: 
	SpriteRenderer(std::string path, RenderLayer* layer, int rows = 1, int columns = 1, int step = 1);
	~SpriteRenderer();

	// Draws the Texture on the RenderLayer's renderer.
	void draw();

	// Sets the clip of the image that's currently shown.
	void setCurrentClip(int clip);

	// GetID is used to compare types of Components.
	std::string getID() { return ID; }

private:
	// Used to compare components for similiarity.
	std::string ID = "SpriteRenderer";

	int spriteClip;
	int spriteRows;
	int spriteColumns;

	int clipWidth;
	int clipHeight;

	SDL_Rect* spriteClips;

	Texture* texture;

	void calculateSpriteClips();
};