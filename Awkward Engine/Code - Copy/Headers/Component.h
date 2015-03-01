#pragma once

#include "GameObject.h"
#include "Vector3.h"
#include "Vector2.h"


class GameObject;

class Component
{
public:
	bool enabled;
	GameObject* gameObject;

	virtual void Update() = 0;
};