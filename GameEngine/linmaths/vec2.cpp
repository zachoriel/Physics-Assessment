#include "vec2.h"

#include "mathutils.h"

#include <cmath>
#include <cfloat>

#define DEG2RAD 0.0174533

float &vec2::operator[](unsigned idx)
{
	return v[idx];
}
float vec2::operator[](unsigned idx) const
{
	return v[idx];
}
 
vec2 operator+(const vec2 &lhs, const vec2 &rhs)
{
	vec2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;

	return result;
}
vec2 operator-(const vec2 &lhs, const vec2 &rhs)
{
	vec2 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;

	return result;
}
vec2 operator*(const vec2 &lhs, float rhs)
{
	vec2 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;

	return result;
}
vec2 operator*(float lhs, const vec2 &rhs)
{
	return rhs * lhs;
}
vec2 operator/(const vec2 &lhs, float rhs)
{
	vec2 result;
	result.x = lhs.x / rhs;
	result.y = lhs.y / rhs;

	return result;
}
vec2 operator-(const vec2 &lhs)
{
	vec2 result;
	result.x = lhs.x * -1;
	result.y = lhs.y * -1;

	return result;
}

vec2 &operator+=(vec2 &lhs, const vec2 &rhs)
{
	lhs = lhs + rhs;

	return lhs;
}
vec2 &operator-=(vec2 &lhs, const vec2 &rhs)
{
	lhs = lhs - rhs;

	return lhs;
}
vec2 &operator*=(vec2 &lhs, float rhs)
{
	lhs = lhs * rhs;

	return lhs;
}
vec2 &operator/=(vec2 &lhs, float rhs)
{
	lhs = lhs / rhs;

	return lhs;
}

bool operator==(const vec2 &lhs, const vec2 &rhs)
{
	if (abs(lhs.x - rhs.x) <= EPSILON &&
		abs(lhs.y - rhs.y) <= EPSILON)
	{
		return true;
	}

	return false;
}
bool operator!=(const vec2 &lhs, const vec2 &rhs)
{
	return !(lhs == rhs);
}

float mag(const vec2 &v)
{
	float aSqr = v.x * v.x;
	float bSqr = v.y * v.y;

	return sqrtf(aSqr + bSqr);
}
vec2 norm(const vec2 &v)
{
	vec2 temp = v;
	float len = mag(v);

	temp /= len;

	return temp;
}
vec2 &normalize(vec2 &v)
{
	v = norm(v);

	return v;
}
float dot(const vec2 &a, const vec2 &b)
{
	float x = a.x * b.x;
	float y = a.y * b.y;
	return x + y;
}
float dist(const vec2 &a, const vec2 &b)
{
	return mag(b - a);
}
vec2 perp(const vec2 &v)
{
	return vec2{ v.y, -v.x };
}
vec2 lerp(const vec2 &s, const vec2 &e, float a)
{
	return s + a * (e - s);
}
vec2 min(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	temp.x = min(a.x, b.x);
	temp.y = min(a.y, b.y);

	return temp;
}
vec2 max(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	temp.x = max(a.x, b.x);
	temp.y = max(a.y, b.y);

	return temp;
}



vec2 project(const vec2 & v, const vec2 & axis)
{
	return dot(v, axis) * axis;
}

vec2 reflect(const vec2 & v, const vec2 & axis)
{
	return v - 2 * project(v, axis);
}

float toAngle(const vec2 &v)
{
	return 57.2958*atan2f(v.y, v.x);
}

vec2 fromAngle(float ang)
{
	return vec2{cosf(ang*DEG2RAD),sinf(ang*DEG2RAD)};
}

vec2 randRange(const vec2 & a_min, const vec2 & a_max)
{
	return vec2{  (rand() / (float)RAND_MAX) * (a_max.x - a_min.x) + a_min.x,
				  (rand() / (float)RAND_MAX) * (a_max.y - a_min.y) + a_min.y  };
}

vec2 clamp(const vec2 &a_min, const vec2 &a_val, const vec2 &a_max)
{
	return max(a_min, min(a_val, a_max));
}

vec2 snap(const vec2 &a_min, const vec2 &a_val, const vec2 &a_max)
{
	return vec2{snap(a_min.x, a_val.x, a_max.x),
				snap(a_min.y, a_val.y, a_max.y)};
}