//classe simple avec un constructeur et sa fonction
#pragma once
#ifndef FANTOME2_H
#define FANTOME2_H
#include "EnnemiBase.h"
class Fantome2 : public EnnemiBase
{
public:
	Fantome2(): EnnemiBase() {}
	void Dessiner();
};
#endif 
#pragma once
