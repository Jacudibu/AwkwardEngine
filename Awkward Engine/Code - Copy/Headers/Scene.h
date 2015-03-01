#pragma once

#include "GameObject.h"

// A Scene manages all GameObjects. Think of it as a Level, that can be saved and loaded.
class Scene
{
public:
	// Calls the Update function of every GameObject inside the Scene.
	void Update();

	void addGameObject(GameObject* object);
	void removeGameObject(GameObject* object);

	// Currently not implemented! DERP! //#TODO: CHANGE DIS
	void save(std::string path);
	void load(std::string path);
private:
	std::list<GameObject*> objectList;
};