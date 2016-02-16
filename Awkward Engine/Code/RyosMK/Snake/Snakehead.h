#pragma once

#include "Direction.h"
#include "Field.h"
#include "Snaketail.h"

#include "../../Engine/Component.h"
#include "../../Engine/Input/Input.h"
#include "../../Engine/Utility/Time.h"

class Snakehead : public Component
{
public:
	float speed = 0.4f;

	Snakehead(Field* Field);
	void Update();

private:
	float timer = 0.0f;

	Direction nextDir =  Direction::Right;
	Direction currentDir = Direction::Right;

	int x;
	int y;

	void processInput();
	void moveTo(int x, int y);

	bool gameOver = false;

	Field* field;
	Snaketail* next;
};