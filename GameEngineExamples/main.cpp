#include "engine.h"
#include "GameObjects.h"
#include "LaserBeam.h"
#include <cassert>
#include <iostream>

bool doCollision(Player & player, const Wall & wall)
{

	auto hit = collides(player.transform, player.collider,
		wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(player.transform.position, player.rigidbody.velocity, hit);
		return true;
	}
	return false;
}

void main()
{
	sfw::initContext();

	Player player;
	player.sprite = sfw::loadTextureMap("../resources/classic_ship.png");
	player.transform.dimension = vec2{ 64, 64 };
	player.transform.position = vec2{ 600,300 };
	player.collider.box.extents = { .5,.5 };

	Wall walls[4];
	walls[0].collider.box = AABB::fromExtents({750,1}, {799,599});
	walls[1].collider.box = AABB::fromExtents({1,1 }, { 50,599 });
	// walls[2].collider.box = AABB::fromExtents({200,100}, {400,200});

	while (sfw::stepContext())
	{	
		float dt = sfw::getDeltaTime();

		
		player.controller.poll(player.transform, player.rigidbody);

		player.rigidbody.integrate(player.transform, dt);
		
		player.sprite.draw(player.transform);

		player.beam.start(player.transform);
		
		do for (int i = 0; i < 3; ++i)
			player.beam.step(walls[i].transform, walls[i].collider);
		while (player.beam.next() > 0);

		for (int i = 0; i < 3; ++i)
		{
			auto hit = collides(player.transform, player.collider,
								walls[i].transform, walls[i].collider);
			
			if(hit.penetrationDepth > 0)
			{
			vec2 pos = player.transform.getGlobalPosition();
			
			vec2 vel = player.rigidbody.velocity;
			static_resolution(pos, vel, hit);
			player.transform.position = pos;
			player.rigidbody.velocity = vel;
			}
		}

		for (int i = 0; i < 2; ++i)
		{
			doCollision(player, walls[i]);
		}

		player.beam.draw(YELLOW);	
		player.controller.draw(player.transform);
		player.collider.debugDraw(player.transform,BLUE);

		for (int i = 0; i < 3; ++i)		
			walls[i].collider.debugDraw(walls[i].transform, GREEN);
	}

	sfw::termContext();
}