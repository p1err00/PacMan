#include "Joueur.h"

extern int NbColonnes;
extern int NbLignes;
extern char** Matrice;
extern int deplacement, droitei, gauchei, droitej, gauchej;

void Joueur::Dessiner()
{
	switch (deplacement) {
	case 1: {//droite
		glPushMatrix();
		glTranslated(PosC + 0.5, PosL + 0.5, 0.0);
		glColor3d(1.0, 1.0, 0.0);//Couleur jaune
		glutSolidSphere(0.4, 12, 12); // Sphère de la tête
		glColor3d(0, 0, 0);
		glTranslated(0.1, -0.1, 0.0);
		glBegin(GL_TRIANGLES);//bouche
		glColor3d(0, 0, 0);
		glVertex2d(-0.1, 0.1);
		glVertex2d(0.3, 0.4);
		glVertex2d(0.3, -0.3);
		glEnd();
		glPopMatrix();
		break;
	}
	case 2: {//haut
		glPushMatrix();
		glTranslated(PosC + 0.5, PosL + 0.5, 0.0);
		glColor3d(1.0, 1.0, 0.0);//Couleur jaune
		glutSolidSphere(0.4, 12, 12); // Sphère de la tête
		glColor3d(0, 0, 0);
		glTranslated(0.1, -0.1, 0.0);
		glBegin(GL_TRIANGLES);//bouche
		glColor3d(0, 0, 0);
		glVertex2d(-0.1, 0.1);
		glVertex2d(0.3, -0.3);
		glVertex2d(-0.5, -0.4);
		glEnd();
		glPopMatrix();
		break;
	}
	case 3: {//gauche
		glPushMatrix();
		glTranslated(PosC + 0.5, PosL + 0.5, 0.0);
		glColor3d(1.0, 1.0, 0.0);//Couleur jaune
		glutSolidSphere(0.4, 12, 12); // Sphère de la tête
		glColor3d(0, 0, 0);
		glTranslated(0.1, -0.1, 0.0);
		glBegin(GL_TRIANGLES);//bouche
		glColor3d(0, 0, 0);
		glVertex2d(-0.1, 0.1);
		glVertex2d(-0.5, -0.4);
		glVertex2d(-0.5, 0.4);
		glEnd();
		glPopMatrix();
		break;
	}
	case 4: {//bas
		glPushMatrix();
		glTranslated(PosC + 0.5, PosL + 0.5, 0.0);
		glColor3d(1.0, 1.0, 0.0);//Couleur jaune
		glutSolidSphere(0.4, 12, 12); // Sphère de la tête
		glColor3d(0, 0, 0);
		glTranslated(0.1, -0.1, 0.0);
		glBegin(GL_TRIANGLES);//bouche
		glColor3d(0, 0, 0);
		glVertex2d(-0.1, 0.1);
		glVertex2d(-0.5, 0.5);
		glVertex2d(0.3, 0.5);
		glEnd();
		glPopMatrix();
		break;
	}
	case 5: {//plein
		glPushMatrix();
		glTranslated(PosC + 0.5, PosL + 0.5, 0.0);
		glColor3d(1.0, 1.0, 0.0);//Couleur jaune
		glutSolidSphere(0.4, 12, 12); // Sphère de la tête
		glColor3d(0, 0, 0);
		glTranslated(0.1, -0.1, 0.0);

		glPopMatrix();
		break;
	}
	}
}

void Joueur::Teleportation()
{//fonction pour la teleportation suivant les coordonnées du joueur
	if (gauchei == PosC && gauchej == PosL)//si les coordonnées du joueur sont les mêmes que celui du point de téléportation 
	{
		PosC = droitei; //alors il prend les coordonnées du nouveau point
		PosL = droitej;

	}
	else if (droitei == PosC && droitej == PosL)//pareil mais pour le deuxième point
	{
		PosC = gauchei;
		PosL = gauchej;

	}
}

