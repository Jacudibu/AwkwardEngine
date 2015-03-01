#pragma once

#include "Renderer.h"
#include "Texture.h"

class SpriteRenderer : public Renderer
{
public: 
	SpriteRenderer(std::string path, RenderLayer* layer, int rows = 1, int columns = 1, int step = 1);
	~SpriteRenderer();

	void draw();
	void setCurrentClip(int clip);

private:
	int spriteClip;
	int spriteRows;
	int spriteColumns;

	int clipWidth;
	int clipHeight;

	SDL_Rect* spriteClips;

	Texture* texture;

	void calculateSpriteClips();
};