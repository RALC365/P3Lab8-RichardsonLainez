#include "Comun.h"

Comun::Comun(string nombre, string debilidad, int vida){
	this->nombre = nombre;
	this->debilidad = debilidad;
	this->vida = vida;
	this->defensa = 0;
	this->ataque = 5;
}

void Comun::derrotado(Heroe* heroe){
	int money = heroe->getDinero();
	money += 40;
	heroe->setDinero(money);
}
