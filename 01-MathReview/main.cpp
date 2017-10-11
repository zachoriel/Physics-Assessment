#include <iostream>
#include <cassert>

#include "mathutils.h"

int main()
{
	float val = 0;
	val = sqr(4);
	val = dbl(2);
	val = cube(3);
	val = degToRad(180);
	val = radToDeg(3.14159);
	val = basicQuat(0);
	val = lerp(0, 10, 0.5);
	val = dist({ 0,0 }, { 0,2 });

	while (true) {}
} 