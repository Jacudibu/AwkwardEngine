#include "Headers\Music.h"
#include "Headers\ResourceManager.h"

Music::Music()
{
	music = nullptr;
}

Music::~Music()
{
	free();
}

void Music::free()
{
	if (music != nullptr)
	{
		ResourceManager::unloadMusic(path);
		music = nullptr;
		path = "";
	}
}

void Music::loadMusicFromFile(std::string filePath)
{
	free();

	path = filePath;
	music = ResourceManager::loadMusicFromFile(path);
}

void Music::Play(bool loop)
{
	if (music != nullptr)
	{
		if (loop)
			Mix_PlayMusic(music, -1);
		else
			Mix_PlayMusic(music, 0);
	}
	else
		printf("Failed to play Music: No music file loaded.");
}

void Music::Pause()
{
	if (Mix_PlayingMusic() == 1 && Mix_PausedMusic() == 0)
		Mix_PauseMusic();
}

void Music::Resume()
{
	if (Mix_PlayingMusic() == 1 && Mix_PausedMusic() == 1)
		Mix_ResumeMusic();
}

void Music::Toggle()
{
	if (Mix_PlayingMusic() == 1)
	{
		if (Mix_PausedMusic() == 1)
			Mix_ResumeMusic();
		else
			Mix_PauseMusic();
	}
}

void Music::Stop()
{
	Mix_HaltMusic();
}

bool Music::isPlaying()
{
	return Mix_PlayingMusic() == 1;
}

bool Music::isPaused()
{
	return Mix_PlayingMusic() == 1 && Mix_PausedMusic() == 1;
}

void Music::setVolume(Uint8 value)
{
	Mix_VolumeMusic(value);
}