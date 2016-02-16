#pragma once

#include <SDL.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h> // sleep function!

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include "ROCCAT_Talk.h"

#include "KeyMap.h"
#include "KeyDictionary.h"


#include "../../Engine/Component.h"

class KeyboardIllumination : public Component
{
public:
	KeyboardIllumination();
	~KeyboardIllumination();

	// Updates Keyboard Lightning 10 times per second.
	void Update();

	// Turns the light of the given key on.
	void setOn(KeyCode key);
	void setOn(SDL_Scancode code);
	void setOn(std::string text);

	// Turns the light of the given key off.
	void setOff(KeyCode key);
	void setOff(SDL_Scancode code);
	void setOff(std::string text);

	// Toggles the light of the given key on or off.
	void toggle(KeyCode key);

private:
	CROCCAT_Talk roccat;
	BYTE frame_data[110];
	float updateTimer = 0.0f;

	KeyCode decodeScancode(SDL_Scancode code);
	KeyDictionary* dictionary;

	int test = 0;
};