#pragma once

struct Vector3
{
	Vector3();
	Vector3(float _x, float _y, float _z);

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	// Returns a normalized version of the Vector with a magnitude of 1.
	Vector3 Vector3::Normalized();

	// --- Statics ---

	// Smoothly moves Vector between start and end, depending on percent in Range[0,1].
	static Vector3 Lerp(Vector3 start, Vector3 end, float percent);

	// Smoothly lerps the Vector between start and end.
	static Vector3 Slerp(Vector3 start, Vector3 end, float percent);

	// Dot product of Vector a and Vector b
	static float Dot(Vector3 a, Vector3 b);

	// Cross product of Vector a and Vector b
	static Vector3 Cross(Vector3 a, Vector3 b);

	// Returns the Angle of the two Vectors in 2D Space in Degrees.
	static float Angle2D(Vector3 a, Vector3 b);

	// Overloaded Operands to play with.
	Vector3 &operator+=(const Vector3 &other);
	Vector3 &operator-=(const Vector3 &other);
	Vector3 &operator*=(const Vector3 &other);
	Vector3 &operator*=(const float &other);
};