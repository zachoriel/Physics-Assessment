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
	Transform myTransform;
	myTransform.position = vec2{ 400,300 };
	myTransform.dimension = vec2{ 2,2 };
	myTransform.angle = 0;

	Transform myTransformTwo;
	myTransformTwo.position = vec2{ 400,300 };
	myTransformTwo.dimension = vec2{ 2,2 };
	myTransformTwo.angle = 180;

	Transform myTransformThree;
	myTransformThree.position = vec2{ 100,500 };
	myTransformThree.dimension = vec2{ 2,2 };
	myTransformThree.angle = 0;

	Transform myTransformFour;
	myTransformFour.position = vec2{ 100,500 };
	myTransformFour.dimension = vec2{ 2,2 };
	myTransformFour.angle = 180;

	Transform myTransformFive;
	myTransformFive.position = vec2{ 700,100 };
	myTransformFive.dimension = vec2{ 2,2 };
	myTransformFive.angle = 0;

	Transform myTransformSix;
	myTransformSix.position = vec2{ 700,100 };
	myTransformSix.dimension = vec2{ 2,2 };
	myTransformSix.angle = 180;

	Transform myTransformSeven;
	myTransformSeven.position = vec2{ 400,500 };
	myTransformSeven.dimension = vec2{ 2,2 };
	myTransformSeven.angle = 0;

	Transform myTransformEight;
	myTransformEight.position = vec2{ 400,500 };
	myTransformEight.dimension = vec2{ 2,2 };
	myTransformEight.angle = 180;

	Transform myTransformNine;
	myTransformNine.position = vec2{ 400,100 };
	myTransformNine.dimension = vec2{ 2,2 };
	myTransformNine.angle = 0;

	Transform myTransformTen;
	myTransformTen.position = vec2{ 400,100 };
	myTransformTen.dimension = vec2{ 2,2 };
	myTransformTen.angle = 180;

	Transform myTransformEleven;
	myTransformEleven.position = vec2{ 700,500 };
	myTransformEleven.dimension = vec2{ 2,2 };
	myTransformEleven.angle = 0;

	Transform myTransformTwelve;
	myTransformTwelve.position = vec2{ 700,500 };
	myTransformTwelve.dimension = vec2{ 2,2 };
	myTransformTwelve.angle = 180;

	Transform myTransformThirteen;
	myTransformThirteen.position = vec2{ 100,100 };
	myTransformThirteen.dimension = vec2{ 2,2 };
	myTransformThirteen.angle = 0;

	Transform myTransformFourteen;
	myTransformFourteen.position = vec2{ 100,100 };
	myTransformFourteen.dimension = vec2{ 2,2 };
	myTransformFourteen.angle = 180;

	Transform myTransformFifteen;
	myTransformFifteen.position = vec2{ 700,300 };
	myTransformFifteen.dimension = vec2{ 2,2 };
	myTransformFifteen.angle = 0;

	Transform myTransformSixteen;
	myTransformSixteen.position = vec2{ 700,300 };
	myTransformSixteen.dimension = vec2{ 2,2 };
	myTransformSixteen.angle = 180;

	Transform myTransformSeventeen;
	myTransformSeventeen.position = vec2{ 100,300 };
	myTransformSeventeen.dimension = vec2{ 2,2 };
	myTransformSeventeen.angle = 0;

	Transform myTransformEighteen;
	myTransformEighteen.position = vec2{ 100,300 };
	myTransformEighteen.dimension = vec2{ 2,2 };
	myTransformEighteen.angle = 180;

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
			myTransformThree.angle += sfw::getDeltaTime() * 10;
			myTransformFour.angle += sfw::getDeltaTime() * 10;
		}
		else if (me.pos.x == 120 || (me.pos.y == 500))
		{
			myTransformThree.angle += sfw::getDeltaTime() * 0;
			myTransformFour.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 420 || (me.pos.y != 500))
		{
			myTransformSeven.angle += sfw::getDeltaTime() * 20;
			myTransformEight.angle += sfw::getDeltaTime() * 20;
		}
		else if (me.pos.x == 420 || (me.pos.y == 500))
		{
			myTransformSeven.angle += sfw::getDeltaTime() * 0;
			myTransformEight.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 720 || (me.pos.y != 500))
		{
			myTransformEleven.angle += sfw::getDeltaTime() * 30;
			myTransformTwelve.angle += sfw::getDeltaTime() * 30;
		}
		else if (me.pos.x == 720 || (me.pos.y == 500))
		{
			myTransformEleven.angle += sfw::getDeltaTime() * 0;
			myTransformTwelve.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 100 || (me.pos.y != 280))
		{
			myTransformSeventeen.angle += sfw::getDeltaTime() * 40;
			myTransformEighteen.angle += sfw::getDeltaTime() * 40;
		}
		else if (me.pos.x == 100 || (me.pos.y == 280))
		{
			myTransformSeventeen.angle += sfw::getDeltaTime() * 0;
			myTransformEighteen.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 400 || (me.pos.y != 280))
		{
			myTransform.angle += sfw::getDeltaTime() * 50;
			myTransformTwo.angle += sfw::getDeltaTime() * 50;
		}
		else if (me.pos.x == 400 || (me.pos.y == 280))
		{
			myTransform.angle += sfw::getDeltaTime() * 0;
			myTransformTwo.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 700 || (me.pos.y != 280))
		{
			myTransformFifteen.angle += sfw::getDeltaTime() * 60;
			myTransformSixteen.angle += sfw::getDeltaTime() * 60;
		}
		else if (me.pos.x == 700 || (me.pos.y == 280))
		{
			myTransformFifteen.angle += sfw::getDeltaTime() * 0;
			myTransformSixteen.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 80 || (me.pos.y != 100))
		{
			myTransformThirteen.angle += sfw::getDeltaTime() * 70;
			myTransformFourteen.angle += sfw::getDeltaTime() * 70;
		}
		else if (me.pos.x == 80 || (me.pos.y == 100))
		{
			myTransformThirteen.angle += sfw::getDeltaTime() * 0;
			myTransformFourteen.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 380 || (me.pos.y != 100))
		{
			myTransformNine.angle += sfw::getDeltaTime() * 80;
			myTransformTen.angle += sfw::getDeltaTime() * 80;
		}
		else if (me.pos.x == 380 || (me.pos.y == 100))
		{
			myTransformNine.angle += sfw::getDeltaTime() * 0;
			myTransformTen.angle += sfw::getDeltaTime() * 0;
		}
		if (me.pos.x != 680 || (me.pos.y != 100))
		{
			myTransformFive.angle += sfw::getDeltaTime() * 100;
			myTransformSix.angle += sfw::getDeltaTime() * 100;
		}
		else if (me.pos.x == 680 || (me.pos.y == 100))
		{
			myTransformFive.angle += sfw::getDeltaTime() * 0;
			myTransformSix.angle += sfw::getDeltaTime() * 0;
		}
		

		// Line movement
		myTransformFive.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };
		myTransformSix.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

		// Transform size
		DrawMatrix(myTransform.getGlobalTransform(), 40);
		DrawMatrix(myTransformTwo.getGlobalTransform(), 40);
		DrawMatrix(myTransformThree.getGlobalTransform(), 40);
		DrawMatrix(myTransformFour.getGlobalTransform(), 40);
		DrawMatrix(myTransformFive.getGlobalTransform(), 40);
		DrawMatrix(myTransformSix.getGlobalTransform(), 40);
		DrawMatrix(myTransformSeven.getGlobalTransform(), 40);
		DrawMatrix(myTransformEight.getGlobalTransform(), 40);
		DrawMatrix(myTransformNine.getGlobalTransform(), 40);
		DrawMatrix(myTransformTen.getGlobalTransform(), 40);
		DrawMatrix(myTransformEleven.getGlobalTransform(), 40);
		DrawMatrix(myTransformTwelve.getGlobalTransform(), 40);
		DrawMatrix(myTransformThirteen.getGlobalTransform(), 40);
		DrawMatrix(myTransformFourteen.getGlobalTransform(), 40);
		DrawMatrix(myTransformFifteen.getGlobalTransform(), 40);
		DrawMatrix(myTransformSixteen.getGlobalTransform(), 40);
		DrawMatrix(myTransformSeventeen.getGlobalTransform(), 40);
		DrawMatrix(myTransformEighteen.getGlobalTransform(), 40);

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