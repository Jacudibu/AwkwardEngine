#pragma once

#include "../Engine/Component.h"
#include "../Engine/Renderer/Camera.h"
#include "../Engine/Utility/Time.h"
#include "../Engine/Input/Input.h"
#include "../Engine/Renderer/SpriteRenderer.h"


class MouseComponent : public Component
{
public:
	MouseComponent(Camera* camera)
	{
		ID = "MouseComponent";
		cam = camera;
	}

	void Update()
	{
		if (cam == nullptr)
			return;

		// Change mouse cursor
		gameObject->transform->Position = { (float)Input::getMousePositionX(), (float)Input::getMousePositionY(), 0.0f };
		gameObject->transform->Position -= cam->transform->Position;

		mouseObjectStep += Time::getDeltaTime();

		((SpriteRenderer*)gameObject->getComponent("SpriteRenderer"))->setCurrentClip(((int)mouseObjectStep % 2) + 1);
	}

private:
	float mouseObjectStep = 0;
	Camera* cam;
};