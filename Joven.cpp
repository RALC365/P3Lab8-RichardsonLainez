#include "Joven.h"

Joven::Joven(string nombre){
	this->nombre = nombre;
	vidaMax = 12;
	vida = vidaMax;
	jefesDerrotados = 0;
	dinero = 0;
	item = NULL;

	defensa = 2;
	ataque = 4;
	especial = 0;
	especialDisponible = false;
}