#pragma once

#include <SDL.h>
#include <string>
#include "KeyMap.h"

class KeyDictionary
{
public:

	KeyDictionary();
	~KeyDictionary();

	std::string toString(KeyCode);
	std::string toString(SDL_Scancode);

	KeyCode toKeyCode(std::string);
	KeyCode toKeyCode(SDL_Scancode);

	SDL_Scancode toScanCode(std::string);
	SDL_Scancode toScanCode(KeyCode);

	
private:

	struct Key
	{
		KeyCode key;
		SDL_Scancode scan;
		std::string letter;

	};

	Key keys[110];
};
