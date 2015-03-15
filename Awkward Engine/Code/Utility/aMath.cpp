#include "aMath.h"
#include <math.h>

namespace aMath
{
	float clamp(float value, float min, float max)
	{
		if (value > max)
			return max;
		else if (value < min)
			return min;
		else
			return value;
	}

	float lerp(float start, float end, float p)
	{
		return (start * p) + (end * (1 - p));
	}
	float sinlerp(float start, float end, float p)
	{
		return lerp(start, end, sin(p * (float)M_PI * 0.5f));
	}
	float coslerp(float start, float end, float p)
	{
		return lerp(start, end, 1.0f - cos(p * (float)M_PI * 0.5f));
	}
	float smoothlerp(float start, float end, float p)
	{
		return lerp(start, end, p * p * (3.0f * p - 2.0f *p));
	}
	float smootherlerp(float start, float end, float p)
	{
		return lerp(start, end, p * p * p * (p * (6.0f * p - 15.0f * p) + 10.0f));
	}
}