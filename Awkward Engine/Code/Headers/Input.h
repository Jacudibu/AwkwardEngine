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

	// Returns true if the given Key is currently hold down.
	bool getKey(SDL_Scancode scancode);

	// Returns true if the given Key got released during the last frame.
	bool getKeyUp(SDL_Scancode scancode);
	
	// Returns true if the given Key got pushed.
	bool getKeyDown(SDL_Scancode scancode);

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

	void displayMouseCursor(bool enabled);


	// ---- Do Not touch these!

	// Removes all KeyDown and KeyUp Events.
	// Therefore it is called before the Events are handled.
	// Don't call that anywhere else if you don't know what you're doing.
	void RemoveKeyUpDownFlags();

	// Handles all incoming SDL_Events regarding Input.
	// Thats normally done by the game loop, so no need to call that.
	void HandleEvent(SDL_Event e);
}