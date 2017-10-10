#pragma once

struct point2d
{
	float x;
	float y;
};

// Accepts a value and returns the square of the value
float sqr(float v);

// Accepts a value and returns the double of the value.
float dbl(float v);

// Accepts a value and returns the cube of the value.
float cube(float v);

// Accepts a measure of rotation expressed in degrees and returns it in radians.
float degToRad(float deg);

// Accepts a measure of rotation expressed in degrees and returns it in radians.
float radToDeg(float rad);

// Returns the y value for the given x value in the represented quadratic.
float basicQuat(float x);

// LERP
float lerp(float start, float end, float time);

float dist(point2d a, point2d b);