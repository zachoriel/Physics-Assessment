#include "mathutils.h"

#define _USE_MATH_DEFINES
#include <cmath>

float sqr(float v)
{
	return v * v;
}

float dbl(float v)
{
	return v * 2;
}

float cube(float v)
{
	return v * v * v;
}

float degToRad(float deg)
{
	return deg * M_PI / 180;
}

float radToDeg(float rad)
{
	return rad * 180 / M_PI;
}

float basicQuat(float x)
{
	return sqr(x) + 2 * x - 7;
}

float lerp(float start, float end, float time)
{
	return start + time * (end - start);
}

float dist(point2d a, point2d b)
{
	return sqrtf(sqr(b.x - a.x) + sqr(b.y - a.y));
}