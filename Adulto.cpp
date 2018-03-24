#include "Adulto.h"

Adulto::Adulto(string nombre){
	this->nombre = nombre;
	vidaMax = 12;
	vida = vidaMax;
	jefesDerrotados = 0;
	dinero = 0;
	item = NULL;

	defensa = 4;
	ataque = 8;
	especial = 12;
	especialDisponible = true;
}