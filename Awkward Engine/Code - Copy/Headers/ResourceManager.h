/* ResourceManager

   This class provides a static Database of all loaded files and utilitys to load new files.
*/

#pragma once

#include <map>
#include <string>

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


namespace ResourceManager
{
	// Returns a pointer to the loaded texture.
	SDL_Texture* loadTextureFromFile(std::string path, SDL_Renderer* renderer, bool useColorKey = false);

	// Returns a pointer to the loaded texture.
	SDL_Texture* loadTextureFromText(std::string text, SDL_Renderer* renderer, SDL_Color textColor, TTF_Font* font);

	// Returns a pointer to the loaded sound.
	Mix_Chunk* loadSoundFromFile(std::string path);

	// Returns a pointer to the loaded music.
	Mix_Music* loadMusicFromFile(std::string path);

	// Unloads a texture if it is no longer needed.
	void unloadTexture(std::string path);
	
	// Unloads a texture if it is no longer needed.
	void unloadTexture(std::string path);

	// Unloads a sound if it is no longer needed.
	void unloadSound(std::string path);

	// Unloads a music if it is no longer needed.
	void unloadMusic(std::string path);


};