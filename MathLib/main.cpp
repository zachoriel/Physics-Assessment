#include "mat3.h"
#include "mathutils.h"
#include "vec2.h"
#include "Vec3.h"
#include <cmath>
#include <cfloat>
#include <iostream>
#include <assert.h>

int main()
{

	mat3 I = mat3::identity();
	mat3 Z = mat3::zero();
	mat3 A = { 1,2,3,4,5,6,7,8,9 };
	vec3 v = { 1,2,3 };

	assert(I + Z == I);
	assert(Z + I == I);
	assert(I - Z == I);
	assert(!(Z - I == I));
	assert(transpose(I) == I);
	assert(A*I == A);
	assert(I*A == A);

	assert(I*v == v);

	assert(inverse(I) == I);

	// -6.39757843e-07 == the equivalent of 0.
	// -0.0000006 : close to zero!

	mat3 T = scale(vec2{ 1, 2 }) *
			 rotate(90) *
			 translate(vec2{ 3, 0 });

	assert((T[2].xy == vec2{ 0,6 }));

	while (true) {}

}