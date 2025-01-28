#include "Minaret.h"

#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <math.h>

#include "Cube.h"
#include "Point.h"
#include "Cylinder.h"
#include "HalfBall.h"
#include "texture.h"


Minaret::Minaret()
{
	
}


Minaret::~Minaret()
{
}

void Minaret::draw1(int texture,int textureCube, int textureHalfBall)
{
	Point base1=Point(0,0,0);
	float radius1 = 1;
	float radius2 = 0.85;
	float radius3=0.1;
	float cubeX=3;
	float cubeY=0.1;
	float cubeZ=3;
	float dist = 1;
	float height1 = 4;
	float height2 = 2;
	float height3 = 0.4;
	float width = 0.1;
	float padding = 0.3;

	Cylinder cylinder = Cylinder();
	Cube cube = Cube();
	HalfBall halfBall = HalfBall();

	glPushMatrix();
	cylinder.DrawCylinderBody(base1, radius1, radius1, height1, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(0, height1, 0), radius2, radius2, height2, texture);
	glPopMatrix();

	glPushMatrix();
	halfBall.drawHalfBall(radius2, textureHalfBall, Point(0, height1+height2, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX/2, height1+dist, cubeZ/2);
	cube.drawCube(cubeX, cubeY, cubeZ, textureCube, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX/2, height1, cubeZ/2);
	cube.drawCube(cubeX, cubeY, cubeZ,texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX/2, height1, cubeZ/2);
	cube.drawCube(cubeX, height3, width, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX/2, height1, cubeZ/2);
	cube.drawCube(width, height3, cubeZ, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX/2, height1, -cubeZ/2);
	cube.drawCube(cubeX, height3, width, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(cubeX/2, height1, cubeZ/2);
	cube.drawCube(width, height3, cubeZ, texture, 1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((cubeX/2)-padding, height1, (cubeZ/2)-padding), radius3, radius3, dist, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(cubeX/2)+padding, height1, (cubeZ/2)-padding), radius3, radius3, dist, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((cubeX / 2) - padding, height1, -(cubeZ/2)+padding), radius3, radius3, dist, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(cubeX / 2) + padding, height1, -(cubeZ / 2) + padding), radius3, radius3, dist, texture);
	glPopMatrix();
}

void Minaret::draw2(int texture,int textureCube, int textureHalfBall)
{
	float radius1 = 0.85;
	float radius2 = 0.1;
	float cubeX1 = 2;
	float cubeY1 = 4;
	float cubeZ1 = 2;
	float cubeX2 = 3;
	float cubeY2 = 0.1;
	float cubeZ2 = 3;
	float height1 = 2;
	float height2 = 0.4;
	float dist = 1;
	float padding = 0.3;
	float width = 0.1;

	Cylinder cylinder = Cylinder();
	Cube cube = Cube();
	HalfBall halfBall = HalfBall();

	glPushMatrix();
	glTranslated(-cubeX1/2, 0, 0);
	cube.drawCube(cubeX1, cubeY1, cubeZ1, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -cubeX1/2);
	cylinder.DrawCylinderBody(Point(0, cubeY1, 0), radius1, radius1, height1, texture);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -cubeX1 / 2);
	halfBall.drawHalfBall(radius1, textureHalfBall, Point(0, cubeY1+height1, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX2/2, cubeY1+dist, cubeZ2/2);
	cube.drawCube(cubeX2, cubeY2, cubeZ2, textureCube, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX2/2, cubeY1, cubeZ2/2);
	cube.drawCube(cubeX2, cubeY2, cubeZ2, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX2/2, cubeY1, cubeZ2/2);
	cube.drawCube(cubeX2, height2, width, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX2/2, cubeY1, cubeZ2/2);
	cube.drawCube(width, height2, cubeZ2, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX2/2, cubeY1, -cubeZ2/2);
	cube.drawCube(cubeX2, height2, width, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(cubeX2/2, cubeY1, cubeZ2/2);
	cube.drawCube(width, height2, cubeZ2, texture, 1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((cubeX2/2)-padding, cubeY1, (cubeZ2/2)-padding), radius2, radius2, dist, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(cubeX2 / 2) + padding, cubeY1, (cubeZ2 / 2) - padding), radius2, radius2, dist, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((cubeX2 / 2) - padding, cubeY1, -(cubeZ2 / 2) + padding), radius2, radius2, dist, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(cubeX2 / 2) + padding, cubeY1, -(cubeZ2 / 2) + padding), radius2, radius2, dist, texture);
	glPopMatrix();
}

void Minaret::draw3(int texture, int textureCube, int textureHalfBall)
{
	float radius1 = 0.5;
	float radius2 = 0.35;
	float radius3 = 0.1;
	float cubeX1 = 2;
	float cubeY1 = 4;
	float cubeZ1 = 2;
	float cubeX2 = 1.5;
	float cubeY2 = 1;
	float cubeZ2 = 1.5;
	float cubeX3 = 3;
	float cubeY3 = 0.1;
	float cubeZ3 = 3;
	float height1 = 1;
	float height2 = 0.5;
	float height3 = 0.4;
	float width = 0.1;
	float padding = 0.3;

	Cylinder cylinder = Cylinder();
	Cube cube = Cube();
	HalfBall halfBall = HalfBall();

	glPushMatrix();
	glTranslated(-cubeX1 / 2, 0, 0);
	cube.drawCube(cubeX1, cubeY1, cubeZ1, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX2/2,cubeY1, 0);
	cube.drawCube(cubeX2, cubeY2, cubeZ2, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -cubeZ2 / 2);
	cylinder.DrawCylinderBody(Point(0,cubeY1+cubeY2,0), radius1, radius1, height1, texture);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -cubeZ2/2);
	cylinder.DrawCylinderBody(Point(0, cubeY1 + cubeY2+height1, 0), radius2, radius2, height2, texture);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -cubeZ2 / 2);
	halfBall.drawHalfBall(radius2, textureHalfBall, Point(0, cubeY1+cubeY2+height1 + height2, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX3 / 2, cubeY1+cubeY2, cubeZ3 / 2);
	cube.drawCube(cubeX3, cubeY3, cubeZ3, textureCube, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX3 / 2, cubeY1, cubeZ3 / 2);
	cube.drawCube(cubeX3, cubeY3, cubeZ3, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX3 / 2, cubeY1, cubeZ3 / 2);
	cube.drawCube(cubeX3, height3, width, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX3 / 2, cubeY1, cubeZ3 / 2);
	cube.drawCube(width, height3, cubeZ3, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX3 / 2, cubeY1, -cubeZ3 / 2);
	cube.drawCube(cubeX3, height3, width, texture, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(cubeX3 / 2, cubeY1, cubeZ3 / 2);
	cube.drawCube(width, height3, cubeZ3, texture, 1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((cubeX3 / 2) - padding, cubeY1, (cubeZ3 / 2) - padding), radius3, radius3, cubeY2, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(cubeX3 / 2) + padding, cubeY1, (cubeZ3 / 2) - padding), radius3, radius3, cubeY2, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((cubeX3 / 2) - padding, cubeY1, -(cubeZ3 / 2) + padding), radius3, radius3, cubeY2, texture);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(cubeX3 / 2) + padding, cubeY1, -(cubeZ3 / 2) + padding), radius3, radius3, cubeY2, texture);
	glPopMatrix();


}
