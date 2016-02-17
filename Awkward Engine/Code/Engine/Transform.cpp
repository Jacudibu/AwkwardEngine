#include "Transform.h"

Transform::Transform(GameObject* object)
{
	gameObject = object;
	Position = { 0.0f, 0.0f, 0.0f };
	Rotation = 0.0f;
	Scale = { 0.0f, 0.0f };
}
Transform::~Transform()
{
	SetParent(nullptr);
}

void Transform::Translate(Vector3 offset)
{
	Position += offset;
}
void Transform::Rotate(float angle)
{
	Rotation += angle;
}


std::list<Transform*> Transform::GetChildren()
{
	return children;
}
Transform* Transform::getParent()
{
	return parent;
}

void Transform::SetParent(Transform* p)
{
	if (parent != nullptr)
		parent->RemoveChild(this);
	
	parent = p;

	if (p != nullptr)
		p->AddChild(this);
}

GameObject* Transform::getGameObject()
{
	return gameObject;
}

Transform* Transform::getWorldTransform()
{
	Transform* trans = this;

	Transform* result = new Transform(*trans);

	while (trans->parent != nullptr)
	{
		trans = parent;
		result->Position += trans->Position;
		result->Rotation += trans->Rotation;
		result->Scale *= trans->Scale;
	}

	return result;
}


void Transform::AddChild(Transform* child)
{
	children.push_back(child);
}
void Transform::RemoveChild(Transform* child)
{
	children.remove(child);
}