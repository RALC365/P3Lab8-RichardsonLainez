#ifndef JEFE_H
#define JEFE_H

#include "Heroe.h"
#include "Monstruo.h"
#include <string>

using namespace std;

class Jefe : public Monstruo
{
	public:
		void derrotado(Heroe*);
		Jefe(string, string, int);
};

#endif