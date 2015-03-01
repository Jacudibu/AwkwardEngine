#pragma once

#include <list>

#include "Headers\Vector3.h"
#include "Headers\Vector2.h"
#include "Headers\GameObject.h"

class GameObject;

class Transform
{
public:
	Vector3 Position;
	float   Rotation;
	Vector2 Scale;

	Transform(GameObject* object);
	~Transform();

	// Moves the Position by given offset.
	void Translate(Vector3 offset);
	// Rotations the Object by given angle.
	void Rotate(float angle);

	// Returns a list with points to all Children of the Transform.
	std::list<Transform*> GetChildren();
	Transform* getParent();

	// Returns the current position, rotation and Scale in World Space.
	Transform* getWorldTransform();

	// Sets the Transform's Parent. Passing nullptr takes the Transform up to the highest Level.
	void SetParent(Transform* p);

	GameObject* getGameObject();



protected:
	// Adds a Child to the Transform's children list.
	void AddChild(Transform* child);

	// Removes a Child from the Transform's children list.
	void RemoveChild(Transform* child);

private:
	// A list containing all children.
	std::list<Transform*> children;

	// The parent of the Transform.
	Transform* parent;
	GameObject* gameObject;
};