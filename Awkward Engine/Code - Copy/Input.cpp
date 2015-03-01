#include "Headers\Input.h"
//#include <stdio.h>

const Uint8* Input::currentKeyStates = SDL_GetKeyboardState(nullptr);
Input::MouseInput Input::mouse = {0, 0, false, false, false};

bool Input::getKeyDown(SDL_Scancode query)
{ 
	return currentKeyStates[query];
}

void Input::updateMouse()
{
	Uint32 status = SDL_GetMouseState(&mouse.posX, &mouse.posY);

	mouse.LButton   = status & SDL_BUTTON(SDL_BUTTON_LEFT);
	mouse.MButton   = status & SDL_BUTTON(SDL_BUTTON_MIDDLE);
	mouse.RButton   = status & SDL_BUTTON(SDL_BUTTON_RIGHT);

	// For Debug Reasons:
	// printf("x%d / y%d, LB: %d, MB: %d, RB: %d\n", mouse.posX, mouse.posY, mouse.LButton, mouse.MButton, mouse.RButton);
}

void Input::displayMouseCursor(bool enabled)
{
	if (enabled)
		SDL_ShowCursor(1);
	else
		SDL_ShowCursor(0);
}