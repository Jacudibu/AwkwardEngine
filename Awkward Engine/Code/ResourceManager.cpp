#include "Headers\ResourceManager.h"

namespace ResourceManager
{
	namespace // These are "real" private variables that can only be accessed within this file.
	{
		struct TextureWithCount { SDL_Texture* texture; int counter; };
		struct SoundWithCount { Mix_Chunk* sound; int counter; };
		struct MusicWithCount { Mix_Music* music; int counter; };

		std::map <std::string, TextureWithCount> textures;
		std::map <std::string, SoundWithCount>   sounds;
		std::map <std::string, MusicWithCount>   music;
	}

	SDL_Texture* loadTextureFromFile(std::string path, SDL_Renderer* renderer, bool useColorKey)
	{
		if (textures.find(path) != textures.end())
		{
			// Texture is already mapped
			textures.find(path)->second.counter++;
			return textures.find(path)->second.texture;
		}
		else
		{
			// Texture is not loaded yet, so let's load it.
			TextureWithCount newTexture;

			// Load image at specified path into a surface
			SDL_Surface* loadedSurface = IMG_Load(path.c_str());
			if (loadedSurface == nullptr)
			{
				printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
				return nullptr;
			}

			// Color key image
			if (useColorKey)
			{
				SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
			}

			// Create texture from surface pixels
			newTexture.texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (newTexture.texture == nullptr)
			{
				printf("Unable to create texture from %s!SDL Error : %s\n", path.c_str(), SDL_GetError());
				SDL_FreeSurface(loadedSurface); // We do that here because afterwards we will return
				return nullptr;
			}

			// Get rid of loaded surface
			SDL_FreeSurface(loadedSurface);

			// Add Texture into our map
			newTexture.counter = 1;
			textures.insert(std::pair<std::string, TextureWithCount>(path, newTexture));

			return newTexture.texture;
		}
	}
	SDL_Texture* loadTextureFromText(std::string text, SDL_Renderer* renderer, SDL_Color textColor, TTF_Font* font)
	{
		if (textures.find(text) != textures.end())
		{
			// Texture is already mapped
			textures.find(text)->second.counter++;
			return textures.find(text)->second.texture;
		}
		else
		{
			// Texture is not loaded yet, so let's load it.
			TextureWithCount newTexture;

			// Render text surface
			SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
			if (textSurface == nullptr)
			{
				printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
				return nullptr;
			}

			// Create texture from surface pixels
			newTexture.texture = SDL_CreateTextureFromSurface(renderer, textSurface);
			if (newTexture.texture == nullptr)
			{
				printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
				SDL_FreeSurface(textSurface);
				return nullptr;
			}

			// Get rid of old surface
			SDL_FreeSurface(textSurface);

		    // Add Texture into our map
			newTexture.counter = 1;
			textures.insert(std::pair<std::string, TextureWithCount>(text, newTexture));

			return newTexture.texture;
		}
	}
	Mix_Chunk* loadSoundFromFile(std::string path)
	{
		if (sounds.find(path) != sounds.end())
		{
			// Sound is already mapped
			sounds.find(path)->second.counter++;
			return sounds.find(path)->second.sound;
		}
		else
		{
			// Sound is not loaded yet, do it now.
			SoundWithCount newSound;

			newSound.sound = Mix_LoadWAV(path.c_str());
			if (newSound.sound == nullptr)
			{
				printf("Failed to load Sound file at path %s - SDL_mixer Error: %s", path, Mix_GetError());
				return nullptr;
			}

			// Add Sound into our map
			newSound.counter = 1;
			sounds.insert(std::pair<std::string, SoundWithCount>(path, newSound));

			return newSound.sound;
		}
	}
	Mix_Music* loadMusicFromFile(std::string path)
	{
		if (music.find(path) != music.end())
		{
			// Music is already mapped
			music.find(path)->second.counter++;
			return music.find(path)->second.music;
		}
		else
		{
			// Music is not loaded yet, do it now.
			MusicWithCount newMusic;

			newMusic.music = Mix_LoadMUS(path.c_str());
			if (newMusic.music == nullptr)
			{
				printf("Failed to load Music file at path %s - SDL_mixer Error: %s", path, Mix_GetError());
				return nullptr;
			}

			// Add Music into our map
			newMusic.counter = 1;
			music.insert(std::pair<std::string, MusicWithCount>(path, newMusic));

			return newMusic.music;
		}
	}

	void unloadTexture(std::string path)
	{
		if (textures.find(path) != textures.end())
		{
			textures.find(path)->second.counter--;
			if (textures.find(path)->second.counter <= 0)
			{
				SDL_DestroyTexture(textures.find(path)->second.texture);
				textures.erase(path);
			}
		}
		else
		{
			printf("Can't unload Texture at %s, seems to not being loaded!", path);
		}
	}
	void unloadSound(std::string path)
	{
		if (sounds.find(path) != sounds.end())
		{
			sounds.find(path)->second.counter--;
			if (sounds.find(path)->second.counter <= 0)
			{
				Mix_FreeChunk(sounds.find(path)->second.sound);
				sounds.erase(path);
			}
		}
		else
		{
			printf("Can't unload Sound at %s, seems to not being loaded!", path);
		}
	}
	void unloadMusic(std::string path)
	{
		if (music.find(path) != music.end())
		{
			music.find(path)->second.counter--;
			if (music.find(path)->second.counter <= 0)
			{
				Mix_FreeMusic(music.find(path)->second.music);
				music.erase(path);
			}
		}
		else
		{
			printf("Can't unload Music at %s, seems to not being loaded!", path);
		}
		

	}

}