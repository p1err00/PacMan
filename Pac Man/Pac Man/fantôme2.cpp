#include "fantôme2.h"
//dessin de mon fantôme
void Fantome2::Dessiner()
{
	//tête
	glPushMatrix();
	glTranslated(PosC + 0.5, PosL + 0.5, 0.0);
	glColor3d(0, 1, 0);
	glutSolidSphere(0.4, 12, 12);

	//corps
	glTranslated(-0.4, 0, 0.0);
	glBegin(GL_QUADS);
	glColor3d(0, 1, 0);
	glVertex2d(0.0, 0);
	glVertex2d(0.0, 0.35);
	glVertex2d(0.8, 0.35);
	glVertex2d(0.8, 0);
	glEnd();

	//"pieds"
	glTranslated(0.25, 0.35, 0.0);
	glColor3d(0, 1, 0);
	glutSolidSphere(0.12, 12, 12);

	glTranslated(0.4, 0, 0.0);
	glColor3d(0, 1, 0);
	glutSolidSphere(0.12, 12, 12);

	//yeux
	glTranslated(-0.1, -0.45, 0.0);
	glColor3d(1, 1, 1);
	glutSolidSphere(0.15, 12, 12);
	glColor3d(0.5, 0.5, 1);
	glutSolidSphere(0.07, 12, 12);

	glTranslated(-0.35, 0, 0.0);
	glColor3d(1, 1, 1);
	glutSolidSphere(0.15, 12, 12);
	glColor3d(0.5, 0.5, 1);
	glutSolidSphere(0.07, 12, 12);

	glPopMatrix();
}