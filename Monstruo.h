#ifndef MONSTRUO_H
#define MONSTRUO_H

#include "Heroe.h"
#include <string>

using namespace std;

class Heroe;
class Monstruo
{
	protected:
		int vida;
		int defensa;
		int ataque;
		string nombre;
		string debilidad;

	public:
		string getDebilidad();
		string getNombre();
		int getAtaque();
		void setAtaque(int);
		int getVida();
		void setVida(int);
		int getDefensa();
		void setDefensa(int);
		void atacar(Heroe*);
		virtual void derrotado(Heroe*) = 0;
};

#endif