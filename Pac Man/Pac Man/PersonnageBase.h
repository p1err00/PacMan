#pragma once
#ifndef PERSONNAGE_BASE_H
#define PERSONNAGE_BASE_H
// Inclusions utiles pour toutes les classes dérivées
#include <iostream>
using namespace std;
#include "GL/glut.h"
class PersonnageBase
{
protected:
	// Position Colonne et Ligne sur la matrice
	int PosC, PosL;
public:
	// Accesseurs
	int GetPosC() const { return PosC; }
	int GetPosL() const { return PosL; }

	// Mutateurs
	void SetPosC(int C) { PosC = C; }
	void SetPosL(int L) { PosL = L; }

	// Constructeur
	PersonnageBase() { PosC = PosL = 0; }

	// Fonction de déplacement
	void BougerEnHaut();
	void BougerEnBas();
	void BougerAGauche();
	void BougerADroite();

	virtual void Dessiner() = 0;
};
#endif 