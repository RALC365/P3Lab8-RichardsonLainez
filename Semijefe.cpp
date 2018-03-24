#include "Semijefe.h"

Semijefe::Semijefe(string nombre, string debilidad, int vida){
	this->nombre = nombre;
	this->debilidad = debilidad;
	this->vida = vida;
	this->defensa = 1;
	this->ataque = 7;
}

void Semijefe::derrotado(Heroe* heroe){
	int money = heroe->getDinero();
	money += 100;
	heroe->setDinero(money);
}
