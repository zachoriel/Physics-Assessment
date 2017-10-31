#pragma once

#include "mathutils.h"
#include <cmath>

struct Collision
{
	float penetrationDepth;
	float handedness;
};

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax);