#include "Snakehead.h"

Snakehead::Snakehead(Field* Field)
{
	ID = "Snakehead";

	x = 0;
	y = 0;
	
	field = Field;
	next = nullptr;
}

void Snakehead::Update()
{

	processInput();

	timer += Time::getDeltaTime();

	if (timer > speed)
	{
		timer -= speed;

		if (!gameOver)
		{

			// Move to nextDir
			if (nextDir == Direction::Down)
			{
				moveTo(x, y - 1);
			}
			else if (nextDir == Direction::Up)
			{
				moveTo(x, y + 1);
			}
			else if (nextDir == Direction::Left)
			{
				moveTo(x - 1, y);
			}
			else if (nextDir == Direction::Right)
			{
				moveTo(x + 1, y);
			}

			currentDir = nextDir;
		}
		else
		{
			field->toggleFieldLight(x, y);
		}
	}
}

void Snakehead::processInput()
{
	if (Input::getKeyDown(SDL_SCANCODE_UP) && currentDir != Direction::Down)
	{
		nextDir = Direction::Up;
	}
	else if (Input::getKeyDown(SDL_SCANCODE_DOWN) && currentDir != Direction::Up)
	{
		nextDir = Direction::Down;
	}
	else if (Input::getKeyDown(SDL_SCANCODE_LEFT) && currentDir != Direction::Right)
	{
		nextDir = Direction::Left;
	}
	else if (Input::getKeyDown(SDL_SCANCODE_RIGHT) && currentDir != Direction::Left)
	{
		nextDir = Direction::Right;
	}
}

void Snakehead::moveTo(int newX, int newY)
{
	// Clamp Values first
	if (newX > 9)
		newX = 0;
	else if (newX < 0)
		newX = 9;

	if (newY > 3)
		newY = 0;
	else if (newY < 0)
		newY = 3;

	// Collected some candy!
	if (field->getFieldStatus(newX, newY) == 1)
	{
		field->collectCandy();
		Snaketail* tail = new Snaketail(field, next, x, y);
		next = tail;
		field->addComponent(tail);

		// Incease speed (by decreasing it! yes that makes sense!)
		speed -= 0.01f;

		// Only move the head forwards
		x = newX;
		y = newY;

		// mark new position
		field->setFieldObject(-1, x, y);
		field->setFieldLight(true, x, y);
		
	}
	else if (field->getFieldStatus(newX, newY) == -1)
	{
		gameOver = true;
		field->GameOver();
	} // laravell
	else
	{
		// remove traces at old position
		field->setFieldLight(false, x, y);
		field->setFieldObject(0, x, y);

		// Move the tails forward
		if (next != nullptr)
			next->moveTo(x, y);

		x = newX;
		y = newY;

		// mark new position
		field->setFieldObject(-1, x, y);
		field->setFieldLight(true, x, y);
	}
}