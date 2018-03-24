#ifndef SEMIJEFE_H
#define SEMIJEFE_H

#include "Heroe.h"
#include "Monstruo.h"
#include <string>

using namespace std;

class Semijefe : public Monstruo
{
	public:
		void derrotado(Heroe*);
		Semijefe(string, string, int);
};

#endif