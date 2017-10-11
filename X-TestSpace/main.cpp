#include "mathutils.h"

#include "vec2.h"

#include <cassert>

int main()
{
	int val = min(1, 3);

	vec2 test;
	test.x = 5;
	test.y = 20;

	vec2 testB;
	testB.x = 13;
	testB.y = 4;

	vec2 result = test + testB;

	vec2 num;
	num.x = 0;
	num.y = 0;

	num += test;

	bool eq = num == test;
	bool ieq = num == testB;
	
	// equality and inequality
	{
		vec2 a = { 0,0 };
		vec2 b = { 0,0 };
		vec2 c = { 0,1 };

		assert(a == b);
		//assert(a != c);
	}

	{
		vec2 a = { 5,3 };
		vec2 b = { 4,2 };
		
		assert((a + b) == (vec2{9, 5}));

		
	}



	while (true) {}
}