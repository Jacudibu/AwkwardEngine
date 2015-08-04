#pragma once

#include "../Core/Component.h"
#include "../Renderer/SpriteRenderer.h"

class RotatingComponent : public Component
{
public:
	RotatingComponent()
	{
		__super::ID = "RotatingComponent";
	}

	float rotationSpeed = 1;

	void Update();
};