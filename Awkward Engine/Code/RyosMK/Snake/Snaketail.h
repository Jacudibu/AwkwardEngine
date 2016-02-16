#include "Direction.h"
#include "Field.h"

#include "../../Engine/Component.h"

class Snaketail : public Component
{
public:

	Snaketail(Field* Field, Snaketail* nextTail, int posX, int posY)
	{
		ID = "Snaketail";

		field = Field;
		next = nextTail;
	
		x = posX;
		y = posY;
	}

	void Update() {};

	void moveTo(int newX, int newY)
	{
		// remove traces at old position
		field->setFieldLight(false, x, y);
		field->setFieldObject(0, x, y);

		// Tell next body part to slide with us
		if (next != nullptr)
			next->moveTo(x, y);

		// Move forward
		x = newX;
		y = newY;

		field->setFieldObject(-1, x, y);
		field->setFieldLight(true, x, y);
	}

private:
	Snaketail* next;
	Field* field;

	int x;
	int y;
};