#pragma once

#include "../Engine/Component.h"
#include "../Engine/Renderer/Camera.h"
#include "../Engine/Utility/Time.h"
#include "../Engine/Utility/Config.h"

class RotateToMouseCursorComponent : public Component
{
public:
	RotateToMouseCursorComponent(Camera* camera, Config* conf, GameObject* mouse)
	{
		ID = "RotateToMouseCursorComponent";
		cam = camera;
		config = conf;
		mouseObject = mouse;
	}

	void Update()
	{
		float degrees = Vector3::Angle2D({ cam->transform->Position.x + config->getScreenWidth()  / 2,
										   cam->transform->Position.y + config->getScreenHeight() / 2,
										   cam->transform->Position.z
										 }, mouseObject->transform->Position);

		gameObject->transform->Rotation = degrees;// +degreeOffset;
	}
	
private:
	Camera* cam;
	Config* config;
	GameObject* mouseObject;
};