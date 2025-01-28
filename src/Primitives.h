#pragma once
#include "Point.h"
class Primitives
{
public:
	Primitives();
	~Primitives();
	static void drawCube(float sX, float sY, float sZ, int texture, float num);
	static void drawCubeWithSpecificTexture(float sX, float sY, float sZ, int front, int back, int left, int right, int top, int bottom);
	static void drawMinusCube(Point point, double tallX, double tallY, double tallZ, int tex1, int tex2);
	static void drawSphere(Point center, double r, int lats, int longs);
	static void drawHalfSphere(Point center, double r, int lats, int longs);
	static void drawRegularOctahedron(Point center, double tallXZ, double tallY, int tex);
	static void drawMinusRegularOctahedronDoor(Point center, double tallXZ, double tallY, int tex, int texDoor, int rep1, int rep2);
	static void drawMinusRegularOctahedronWindow(Point center, double tallXZ, double tallY, int tex, int rep1, int rep2, int windowUp, int windowDown);
	static void drawOctagon(Point center, double radious, char ignoredDimension, int tex);
	static void drawMinusOctagon(Point center, double radious1, double radious2, int tex = -1);
	static void drawRectangle(Point center, double side1, double side2, char ignoredDimension, int tex, int repeet);
	static void drawHalfBall(float rad, int texture = -1, Point center = Point(0, 0, 0));
	static void drawBall(float rad, int texture = -1, Point center = Point(0, 0, 0));
	static double drawArch(Point center, double radious1, double radious2, int tex);
	static void DrawHalfCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture);
	static void DrawCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture);
};

