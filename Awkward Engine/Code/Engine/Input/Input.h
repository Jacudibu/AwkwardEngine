#pragma once

#include <SDL.h>

namespace Input
{
	// Enum to Handle Mouse Buttons in a convinient way.
	enum MouseButton
	{
		Left = 0,
		Middle = 1,
		Right = 2,
	};

	//-----------------
	// General Utility
	//-----------------

	void displayMouseCursor(bool enabled);



	//---------
	// Getters
	//---------

	// Returns true if any Key is currently hold down Includes Keyboard, Controller and Mouse input.
	bool getAnyKey();

	// Returns true if any Key got released during the last frame. Includes Keyboard, Controller and Mouse input.
	bool getAnyKeyUp();

	// Returns true if any Key got pressed. Includes Keyboard, Controller and Mouse input.
	bool getAnyKeyDown();


	// Keyboard
	//----------

	// Returns true if the given Key is currently hold down.
	bool getKey(SDL_Scancode scancode);

	// Returns true if the given Key got released during the last frame.
	bool getKeyUp(SDL_Scancode scancode);
	
	// Returns true if the given Key got pushed.
	bool getKeyDown(SDL_Scancode scancode);


	// Mouse Stuff
	//-------------

	//  Returns the current X Position of the Mouse.
	int getMousePositionX();

	// Returns the current Y Position of the Mouse.
	int getMousePositionY();

	// Returns true if the given mouseButton is currently hold down.
	bool getMouse(MouseButton button);

	// Returns true if the given mouseButton got released during the last frame.
	bool getMouseUp(MouseButton button);

	// Returns true if the given mouseButton got pressed.
	bool getMouseDown(MouseButton button);


	// Controller Stuff
	//------------------

	// Returns the Position of the given controller axis in Range [-1,1]
	float getControllerAxis(int controller, SDL_GameControllerAxis axis);

	// Returns true while the button on the given controller is held down.
	bool getControllerButton(int controller, SDL_GameControllerBindType button);

	// Returns true in the frame the given button is released.
	bool getControllerButtonUp(int controller, SDL_GameControllerBindType button);

	// Returns true in the frame the given button is pressed.
	bool getControllerButtonDown(int controller, SDL_GameControllerBindType button);



	//------------------------------
	// Stuff thats called by Game.h
	//------------------------------

	// Initializes the Controllers.
	// Needs to be called once before the Game Loop starts if you wan't to query Controller Input.
	void Init();

	// De-Initializes the Controllers.
	// Needs to be called once after the Game Loop is finished if you don't like memory leaks.
	void Shutdown();

	// Removes all KeyDown and KeyUp Events.
	// Therefore it is called before the Events are handled.
	// Don't call that anywhere else if you don't know what you're doing.
	void RemoveKeyUpDownFlags();

	// Handles all incoming SDL_Events regarding Input.
	// Thats normally done by the game loop, so no need to call that.
	void HandleEvent(SDL_Event e);
}