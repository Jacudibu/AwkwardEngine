#pragma once

/*
Enum meant to provide simple access to KeyCodes.
For more information, refer to TALKFX_SDK_v2.1.1/docs/TalkFX_SDK_Documentation.pdf - page 4.
*/
enum KeyCode
{
	Size = 110, // 110 Keys total. Trust me, I'm an engineer!

	ESC = 0,
	F1 = 1,
	F2 = 2,
	F3 = 3,
	F4 = 4,
	F5 = 5,
	F6 = 6,
	F7 = 7,
	F8 = 8,
	F9 = 9,
	F10 = 10,
	F11 = 11,
	F12 = 12,

	// "special" letters
	SharpS = 28,
	UE = 50,
	AE = 72,
	OE = 71,

	// "normal" keys
	Alpha1 = 18,
	Alpha2 = 19,
	Alpha3 = 20,
	Alpha4 = 21,
	Alpha5 = 22,
	Alpha6 = 23,
	Alpha7 = 24,
	Alpha8 = 25,
	Alpha9 = 26,
	Alpha0 = 27,

	Q = 40,
	W = 41,
	E = 42,
	R = 43,
	T = 44,
	Z = 45, // German Z. On English Keyboards this would be Y.
	U = 46,
	I = 47,
	O = 48,
	P = 49,
	A = 62,
	S = 63,
	D = 64,
	F = 65,
	G = 66,
	H = 67,
	J = 68,
	K = 69,
	L = 70,
	Y = 80, // German Y. On English Keyboards this would be Z.
	X = 81,
	C = 82,
	V = 83,
	B = 84,
	N = 85,
	M = 86,

	// Other Keys
	Caret = 17,
	Plus = 51,
	Hash = 73,
	Less = 79,
	Comma = 87,
	Dot = 88,
	Minus = 89,
	Quote = 29,

	// Function Keys
	Print = 13,
	ScrollLock = 14,
	Pause = 15,

	Insert = 31,
	Pos1 = 32,
	PageUp = 33,

	Del = 53,
	End = 54,
	PageDown = 55,

	ArrowUp = 91,
	ArrowLeft = 105,
	ArrowDown = 106,
	ArrowRight = 107,

	// Bigger Keys
	Tab = 39,
	CapsLock = 61,
	LShift = 78,
	LCtrl = 97,
	Windows = 98,
	Alt = 99,
	Space = 100,
	AltGr = 101,
	FN = 102,
	Menu = 103,	// That ugly button that acts as a right click.
	RCtrl = 104,
	Enter = 52,
	Backspace = 30,
	RShift = 90,

	// Numpad
	Num_Lock = 34,
	Num_Divide = 35,
	Num_Multiply = 36,
	Num_Minus = 37,
	Num_Plus = 59,
	Num_Enter = 95,
	Num_Period = 109,
	Num_0 = 108,
	Num_1 = 92,
	Num_2 = 93,
	Num_3 = 94,
	Num_4 = 74,
	Num_5 = 75,
	Num_6 = 76,
	Num_7 = 56,
	Num_8 = 57,
	Num_9 = 58,

	// Roccat Keyboard only
	M1 = 16,
	M2 = 38,
	M3 = 60,
	M4 = 77,
	M5 = 96,
};