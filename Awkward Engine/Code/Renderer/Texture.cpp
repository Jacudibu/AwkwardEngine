#include "Texture.h"
#include "..\Utility\ResourceManager.h"

Texture::Texture()
{
	texture = nullptr;
	width   = 0;
	height  = 0;
}

Texture::Texture(std::string filePath, SDL_Renderer* renderer, bool useColorKey)
{
	loadTextureFromFile(filePath, renderer, useColorKey);
}

Texture::Texture(std::string textureText, SDL_Renderer* renderer, SDL_Color textColor, TTF_Font* font)
{
	loadTextureFromRenderedText(textureText, renderer, textColor, font);
}

Texture::~Texture()
{
	free();
}

void Texture::loadTextureFromFile(std::string filePath, SDL_Renderer* renderer, bool useColorKey)
{
	// Get rid of preexisting texture
	free();

	path = filePath;
	
	// Load image at specified path into a surface
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		texture = nullptr;
		return;
	}

	// Color key image
	if (useColorKey)
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
	}

	// Create texture from surface pixels
	texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	if (texture == nullptr)
	{
		printf("Unable to create texture from %s!SDL Error : %s\n", path.c_str(), SDL_GetError());
		SDL_FreeSurface(loadedSurface); // We do that here because afterwards we will return
		return;
	}

	// Get rid of loaded surface
	SDL_FreeSurface(loadedSurface);

	// Get image dimensions
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

void Texture::loadTextureFromRenderedText(std::string textureText, SDL_Renderer* renderer, SDL_Color textColor, TTF_Font* font)
{
	// TODO: This is Solid text. Add Shaded & Blended as stated here: http://www.libsdl.org/projects/docs/SDL_ttf/SDL_ttf_35.html

	// Get rid of preexisting texture
	free();
	
	path = textureText;

	// Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
	if (textSurface == nullptr)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		texture = nullptr;
		return;
	}

	// Create texture from surface pixels
	texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (texture == nullptr)
	{
		printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		SDL_FreeSurface(textSurface);
		return;
	}

	// Get rid of old surface
	SDL_FreeSurface(textSurface);

	// Get Image dimensions
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

void Texture::free()
{
	// Free texture if it exists
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
		path = "";
		width   = 0;
		height  = 0;
	}
}

void Texture::render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip, double rotationAngle, SDL_Point* rotationCenter, SDL_RendererFlip flip)
{
	// Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, width, height }; // TODO: Currently the anchor is always the upper left. How about Centered?
	                                               // TODO: Oh, and also... x/y should come from the Transform somehow
	
	// Set clip rendering dimensions
	if (clip != nullptr)
	{	
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, rotationAngle, rotationCenter, flip);
	// TODO: Use SDL_RenderCopy (SDL_RenderCopyEx(renderer, texture, clip, &renderQuad);
	//       When there are no aditional things given(?)
}

// Getters and Setters
void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	// Moluate texture
	SDL_SetTextureColorMod(texture, red, green, blue);
}
void Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(texture, blending);
}
void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(texture, alpha);
}

int Texture::getWidth()
{
	return width;
}
int Texture::getHeight()
{
	return height;
}