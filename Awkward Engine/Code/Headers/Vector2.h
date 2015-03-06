#pragma once

#include "Vector3.h"

struct Vector2
{
	Vector2();
	Vector2(float _x, float _y);

	float x;
	float y;

	// Returns a normalized version of the Vector with a magnitude of 1.
	Vector2 Normalized();

	// --- Statics ---

	// Smoothly moves between start and end, depending on percent in Range[0,1].
	static Vector2 Lerp(Vector2 start, Vector2 end, float percent);

	// Smoothly lerps the Vector between start and end.
	static Vector2 Slerp(Vector2 start, Vector2 end, float percent);

	// Dot product of Vector a and Vector b
	static float Dot(Vector2 a, Vector2 b);

	// Overloaded Operands to play with.
	Vector2 &operator+=(const Vector2 &other);
	Vector2 &operator-=(const Vector2 &other);
	Vector2 &operator*=(const Vector2 &other);
	Vector2 &operator*=(const float &other);
};