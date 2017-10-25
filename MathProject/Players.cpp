#include "Players.h"
#include "Transforms.h"
#include "sfwdraw.h"

void Player::update()
{
	vec2 movement = { 0,0 };

	if (sfw::getKey('W'))
	{
		movement.y += 1;
	}
	if (sfw::getKey('S'))
	{
		movement.y -= 1;
	}
	if (sfw::getKey('A'))
	{
		movement.x -= 1;
	}
	if (sfw::getKey('D'))
	{
		movement.x += 1;
	}
	if (sfw::getKey('R'))
	{
		pos.x = 400;
		pos.y = 200;
	}

	// CHEATS 
	if (sfw::getKey('1'))
	{
		pos.x = 120;
		pos.y = 500;
	}
	if (sfw::getKey('2'))
	{
		pos.x = 420;
		pos.y = 500;
	}
	if (sfw::getKey('3'))
	{
		pos.x = 720;
		pos.y = 500;
	}
	if (sfw::getKey('4'))
	{
		pos.x = 100;
		pos.y = 280;
	}
	if (sfw::getKey('5'))
	{
		pos.x = 400;
		pos.y = 280;
	}
	if (sfw::getKey('6'))
	{
		pos.x = 700;
		pos.y = 280;
	}
	if (sfw::getKey('7'))
	{
		pos.x = 80;
		pos.y = 100;
	}
	if (sfw::getKey('8'))
	{
		pos.x = 380;
		pos.y = 100;
	}
	if (sfw::getKey('9'))
	{
		pos.x = 680;
		pos.y = 100;
	}

	movement *= speed;

	// Screen edges
	if (pos.x > 800)
	{
		pos.x = 0;
		pos.y = 300;
	}
	if (pos.x < 0)
	{
		pos.x = 800;
		pos.y = 300;
	}
	if (pos.y > 600)
	{
		pos.x = 400;
		pos.y = 0;
	}
	if (pos.y < 0)
	{
		pos.x = 400;
		pos.y = 600;
	}

	pos += movement;
}

void Player::draw()
{
	sfw::drawCircle(pos.x, pos.y, 5.f);
}

void Circles::draw()
{
	sfw::drawCircle(pos.x, pos.y, 2.f);
}