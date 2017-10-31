#include "DrawShape.h"
#include "sfwdraw.h"

void drawCircle(const circle &C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}


void DrawVecLine(const vec2 &a, const vec2 &b)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, MAGENTA);
}

void drawAABB(const AABB & box)
{
	vec2 TR = box.position + box.extents;
	vec2 BL = box.position - box.extents;
	vec2 TL = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 BR = { TR.x, BL.y };

	DrawVecLine(TR, TL);
	DrawVecLine(TL, BL);
	DrawVecLine(BL, BR);
	DrawVecLine(BR, TR);


}
