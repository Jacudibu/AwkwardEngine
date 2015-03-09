#pragma once

#include <SDL_mixer.h>
#include <string>
#include "..\Core\Component.h"

// Music is streamed, meaning it performs great with large files (like background music)
// As a drawback, you can only play one music at a time. So choose wisely.
class Music : public Component
{
public:
	Music();
	~Music();

	// Load the music located at the path.
	// Supported Formats: WAVE, MOD, MIDI, OGG, MP3, FLAC
	void loadMusicFromFile(std::string filePath);

	// Play the music thats loaded inside this Instance.
	void Play(bool loop = true);

	// Play the Music file loaded inside the given Instance.
	static void Play(Music music, bool loop = true);

	// Pause current Music. Nothing happens if no Music is played.
	static void Pause();

	// Resume paused Music. Nothing happens if no Music is played.
	static void Resume();

	// Toggles between paused and unpaused. Does nothing if no Music is played.
	static void Toggle();

	// Stops current Music.
	static void Stop();

	// Returns true if Music is playing.
	static bool isPlaying();

	// Returns true if Music is paused or not Playing at all.
	static bool isPaused();

	// Set the Volume of the Music.
	static void setVolume(Uint8);

	// Frees allocated Memory.
	void free();

	// Update does nothing.
	virtual void Update() {}

	// GetID is used to compare types of Components.
	std::string getID() { return ID; }

private:
	// Used to compare components for similiarity.
	std::string ID = "Music";

	Mix_Music* music;
	std::string path;
};