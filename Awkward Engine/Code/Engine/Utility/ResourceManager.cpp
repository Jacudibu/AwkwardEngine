#include "ResourceManager.h"

namespace ResourceManager
{
	namespace // These are "real" private variables that can only be accessed within this file.
	{
		struct TextureWithCount { Texture* texture; int counter; };
		struct SoundWithCount { Mix_Chunk* sound; int counter; };
		struct MusicWithCount { Mix_Music* music; int counter; };

		std::map <std::string, TextureWithCount> textures;
		std::map <std::string, SoundWithCount>   sounds;
		std::map <std::string, MusicWithCount>   music;
	}

	Texture* loadTextureFromFile(std::string path, SDL_Renderer* renderer, bool useColorKey)
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
			newTexture.texture = new Texture(path, renderer, useColorKey);

			// Add Texture into our map
			newTexture.counter = 1;
			textures.insert(std::pair<std::string, TextureWithCount>(path, newTexture));

			return newTexture.texture;
		}
	}
	Texture* loadTextureFromText(std::string text, SDL_Renderer* renderer, SDL_Color textColor, TTF_Font* font)
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
			newTexture.texture = new Texture(text, renderer, textColor, font);

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
				delete(textures.find(path)->second.texture);
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