#pragma once

#include "../Engine/Scene.h"

#include "../Testing/RotatingComponent.h"
#include "../Testing/FPSTextUpdateComponent.h"
#include "../Testing/MoveCameraComponent.h"
#include "../Testing/MouseComponent.h"
#include "../Testing/RotateToMouseCursorComponent.h"
#include "../Testing/PlaySoundOnButtonPressComponent.h"
#include "../Testing/ConstantRotationComponent.h"

#include "Snake/Field.h"
#include "Snake/Snakehead.h"

class TestingScene : public Scene
{
public:
	TestingScene(Camera* camera, Config* configs, RenderLayer* layer)
	{
		cam = camera;
		config = configs;
		renderLayer = layer;
		Init();
	}

	~TestingScene()
	{
	}

	void Init()
	{
		/*
		// ---- Awkward Engine standart shiet
		GameObject* mouseObject = new GameObject();
		GameObject* awkwardLogoObject = new GameObject();
		GameObject* fpsObject = new GameObject();
		GameObject* soundObject = new GameObject();

		soundObject->addComponent(new Sound("resources/testsounds/punch.wav", 128));
		soundObject->addComponent(new PlaySoundOnButtonPressComponent());

		mouseObject->addComponent(new SpriteRenderer("resources/cursor.png", renderLayer, 1, 2, 1));
		mouseObject->addComponent(new ConstantRotationComponent());
		mouseObject->addComponent(new MouseComponent(cam));

		awkwardLogoObject->transform->Position = { (float)config->getScreenWidth() / 2, (float)config->getScreenHeight() / 2, 0 };
		awkwardLogoObject->addComponent(new RotatingComponent());
		awkwardLogoObject->addComponent(new SpriteRenderer("resources/awkwardLogo.png", renderLayer));

		fpsObject->addComponent(new TextRenderer("FPS", renderLayer, { 0x0, 0x0, 0x0, 0xFF }));
		fpsObject->addComponent(new FPSTextUpdateComponent());
		fpsObject->addComponent(new RotateToMouseCursorComponent(cam, config, mouseObject));
		fpsObject->transform->Position = { (float)config->getScreenWidth() / 2, (float)config->getScreenHeight() / 2, 0 };

		addGameObject(mouseObject);
		addGameObject(awkwardLogoObject);
		addGameObject(fpsObject);
		addGameObject(soundObject);

		cam->addComponent(new MoveCameraComponent());
		// ---- Awkward Engine standart shiet
		*/

		Field* field = new Field(renderLayer);
		field->addComponent(new Snakehead(field));




		addGameObject(field);
	}
};