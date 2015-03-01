#pragma once

struct Vector2
{
	Vector2();
	Vector2(float _x, float _y);

	float x;
	float y;

	// Smoothly moves Vector at its current position between start and end, depending on percent in Range[0,1].
	static Vector2 Lerp(Vector2 start, Vector2 end, float percent);

	// Yet unimplemented.
	// Lerps the Vector in a curvy form.
	static Vector2 Slerp(Vector2 start, Vector2 end, float percent);

	// Yet unimplemented.
	// Dot product of Vector1 and Vector2
	static Vector2 Dot(Vector2 a, Vector2 b);

	// Yet unimplemented.
	// Cross product of Vector1 and Vector2
	static Vector2 Cross(Vector2 a, Vector2 b);



	// Overloaded Operands.
	Vector2 &operator+=(const Vector2 &other);
	Vector2 &operator-=(const Vector2 &other);
	Vector2 &operator*=(const Vector2 &other);
};