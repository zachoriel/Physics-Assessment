#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "mat3.h"
#include <cmath>

int main()
{
	sfw::initContext();

	Transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimension = vec2{ 1,1 };
	myTransform.angle = 0;

	Transform myBaby;
	myBaby.position = vec2{ 10,10 };
	myBaby.dimension = vec2{ 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTransform;

	/* Player me;
	me.pos = { 400,300 };  // old stuff
	me.speed = 10; */

	while (sfw::stepContext())
	{
		float t = sfw::getTime();

		myTransform.angle += sfw::getDeltaTime() * 180;
		myTransform.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

		DrawMatrix(myTransform.getGlobalTransform(), 40);
		DrawMatrix(myBaby.getGlobalTransform(), 30);
		
		/* me.update();
		me.draw(); */   // part of the old stuff
	}

	sfw::termContext();
}