#ifndef BOMBA_H
#define BOMBA_H

#include "Item.h"
#include "Heroe.h"
#include "Monstruo.h"
#include <string>

using namespace std;

class Bomba : public Item
{
	public:
		Bomba(string, string);
		void utilizar(Heroe*, Monstruo*);
};

#endif