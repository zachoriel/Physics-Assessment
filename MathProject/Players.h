#pragma once

#include "vector2.h"

class Player
{
public:
	vec2 pos;

	float speed;

	void update();
	void draw();
};

class Circles
{
public:
	vec2 pos;

	void draw();
};
