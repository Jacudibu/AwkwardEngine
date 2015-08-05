#include "../Engine/Component.h"
#include "../Engine/Utility/Time.h"

class ConstantRotationComponent : public Component
{
public:
	ConstantRotationComponent()
	{
		ID = "ConstantRotationComponent";
	}

	void Update()
	{
		gameObject->transform->Rotate(speed * Time::getDeltaTime() * 100);
	}

	float speed = 2;
};