#include "Cube.h"
#define _USE_MATH_DEFINES
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <math.h>
#include "texture.h"


Cube::Cube()
{
}


Cube::~Cube()
{
}

void Cube::drawCube(float sX, float sY, float sZ, int texture, float num){


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
