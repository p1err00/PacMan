//classe simple avec un constructeur et sa fonction
#pragma once
#ifndef FANTOME_H
#define FANTOME_H
#include "EnnemiBase.h"
class Fantome : public EnnemiBase
{
public:
	Fantome() : EnnemiBase() {}
	void Dessiner();
};
#endif 
