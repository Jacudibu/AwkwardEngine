#pragma once

#include <SDL.h>

// TODO: Include SCROLL WHEEL!

/* Class to Manage User Input of any type.
 */
class Input
{
public:

	/* Used to manage Mouse input.
	 */ // TODO: SCROLL THE WHEEL!
	struct MouseInput
	{
		int posX;
		int posY;
		bool LButton;
		bool MButton;
		bool RButton;
	}; // TODO: SCROLL WHEEEEEEEEEL!

	/* Used to Update Mouse Movement.
	   Automatically called whenever a Mouse event occurs, no need to use this for normal people. :P
	*/
	static void updateMouse(); // #TODO: protected & friends with Game

	/* Used to check wether a Key is pressed. 
	   For SDL_Scancode References, go to http://wiki.libsdl.org/SDL_Scancode.
	 */
	static bool getKeyDown(SDL_Scancode query);
	static void displayMouseCursor(bool enabled);
	
	static MouseInput mouse;


private:
	static const Uint8* currentKeyStates;
};