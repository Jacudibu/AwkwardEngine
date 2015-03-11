#include <typeinfo>

#include "GameObject.h"

GameObject::GameObject()
{
	transform = new Transform(this);
}
GameObject::~GameObject()
{
	delete(transform);

	for (Component* comp : components)
	{
		delete comp;
	}
}

void GameObject::addComponent(Component* comp)
{
	// If the Component was attached to another GameObject before, remove it.
	if (comp->gameObject != nullptr)
		comp->gameObject->removeComponent(comp);

	comp->gameObject = this;
	components.push_back(comp);
}
void GameObject::removeComponent(Component* comp)
{
	components.remove(comp);
	comp->gameObject = nullptr;
}

void GameObject::Update()
{
	if (!enabled)
		return;

	for (Component* comp : components)
	{
		comp->Update();
	}
}

Component* GameObject::getComponent(std::string ID)
{
	for (Component* comp : components)
	{
		if (comp->getID().compare(ID) == 0)
			return comp;
	}

	return nullptr;
}
std::vector<Component*> GameObject::getComponents(std::string ID)
{
	std::vector<Component*> result;
	
	for (Component* comp : components)
	{
		if (comp->getID().compare(ID) == 0)
			result.push_back(comp);
	}

	return result;
}
std::vector<Component*> GameObject::getComponentsInChildren(std::string ID)
{
	std::vector<Component*> result;
	
	for (Transform* trans : transform->GetChildren())
	{
		std::vector<Component*> tempVector = trans->getGameObject()->getComponents(ID);
		result.insert(result.end(), tempVector.begin(), tempVector.end());
	}

	return result;
}
