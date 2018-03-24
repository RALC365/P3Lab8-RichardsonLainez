#ifndef COMUN_H
#define COMUN_H

#include "Heroe.h"
#include "Monstruo.h"
#include <string>

using namespace std;

class Comun : public Monstruo
{
	public:
		void derrotado(Heroe*);
		Comun(string, string, int);
};

#endif