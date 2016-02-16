#include "KeyboardIllumination.h"

#include "../../Engine/Utility/Time.h"
#include <sstream>

KeyboardIllumination::KeyboardIllumination()
{
	ID = "KeyboardIllumination";

	// Try to connect to the Ryos
	if (!roccat.init_ryos_talk())
	{
		printf("Keyboard - Error: Could not connect to Ryos Keyboard!\n");
	}
	else
	{
		printf("Keyboard - Succes: Connection established!\n");

		// Activate SDK Mode
		roccat.set_ryos_kb_SDKmode(TRUE);
		roccat.turn_off_all_LEDS();

		memset(frame_data, 0, 110);
	}

	dictionary = new KeyDictionary();
}
KeyboardIllumination::~KeyboardIllumination()
{
	// Eliminate all Indications that we've ever used the SDKMode
	roccat.turn_off_all_LEDS();
	roccat.RestoreLEDRGB();
	roccat.set_ryos_kb_SDKmode(FALSE);

	delete dictionary;
}

void KeyboardIllumination::Update()
{
	updateTimer += Time::getDeltaTime();

	if (updateTimer >= 0.1f)
	{
		updateTimer -= 0.1f;
		roccat.Set_all_LEDS(frame_data);

		/*
		// Line Effect
		printf("%i: %s\n", test, dictionary->toString(((KeyCode)test)).c_str());
		
		if (test == 0)
			setOff((KeyCode)109);
		else
			setOff((KeyCode)(test - 1));
		
		setOn((KeyCode)test);
		test++;
		test = test % 110;
		*/
	}
}

void KeyboardIllumination::setOn(KeyCode key)
{
	if (key < 110)
		frame_data[key] = 1;
}
void KeyboardIllumination::setOn(SDL_Scancode code)
{
	setOn(dictionary->toKeyCode(code));
}
void KeyboardIllumination::setOn(std::string text)
{
	// FIXME: Probably one of these "OH MA GOSH DIS IS SO LAZY AND INEFFICIENT Q_Q" Solutions. :c
	for (char a : text)
	{	
		std::stringstream ss;
		std::string target;

		ss << a;
		ss >> target;

		setOn(dictionary->toKeyCode(target));
	}
}


void KeyboardIllumination::setOff(KeyCode key)
{
	if (key < 110)
		frame_data[key] = 0;
}
void KeyboardIllumination::setOff(SDL_Scancode code)
{
	setOff(dictionary->toKeyCode(code));
}
void KeyboardIllumination::setOff(std::string text)
{
	// FIXME: Probably one of these "OH MA GOSH DIS IS SO LAZY AND INEFFICIENT Q_Q" Solutions. :c
	for (char a : text)
	{
		std::stringstream ss;
		std::string target;

		ss << a;
		ss >> target;

		setOff(dictionary->toKeyCode(target));
	}
}

void KeyboardIllumination::toggle(KeyCode key)
{
	if (key < 110)
	{
		if (frame_data[key] == 0)
			frame_data[key] = 1;
		else
			frame_data[key] = 0;
	}
}

KeyCode KeyboardIllumination::decodeScancode(SDL_Scancode code)
{
	return KeyCode::A;
}