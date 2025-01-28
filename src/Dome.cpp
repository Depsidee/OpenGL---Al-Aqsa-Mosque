#include "Dome.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <math.h>

#include "Point.h"
#include "texture.h"
#include "Cylinder.h"
#include "Octagon.h"
#include "Octahedron.h"
#include "HalfBall.h"
#include "Cube.h"
#define M_PI_4 0.785398163397448309616


Dome::Dome()
{
}


Dome::~Dome()
{
}

void Dome::draw1(int texture, int textureCylinder, int textureHalfBall,int textureGround)
{
	float height = 1.5;
	double tallXZ1 = 2;
	double tallY1 = 1;
	double tallXZ2 = tallXZ1+0.2;
	double tallY2 = 0.1;
	double tallXZ3 = 1;
	double tallY3 = 1;
	double tallXZ4 = tallXZ3 + 0.2;
	double tallY4 = 0.1;
	double tallXZ5 = tallXZ1;
	double tallY5 = 0.2;
	float radius = 0.1;
	double a = tallXZ1 / (2 * sin(M_PI_4) + 1);

	double additional1 = 0.1;
	double additional2 = 0.05;

	Octahedron octahedron = Octahedron();
	Octagon octagon = Octagon();
	HalfBall halfBall = HalfBall();
	Cylinder cylinder = Cylinder();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, height, 0), tallXZ1, tallY1, texture);
	octagon.drawOctagon(Point(0, height + (tallY1 / 2), 0), (tallXZ1 / 2) + additional1, 'y', texture);
	octagon.drawOctagon(Point(0, height - (tallY1 / 2), 0), (tallXZ1 / 2) + additional1, 'y', texture);
	glPopMatrix();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, height+(tallY1/2), 0), tallXZ2, tallY2, texture);
	octagon.drawOctagon(Point(0, height + (tallY1 / 2) + (tallY2 / 2), 0), (tallXZ2 / 2) + additional1, 'y', texture);
	octagon.drawOctagon(Point(0, height + (tallY1 / 2) - (tallY2 / 2), 0), (tallXZ2 / 2) + additional1, 'y', texture);
	glPopMatrix();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, height + (tallY1 / 2)+(tallY2/2), 0), tallXZ3, tallY3, texture);
	octagon.drawOctagon(Point(0, height + (tallY1 / 2) + (tallY2 / 2) + (tallY3 / 2), 0), (tallXZ3 / 2) + additional2, 'y', texture);
	octagon.drawOctagon(Point(0, height + (tallY1 / 2) + (tallY2 / 2) - (tallY3 / 2), 0), (tallXZ3 / 2) + additional2, 'y', texture);
	glPopMatrix();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, height + (tallY1 / 2) + (tallY2 / 2) + (tallY3 / 2), 0), tallXZ4,tallY4, texture);
	octagon.drawOctagon(Point(0, height + (tallY1 / 2) + (tallY2 / 2) + (tallY3 / 2) + (tallY4 / 2), 0), (tallXZ4 / 2) + additional2, 'y', texture);
	octagon.drawOctagon(Point(0, height + (tallY1 / 2) + (tallY2 / 2) + (tallY3 / 2) - (tallY4 / 2), 0), (tallXZ4 / 2) + additional2, 'y', texture);
	glPopMatrix();

	glPushMatrix();
	halfBall.drawHalfBall(tallXZ3 / 2, textureHalfBall, Point(0, height + (tallY1 / 2) + (tallY2 / 2) + (tallY3 / 2) + (tallY4 / 2), 0));
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(a, 0, (a / 2)), radius, radius, height - (tallY1 / 2), textureCylinder);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((a / 2), 0, a), radius, radius, height - (tallY1 / 2), textureCylinder);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(a / 2), 0, a), radius, radius, height - (tallY1 / 2), textureCylinder);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-a, 0, (a / 2)), radius, radius, height - (tallY1 / 2), textureCylinder);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-a, 0, -(a / 2)), radius, radius, height - (tallY1 / 2), textureCylinder);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(a / 2), 0, -a), radius, radius, height - (tallY1 / 2), textureCylinder);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((a / 2), 0, -a), radius, radius, height - (tallY1 / 2), textureCylinder);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(a, 0, -(a / 2)), radius, radius, height-(tallY1/2), textureCylinder);
	glPopMatrix();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, 0, 0), tallXZ5, tallY5, textureGround);
	//octagon.drawOctagon(Point(0, 0 + (tallY5 / 2), 0), (tallXZ5 / 2) + additional1, 'y', textureGround);
	octagon.drawOctagon(Point(0, 0 - (tallY5 / 2), 0), (tallXZ5 / 2) + additional1, 'y', textureGround);
	glPopMatrix();
}

void Dome::draw2(int textureCube, int textureOctahedron, int textureHalfBall, int textureDoor,int textureGround,int textureWindow)
{
	double height = 1;
	double cubeX = 7;
	double cubeY = 0.5;
	double cubeZ = 7;
	double cubeX1 = 3;
	double cubeY1 = 3;
	double cubeZ1 = 3;
	double cubeX2 = cubeX1 + 0.2;
	double cubeY2 =  0.1;
	double cubeZ2 = cubeZ1 + 0.2;
	double tallXZ1 = cubeX1-1;
	double tallY1 = 1;
	double tallXZ2 = tallXZ1 +0.2;
	double tallY2 = 0.1;
	double doorX = 0.5;
	double doorY = 1.5;
	double doorZ = 0.0001;
	double windowX = 0.5;
	double windowY = 0.5;
	double windowZ = 0.0001;
	double heightWindow = 2;

	double additional = 0.1;

	Cube cube = Cube();
	Octahedron octahedron = Octahedron();
	Octagon octagon = Octagon();
	HalfBall halfBall = HalfBall();
	Point pDoor1 =  Point(-doorX/2, 0, (cubeZ1/2) + doorZ);
	Point pDoor2 = Point(doorX / 2, 0, (cubeZ1 / 2) + doorZ);
	Point pDoor3 = Point(doorX / 2, doorY, (cubeZ1 / 2) + doorZ);
	Point pDoor4 = Point(-doorX / 2, doorY, (cubeZ1 / 2) + doorZ);
	Point pWindow1 = Point(-windowX / 2, heightWindow, (cubeZ1 / 2) + doorZ);
	Point pWindow2 = Point(windowX / 2, heightWindow, (cubeZ1 / 2) + doorZ);
	Point pWindow3 = Point(windowX / 2, heightWindow+windowY, (cubeZ1 / 2) + doorZ);
	Point pWindow4 = Point(-windowX / 2, heightWindow+windowY, (cubeZ1 / 2) + doorZ);

	glPushMatrix();
	glTranslated(-cubeX / 2, 0, cubeZ / 2);
	cube.drawCube(cubeX, cubeY, cubeZ, textureCube, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX1/2, cubeY, cubeZ1/2);
	cube.drawCube(cubeX1,cubeY1,cubeZ1,textureCube,1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-cubeX2/2, cubeY+cubeY1, cubeZ2/2);
	cube.drawCube(cubeX2, cubeY2, cubeZ2, textureCube, 1);
	glPopMatrix();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, cubeY+cubeY1+cubeY2, 0), tallXZ1, tallY1, textureOctahedron);
	octagon.drawOctagon(Point(0, cubeY + cubeY1 + cubeY2 + (tallY1 / 2), 0), (tallXZ1 / 2) + additional, 'y', textureOctahedron);
	octagon.drawOctagon(Point(0, cubeY + cubeY1 + cubeY2 - (tallY1 / 2), 0), (tallXZ1 / 2) + additional, 'y', textureOctahedron);
	glPopMatrix();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, cubeY + cubeY1 + cubeY2 + (tallY1 / 2), 0), tallXZ2, tallY2, textureOctahedron);
	octagon.drawOctagon(Point(0, cubeY + cubeY1 + cubeY2 + (tallY1 / 2) + (tallY2 / 2), 0), (tallXZ2 / 2) + additional , 'y', textureOctahedron);
	octagon.drawOctagon(Point(0, cubeY + cubeY1 + cubeY2 + (tallY1 / 2) - (tallY2 / 2), 0), (tallXZ2 / 2) + additional, 'y', textureOctahedron);
	glPopMatrix();

	glPushMatrix();
	halfBall.drawHalfBall(tallXZ1 / 2, textureHalfBall, Point(0, cubeY + cubeY1 + cubeY2 + (tallY1 / 2) + (tallY2 / 2), 0));
	glPopMatrix();

	//Left Door
	glPushMatrix();
	glTranslated(-0.7, cubeY + 0.2, 0);
	glBindTexture(GL_TEXTURE_2D, textureDoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(pDoor1.x, pDoor1.y, pDoor1.z);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(pDoor2.x, pDoor2.y, pDoor2.z);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(pDoor3.x, pDoor3.y, pDoor3.z);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(pDoor4.x, pDoor4.y, pDoor4.z);
	glEnd();
	glPopMatrix();

	//Right Door
	glPushMatrix();
	glTranslated(0.7, cubeY+0.2, 0);
	glBindTexture(GL_TEXTURE_2D, textureDoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(pDoor1.x, pDoor1.y, pDoor1.z);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(pDoor2.x, pDoor2.y, pDoor2.z);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(pDoor3.x, pDoor3.y, pDoor3.z);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(pDoor4.x, pDoor4.y, pDoor4.z);
	glEnd();
	glPopMatrix();

	//Right Window
	glPushMatrix();
	glRotated(90,0,1,0);
	glBindTexture(GL_TEXTURE_2D, textureDoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(pWindow1.x, pWindow1.y, pWindow1.z);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(pWindow2.x, pWindow2.y, pWindow2.z);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(pWindow3.x, pWindow3.y, pWindow3.z);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(pWindow4.x, pWindow4.y, pWindow4.z);
	glEnd();
	glPopMatrix();

	//Back Window
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, textureDoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(pWindow1.x, pWindow1.y, pWindow1.z);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(pWindow2.x, pWindow2.y, pWindow2.z);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(pWindow3.x, pWindow3.y, pWindow3.z);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(pWindow4.x, pWindow4.y, pWindow4.z);
	glEnd();
	glPopMatrix();

	//Left Window
	glPushMatrix();
	glRotated(270, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, textureDoor);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(pWindow1.x, pWindow1.y, pWindow1.z);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(pWindow2.x, pWindow2.y, pWindow2.z);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(pWindow3.x, pWindow3.y, pWindow3.z);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(pWindow4.x, pWindow4.y, pWindow4.z);
	glEnd();
	glPopMatrix();
}

void Dome::draw3(int texture1, int texture2)
{
	float height = 2;
	double tallXZ = 4;
	double tallY = 0.3;
	float radius = 0.15;
	double a = tallXZ / (2 * sin(M_PI_4) + 1);

	double additional = 0.15;

	Octahedron octahedron = Octahedron();
	Octagon octagon = Octagon();
	HalfBall halfBall = HalfBall();
	Cylinder cylinder = Cylinder();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, height, 0), tallXZ, tallY, texture1);
	//octagon.drawOctagon(Point(0, height + (tallY / 2), 0), (tallXZ / 2) + additional, 'y', texture1);
	octagon.drawOctagon(Point(0, height - (tallY / 2), 0), (tallXZ / 2) + additional, 'y', texture1);
	glPopMatrix();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, height + (tallY / 2), 0), tallXZ, tallY, texture2);
	octagon.drawOctagon(Point(0, height + (tallY / 2) + (tallY / 2), 0), (tallXZ / 2) + additional, 'y', texture2);
	//octagon.drawOctagon(Point(0, height + (tallY / 2) - (tallY / 2), 0), (tallXZ / 2) + additional, 'y', texture2);
	glPopMatrix();

	glPushMatrix();
	halfBall.drawHalfBall(tallXZ / 2, texture2, Point(0, height + (tallY / 2) + (tallY / 2), 0));
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(a, 0, (a / 2)), radius, radius, height, texture1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((a / 2), 0, a), radius, radius, height, texture1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(a / 2), 0, a), radius, radius, height, texture1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-a, 0, (a / 2)), radius, radius, height, texture1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-a, 0, -(a / 2)), radius, radius, height, texture1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(-(a / 2), 0, -a), radius, radius, height, texture1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point((a / 2), 0, -a), radius, radius, height, texture1);
	glPopMatrix();

	glPushMatrix();
	cylinder.DrawCylinderBody(Point(a, 0, -(a / 2)), radius, radius, height, texture1);
	glPopMatrix();

	glPushMatrix();
	octahedron.drawRegularOctahedron(Point(0, 0, 0), tallXZ, tallY, texture1);
	//octagon.drawOctagon(Point(0, height + (tallY / 2), 0), (tallXZ / 2) + additional, 'y', texture1);
	octagon.drawOctagon(Point(0, 0, 0), (tallXZ / 2) + additional, 'y', texture1);
	glPopMatrix();


	
}
