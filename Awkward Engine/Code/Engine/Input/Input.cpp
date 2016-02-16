#include "Input.h"
#include "KeyState.h"
#include "MouseState.h"
#include "Controller.h"

#include <forward_list>
#include <vector>

namespace Input
{
	namespace // private stufflets
	{
		KeyState keyStates[SDL_NUM_SCANCODES];
		MouseState mouseState;
		std::vector<Controller*> controllers;

		bool anyKeyDown, anyKeyUp;
		int  anyKey; // as long as anyKey equals 0, no Key is pressed. Increment on keyDown, decrement on keyUp.

		// forward_lists with Stuff thats going to be reset in the next frame.
		std::forward_list<int> keyUpRemovals;
		std::forward_list<int> keyDownRemovals;
		std::forward_list<std::pair<int, int>> buttonDownRemovals;
		std::forward_list<std::pair<int, int>> buttonUpRemovals;
		
		// SDL_Event Handlers that are called in HandleEvent
			// Keyboard:
		void handleKeyDown(SDL_Event e)
		{
				// Return if the event is just a repeat.
			if (e.key.repeat != 0)
				return;

			// printf("pressed key: %i\n", e.key.keysym.scancode);

			keyStates[e.key.keysym.scancode].KeyDown = true;
			keyStates[e.key.keysym.scancode].Key = true;
			keyDownRemovals.push_front(e.key.keysym.scancode);
			anyKeyDown = true;
			anyKey++;
		}
		void handleKeyUp(SDL_Event e)
		{
			keyStates[e.key.keysym.scancode].KeyUp = true;
			keyStates[e.key.keysym.scancode].Key = false;
			keyUpRemovals.push_front(e.key.keysym.scancode);
			anyKeyUp = true;
			anyKey--;
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
			anyKeyDown = true;
			anyKey++;
		}
		void handleMouseButtonUp(SDL_Event e)
		{
			mouseState.Buttons[e.button.button - 1].KeyUp = true;
			mouseState.Buttons[e.button.button - 1].Key = false;
			anyKeyUp = true;
			anyKey--;
		}
		void handleMouseWheel(SDL_Event e)
		{
			mouseState.WheelDistance += e.wheel.y;
		}

			//Controller:
		void handleControllerDeviceRemoved(SDL_Event e)
		{
			printf("HandleControllerDeviceRemovedcalled for device ID %d.\n", e.cdevice.which);
		}
		void handleControllerDeviceAdded(SDL_Event e)
		{
			printf("HandleControllerDeviceAdded called for device ID %d.\n", e.cdevice.which);
		}
		void handleControllerButtonDown(SDL_Event e)
		{
			controllers[e.cbutton.which]->buttonStates[e.cbutton.button].KeyDown = true;
			controllers[e.cbutton.which]->buttonStates[e.cbutton.button].Key = true;
			buttonDownRemovals.push_front({ e.cbutton.which , e.cbutton.button });
			anyKeyDown = true;
			anyKey++;
		}
		void handleControllerButtonUp(SDL_Event e)
		{
			controllers[e.cbutton.which]->buttonStates[e.cbutton.button].KeyUp = true;
			controllers[e.cbutton.which]->buttonStates[e.cbutton.button].Key = false;
			buttonUpRemovals.push_front({ e.cbutton.which, e.cbutton.button });
			anyKeyUp = true;
			anyKey--;
		}
		void handleControllerAxisMotion(SDL_Event e)
		{
			if (e.caxis.value > 5000 || e.caxis.value < -8000)
			{
				printf("Axis Motion: Axis %d, Value: %d\n", e.caxis.axis, e.caxis.value);
			}
		}
		void handleControllerDeviceRemapped(SDL_Event e)
		{

		}
	} // End of private Stufflets

	void Init()
	{
		int x = 0;
		// Check for Connected Controllers
		if (SDL_NumJoysticks() > 0)
		{
			// Load Controllers
			for (int i = 0; i < SDL_NumJoysticks(); i++)
			{
				if (SDL_IsGameController(i))
				{
					controllers.push_back(new Controller(SDL_GameControllerOpen(i)));
					if (controllers.back()->controller == nullptr)
					{
						printf("WARNING: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
					}
				}
				x++;
			}
		}
	}
	
	void Shutdown()
	{
		// Delete Controllers
		for (Controller* controller : controllers)
		{
			delete controller;
		}
	}

	// GETTERS

	bool getAnyKey()
	{
		return anyKey != 0;
	}
	bool getAnyKeyUp()
	{
		return anyKeyUp;
	}
	bool getAnyKeyDown()
	{
		return anyKeyDown;
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

	float getControllerAxis(int controller, SDL_GameControllerAxis axis)
	{
		return controllers[controller]->getAxis(axis);
	}
	bool getControllerButton(int controller, SDL_GameControllerBindType button)
	{
		return controllers[controller]->getButton(button);
	}
	bool getControllerButtonUp(int controller, SDL_GameControllerBindType button)
	{
		return controllers[controller]->getButtonUp(button);
	}
	bool getControllerButtonDown(int controller, SDL_GameControllerBindType button)
	{
		return controllers[controller]->getButtonDown(button);
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

		// Controllers
			// KeyUp
		for (std::pair<int, int> i : buttonUpRemovals)
		{
			controllers[i.first]->buttonStates[i.second].KeyUp = false;
		}
		keyUpRemovals.clear();

			// KeyDown
		for (std::pair<int, int> i : buttonDownRemovals)
		{
			controllers[i.first]->buttonStates[i.second].KeyDown = false;
		}
		keyDownRemovals.clear();

		anyKeyDown = false;
		anyKeyUp = false;
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