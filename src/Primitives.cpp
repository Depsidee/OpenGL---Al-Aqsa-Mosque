#define _USE_MATH_DEFINES
#include "Primitives.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <math.h>
#include "texture.h"

Primitives::Primitives()
{
}


Primitives::~Primitives()
{
}

//---------------------------cube---------------------------
void Primitives::drawCube(float sX, float sY, float sZ, int texture, float num){


	float tX = sX*num;
	float tZ = sZ*num;
	float tY = sY*num;

	glPushMatrix();
	//back
	glBindTexture(GL_TEXTURE_2D, texture);
	//glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex3f(0, 0, 0);
	glTexCoord2f(tX, 0);	glVertex3f(sX, 0, 0);
	glTexCoord2f(tX, tY);	glVertex3f(sX, sY, 0);
	glTexCoord2f(0, tY);	glVertex3f(0, sY, 0);
	glEnd();


	//right
	//glColor3f(0, 1, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture);
	glTranslated(sX, 0, 0);
	glRotated(90, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex3f(0, 0, 0);
	glTexCoord2f(tZ, 0);	glVertex3f(sZ, 0, 0);
	glTexCoord2f(tZ, tY);	glVertex3f(sZ, sY, 0);
	glTexCoord2f(0, tY);	glVertex3f(0, sY, 0);
	glEnd();

	//front
	//glColor3f(1, 0, 1);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTranslated(sZ, 0, 0);
	glRotated(90, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex3f(0, 0, 0);
	glTexCoord2f(tX, 0);	glVertex3f(sX, 0, 0);
	glTexCoord2f(tX, tY);	glVertex3f(sX, sY, 0);
	glTexCoord2f(0, tY);	glVertex3f(0, sY, 0);
	glEnd();

	//left
	//glColor3f(1, 0, 0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTranslated(sX, 0, 0);
	glRotated(90, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex3f(0, 0, 0);
	glTexCoord2f(tZ, 0);	glVertex3f(sZ, 0, 0);
	glTexCoord2f(tZ, tY);	glVertex3f(sZ, sY, 0);
	glTexCoord2f(0, tY);	glVertex3f(0, sY, 0);
	glEnd();
	glPopMatrix(); //reset the origin

	//top
	//glColor3f(0, 0, 1);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture);
	glTranslated(0, sY, 0);
	glRotated(-90, 1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex3f(0, 0, 0);
	glTexCoord2f(tX, 0);	glVertex3f(sX, 0, 0);
	glTexCoord2f(tX, tZ);	glVertex3f(sX, sZ, 0);
	glTexCoord2f(0, tZ);	glVertex3f(0, sZ, 0);
	glEnd();
	glPopMatrix(); //reset the origin

	//bottom
	//glColor3f(1, 1, 1);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture);
	glRotated(-90, 1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex3f(0, 0, 0);
	glTexCoord2f(tX, 0);	glVertex3f(sX, 0, 0);
	glTexCoord2f(tX, tZ);	glVertex3f(sX, sZ, 0);
	glTexCoord2f(0, tZ);	glVertex3f(0, sZ, 0);
	glEnd();

	glPopMatrix(); //reset the origin after drawing
	glPopMatrix(); //reset the origin after drawing




}
//---------------------------cube with specific texture---------------------------
void Primitives::drawCubeWithSpecificTexture(float sX, float sY, float sZ, int front, int back, int left, int right, int top, int bottom){



	glPushMatrix();
	//back
	glBindTexture(GL_TEXTURE_2D, back);
	//glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(sX, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(sX, sY, 0);
	glTexCoord2f(1, 0); glVertex3f(0, sY, 0);
	glEnd();


	//right
	//glColor3f(0, 1, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, right);
	glTranslated(sX, 0, 0);
	glRotated(90, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(sZ, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(sZ, sY, 0);
	glTexCoord2f(1, 0); glVertex3f(0, sY, 0);
	glEnd();

	//front
	//glColor3f(1, 0, 1);
	glBindTexture(GL_TEXTURE_2D, front);
	glTranslated(sZ, 0, 0);
	glRotated(90, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(sX, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(sX, sY, 0);
	glTexCoord2f(1, 0); glVertex3f(0, sY, 0);
	glEnd();

	//left
	//glColor3f(1, 0, 0);
	glBindTexture(GL_TEXTURE_2D, left);
	glTranslated(sX, 0, 0);
	glRotated(90, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(sZ, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(sZ, sY, 0);
	glTexCoord2f(1, 0); glVertex3f(0, sY, 0);
	glEnd();
	glPopMatrix(); //reset the origin

	//top
	//glColor3f(0, 0, 1);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, top);
	glTranslated(0, sY, 0);
	glRotated(-90, 1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(sX, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(sX, sZ, 0);
	glTexCoord2f(1, 0); glVertex3f(0, sZ, 0);
	glEnd();
	glPopMatrix(); //reset the origin

	//bottom
	//glColor3f(1, 1, 1);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, bottom);
	glRotated(-90, 1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(sX, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(sX, sZ, 0);
	glTexCoord2f(1, 0); glVertex3f(0, sZ, 0);
	glEnd();

	glPopMatrix(); //reset the origin after drawing
	glPopMatrix(); //reset the origin after drawing




}

//---------------------------open box---------------------------
void Primitives::drawMinusCube(Point point, double tallX, double tallY, double tallZ, int tex1, int tex2) {
	//DRAWING THE LEFT FACE
	glBindTexture(GL_TEXTURE_2D, tex2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(point.x - (tallX / 2), point.y - (tallY / 2), point.z + (tallZ / 2));
	glTexCoord2d(0, 1);
	glVertex3d(point.x - (tallX / 2), point.y + (tallY / 2), point.z + (tallZ / 2));
	glTexCoord2d(1, 1);
	glVertex3d(point.x - (tallX / 2), point.y + (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(1, 0);
	glVertex3d(point.x - (tallX / 2), point.y - (tallY / 2), point.z - (tallZ / 2));
	glEnd();
	//DRWAING THE BACK FACE
	glBindTexture(GL_TEXTURE_2D, tex1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(point.x - (tallX / 2), point.y - (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(0, 1);
	glVertex3d(point.x - (tallX / 2), point.y + (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(1, 1);
	glVertex3d(point.x + (tallX / 2), point.y + (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(1, 0);
	glVertex3d(point.x + (tallX / 2), point.y - (tallY / 2), point.z - (tallZ / 2));
	glEnd();
	//DRAWING THE RIGHT FACE
	glBindTexture(GL_TEXTURE_2D, tex2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(point.x + (tallX / 2), point.y - (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(0, 1);
	glVertex3d(point.x + (tallX / 2), point.y + (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(1, 1);
	glVertex3d(point.x + (tallX / 2), point.y + (tallY / 2), point.z + (tallZ / 2));
	glTexCoord2d(1, 0);
	glVertex3d(point.x + (tallX / 2), point.y - (tallY / 2), point.z + (tallZ / 2));
	glEnd();
	//DRAWING THE TOP FACE
	glBindTexture(GL_TEXTURE_2D, tex2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(point.x - (tallX / 2), point.y + (tallY / 2), point.z + (tallZ / 2));
	glTexCoord2d(0, 1);
	glVertex3d(point.x - (tallX / 2), point.y + (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(1, 1);
	glVertex3d(point.x + (tallX / 2), point.y + (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(1, 0);
	glVertex3d(point.x + (tallX / 2), point.y + (tallY / 2), point.z + (tallZ / 2));
	glEnd();
	//DRAWING THE BOTTOM FACE
	glBindTexture(GL_TEXTURE_2D, tex2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(point.x - (tallX / 2), point.y - (tallY / 2), point.z + (tallZ / 2));
	glTexCoord2d(0, 1);
	glVertex3d(point.x - (tallX / 2), point.y - (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(1, 1);
	glVertex3d(point.x + (tallX / 2), point.y - (tallY / 2), point.z - (tallZ / 2));
	glTexCoord2d(1, 0);
	glVertex3d(point.x + (tallX / 2), point.y - (tallY / 2), point.z + (tallZ / 2));
	glEnd();
}
//---------------------------sphere---------------------------
void Primitives::drawSphere(Point center, double r, int lats, int longs) {
	int i, j;
	for (i = 0; i <= lats; i++) {
		double lat0 = 3.14 * (-0.5 + (double)(i - 1) / lats);
		double z0 = r*sin(lat0);
		double zr0 = r*cos(lat0);

		double lat1 = 3.14 * (-0.5 + (double)i / lats);
		double z1 = r*sin(lat1);
		double zr1 = r*cos(lat1);

		glPushMatrix();
		glTranslated(center.x, center.y, center.z);
		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= longs; j++) {
			double lng = 2 * 3.14 * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(x * zr0, y * zr0, z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(x * zr1, y * zr1, z1);
		}
		glEnd();
		glPopMatrix();
	}
}
//---------------------------half sphere---------------------------
void Primitives::drawHalfSphere(Point center, double r, int lats, int longs) {
	int i, j;
	for (i = 0; i <= lats; i++) {
		double lat0 = 3.14 * (-0.5 + (double)(i - 1) / lats);
		double z0 = r*sin(lat0);
		double zr0 = r*cos(lat0);

		double lat1 = 3.14 * (-0.5 + (double)i / lats);
		double z1 = r*sin(lat1);
		double zr1 = r*cos(lat1);

		glPushMatrix();
		glTranslated(center.x, center.y, center.z);
		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= longs; j++) {
			double lng = 3.14 * (double)(j) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(x * zr0, y * zr0, z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(x * zr1, y * zr1, z1);
		}
		glEnd();
		glPopMatrix();
	}
}
//---------------------------Octahedron---------------------------
void Primitives::drawRegularOctahedron(Point center, double tallXZ, double tallY, int tex) {
	//DEFINING A PARAMETER FOR CALCULATING THE TALL OF THE SIDE
	double tall = tallXZ / (2 * sin(M_PI_4) + 1);
	glBindTexture(GL_TEXTURE_2D, tex);
	//DRAWING THE FRONT FACE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x - tall / 2, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, 1);
	glVertex3d(center.x - tall / 2, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 1);
	glVertex3d(center.x + tall / 2, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 0);
	glVertex3d(center.x + tall / 2, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();
	//DRAWING THE FRONT-RIGHT FACE
	glPushMatrix();
	glTranslated(center.x + tall / 2, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glRotated(45, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(1, 1);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();
	//DRAWING THE RIGHT FACE

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - tall / 2);
	glTexCoord2d(0, 1);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - tall / 2);
	glTexCoord2d(1, 1);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + tall / 2);
	glTexCoord2d(1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + tall / 2);
	glEnd();

	//DRAWING THE BACK-RIGHT FACE
	glPushMatrix();
	glTranslated((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - tall / 2);
	glRotated(135, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(1, 1);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();
	//DRAWING THE BACK FACE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x - tall / 2, center.y - tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glTexCoord2d(0, 1);
	glVertex3d(center.x - tall / 2, center.y + tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glTexCoord2d(1, 1);
	glVertex3d(center.x + tall / 2, center.y + tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glTexCoord2d(1, 0);
	glVertex3d(center.x + tall / 2, center.y - tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glEnd();
	//DRAWING THE BACK-LEFT FACE
	glPushMatrix();
	glTranslated(center.x - tall / 2, center.y - tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glRotated(-135, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(1, 1);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();
	//DRAWING THE LEFT FACE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - tall / 2);
	glTexCoord2d(0, 1);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - tall / 2);
	glTexCoord2d(1, 1);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + tall / 2);
	glTexCoord2d(1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + tall / 2);
	glEnd();
	//DRAWING THE FRONT-LEFT FACE
	glPushMatrix();
	glTranslated((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + tall / 2);
	glRotated(-45, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(1, 1);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();


}

//---------------------------Octahedron with door---------------------------
void Primitives::drawMinusRegularOctahedronDoor(Point center, double tallXZ, double tallY, int tex, int texDoor, int rep1, int rep2) {
	//DEFINING A PARAMETER FOR CALCULATING THE TALL OF THE SIDE
	double tall = tallXZ / (2 * sin(M_PI_4) + 1);
	glBindTexture(GL_TEXTURE_2D, tex);
	//DRAWING THE FRONT FACE

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x - tall / 2, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, rep2);
	glVertex3d(center.x - tall / 2, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(rep1, rep2);
	glVertex3d(center.x - 0.5, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(rep1, 0);
	glVertex3d(center.x - 0.5, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x + tall / 2, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, rep2);
	glVertex3d(center.x + tall / 2, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(rep1, rep2);
	glVertex3d(center.x + 0.5, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(rep1, 0);
	glVertex3d(center.x + 0.5, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texDoor);






	glBindTexture(GL_TEXTURE_2D, tex);
	//DRAWING THE FRONT-RIGHT FACE
	glPushMatrix();
	glTranslated(center.x + tall / 2, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glRotated(45, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, rep2);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(rep1, rep2);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(rep1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();
	//DRAWING THE RIGHT FACE


	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - tall / 2);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - tall / 2);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 0.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 0.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + tall / 2);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + tall / 2);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 0.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 0.5);
	glEnd();

	//DRAWING THE BACK-RIGHT FACE
	glPushMatrix();
	glTranslated((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - tall / 2);
	glRotated(135, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, rep2);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(rep1, rep2);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(rep1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();
	//DRAWING THE BACK FACE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x - tall / 2, center.y - tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glTexCoord2d(0, rep2);
	glVertex3d(center.x - tall / 2, center.y + tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glTexCoord2d(rep1, rep2);
	glVertex3d(center.x + tall / 2, center.y + tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glTexCoord2d(rep1, 0);
	glVertex3d(center.x + tall / 2, center.y - tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glEnd();


	//DRAWING THE BACK-LEFT FACE
	glPushMatrix();
	glTranslated(center.x - tall / 2, center.y - tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glRotated(-135, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, rep2);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(rep1, rep2);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(rep1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();
	//DRAWING THE LEFT FACE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - tall / 2);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - tall / 2);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 0.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 0.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + tall / 2);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + tall / 2);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 0.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 0.5);
	glEnd();
	//DRAWING THE FRONT-LEFT FACE
	glPushMatrix();
	glTranslated((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + tall / 2);
	glRotated(-45, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, rep2);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(rep1, rep2);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(rep1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();


}

//---------------------------Octahedron with window---------------------------
void Primitives::drawMinusRegularOctahedronWindow(Point center, double tallXZ, double tallY, int tex, int rep1, int rep2, int windowUp, int windowDown) {
	//DEFINING A PARAMETER FOR CALCULATING THE TALL OF THE SIDE
	double tall = tallXZ / (2 * sin(M_PI_4) + 1);
	glBindTexture(GL_TEXTURE_2D, tex);
	//DRAWING THE FRONT FACE

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x - tall / 2, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, rep2);
	glVertex3d(center.x - tall / 2, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, rep2);
	glVertex3d(center.x - 1.5, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 0);
	glVertex3d(center.x - 1.5, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x + tall / 2, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, rep2);
	glVertex3d(center.x + tall / 2, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, rep2);
	glVertex3d(center.x + 1.5, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 0);
	glVertex3d(center.x + 1.5, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();




	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x - 1, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, rep2);
	glVertex3d(center.x - 1, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(rep1 / 2, rep2);
	glVertex3d(center.x + 1, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(rep1 / 2, 0);
	glVertex3d(center.x + 1, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();

	glBindTexture(GL_TEXTURE_2D, windowUp);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x - 1, center.y + 0.2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, 1);
	glVertex3d(center.x - 1, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 1);
	glVertex3d(center.x - 1.5, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 0);
	glVertex3d(center.x - 1.5, center.y + 0.2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();


	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x + 1, center.y + 0.2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, 1);
	glVertex3d(center.x + 1, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 1);
	glVertex3d(center.x + 1.5, center.y + tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 0);
	glVertex3d(center.x + 1.5, center.y + 0.2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();

	glBindTexture(GL_TEXTURE_2D, windowDown);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3d(center.x - 1, center.y - 0.2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, 0);
	glVertex3d(center.x - 1, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 0);
	glVertex3d(center.x - 1.5, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 1);
	glVertex3d(center.x - 1.5, center.y - 0.2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();


	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3d(center.x + 1, center.y - 0.2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(0, 0);
	glVertex3d(center.x + 1, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 0);
	glVertex3d(center.x + 1.5, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glTexCoord2d(1, 1);
	glVertex3d(center.x + 1.5, center.y - 0.2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glEnd();



	//DRAWING THE FRONT-RIGHT FACE
	glBindTexture(GL_TEXTURE_2D, tex);
	glPushMatrix();
	glTranslated(center.x + tall / 2, center.y - tallY / 2, (center.z + tall / 2) + (tall * sin(M_PI_4)));
	glRotated(45, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, rep2);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(rep1, rep2);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(rep1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();
	//DRAWING THE RIGHT FACE

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - tall / 2);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - tall / 2);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + 0.2, center.z - 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + 0.2, center.z - 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - 0.2, center.z - 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - 0.2, center.z - 1.5);
	glEnd();


	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + tall / 2);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + tall / 2);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + 0.2, center.z + 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + 0.2, center.z + 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - 0.2, center.z + 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - 0.2, center.z + 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 1);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 1);
	glEnd();

	//DRAWING THE BACK-RIGHT FACE
	glPushMatrix();
	glTranslated((center.x + tall / 2) + (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - tall / 2);
	glRotated(135, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, rep2);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(rep1, rep2);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(rep1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();
	//DRAWING THE BACK FACE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(center.x - tall / 2, center.y - tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glTexCoord2d(0, rep2);
	glVertex3d(center.x - tall / 2, center.y + tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glTexCoord2d(rep1, rep2);
	glVertex3d(center.x + tall / 2, center.y + tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glTexCoord2d(rep1, 0);
	glVertex3d(center.x + tall / 2, center.y - tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glEnd();
	//DRAWING THE BACK-LEFT FACE
	glPushMatrix();
	glTranslated(center.x - tall / 2, center.y - tallY / 2, (center.z - tall / 2) - (tall * sin(M_PI_4)));
	glRotated(-135, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, rep2);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(rep1, rep2);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(rep1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();
	//DRAWING THE LEFT FACE

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - tall / 2);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - tall / 2);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + 0.2, center.z - 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + 0.2, center.z - 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - 0.2, center.z - 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - 0.2, center.z - 1.5);
	glEnd();


	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + tall / 2);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + tall / 2);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + 0.2, center.z + 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + 0.2, center.z + 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - 0.2, center.z + 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 1.5);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - 0.2, center.z + 1.5);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z - 1);
	glTexCoord2d(0, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z - 1);
	glTexCoord2d(rep1, rep2);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y + tallY / 2, center.z + 1);
	glTexCoord2d(rep1, 0);
	glVertex3d((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + 1);
	glEnd();
	//DRAWING THE FRONT-LEFT FACE
	glPushMatrix();
	glTranslated((center.x - tall / 2) - (tall * sin(M_PI_4)), center.y - tallY / 2, center.z + tall / 2);
	glRotated(-45, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, rep2);
	glVertex3d(0, tallY, 0);
	glTexCoord2d(rep1, rep2);
	glVertex3d(tall, tallY, 0);
	glTexCoord2d(rep1, 0);
	glVertex3d(tall, 0, 0);
	glEnd();
	glPopMatrix();


}

//---------------------------Octagon---------------------------
void Primitives::drawOctagon(Point center, double radious, char ignoredDimension, int tex) {
	double angleIncrement = M_PI / 4;
	switch (ignoredDimension)
	{
	case 'x':
		glBindTexture(GL_TEXTURE_2D, tex);
		glBegin(GL_POLYGON);
		for (double angle = 0.0; angle < 2.0 * M_PI; angle += angleIncrement) {
			glTexCoord2d(cos(angle + (M_PI / 8)), sin(angle + (M_PI / 8)));
			double z = center.z + radious * cos(angle + (M_PI / 8));
			double y = center.y + radious * sin(angle + (M_PI / 8));
			glVertex3d(center.x, y, z);
		}
		glEnd();
		break;
	case 'y':
		glBindTexture(GL_TEXTURE_2D, tex);
		glBegin(GL_POLYGON);
		for (double angle = 0.0; angle < 2.0 * M_PI; angle += angleIncrement) {
			glTexCoord2d(cos(angle + (M_PI / 8)), sin(angle + (M_PI / 8)));
			double x = center.x + radious * cos(angle + (M_PI / 8));
			double z = center.z + radious * sin(angle + (M_PI / 8));
			glVertex3d(x, center.y, z);
		}
		glEnd();
		break;
	case 'z':
		glBindTexture(GL_TEXTURE_2D, tex);
		glBegin(GL_POLYGON);
		for (double angle = 0.0; angle < 2.0 * M_PI; angle += angleIncrement) {
			glTexCoord2d(cos(angle + (M_PI / 8)), sin(angle + (M_PI / 8)));
			double x = center.x + radious * cos(angle + (M_PI / 8));
			double y = center.y + radious * sin(angle + (M_PI / 8));
			glVertex3d(x, y, center.z);
		}
		glEnd();
		break;
	default:
		break;
	}
}

//---------------------------Rectangle---------------------------
void Primitives::drawRectangle(Point center, double side1, double side2, char ignoredDimension, int tex, int repeet) {

	switch (ignoredDimension)
	{
	case 'x':
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glTexCoord2d(side1 / repeet, side2 / repeet);
		glVertex3d(center.x, center.y + (side1 / 2), center.z + (side2 / 2));
		glTexCoord2d(0, side2 / repeet);
		glVertex3d(center.x, center.y + (side1 / 2), center.z - (side2 / 2));
		glTexCoord2d(0, 0);
		glVertex3d(center.x, center.y - (side1 / 2), center.z - (side2 / 2));
		glTexCoord2d(side1 / repeet, 0);
		glVertex3d(center.x, center.y - (side1 / 2), center.z + (side2 / 2));
		glEnd();
		break;
	case 'y':
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glTexCoord2d(side1 / repeet, side2 / repeet);
		glVertex3d(center.x + (side1 / 2), center.y, center.z + (side2 / 2));
		glTexCoord2d(side1 / repeet, 0);
		glVertex3d(center.x + (side1 / 2), center.y, center.z - (side2 / 2));
		glTexCoord2d(0, 0);
		glVertex3d(center.x - (side1 / 2), center.y, center.z - (side2 / 2));
		glTexCoord2d(0, side2 / repeet);
		glVertex3d(center.x - (side1 / 2), center.y, center.z + (side2 / 2));
		glEnd();
		break;
	case 'z':
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glTexCoord2d(side1 / repeet, side2 / repeet);
		glVertex3d(center.x + (side1 / 2), center.y + (side2 / 2), center.z);
		glTexCoord2d(side1 / repeet, 0);
		glVertex3d(center.x + (side1 / 2), center.y - (side2 / 2), center.z);
		glTexCoord2d(0, 0);
		glVertex3d(center.x - (side1 / 2), center.y - (side2 / 2), center.z);
		glTexCoord2d(0, side2 / repeet);
		glVertex3d(center.x - (side1 / 2), center.y + (side2 / 2), center.z);
		glEnd();
		break;
	default:
		break;
	}
}

//---------------------------half ball (sphere with texture)---------------------------
void Primitives::drawHalfBall(float rad, int texture, Point center)
{
	glTranslated(center.x, center.y, center.z);
	float lastcenter = rad*sin(3.14 / 2);
	float lastr = rad*cos(3.14 / 2);
	for (float vertical = 3.14 / 2.0; vertical >= 0; vertical -= 0.1)
	{

		float centeri = rad*sin(vertical);
		float ri = rad*cos(vertical);
		int col = 0;
		for (float horizin = 0; horizin <= 2 * 3.14 + 0.1; horizin += 0.1)
		{
			Point a = Point(ri*cos(horizin), centeri, ri*sin(horizin));
			Point b = Point(ri*cos(horizin + 0.1), centeri, ri*sin(horizin + 0.1));
			Point c = Point(lastr*cos(horizin), lastcenter, lastr*sin(horizin));
			Point d = Point(lastr*cos(horizin + 0.1), lastcenter, lastr*sin(horizin + 0.1));
			if (texture != -1)
			{
				glBindTexture(GL_TEXTURE_2D, texture);
				glBegin(GL_QUADS);
				glTexCoord2d(1 - (horizin) / (2 * 3.14), 0.5 + sin(vertical - 0.1) / 2.0);
				glVertex3f(a.x, a.y, a.z);
				glTexCoord2d(1 - (horizin + 0.1) / (2 * 3.14), 0.5 + sin(vertical - 0.1) / 2.0);
				glVertex3f(b.x, b.y, b.z);
				glTexCoord2d(1 - (horizin + 0.1) / (2 * 3.14), 0.5 + sin(vertical) / 2.0);
				glVertex3f(d.x, d.y, d.z);
				glTexCoord2d(1 - (horizin) / (2 * 3.14), 0.5 + sin(vertical) / 2.0);
				glVertex3f(c.x, c.y, c.z);
				glEnd();
			}
			else
			{
				glBegin(GL_QUADS);
				glVertex3f(a.x, a.y, a.z);
				glVertex3f(b.x, b.y, b.z);
				glVertex3f(d.x, d.y, d.z);
				glVertex3f(c.x, c.y, c.z);
				glEnd();
			}
		}
		lastr = ri;
		lastcenter = centeri;
	}
	glTranslated(-center.x, -center.y, -center.z);

}


//---------------------------ball (sphere with texture)---------------------------
void Primitives::drawBall(float rad, int texture, Point center)
{
	glTranslated(center.x, center.y, center.z);
	float lastcenter = rad*sin(3.14 / 2);
	float lastr = rad*cos(3.14 / 2);
	for (float vertical = 3.14 * 2.0; vertical >= 0; vertical -= 0.1)
	{

		float centeri = rad*sin(vertical);
		float ri = rad*cos(vertical);
		int col = 0;
		for (float horizin = 0; horizin <= 2 * 3.14 + 0.1; horizin += 0.1)
		{
			Point a = Point(ri*cos(horizin), centeri, ri*sin(horizin));
			Point b = Point(ri*cos(horizin + 0.1), centeri, ri*sin(horizin + 0.1));
			Point c = Point(lastr*cos(horizin), lastcenter, lastr*sin(horizin));
			Point d = Point(lastr*cos(horizin + 0.1), lastcenter, lastr*sin(horizin + 0.1));
			if (texture != -1)
			{
				glBindTexture(GL_TEXTURE_2D, texture);
				glBegin(GL_QUADS);
				glTexCoord2d(1 - (horizin) / (2 * 3.14), 0.5 + sin(vertical - 0.1));
				glVertex3f(a.x, a.y, a.z);
				glTexCoord2d(1 - (horizin + 0.1) / (2 * 3.14), 0.5 + sin(vertical - 0.1));
				glVertex3f(b.x, b.y, b.z);
				glTexCoord2d(1 - (horizin + 0.1) / (2 * 3.14), 0.5 + sin(vertical));
				glVertex3f(d.x, d.y, d.z);
				glTexCoord2d(1 - (horizin) / (2 * 3.14), 0.5 + sin(vertical));
				glVertex3f(c.x, c.y, c.z);
				glEnd();
			}
			else
			{
				glBegin(GL_QUADS);
				glVertex3f(a.x, a.y, a.z);
				glVertex3f(b.x, b.y, b.z);
				glVertex3f(d.x, d.y, d.z);
				glVertex3f(c.x, c.y, c.z);
				glEnd();
			}
		}
		lastr = ri;
		lastcenter = centeri;
	}

	glTranslated(-center.x, -center.y, -center.z);

}
//---------------------------MinusOctagon (ãËãä ÈáÇ ÇÍÏ ÇáÇÖáÚ)---------------------------
void Primitives::drawMinusOctagon(Point center, double radious1, double radious2, int tex) {
	double angleIncrement = M_PI / 4;
	double previousX1, previousZ1, previousX2, previousZ2;

	for (double angle = 0.0; angle < 2.0 * M_PI + angleIncrement; angle += angleIncrement) {
		double x1 = center.x + radious1 * cos(angle + (M_PI / 8));
		double z1 = center.z + radious1 * sin(angle + (M_PI / 8));
		double x2 = center.x + radious2 * cos(angle + (M_PI / 8));
		double z2 = center.z + radious2 * sin(angle + (M_PI / 8));
		if (angle != 0.0) {
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
			glBindTexture(GL_TEXTURE_2D, tex);
			glBegin(GL_QUADS);
			glTexCoord2d(radious2 - radious1, 0);
			glVertex3d(previousX1, center.y, previousZ1);
			glTexCoord2d(radious2 - radious1, radious2 - radious1);
			glVertex3d(previousX2, center.y, previousZ2);
			glTexCoord2d(0, radious2 - radious1);
			glVertex3d(x2, center.y, z2);
			glTexCoord2d(0, 0);
			glVertex3d(x1, center.y, z1);
			glEnd();
			glCullFace(GL_FRONT);
			glBegin(GL_QUADS);
			glVertex3d(previousX1, center.y, previousZ1);
			glVertex3d(previousX2, center.y, previousZ2);
			glVertex3d(x2, center.y, z2);
			glVertex3d(x1, center.y, z1);
			glEnd();
			glDisable(GL_CULL_FACE);


		}
		previousX1 = x1;
		previousZ1 = z1;
		previousX2 = x2;
		previousZ2 = z2;
	}

}
//--------------------------Arch (ÞæÓ)--------------------------
double Primitives::drawArch(Point center, double radious1, double radious2, int tex) {
	double angle;
	double incr1 = center.y;
	double incr2 = radious2;
	double hight = 0;
	double incrementValue = (2 * radious2) / (M_PI / (0.002));
	glBindTexture(GL_TEXTURE_2D, tex);
	glBegin(GL_LINES);
	for (angle = 0.0; angle < M_PI; angle += 0.001) {
		double x1 = center.x + radious1 * cos(angle);
		double y1 = center.y + radious1 * sin(angle);
		double x2 = center.x + radious2 * cos(angle);
		double y2 = center.y + radious2 * sin(angle);

		if (angle <= M_PI / 4) {
			glTexCoord2d(x1, y1);
			glVertex3d(x1, y1, center.z);
			glTexCoord2d(radious2, incr1);
			glVertex3d(radious2, incr1, center.z);
			incr1 += 0.002;
		}

		if (angle > M_PI / 4 && angle <= (3 * M_PI) / 4) {
			glTexCoord2d(x1, y1);
			glVertex3d(x1, y1, center.z);
			glTexCoord2d(incr2, incr1);
			glVertex3d(incr2, incr1, center.z);
			incr2 -= incrementValue;
			if (angle <3 * M_PI / 8){
				hight = incr1 - center.y;
			}
		}

		if (angle >(3 * M_PI) / 4) {
			glTexCoord2d(x1, y1);

			glVertex3d(x1, y1, center.z);
			glTexCoord2d(radious2, incr1);
			glVertex3d(-radious2, incr1, center.z);
			incr1 -= 0.002;
		}
	}
	glEnd();
	return hight;
}

void Primitives::DrawHalfCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture)
{
	glTranslated(Base_center1.x, Base_center1.y, Base_center1.z);
	Base_center1 = Point(0, 0, 0);
	Point Base_center2 = Point(0, 0, height);

	float angle = 0, x1 = Base_rad1, y1 = 0, x2 = Base_rad2, y2 = 0;
	for (angle = 0; angle <= 3.14 + 0.05; angle += 0.05)
	{
		Point a = Point(x1, y1, Base_center1.z);
		Point b = Point(x2, y2, Base_center2.z);
		x1 = Base_rad1*cos(angle);
		y1 = Base_rad1*sin(angle);
		x2 = Base_rad2*cos(angle);
		y2 = Base_rad2*sin(angle);
		Point c = Point(x2, y2, Base_center2.z);
		Point d = Point(x1, y1, Base_center1.z);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);

		glTexCoord2f(angle / 3.14, a.z / height);
		glVertex3f(a.x, a.y, a.z);

		glTexCoord2f(angle / 3.14, b.z / height);
		glVertex3f(b.x, b.y, b.z);

		glTexCoord2f((angle + 0.1) / 3.14, c.z / height);
		glVertex3f(c.x, c.y, c.z);

		glTexCoord2f((angle + 0.1) / 3.14, d.z / height);
		glVertex3f(d.x, d.y, d.z);

		glEnd();
	}
	glTranslated(-Base_center1.x, -Base_center1.y, -Base_center1.z);

}

void Primitives::DrawCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture)
{
		glTranslated(Base_center1.x, Base_center1.y, Base_center1.z);
		glRotated(-90, 1, 0, 0);
		Base_center1 = Point(0, 0, 0);
		Point Base_center2 = Point(0, 0, height);
		if (texture != -1)
			glColor3f(1, 1, 1);
		float angle = 0, x1 = Base_rad1, y1 = 0, x2 = Base_rad2, y2 = 0;
		for (angle = 0; angle <= 2 * 3.14 + 0.05; angle += 0.05)
		{
			Point a = Point(x1, y1, Base_center1.z);
			Point b = Point(x2, y2, Base_center2.z);
			x1 = Base_rad1*cos(angle);
			y1 = Base_rad1*sin(angle);
			x2 = Base_rad2*cos(angle);
			y2 = Base_rad2*sin(angle);
			Point c = Point(x2, y2, Base_center2.z);
			Point d = Point(x1, y1, Base_center1.z);
			glBindTexture(GL_TEXTURE_2D, texture);
			glBegin(GL_QUADS);

			glTexCoord2f(angle / 2 * 3.14, a.z / height);
			glVertex3f(a.x, a.y, a.z);

			glTexCoord2f(angle / 2 * 3.14, b.z / height);
			glVertex3f(b.x, b.y, b.z);

			glTexCoord2f((angle + 0.1) / 2 * 3.14, c.z / height);
			glVertex3f(c.x, c.y, c.z);

			glTexCoord2f((angle + 0.1) / 2 * 3.14, d.z / height);
			glVertex3f(d.x, d.y, d.z);

			glEnd();
		}
		glTranslated(-Base_center1.x, -Base_center1.y, -Base_center1.z);

}
