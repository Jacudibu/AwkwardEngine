#include "Headers\Sound.h"
#include "Headers\ResourceManager.h"

Sound::Sound()
{
	sound = nullptr;
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

void Sound::loadSoundFromFile(std::string filePath)
{
	free();

	sound = ResourceManager::loadSoundFromFile(filePath);
	path =  filePath;
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