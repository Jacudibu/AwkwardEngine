#include "KeyDictionary.h"

KeyDictionary::KeyDictionary()
{
	// First Keyboard Row
	keys[0] = { KeyCode::ESC, SDL_SCANCODE_ESCAPE, "UNDEFINED" };
	keys[1] = { KeyCode::F1, SDL_SCANCODE_F1, "UNDEFINED" };
	keys[2] = { KeyCode::F2, SDL_SCANCODE_F2, "UNDEFINED" };
	keys[3] = { KeyCode::F3, SDL_SCANCODE_F3, "UNDEFINED" };
	keys[4] = { KeyCode::F4, SDL_SCANCODE_F4, "UNDEFINED" };
	keys[5] = { KeyCode::F5, SDL_SCANCODE_F5, "UNDEFINED" };
	keys[6] = { KeyCode::F6, SDL_SCANCODE_F6, "UNDEFINED" };
	keys[7] = { KeyCode::F7, SDL_SCANCODE_F7, "UNDEFINED" };
	keys[8] = { KeyCode::F8, SDL_SCANCODE_F8, "UNDEFINED" };
	keys[9] = { KeyCode::F9, SDL_SCANCODE_F9, "UNDEFINED" };
	keys[10] = { KeyCode::F10, SDL_SCANCODE_F10, "UNDEFINED" };
	keys[11] = { KeyCode::F11, SDL_SCANCODE_F11, "UNDEFINED" };
	keys[12] = { KeyCode::F12, SDL_SCANCODE_F12, "UNDEFINED" };
	keys[13] = { KeyCode::Print, SDL_SCANCODE_PRINTSCREEN, "UNDEFINED" };
	keys[14] = { KeyCode::ScrollLock, SDL_SCANCODE_SCROLLLOCK, "UNDEFINED" };
	keys[15] = { KeyCode::Pause, SDL_SCANCODE_PAUSE, "UNDEFINED" };

	//Second Keyboard Row
	keys[16] = { KeyCode::M1, SDL_SCANCODE_F24, "UNDEFINED" };
	keys[17] = { KeyCode::Caret, SDL_SCANCODE_GRAVE, "^" };
	keys[18] = { KeyCode::Alpha1, SDL_SCANCODE_1, "1" };
	keys[19] = { KeyCode::Alpha2, SDL_SCANCODE_2, "2" };
	keys[20] = { KeyCode::Alpha3, SDL_SCANCODE_3, "3" };
	keys[21] = { KeyCode::Alpha4, SDL_SCANCODE_4, "4" };
	keys[22] = { KeyCode::Alpha5, SDL_SCANCODE_5, "5" };
	keys[23] = { KeyCode::Alpha6, SDL_SCANCODE_6, "6" };
	keys[24] = { KeyCode::Alpha7, SDL_SCANCODE_7, "7" };
	keys[25] = { KeyCode::Alpha8, SDL_SCANCODE_8, "8" };
	keys[26] = { KeyCode::Alpha9, SDL_SCANCODE_9, "9" };
	keys[27] = { KeyCode::Alpha0, SDL_SCANCODE_0, "0" };
	keys[28] = { KeyCode::SharpS, SDL_SCANCODE_MINUS, "ß" };
	keys[29] = { KeyCode::Quote, SDL_SCANCODE_EQUALS, "´" };
	keys[30] = { KeyCode::Backspace, SDL_SCANCODE_BACKSPACE, "UNDEFINED" };
	keys[31] = { KeyCode::Insert, SDL_SCANCODE_INSERT, "UNDEFINED" };
	keys[32] = { KeyCode::Pos1, SDL_SCANCODE_HOME, "UNDEFINED" };
	keys[33] = { KeyCode::PageUp, SDL_SCANCODE_PAGEUP, "UNEDEFINED" };
	keys[34] = { KeyCode::Num_Lock, SDL_SCANCODE_NUMLOCKCLEAR, "UNDEFINED" };
	keys[35] = { KeyCode::Num_Divide, SDL_SCANCODE_KP_DIVIDE, "/" };
	keys[36] = { KeyCode::Num_Multiply, SDL_SCANCODE_KP_MULTIPLY, "*" };
	keys[37] = { KeyCode::Num_Minus, SDL_SCANCODE_KP_MINUS, "-" };

	// Third Keyboard Row
	keys[38] = { KeyCode::M2, SDL_SCANCODE_F24, "UNDEFINED" };
	keys[39] = { KeyCode::Tab, SDL_SCANCODE_TAB, "UNDEFINED" };
	keys[40] = { KeyCode::Q, SDL_SCANCODE_Q, "q" };
	keys[41] = { KeyCode::W, SDL_SCANCODE_W, "w" };
	keys[42] = { KeyCode::E, SDL_SCANCODE_E, "e" };
	keys[43] = { KeyCode::R, SDL_SCANCODE_R, "r" };
	keys[44] = { KeyCode::T, SDL_SCANCODE_T, "t" };
	keys[45] = { KeyCode::Z, SDL_SCANCODE_Z, "z" };
	keys[46] = { KeyCode::U, SDL_SCANCODE_U, "u" };
	keys[47] = { KeyCode::I, SDL_SCANCODE_I, "i" };
	keys[48] = { KeyCode::O, SDL_SCANCODE_O, "o" };
	keys[49] = { KeyCode::P, SDL_SCANCODE_P, "p" };
	keys[50] = { KeyCode::UE, SDL_SCANCODE_LEFTBRACKET, "ü" };
	keys[51] = { KeyCode::Plus, SDL_SCANCODE_RIGHTBRACKET, "+" };
	keys[52] = { KeyCode::Enter, SDL_SCANCODE_RETURN, "UNDEFINED" };
	keys[53] = { KeyCode::Del, SDL_SCANCODE_DELETE, "UNDEFINED" };
	keys[54] = { KeyCode::End, SDL_SCANCODE_END, "UNDEFINED" };
	keys[55] = { KeyCode::PageDown, SDL_SCANCODE_PAGEDOWN, "UNDEFINED" };
	keys[56] = { KeyCode::Num_7, SDL_SCANCODE_KP_7, "UNDEFINED" };
	keys[57] = { KeyCode::Num_8, SDL_SCANCODE_KP_8, "UNDEFINED" };
	keys[58] = { KeyCode::Num_9, SDL_SCANCODE_KP_9, "UNDEFINED" };
	keys[59] = { KeyCode::Num_Plus, SDL_SCANCODE_KP_PLUS, "UNDEFINED" };

	// Fourth Keyboard Row
	keys[60] = { KeyCode::M3, SDL_SCANCODE_F24, "UNDEFINED" };
	keys[61] = { KeyCode::CapsLock, SDL_SCANCODE_CAPSLOCK, "UNDEFINED" };
	keys[62] = { KeyCode::A, SDL_SCANCODE_A, "a" };
	keys[63] = { KeyCode::S, SDL_SCANCODE_S, "s" };
	keys[64] = { KeyCode::D, SDL_SCANCODE_D, "d" };
	keys[65] = { KeyCode::F, SDL_SCANCODE_F, "f" };
	keys[66] = { KeyCode::G, SDL_SCANCODE_G, "g" };
	keys[67] = { KeyCode::H, SDL_SCANCODE_H, "h" };
	keys[68] = { KeyCode::J, SDL_SCANCODE_J, "j" };
	keys[69] = { KeyCode::K, SDL_SCANCODE_K, "k" };
	keys[70] = { KeyCode::L, SDL_SCANCODE_L, "l" };
	keys[71] = { KeyCode::OE, SDL_SCANCODE_SEMICOLON, "ö" };
	keys[72] = { KeyCode::AE, SDL_SCANCODE_APOSTROPHE, "ä" };
	keys[73] = { KeyCode::Hash, SDL_SCANCODE_BACKSLASH, "#" };
	keys[74] = { KeyCode::Num_4, SDL_SCANCODE_KP_4, "UNDEFINED" };
	keys[75] = { KeyCode::Num_5, SDL_SCANCODE_KP_5, "UNDEFINED" };
	keys[76] = { KeyCode::Num_6, SDL_SCANCODE_KP_6, "UNDEFINED" };

	// Fifth Keyboard Row
	keys[77] = { KeyCode::M4, SDL_SCANCODE_F24, "UNDEFINED" };
	keys[78] = { KeyCode::LShift, SDL_SCANCODE_LSHIFT, "UNDEFINED" };
	keys[79] = { KeyCode::Less, SDL_SCANCODE_NONUSBACKSLASH, "<" };
	keys[80] = { KeyCode::Y, SDL_SCANCODE_Y, "y" };
	keys[81] = { KeyCode::X, SDL_SCANCODE_X, "x" };
	keys[82] = { KeyCode::C, SDL_SCANCODE_C, "c" };
	keys[83] = { KeyCode::V, SDL_SCANCODE_V, "v" };
	keys[84] = { KeyCode::B, SDL_SCANCODE_B, "b" };
	keys[85] = { KeyCode::N, SDL_SCANCODE_N, "n" };
	keys[86] = { KeyCode::M, SDL_SCANCODE_M, "m" };
	keys[87] = { KeyCode::Comma , SDL_SCANCODE_COMMA, "," };
	keys[88] = { KeyCode::Dot, SDL_SCANCODE_PERIOD, "." };
	keys[89] = { KeyCode::Minus, SDL_SCANCODE_SLASH, "-" };
	keys[90] = { KeyCode::RShift, SDL_SCANCODE_RSHIFT, "UNDEFINED" };
	keys[91] = { KeyCode::ArrowUp, SDL_SCANCODE_UP, "UNDEFINED" };
	keys[92] = { KeyCode::Num_1, SDL_SCANCODE_KP_1, "UNDEFINED" };
	keys[93] = { KeyCode::Num_2, SDL_SCANCODE_KP_2, "UNDEFINED" };
	keys[94] = { KeyCode::Num_3, SDL_SCANCODE_KP_3, "UNDEFINED" };
	keys[95] = { KeyCode::Num_Enter, SDL_SCANCODE_KP_ENTER, "UNDEFINED" };

	// Sixth Keyboard Row
	keys[96] = { KeyCode::M5, SDL_SCANCODE_F24, "UNDEFINED" };
	keys[97] = { KeyCode::LCtrl, SDL_SCANCODE_LCTRL, "UNDEFINED" };
	keys[98] = { KeyCode::Windows, SDL_SCANCODE_LGUI, "UNDEFINED" };
	keys[99] = { KeyCode::Alt, SDL_SCANCODE_LALT, "UNDEFINED" };
	keys[100] = { KeyCode::Space, SDL_SCANCODE_SPACE, " " };
	keys[101] = { KeyCode::AltGr, SDL_SCANCODE_RALT, "UNDEFINED" };
	keys[102] = { KeyCode::FN, SDL_SCANCODE_RGUI, "UNDEFINED" };
	keys[103] = { KeyCode::Menu, SDL_SCANCODE_APPLICATION, "UNDEFINED" };
	keys[104] = { KeyCode::RCtrl, SDL_SCANCODE_RCTRL, "UNDEFINED" };
	keys[105] = { KeyCode::ArrowLeft, SDL_SCANCODE_LEFT, "UNDEFINED" };
	keys[106] = { KeyCode::ArrowDown, SDL_SCANCODE_DOWN, "UNDEFINED" };
	keys[107] = { KeyCode::ArrowRight, SDL_SCANCODE_RIGHT, "UNDEFINED" };
	keys[108] = { KeyCode::Num_0, SDL_SCANCODE_KP_0, "UNDEFINED" };
	keys[109] = { KeyCode::Num_Period, SDL_SCANCODE_KP_PERIOD, "UNDEFINED" };
}

KeyDictionary::~KeyDictionary()
{

}

std::string KeyDictionary::toString(KeyCode code)
{
	if (code < 110)
		return keys[code].letter;

	printf("Warning: Keycode > 109: %i\n", code);
	return "a";
}

std::string KeyDictionary::toString(SDL_Scancode scan)
{
	for (Key key : keys)
	{
		if (key.scan == scan)
			return key.letter;
	}

	printf("Warning: Scancode %i not found in KeyDictionary!\n", scan);
	return "a";
}

KeyCode KeyDictionary::toKeyCode(std::string text)
{
	for (Key key : keys)
	{
		if (key.letter == text)
			return key.key;
	}

	printf("Warning: text %s not found in KeyDictionary!\n", text.c_str());
	return KeyCode::A;
}

KeyCode KeyDictionary::toKeyCode(SDL_Scancode scan)
{
	for (Key key : keys)
	{
		if (key.scan == scan)
			return key.key;
	}

	printf("Warning: Scancode %i not found in KeyDictionary!\n", scan);
	return KeyCode::A;
}

SDL_Scancode KeyDictionary::toScanCode(std::string text)
{
	for (Key key : keys)
	{
		if (key.letter == text)
			return key.scan;
	}

	printf("Warning: text %s not found in KeyDictionary!\n", text.c_str());
	return SDL_SCANCODE_A;
}

SDL_Scancode KeyDictionary::toScanCode(KeyCode code)
{
	if (code < 110)
		return keys[code].scan;

	printf("Warning: Keycode > 109: %i\n", code);
	return SDL_SCANCODE_A;
}