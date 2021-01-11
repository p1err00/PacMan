#ifndef ENNEMI_BASE_H
#define ENNEMI_BASE_H
#include "PersonnageBase.h"
class EnnemiBase : public PersonnageBase
{
private:
	// Pointeur sur l'ennemi suivant dans la liste cha�n�e
	EnnemiBase* Suivant;
public:
	// Constructeur
	EnnemiBase() : PersonnageBase()
	{
		Suivant = NULL;  //initialisation � la valeur NULL
	}
	EnnemiBase* GetSuivant() const { return Suivant; }
	void SetSuivant(EnnemiBase* ptr) { Suivant = ptr; }
	virtual void DeplacementAuto(); // D�placement automatique
	void TestCollision();
};
#endif