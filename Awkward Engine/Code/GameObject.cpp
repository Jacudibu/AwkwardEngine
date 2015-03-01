#include <typeinfo>

#include "Headers\GameObject.h"

GameObject::GameObject()
{
	transform = new Transform(this);
}
GameObject::~GameObject()
{
	delete(transform);
}

void GameObject::addComponent(Component* comp)
{
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

std::vector<class T*> GameObject::GetComponents()
{
	std::vector<T*> result;
	
	for (Component* comp : components)
	{
		if (typeid(comp) == typeid(T))
			result.push_back((T*)comp);
	}

	return result;
}
std::vector<class T*> GameObject::GetComponentsInChildren()
{
	std::vector<T*> result;
	
	for (Transform* trans : transform->GetChildren())
	{
		std::vector<T*> tempVector = trans->getGameObject()->GetComponents();
		result.insert(result.end(), tempVector.begin(), tempVector.end());
	}

	return result;
}