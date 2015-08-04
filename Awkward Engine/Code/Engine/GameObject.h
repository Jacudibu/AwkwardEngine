#pragma once

#include <vector>
#include "Transform.h"
#include "Component.h"

class Transform;
class Component;

class GameObject
{
public:
	std::hash<std::string> componentHash;

	bool enabled = true;
	Transform* transform;

	GameObject();
	~GameObject();

	// Adds a Component into our Component list.
	void addComponent(Component* comp);

	// Removes a Component from our Component list.
	void removeComponent(Component* comp);

	// Calls the Update function of every Component.
	void Update();

	// Returns the first Component with the given ID from the list.
	Component* getComponent(std::string ID);

	// Returns all Components with the given ID from the list.
	std::vector<Component*> getComponents(std::string ID);

	// Returns all the Components with the given ID from every GameObject that's inside the Transform's Children.
	std::vector<Component*> getComponentsInChildren(std::string ID);
	
private:
	std::list<Component*> components;
};