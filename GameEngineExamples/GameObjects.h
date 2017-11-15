#pragma once

#include "engine.h"
#include "MouseLookController.h"
#include "LaserBeam.h"

class Player
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	MouseLookController controller;
	LaserBeam beam;
	Sprite sprite;
};


class Wall
{
public:
	Transform transform;
	Collider collider;
};

class Balls 
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	vec2 pos;

	void draw();
};