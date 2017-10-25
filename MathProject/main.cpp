#include "sfwdraw.h"
#include "Transforms.h"
#include "Players.h"
#include "MathUtilities.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"
#include <cmath>
#include <cfloat>
#include <cassert>
#include <iostream>
using namespace std;

int main()
{
	sfw::initContext();

	// Obstacles
	Transform wheel;
	wheel.position = vec2{ 400,300 };
	wheel.dimension = vec2{ 2,2 };
	wheel.angle = 0;

	Transform wheelTwo;
	wheelTwo.position = vec2{ 400,300 };
	wheelTwo.dimension = vec2{ 2,2 };
	wheelTwo.angle = 180;

	Transform wheelThree;
	wheelThree.position = vec2{ 100,500 };
	wheelThree.dimension = vec2{ 2,2 };
	wheelThree.angle = 0;

	Transform wheelFour;
	wheelFour.position = vec2{ 100,500 };
	wheelFour.dimension = vec2{ 2,2 };
	wheelFour.angle = 180;

	Transform wheelFive;
	wheelFive.position = vec2{ 700,100 };
	wheelFive.dimension = vec2{ 2,2 };
	wheelFive.angle = 0;

	Transform wheelSix;
	wheelSix.position = vec2{ 700,100 };
	wheelSix.dimension = vec2{ 2,2 };
	wheelSix.angle = 180;

	Transform wheelSeven;
	wheelSeven.position = vec2{ 400,500 };
	wheelSeven.dimension = vec2{ 2,2 };
	wheelSeven.angle = 0;

	Transform wheelEight;
	wheelEight.position = vec2{ 400,500 };
	wheelEight.dimension = vec2{ 2,2 };
	wheelEight.angle = 180;

	Transform wheelNine;
	wheelNine.position = vec2{ 400,100 };
	wheelNine.dimension = vec2{ 2,2 };
	wheelNine.angle = 0;

	Transform wheelTen;
	wheelTen.position = vec2{ 400,100 };
	wheelTen.dimension = vec2{ 2,2 };
	wheelTen.angle = 180;

	Transform wheelEleven;
	wheelEleven.position = vec2{ 700,500 };
	wheelEleven.dimension = vec2{ 2,2 };
	wheelEleven.angle = 0;

	Transform wheelTwelve;
	wheelTwelve.position = vec2{ 700,500 };
	wheelTwelve.dimension = vec2{ 2,2 };
	wheelTwelve.angle = 180;

	Transform wheelThirteen;
	wheelThirteen.position = vec2{ 100,100 };
	wheelThirteen.dimension = vec2{ 2,2 };
	wheelThirteen.angle = 0;

	Transform wheelFourteen;
	wheelFourteen.position = vec2{ 100,100 };
	wheelFourteen.dimension = vec2{ 2,2 };
	wheelFourteen.angle = 180;

	Transform wheelFifteen;
	wheelFifteen.position = vec2{ 700,300 };
	wheelFifteen.dimension = vec2{ 2,2 };
	wheelFifteen.angle = 0;

	Transform wheelSixteen;
	wheelSixteen.position = vec2{ 700,300 };
	wheelSixteen.dimension = vec2{ 2,2 };
	wheelSixteen.angle = 180;

	Transform wheelSeventeen;
	wheelSeventeen.position = vec2{ 100,300 };
	wheelSeventeen.dimension = vec2{ 2,2 };
	wheelSeventeen.angle = 0;

	Transform wheelEighteen;
	wheelEighteen.position = vec2{ 100,300 };
	wheelEighteen.dimension = vec2{ 2,2 };
	wheelEighteen.angle = 180;

	// Player
	Player me;
	me.pos = { 400,200 }; 
	me.speed = 2; 

	// Objective objects
	Circles CircleOne;
	CircleOne.pos = { 120,500 };
	Circles CircleTwo;
	CircleTwo.pos = { 420,500 };
	Circles CircleThree;
	CircleThree.pos = { 720,500 };
	Circles CircleFour;
	CircleFour.pos = { 100,280 };
	Circles CircleFive;
	CircleFive.pos = { 400,280 };
	Circles CircleSix;
	CircleSix.pos = { 700,280 };
	Circles CircleSeven;
	CircleSeven.pos = { 80,100 };
	Circles CircleEight;
	CircleEight.pos = { 380,100 };
	Circles CircleNine;
	CircleNine.pos = { 680,100 };

	while (sfw::stepContext())
	{
		float t = sfw::getTime();

		// Rotation speed
		if (me.pos.x != 120 || (me.pos.y != 500))
		{
			wheelThree.angle += sfw::getDeltaTime() * 10;
			wheelFour.angle += sfw::getDeltaTime() * 10;
		}
		else if (me.pos.x == 120 || (me.pos.y == 500))
		{
			wheelThree.angle += sfw::getDeltaTime() * 0;
			wheelFour.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 420 || (me.pos.y != 500))
		{
			wheelSeven.angle += sfw::getDeltaTime() * 20;
			wheelEight.angle += sfw::getDeltaTime() * 20;
		}
		else if (me.pos.x == 420 || (me.pos.y == 500))
		{
			wheelSeven.angle += sfw::getDeltaTime() * 0;
			wheelEight.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 720 || (me.pos.y != 500))
		{
			wheelEleven.angle += sfw::getDeltaTime() * 30;
			wheelTwelve.angle += sfw::getDeltaTime() * 30;
		}
		else if (me.pos.x == 720 || (me.pos.y == 500))
		{
			wheelEleven.angle += sfw::getDeltaTime() * 0;
			wheelTwelve.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 100 || (me.pos.y != 280))
		{
			wheelSeventeen.angle += sfw::getDeltaTime() * 40;
			wheelEighteen.angle += sfw::getDeltaTime() * 40;
		}
		else if (me.pos.x == 100 || (me.pos.y == 280))
		{
			wheelSeventeen.angle += sfw::getDeltaTime() * 0;
			wheelEighteen.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 400 || (me.pos.y != 280))
		{
			wheel.angle += sfw::getDeltaTime() * 50;
			wheelTwo.angle += sfw::getDeltaTime() * 50;
		}
		else if (me.pos.x == 400 || (me.pos.y == 280))
		{
			wheel.angle += sfw::getDeltaTime() * 0;
			wheelTwo.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 700 || (me.pos.y != 280))
		{
			wheelFifteen.angle += sfw::getDeltaTime() * 60;
			wheelSixteen.angle += sfw::getDeltaTime() * 60;
		}
		else if (me.pos.x == 700 || (me.pos.y == 280))
		{
			wheelFifteen.angle += sfw::getDeltaTime() * 0;
			wheelSixteen.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 80 || (me.pos.y != 100))
		{
			wheelThirteen.angle += sfw::getDeltaTime() * 70;
			wheelFourteen.angle += sfw::getDeltaTime() * 70;
		}
		else if (me.pos.x == 80 || (me.pos.y == 100))
		{
			wheelThirteen.angle += sfw::getDeltaTime() * 0;
			wheelFourteen.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 380 || (me.pos.y != 100))
		{
			wheelNine.angle += sfw::getDeltaTime() * 80;
			wheelTen.angle += sfw::getDeltaTime() * 80;
		}
		else if (me.pos.x == 380 || (me.pos.y == 100))
		{
			wheelNine.angle += sfw::getDeltaTime() * 0;
			wheelTen.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 680 || (me.pos.y != 100))
		{
			wheelFive.angle += sfw::getDeltaTime() * 100;
			wheelSix.angle += sfw::getDeltaTime() * 100;
		}
		else if (me.pos.x == 680 || (me.pos.y == 100))
		{
			wheelFive.angle += sfw::getDeltaTime() * 0;
			wheelSix.angle += sfw::getDeltaTime() * 0;
		}
		

		// Line movement
		wheelFive.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };
		wheelSix.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

		// Transform size
		DrawMatrix(wheel.getGlobalTransform(), 40);
		DrawMatrix(wheelTwo.getGlobalTransform(), 40);
		DrawMatrix(wheelThree.getGlobalTransform(), 40);
		DrawMatrix(wheelFour.getGlobalTransform(), 40);
		DrawMatrix(wheelFive.getGlobalTransform(), 40);
		DrawMatrix(wheelSix.getGlobalTransform(), 40);
		DrawMatrix(wheelSeven.getGlobalTransform(), 40);
		DrawMatrix(wheelEight.getGlobalTransform(), 40);
		DrawMatrix(wheelNine.getGlobalTransform(), 40);
		DrawMatrix(wheelTen.getGlobalTransform(), 40);
		DrawMatrix(wheelEleven.getGlobalTransform(), 40);
		DrawMatrix(wheelTwelve.getGlobalTransform(), 40);
		DrawMatrix(wheelThirteen.getGlobalTransform(), 40);
		DrawMatrix(wheelFourteen.getGlobalTransform(), 40);
		DrawMatrix(wheelFifteen.getGlobalTransform(), 40);
		DrawMatrix(wheelSixteen.getGlobalTransform(), 40);
		DrawMatrix(wheelSeventeen.getGlobalTransform(), 40);
		DrawMatrix(wheelEighteen.getGlobalTransform(), 40);

		// Player functions
		me.update();
		me.draw();

		// Object functions
		CircleOne.draw();
		CircleTwo.draw();
		CircleThree.draw();
		CircleFour.draw();
		CircleFive.draw();
		CircleSix.draw();
		CircleSeven.draw();
		CircleEight.draw();
		CircleNine.draw();
	}

	sfw::termContext();
}