#ifndef BOOMERANG_H
#define BOOMERANG_H

#include "Item.h"
#include "Heroe.h"
#include "Monstruo.h"
#include <string>

using namespace std;

class Boomerang : public Item
{
	public:
		Boomerang(string, string);
		void utilizar(Heroe*, Monstruo*);
};

#endif