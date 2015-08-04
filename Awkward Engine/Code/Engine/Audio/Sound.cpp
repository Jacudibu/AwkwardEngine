#include "Sound.h"
#include "..\Utility\ResourceManager.h"

Sound::Sound()
{
	sound = nullptr;
}

Sound::Sound(std::string filePath, Uint8 volume)
{
	loadSoundFromFile(filePath, volume);
}

Sound::~Sound()
{
	free();
}

void Sound::free()
{
	if (sound != nullptr)
	{
		ResourceManager::unloadSound(path);
		sound = nullptr;
		path = "";
	}
}

void Sound::loadSoundFromFile(std::string filePath, Uint8 volume)
{
	free();

	sound = ResourceManager::loadSoundFromFile(filePath);
	path =  filePath;
	setVolume(volume);
}

void Sound::Play()
{
	if (sound != nullptr)
		Mix_PlayChannel(-1, sound, 0);
	else
		printf("Failed to play Sound: No sound file loaded.");
}

void Sound::setVolume(Uint8 value)
{
	sound->volume = value;
}