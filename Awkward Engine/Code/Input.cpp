#include "Headers\Input.h"

#include <forward_list>

namespace Input
{
	namespace // private stufflets
	{
		// Contains infomation of the current Status of the Keys.
		struct KeyState
		{
			bool Key;
			bool KeyUp;
			bool KeyDown;
		};
		KeyState keyStates[SDL_NUM_SCANCODES];

		// Contains information of the current MouseStatus.
		struct MouseState
		{
			int x, y;
			KeyState Buttons[3];
			int WheelDistance;
		};
		MouseState mouseState;

		// forward_lists with Stuff thats going to be reset in the next frame.
		std::forward_list<int> keyUpRemovals;
		std::forward_list<int> keyDownRemovals;
		
		// SDL_Event Handlers that are called in HandleEvent
			// Keyboard:
		void handleKeyDown(SDL_Event e)
		{
				// Return if the event is just a repeat.
			if (e.key.repeat != 0)
				return;

			keyStates[e.key.keysym.scancode].KeyDown = true;
			keyStates[e.key.keysym.scancode].Key = true;
			keyDownRemovals.push_front(e.key.keysym.scancode);
		}
		void handleKeyUp(SDL_Event e)
		{
			keyStates[e.key.keysym.scancode].KeyUp = true;
			keyStates[e.key.keysym.scancode].Key = false;
			keyUpRemovals.push_front(e.key.keysym.scancode);
		}

			//Mouse:
		void handleMouseMotion(SDL_Event e)
		{
			mouseState.x = e.motion.x;
			mouseState.y = e.motion.y;
		}
		void handleMouseButtonDown(SDL_Event e)
		{
			mouseState.Buttons[e.button.button - 1].KeyDown = true;
			mouseState.Buttons[e.button.button - 1].Key = true;
		}
		void handleMouseButtonUp(SDL_Event e)
		{
			mouseState.Buttons[e.button.button - 1].KeyUp = true;
			mouseState.Buttons[e.button.button - 1].Key = false;
		}
		void handleMouseWheel(SDL_Event e)
		{
			mouseState.WheelDistance += e.wheel.y;
		}

			//Controller:
		void handleControllerDeviceRemoved(SDL_Event e)
		{

		}
		void handleControllerDeviceAdded(SDL_Event e)
		{

		}
		void handleControllerButtonDown(SDL_Event e)
		{

		}
		void handleControllerButtonUp(SDL_Event e)
		{

		}
		void handleControllerAxisMotion(SDL_Event e)
		{

		}
		void handleControllerDeviceRemapped(SDL_Event e)
		{

		}
	}

	bool getKey(SDL_Scancode scancode)
	{
		return keyStates[scancode].Key;
	}
	bool getKeyUp(SDL_Scancode scancode)
	{
		return keyStates[scancode].KeyUp;
	}
	bool getKeyDown(SDL_Scancode scancode)
	{
		return keyStates[scancode].KeyDown;
	}

	bool getMouse(MouseButton button)
	{
		return mouseState.Buttons[button].Key;
	}
	bool getMouseUp(MouseButton button)
	{
		return mouseState.Buttons[button].KeyUp;
	}
	bool getMouseDown(MouseButton button)
	{
		return mouseState.Buttons[button].KeyDown;
	}
	int getMousePositionX()
	{
		return mouseState.x;
	}
	int getMousePositionY()
	{
		return mouseState.y;
	}

	void displayMouseCursor(bool enabled)
	{
		if (enabled)
			SDL_ShowCursor(1);
		else
			SDL_ShowCursor(0);
	}

	void RemoveKeyUpDownFlags()
	{
		// Keyboard
		// KeyUp
		for (int i : keyUpRemovals)
		{
			keyStates[i].KeyUp = false;
		}
		keyUpRemovals.clear();

		// KeyDown
		for (int i : keyDownRemovals)
		{
			keyStates[i].KeyDown = false;
		}
		keyDownRemovals.clear();

		// Mouse
		mouseState.Buttons[0].KeyDown = false;
		mouseState.Buttons[0].KeyUp = false;
		mouseState.Buttons[1].KeyDown = false;
		mouseState.Buttons[1].KeyUp = false;
		mouseState.Buttons[2].KeyDown = false;
		mouseState.Buttons[2].KeyUp = false;
		mouseState.WheelDistance = 0;
	}
	void HandleEvent(SDL_Event e)
	{
		switch (e.type)
		{
		case SDL_KEYDOWN:
			handleKeyDown(e);
			break;

		case SDL_KEYUP:
			handleKeyUp(e);
			break;

		case SDL_MOUSEMOTION:
			handleMouseMotion(e);
			break;

		case SDL_MOUSEBUTTONDOWN:
			handleMouseButtonDown(e);
			break;

		case SDL_MOUSEBUTTONUP:
			handleMouseButtonUp(e);
			break;

		case SDL_MOUSEWHEEL:
			handleMouseWheel(e);
			break;

		case SDL_CONTROLLERAXISMOTION:
			handleControllerAxisMotion(e);
			break;

		case SDL_CONTROLLERBUTTONDOWN:
			handleControllerButtonDown(e);
			break;

		case SDL_CONTROLLERBUTTONUP:
			handleControllerButtonUp(e);
			break;

		case SDL_CONTROLLERDEVICEADDED:
			handleControllerDeviceAdded(e);
			break;

		case SDL_CONTROLLERDEVICEREMOVED:
			handleControllerDeviceRemoved(e);
			break;

		case SDL_CONTROLLERDEVICEREMAPPED:
			handleControllerDeviceRemapped(e);
			break;

		default:
			break;
		}
	}
}