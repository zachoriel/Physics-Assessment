#include "Laser.h"
#include "draw\draw.h"
#include "linmaths\vec2.h"

void Laser::start(const Transform &a_origin)
{
	origin.position = a_origin.getGlobalPosition();
	origin.direction = a_origin.getGlobalRight();

	m_current = origin;
	reflections[0] = origin;
	nReflections = 1;
	m_best.exit = -1;
	m_best.entry = 1000000;
	m_power = 1000; // LENGTH
}

bool Laser::step(const Transform & Bt, 
					 const Collider  & Bc)
{		
	Swept res = intersect_ray_AABB(m_current, Bc.getGlobalBox(Bt));

	if (res.entry < res.exit && res.entry > 0 && res.entry < m_best.entry)
	{
		m_best = res;
		return true;
	}
	return false;
}



float Laser::next(Rigidbody *rb)
{
	reflections[nReflections - 1].length = min(m_power,m_best.entry);
	m_power -= m_best.entry;

	if (m_power <= 0 || nReflections == 64) return -1;

	ray reflec;	
	reflec.position  = m_current.position + m_current.direction * m_best.entry;
	reflec.direction = reflect(m_current.direction, m_best.axis*m_best.handedness);
	m_current = reflections[nReflections] = reflec;
	nReflections++;

	m_best.entry = 100000;
	return m_power;
}


void Laser::draw(int color, const mat3 &cam)
{
	for (int i = 0; i < nReflections; ++i)
	{
		drawRay(reflections[i], color);
	}
}