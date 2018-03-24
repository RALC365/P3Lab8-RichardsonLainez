#include "Boomerang.h"

Boomerang::Boomerang(string nombre, string color){
	this->nombre = nombre;
	this->color = color;
}

void Boomerang::utilizar(Heroe* heroe, Monstruo* monstruo){
	int multiplicador;

	if (monstruo->getDebilidad() == "boomerang")
		multiplicador = 2;
	else
		multiplicador = 1;

	int vida = monstruo->getVida();
	vida -= (5 - monstruo->getDefensa()) * multiplicador;
	monstruo->setVida(vida);
}