#include "Player.h"

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
		pos.y = 300;
	}

	movement *= speed;

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
	sfw::drawCircle(pos.x, pos.y, 30.f);
}