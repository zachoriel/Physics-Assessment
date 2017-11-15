#pragma once

#include "engine.h"
#include "MouseAim.h"
#include "Laser.h"

class Player
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	MouseAim controller;
	Laser beam;
	Sprite sprite;
};


class Wall
{
public:
	Transform transform;
	Collider collider;
};