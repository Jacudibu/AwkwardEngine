#include "Headers\Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3 Vector3::Lerp(Vector3 start, Vector3 end, float percent)
{
	return start;
}

Vector3 Vector3::Slerp(Vector3 start, Vector3 end, float percent)
{
	return start;
}

float Vector3::Dot(Vector3 a, Vector3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Vector3 Vector3::Cross(Vector3 a, Vector3 b)
{
	return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y - b.x};
}

Vector3 Vector3::Normalized()
{
	return {x / (x + y + z), y / (x + y +z), z / (x + y + z)};
}

// Overloaded Operands.
Vector3 &Vector3::operator+=(const Vector3 &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}
Vector3 &Vector3::operator-=(const Vector3 &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}
Vector3 &Vector3::operator*=(const Vector3 &other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
	return *this;
}
Vector3 &Vector3::operator*=(const float &other)
{
	x *= other;
	y *= other;
	z *= other;
	return *this;
}

inline Vector3 operator+(Vector3 that, const Vector3 &other)
{
	that += other;
	return that;
}
inline Vector3 operator-(Vector3 that, const Vector3 &other)
{
	that -= other;
	return that;
}
inline Vector3 operator*(Vector3 that, const Vector3 &other)
{
	that *= other;
	return that;
}
inline Vector3 operator*(Vector3 that, const float &other)
{
	that *= other;
	return that;
}

inline bool operator==(const Vector3 &that, const Vector3 &other)
{
	return that.x == other.x && that.y == other.y && that.z == other.z;
}
inline bool operator!=(const Vector3 &that, const Vector3 &other)
{
	return that.x != other.x || that.y != other.y || that.z != other.z;
}