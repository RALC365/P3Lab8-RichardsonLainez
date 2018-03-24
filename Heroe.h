#ifndef HEROE_H
#define HEROE_H

#include "Monstruo.h"
#include <string>
#include <fstream>

using namespace std;

class Item;
class Monstruo;
class Heroe
{
	protected:
		int vida;
		int vidaMax;
		int jefesDerrotados;
		int dinero;
		string nombre;
		Item* item;

		int defensa;
		int ataque;
		int especial;
		bool especialDisponible;

	public:
		virtual int getVida();
		void curar();
		void derrotado();
		void atacar(Monstruo*);
		void atacarEspecial(Monstruo*);
		string getNombre();
		bool puedeCrecer();
		void comprar();
		void guardar(ofstream&);
		void cargar(ifstream&);
		int getDefensa();
		void setVida(int);
		int getDinero();
		void setDinero(int);
		int getJefesDerrotados();
		void setJefesDerrotados(int);
		int getVidaMax();
		void setVidaMax(int);
		Item* getItem();
		void setItem(Item*);
};

#endif