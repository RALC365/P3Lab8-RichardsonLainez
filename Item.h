#ifndef ITEM_H
#define ITEM_H

#include "Heroe.h"
#include "Monstruo.h"
#include <string>

using namespace std;

class Item
{
	protected:
		string nombre;
		string color;

	public:
		virtual void utilizar(Heroe*, Monstruo*) = 0;
		string getNombre();
};

#endif