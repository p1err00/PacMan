#include "PersonnageBase.h"

extern int NbColonnes;
extern int NbLignes;
extern char** Matrice;

//fonction pour que le joueur puisse se déplacer dans le niveau et qu'il ne puisse pas traverser les murs
void PersonnageBase::BougerEnHaut()
{
	if (PosL > 0 && Matrice[PosC][PosL - 1] != '0')
		PosL--;
}

void PersonnageBase::BougerEnBas()
{
	if (PosL < NbLignes - 1 && Matrice[PosC][PosL + 1] != '0')
		PosL++;
}

void PersonnageBase::BougerAGauche()
{
	if (PosC > 0 && Matrice[PosC - 1][PosL] != '0')
		PosC--;
}

void PersonnageBase::BougerADroite()
{
	if (PosC < NbColonnes - 1 && Matrice[PosC + 1][PosL] != '0')
		PosC++;
}