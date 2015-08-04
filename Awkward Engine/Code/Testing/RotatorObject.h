#pragma once

#include "../Core/GameObject.h"
#include "RotatingComponent.h"

class RotatorObject : public GameObject
{
	RotatorObject()
	{
		__super::GameObject();
		RotatingComponent* rotatingComponent = new RotatingComponent();

		addComponent(rotatingComponent);
	}


};