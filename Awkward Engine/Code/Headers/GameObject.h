#pragma once

#include <vector>
#include "Transform.h"
#include "Component.h"

class Transform;
class Component;

class GameObject
{
public:
	bool enabled = true;
	Transform* transform;

	GameObject();
	~GameObject();

	void addComponent(Component* comp);
	void removeComponent(Component* comp);

	void Update();

	std::vector<class T*> GetComponents();
	std::vector<class T*> GetComponentsInChildren();
	
private:
	std::list<Component*> components;
};