#pragma once

#include "KeyState.h"

// Contains information of the current MouseStatus.
struct MouseState
{
	int x, y;
	KeyState Buttons[3];
	int WheelDistance;
};