#ifndef ARCOFLECHA_H
#define ARCOFLECHA_H

#include "Item.h"
#include "Heroe.h"
#include "Monstruo.h"
#include <string>

using namespace std;

class ArcoFlecha : public Item
{
	public:
		ArcoFlecha(string, string);
		void utilizar(Heroe*, Monstruo*);
};

#endif