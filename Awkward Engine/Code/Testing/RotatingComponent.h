#pragma once

#include "../Engine/Component.h"
#include "../Engine/Renderer/SpriteRenderer.h"

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