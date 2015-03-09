#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


class Texture
{
public:
	Texture();
	// Initialize a Texture with a file.
	Texture(std::string path, SDL_Renderer* renderer, bool useColorKey = false);
	// Initialize a Texture from text.
	Texture(std::string textureText, SDL_Renderer* renderer, SDL_Color textColor, TTF_Font* font);
	~Texture();

	std::string path;

	// Loads image at specified path
	void loadTextureFromFile(std::string path, SDL_Renderer* renderer, bool useColorKey = false);

	// Creates image from String
	void loadTextureFromRenderedText(std::string textureText, SDL_Renderer* renderer, SDL_Color textColor, TTF_Font* font);

	// Deallocates texture
	void free();

	/* Renders the texture at a given point.
	 * x - x Position of the Texture
	 * y - y Position of the Texture
	 * renderer - The Renderer that should process the picture
	 * clip - The Part of the Texture that shall be drawn, nullptr for whole texture
	 * rotationAngle - The rotation Angle towards the rotation Center
	 * rotationCenter - The Center of the rotation
	 * flip - SDL_FLIP direction
     */
	void render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip = nullptr, double rotationAngle = 0.0, SDL_Point* rotationCenter = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Set color modulation (Tint)
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Set Blending
	void setBlendMode(SDL_BlendMode blending);

	// Set Alpha Values
	void setAlpha(Uint8 alpha);

	// Gets image dimensions
	int getWidth();
	int getHeight();

private:
	// The actual hardware texture
	SDL_Texture* texture;

	// Image dimensions
	int width;
	int height;

};

