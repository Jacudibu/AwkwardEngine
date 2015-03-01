#pragma once

#include "Renderer.h"
#include "Texture.h"

class TextRenderer : public Renderer
{
public:
	SDL_Color Color;
	static TTF_Font* font;

	
	TextRenderer(std::string newText, RenderLayer* layer, SDL_Color color = { 0xFF, 0xFF, 0xFF, 0xFF });
	~TextRenderer();

	void draw();

	void setText(std::string newText);
	std::string getText();

private:
	Texture* texture;
	std::string text;

	void generate();
};