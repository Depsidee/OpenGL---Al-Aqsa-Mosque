#include "Octahedron.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <math.h>
#include "texture.h"
#define M_PI_4 0.785398163397448309616


Octahedron::Octahedron()
{
}


Octahedron::~Octahedron()
{
}

void Octahedron::drawRegularOctahedron(Point center, double tallXZ, double tallY, int tex) {
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
