#pragma once

#include "GameObject.h"
#include "Utility\Vector3.h"
#include "Utility\Vector2.h"


class GameObject;

class Component
{
public:
	virtual ~Component() { printf("%s deleted!\n", ID.c_str()); };

	// If false, the component will skip all its update functions.
	bool enabled = true;

	// A reference to the gameObject the Component is attached to.
	GameObject* gameObject = nullptr;

	// "Update is called once per Frame." [Obviously not a Unity Quote]
	virtual void Update() = 0;

	// Returns the Component ID.
	virtual std::string getID() {return ID;}

//private:
protected:
	// Used to compare components for similiarity.
	std::string ID;
};