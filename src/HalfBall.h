#pragma once
#include "Point.h"
class HalfBall
{
public:
	HalfBall();
	~HalfBall();
	static void drawHalfBall(float rad, int texture = -1, Point center = Point(0, 0, 0));
};

