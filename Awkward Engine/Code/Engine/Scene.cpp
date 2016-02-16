#include "Scene.h"

Scene::Scene(Camera* camera, Config* configs, RenderLayer* layer)
{
	cam = camera;
	config = configs;
	renderLayer = layer;

	Init();
}

Scene::~Scene()
{
	for (GameObject* object : objectList)
	{
		delete object;
	}
}

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

