#pragma once

#include "GameObject.h"

// A Scene manages all GameObjects. Think of it as a Level, that can be saved and loaded.
class Scene
{
public:
	Scene();
	~Scene();

	// Calls the Update function of every GameObject inside the Scene.
	void Update();

	// Adds the given GameObject into the Scene.
	void addGameObject(GameObject* object);

	// Removes the given GameObject from the Scene.
	void removeGameObject(GameObject* object);

	// Currently not implemented! DERP! //#TODO: CHANGE DIS
	void save(std::string path);
	void load(std::string path);
private:
	std::list<GameObject*> objectList;
};