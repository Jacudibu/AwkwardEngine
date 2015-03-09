#include "Vector2.h"
#include "aMath.h"

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

Vector2 Vector2::Normalized()
{
	return {x / (x + y), y / (x + y)};
}

Vector2 Vector2::Lerp(Vector2 start, Vector2 end, float percent)
{
	return{ aMath::lerp(start.x, end.x, percent),
			aMath::lerp(start.y, end.y, percent) };
}

Vector2 Vector2::Slerp(Vector2 start, Vector2 end, float percent)
{
	return{ aMath::smoothlerp(start.x, end.x, percent),
			aMath::smoothlerp(start.y, end.y, percent) };
}

float Vector2::Dot(Vector2 a, Vector2 b)
{
	return (a.x * b.x + a.y * b.y);
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
Vector2 &Vector2::operator*=(const float &other)
{
	x *= other;
	y *= other;
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
inline Vector2 operator*(Vector2 that, const float &other)
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