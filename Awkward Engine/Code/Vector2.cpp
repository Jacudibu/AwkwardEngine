#include "Headers\Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2 Vector2::Lerp(Vector2 start, Vector2 end, float percent)
{
	return start;
}

Vector2 Vector2::Slerp(Vector2 start, Vector2 end, float percent)
{
	return start;
}

Vector2 Vector2::Dot(Vector2 a, Vector2 b)
{
	return a;
}

Vector2 Vector2::Cross(Vector2 a, Vector2 b)
{
	return a;
}







// Overloaded Operands.
Vector2 &Vector2::operator+=(const Vector2 &other)
{
	x += other.x;
	y += other.y;
	return *this;
}
Vector2 &Vector2::operator-=(const Vector2 &other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}
Vector2 &Vector2::operator*=(const Vector2 &other)
{
	x *= other.x;
	y *= other.y;
	return *this;
}

inline Vector2 operator+(Vector2 that, const Vector2 &other)
{
	that += other;
	return that;
}
inline Vector2 operator-(Vector2 that, const Vector2 &other)
{
	that -= other;
	return that;
}
inline Vector2 operator*(Vector2 that, const Vector2 &other)
{
	that *= other;
	return that;
}

inline bool operator==(const Vector2 &that, const Vector2 &other)
{
	return that.x == other.x && that.y == other.y;
}
inline bool operator!=(const Vector2 &that, const Vector2 &other)
{
	return that.x != other.x || that.y != other.y;
}