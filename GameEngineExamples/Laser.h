#pragma once
#include "engine.h"

class Laser
{
public:
	ray origin, m_current;
	float m_power;
	float m_strength;
	Swept m_best;
	ray reflections[64];
	int nReflections;

	void start(const Transform &a_origin);

	bool step(const Transform &At, const Collider &Bt);

	float next(Rigidbody *rb = nullptr);

	void draw(int color = RED, const mat3 &cam = mat3::identity());
};