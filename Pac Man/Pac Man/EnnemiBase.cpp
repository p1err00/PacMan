#include "EnnemiBase.h"
#include "Joueur.h"

extern Joueur monJoueur;
extern void LibererMemoire();
extern void PMAffichage();

void EnnemiBase::DeplacementAuto()
{//fonction pour le d�placement automatique de mes ennemies suivant une valeur al�atoire et une constante temps
	int hasard = rand() % 4;
	switch (hasard)
	{
	case 0: { BougerEnHaut();   break; }
	case 1: { BougerEnBas();    break; }
	case 2: { BougerADroite();  break; }
	case 3: { BougerAGauche();  break; }
	}
}

void EnnemiBase::TestCollision()
{//test de corr�lation de coordonn�es entre un ennemi et le joueur pour savoir s'il perd
	if (PosC == monJoueur.GetPosC() && PosL == monJoueur.GetPosL())
	{
		cout << "Vous avez perdu !" << endl;
		PMAffichage();
		LibererMemoire();
		system("pause");
		exit(0);
	}
}
