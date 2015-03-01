#include "Headers\Texture.h"
#include "Headers\ResourceManager.h"

Texture::Texture()
{
	texture = nullptr;
	width   = 0;
	height  = 0;
}

Texture::Texture(std::string filePath, SDL_Renderer* renderer)
{
	loadTextureFromFile(filePath, renderer);
}

Texture::~Texture()
{
	free();
}

void Texture::loadTextureFromFile(std::string filePath, SDL_Renderer* renderer)
{
	// Get rid of preexisting texture
	free();

	path = filePath;
	texture = ResourceManager::loadTextureFromFile(path, renderer);

	// Get image dimensions
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

void Texture::loadTextureFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* font, SDL_Renderer* renderer)
{
	// TODO: This is Solid text. Add Shaded & Blended as stated here: http://www.libsdl.org/projects/docs/SDL_ttf/SDL_ttf_35.html

	// Get rid of preexisting texture
	free();
	
	path = textureText;

	texture = ResourceManager::loadTextureFromText(textureText, renderer, textColor, font);

	// Get Image dimensions
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}


void Texture::free()
{
	// Free texture if it exists
	if (texture != nullptr)
	{
		ResourceManager::unloadTexture(path);
		path = "";
		texture = nullptr;
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