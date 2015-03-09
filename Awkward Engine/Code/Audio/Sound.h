#pragma once

#include <SDL_mixer.h>
#include <string>
#include "..\Core\Component.h"

// Use this for Sound Effects.
class Sound : public Component
{
public:
	Sound();
	~Sound();

	// Loads the soundfile from given path.
	// Supported formats: WAVE, AIFF, RIFF, OGG, VOC
	void loadSoundFromFile(std::string filePath);

	// Plays the Sound.
	void Play();

	// Frees allocated Memory.
	void free();

	// Set Volume to a value between 0 (silent) and 128 (loud)
	void setVolume(Uint8 value);

	// Update does nothing.
	virtual void Update() {}

	// GetID is used to compare types of Components.
	std::string getID() { return ID; }

private:
	// Used to compare components for similiarity.
	std::string ID = "Sound"; 
	
	Mix_Chunk* sound;
	std::string path;
};