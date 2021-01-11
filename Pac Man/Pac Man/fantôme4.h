//classe simple avec un constructeur et sa fonction
#pragma once
#ifndef FANTOME4_H
#define FANTOME4_H
#include "EnnemiBase.h"
class Fantome4 : public EnnemiBase
{
public:
	Fantome4() : EnnemiBase() {}
	void Dessiner();
};
#endif 
#pragma once
