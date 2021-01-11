//classe simple avec un constructeur et sa fonction
#pragma once
#ifndef FANTOME3_H
#define FANTOME3_H
#include "EnnemiBase.h"
class Fantome3 : public EnnemiBase
{
public:
	Fantome3(): EnnemiBase() {}
	void Dessiner();
};
#endif 
#pragma once
