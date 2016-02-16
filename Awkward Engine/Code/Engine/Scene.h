#pragma once

#include "GameObject.h"
#include "Renderer\Camera.h"

#include "Renderer\RenderLayer.h"
#include "Utility\Config.h"

// A Scene manages all GameObjects. Think of it as a Level, that can be saved and loaded.
class Scene
{
public:
	Scene() {}
	Scene(Camera* cameras, Config* configs, RenderLayer* layer);
	virtual ~Scene();

	// Get called inside the Constructor.
	// Use this instead of a Constructor.
	virtual void Init() {}

	// Calls the Update function of every GameObject inside the Scene.
	void Update();

	// Adds the given GameObject into the Scene.
	void addGameObject(GameObject* object);

	// Removes the given GameObject from the Scene.
	void removeGameObject(GameObject* object);

	// Currently not implemented! DERP! //#TODO: CHANGE DIS
	void save(std::string path);
	void load(std::string path);

	Camera* getCamera() { return cam; }

protected:
	std::list<GameObject*> objectList;

	Camera* cam;
	RenderLayer* renderLayer;
	Config* config;
};