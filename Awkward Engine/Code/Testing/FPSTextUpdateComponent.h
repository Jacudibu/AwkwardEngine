#pragma once

#include "../Engine/Renderer/TextRenderer.h"
#include "../Engine/Component.h"
#include "../Engine/Utility/Time.h"

#include <sstream>

class FPSTextUpdateComponent : public Component
{
public:
	TextRenderer* fpsRenderer;

	// Variables for FPS
	std::stringstream timeText;

	FPSTextUpdateComponent()
	{
		__super::ID = ID;
	}

	void Update()
	{
		if (fpsRenderer == nullptr)
		{
			fpsRenderer = (TextRenderer*)gameObject->getComponent("TextRenderer");

			if (fpsRenderer == nullptr)
				return;
		}

		// Set text to be rendered
		timeText.str("");
		timeText << "FPS: " << Time::getFPS();

		// Adjust fps text
		fpsRenderer->setText(timeText.str());
	}

private:
	std::string ID = "FPSTextUpdateComponent";
};