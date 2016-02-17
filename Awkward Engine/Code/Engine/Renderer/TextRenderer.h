#pragma once

#include "Renderer.h"
#include "Texture.h"

class TextRenderer : public Renderer
{
public:
	TextRenderer(std::string newText, RenderLayer* layer, SDL_Color color = { 0xFF, 0xFF, 0xFF, 0xFF });
	~TextRenderer();

	SDL_Color Color;
	static TTF_Font* font;

	// Draws the Texture on the Renderlayer's renderer.
	void draw();

	// Generates a new Texture containing the given Text.
	void setText(std::string newText);
	std::string getText();

	// GetID is used to compare types of Components.
	std::string getID() { return ID; }

private:
	// Used to compare components for similiarity.
	std::string ID = "TextRenderer";

	Texture* texture = nullptr;
	std::string text = "";

	void generate();
};