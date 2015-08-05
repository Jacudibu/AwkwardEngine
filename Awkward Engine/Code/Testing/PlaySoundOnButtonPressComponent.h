#pragma once

#include "../Engine/Component.h"
#include "../Engine/Audio/Sound.h"
#include "../Engine/Input/Input.h"

class PlaySoundOnButtonPressComponent : public Component
{
public:
	PlaySoundOnButtonPressComponent()
	{
		ID = "PlaySoundOnButtonPressComponent";
	}

	void Update()
	{
		if (sound == nullptr)
		{
			sound = (Sound*)gameObject->getComponent("Sound");

			if (sound == nullptr)
				return;
		}

		if (Input::getKeyDown(SDL_SCANCODE_U))
			sound->Play();
	}

private:
	Sound* sound;
};