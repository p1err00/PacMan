#pragma once
#ifndef JOUEUR_H
#define JOUEUR_H
#include "PersonnageBase.h"
class Joueur : public PersonnageBase
{
public:
	// Appel du constructeur de la classe mère PersonnageBase
	Joueur() : PersonnageBase() {}

	//appel des fonctions
	void Dessiner();
	void Teleportation();
};
#endif
