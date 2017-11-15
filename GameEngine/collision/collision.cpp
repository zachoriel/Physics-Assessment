#include "Collision.h"

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax)
{
	Collision ret; 

	float lPD = Bmax - Amin;
	float rPD = Amax - Bmin;
	
	ret.penetrationDepth = min(lPD, rPD);
	ret.handedness = copysign(1, rPD - lPD);

	return ret;
}



Collision intersect_circle_AABB(const circle &A, const AABB &B)
{
	vec2 cp = snap(B.min(), A.position, B.max());
	
	return intersect_circle(A, circle{ cp,0 });
}



Collision intersect_AABB(const AABB & A, const AABB & B)
{
	Collision xres = intersect_1D(A.min().x, A.max().x, B.min().x, B.max().x);
	Collision yres = intersect_1D(A.min().y, A.max().y, B.min().y, B.max().y);

	xres.axis = vec2{ 1,0 };
	yres.axis = vec2{ 0,1 };

	return xres.penetrationDepth < yres.penetrationDepth ? xres : yres;
}


Collision intersect_circle(const circle & A, const circle & B)
{
	Collision ret;
	ret.axis       = norm(B.position - A.position);
	ret.handedness = -1;

	float Ap = dot(ret.axis, A.position);
	float Bp = dot(ret.axis, B.position);

	float Amin = Ap - A.radius;
	float Amax = Ap + A.radius;

	float Bmin = Bp - B.radius;
	float Bmax = Bp + B.radius;

	ret.penetrationDepth = intersect_1D(Amin, Amax, Bmin, Bmax).penetrationDepth;

	return ret;
}




void static_resolution(vec2 & pos, vec2 & vel, const Collision & hit, float elasticity)
{
	pos += hit.axis * hit.handedness * hit.penetrationDepth;

	vel = -reflect(vel, hit.axis*hit.handedness) * elasticity;
}

void dynamic_resolution(vec2 & Apos, vec2 & Avel, float Amass, 
						vec2 & Bpos, vec2 & Bvel, float Bmass, 
						const Collision & hit, float elasticity)
{
	vec2 normal = hit.axis * hit.handedness;
	
	vec2 Rvel = Avel - Bvel;	

	float j = 
	   -(1+elasticity)*dot(Rvel, normal) / 
		dot(normal, normal*(1 / Amass + 1 / Bmass));
		

	Avel += (j / Amass) * normal;
	Bvel -= (j / Bmass) * normal;

	Apos += normal * hit.penetrationDepth * Amass/(Amass + Bmass);
	Bpos -= normal * hit.penetrationDepth * Bmass/(Amass + Bmass);
}


Swept intersect_swept_1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel)
{
	Swept res;
	float tl = (Amin - Bmax) / (Bvel - Avel); 
	float tr = (Bmin - Amax) / (Avel - Bvel); 

	res.exit = max(tl, tr);
	res.entry = min(tl, tr);

	res.handedness = copysign(1, tr-tl);

	return res;
}


Swept intersect_ray_AABB(const ray & R, const AABB & B)
{
	Swept result;

	vec2 raxis = perp(R.direction);
	float am = dot(R.position, raxis);
	float bm = B.min(raxis);
	float bx = B.max(raxis);

	Collision res = intersect_1D(am,am,bm,bx);

	if (res.penetrationDepth < 0)
	{
		result.entry = 100000;
		result.exit = -100000;
		return result;
	}


	Swept yres = intersect_swept_1D(R.position.y, R.position.y, R.direction.y, B.min().y, B.max().y, 0);
	yres.axis = { 0,1 };

	Swept xres = intersect_swept_1D(R.position.x, R.position.x, R.direction.x, B.min().x, B.max().x, 0);
	xres.axis = { 1,0 };
	
		result = xres.entry > yres.entry ? xres : yres;	
	

	return result;
}
