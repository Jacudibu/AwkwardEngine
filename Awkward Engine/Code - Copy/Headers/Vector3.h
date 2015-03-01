#pragma once

struct Vector3
{
	Vector3();
	Vector3(float _x, float _y, float _z);

	float x;
	float y;
	float z;

	// Smoothly moves Vector at its current position between start and end, depending on percent in Range[0,1].
	static Vector3 Lerp(Vector3 start, Vector3 end, float percent);

	// Yet unimplemented.
	// Lerps the Vector in a curvy form.
	static Vector3 Slerp(Vector3 start, Vector3 end, float percent);

	// Yet unimplemented.
	// Dot product of Vector1 and Vector3
	static Vector3 Dot(Vector3 a, Vector3 b);

	// Yet unimplemented.
	// Cross product of Vector1 and Vector3
	static Vector3 Cross(Vector3 a, Vector3 b);



	// Overloaded Operands.
	Vector3 &operator+=(const Vector3 &other);
	Vector3 &operator-=(const Vector3 &other);
	Vector3 &operator*=(const Vector3 &other);
};