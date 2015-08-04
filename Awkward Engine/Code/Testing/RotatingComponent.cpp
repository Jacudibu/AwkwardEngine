#include "RotatingComponent.h"
#include "../Engine/Input/Input.h"
#include "../Engine/Utility/Time.h"

void RotatingComponent::Update()
{
	float rotationAmount = 0;

	if (Input::getKey(SDL_SCANCODE_A) || Input::getMouse(Input::MouseButton::Left))
		rotationAmount = 1 * Time::getDeltaTime() * 100.0f;
	if (Input::getKey(SDL_SCANCODE_D) || Input::getMouse(Input::MouseButton::Right))
		rotationAmount = 1 * Time::getDeltaTime() * 100.0f;

	gameObject->transform->Rotate(rotationAmount * rotationSpeed);
}