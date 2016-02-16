#pragma once

#include "../../Engine/GameObject.h"
#include "../Keyboard/KeyboardIllumination.h"
#include <random>

#include "../../Engine/Utility/Time.h"
#include "../../Engine/Renderer/TextRenderer.h"

class Field : public GameObject
{
public:
	Field(RenderLayer* renderLayer)
	{
		keyboard = new KeyboardIllumination();
		scoreText = new TextRenderer("Score", renderLayer, { 0x0, 0x0, 0x0, 0xFF });
		
		randomGenerator.seed(Time::getWindowsTime());

		transform->Position = { 200, 200, 0 };

		// addComponent(new Snakehead(this));
		addComponent(scoreText);
		addComponent(keyboard);
		
		spawnCandy();

		
	}

	~Field() { }
	
	
	void Restart()
	{
		/*
		delete keyboard;
		delete scoreText;

		keyboard = new KeyboardIllumination();
		scoreText = new TextRenderer("Score", renderLayer, { 0x0, 0x0, 0x0, 0xFF });

		randomGenerator.seed(Time::getWindowsTime());
		*/
	}


	void Update()
	{
		__super::Update();

		if (!gameOver)
		{
			candyTimer += Time::getDeltaTime();
			if (candyTimer > 0.2f)
			{
				candyTimer -= 0.2f;
				toggleFieldLight(candyX, candyY);
			}

			scoreText->setText("Score: " + std::to_string(score));
		}
		else
		{
			scoreText->setText("Game Over! Score: " + std::to_string(score));
		}
	}

	void setFieldObject(int status, int x, int y)
	{
		field[x + y * 10] = status;
	}

	int getFieldStatus(int x, int y)
	{
		return field[x + y * 10];
	}

	void setFieldLight(bool status, int x, int y)
	{
		int start = 0;

		switch (y)
		{
		case 3: start = 18; break;
		case 2: start = 40; break;
		case 1: start = 62; break;
		case 0: start = 80; break;
		default: start = 80; break;
		}

		if (status)
			keyboard->setOn((KeyCode) (start + x));
		else
			keyboard->setOff((KeyCode) (start + x));
	}

	void toggleFieldLight(int x, int y)
	{
		int start = 0;

		switch (y)
		{
		case 3: start = 18; break;
		case 2: start = 40; break;
		case 1: start = 62; break;
		case 0: start = 80; break;
		default: start = 80; break;
		}

		keyboard->toggle((KeyCode)(start + x));
	}

	void collectCandy()
	{
		score++;
		spawnCandy();
	}

	void GameOver()
	{
		gameOver = true;
		setFieldLight(false, candyX, candyY);
	}

private:
	// -1: Snake on that field
	//  0: Empty field
	//  1: Candy on that field
	int field[40];
	KeyboardIllumination* keyboard;
	
	TextRenderer* scoreText;
	int score;
	bool gameOver = false;

	// Candy Magic
	float candyTimer = 0.0f;

	std::default_random_engine randomGenerator;
	std::uniform_int_distribution<int> randomDistribution;

	int candyX = 0;
	int candyY = 0;
	
	void spawnCandy()
	{
		std::uniform_int_distribution<int> randomDistribution(0, 39);


		int position;
		do
		{
			position = randomDistribution(randomGenerator);
		} while (field[position] != 0);

		field[position] = 1;

		// enlighten us!
		candyX = position % 10;
		candyY = position / 10;

		setFieldLight(true, candyX, candyY);

	}
	

};