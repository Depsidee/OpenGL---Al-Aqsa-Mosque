#include "Octagon.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <math.h>
#include "texture.h"
#define M_PI 3.14159265358979323846


Octagon::Octagon()
{
}


Octagon::~Octagon()
{
}

void Octagon::drawOctagon(Point center, double radious, char ignoredDimension, int tex) {
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
