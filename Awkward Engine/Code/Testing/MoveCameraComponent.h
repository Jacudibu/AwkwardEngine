#pragma once

#include "../Engine/Renderer/Camera.h"
#include "../Engine/Input/Input.h"
#include "../Engine/Utility/Time.h"

class MoveCameraComponent : public Component
{
public:
	MoveCameraComponent()
	{
		__super::ID = ID;
	}

	void Update()
	{
		if (Input::getKey(SDL_SCANCODE_DOWN))
			gameObject->transform->Position.y += 100 * Time::getDeltaTime();
		if (Input::getKey(SDL_SCANCODE_UP))
			gameObject->transform->Position.y -= 100 * Time::getDeltaTime();
		if (Input::getKey(SDL_SCANCODE_RIGHT))
			gameObject->transform->Position.x += 100 * Time::getDeltaTime();
		if (Input::getKey(SDL_SCANCODE_LEFT))
			gameObject->transform->Position.x -= 100 * Time::getDeltaTime();
	}

private:
	std::string ID = "MoveCameraComponent";
};