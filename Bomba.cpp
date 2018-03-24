#include "Bomba.h"

Bomba::Bomba(string nombre, string color){
	this->nombre = nombre;
	this->color = color;
}

void Bomba::utilizar(Heroe* heroe, Monstruo* monstruo){
	int multiplicador;

	if (monstruo->getDebilidad() == "bomba")
		multiplicador = 2;
	else
		multiplicador = 1;

	int vidaMon = monstruo->getVida();
	vidaMon -= (10 - monstruo->getDefensa()) * multiplicador;
	monstruo->setVida(vidaMon);

	int vidaHer = heroe->getVida();
	vidaHer -= 4;
	heroe->setVida(vidaHer);
}