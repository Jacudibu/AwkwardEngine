#pragma once

#include <SDL.h>
#include "KeyState.h"
#include <stdio.h>

// A struct that manages the Keystates of the connected GameControllers.
struct Controller
{
	// Members
	SDL_GameController* controller;
	SDL_Haptic* haptic;
	KeyState buttonStates[SDL_CONTROLLER_BUTTON_MAX];

	// Functions
	Controller()
	{
		printf("Emtpy Controller created. o.o\n");
	}
	Controller(SDL_GameController* _controller)
	{
		controller = _controller;

		// Get Haptic Device!
		haptic = SDL_HapticOpenFromJoystick(SDL_GameControllerGetJoystick(controller));
		if (haptic == nullptr)
		{
			printf("WARNING: Controller does not support haptics! Dx\n");
		}
		else
		{
			if (SDL_HapticRumbleInit(haptic) < 0)
			{
				printf("WARNING: Unable to initialize rumble! (wtf?!) SDL Error: %s\n", SDL_GetError());
			}
			SDL_HapticRumblePlay(haptic, 0.25, 100);
		}
	}
	~Controller()
	{
		SDL_GameControllerClose(controller);
		controller = nullptr;
		SDL_HapticClose(haptic);
		haptic = nullptr;
		printf("Controller destroyed!");
	}
};