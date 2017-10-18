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

	/* Player me;
	me.pos = { 400,300 };  // old stuff
	me.speed = 10; */

	while (sfw::stepContext())
	{
		float t = sfw::getTime();

		myTransform.angle += sfw::getTime() * 90;
		myTransform.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

		DrawMatrix(myTransform.getLocalTransform(), 40);
		
		/* me.update();
		me.draw(); */   // part of the old stuff
	}

	sfw::termContext();
}