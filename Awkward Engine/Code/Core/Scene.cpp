#include "Scene.h"

void Scene::Update()
{
	for (GameObject* obj : objectList)
	{
		obj->Update();
	}
}

void Scene::addGameObject(GameObject* object)
{
	objectList.push_back(object);
}

void Scene::removeGameObject(GameObject* object)
{
	objectList.remove(object);
}