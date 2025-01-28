#pragma once
#include "Point.h"
class Octagon
{
public:
	Octagon();
	~Octagon();
	static void drawOctagon(Point center, double radious, char ignoredDimension, int tex);
};

