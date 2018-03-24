#include "ArcoFlecha.h"

ArcoFlecha::ArcoFlecha(string nombre, string color){
	this->nombre = nombre;
	this->color = color;
}

void ArcoFlecha::utilizar(Heroe* heroe, Monstruo* monstruo){
	int multiplicador;

	if (monstruo->getDebilidad() == "ArcoFlecha")
		multiplicador = 2;
	else
		multiplicador = 1;

	int vida = monstruo->getVida();
	vida -= 4 * multiplicador;
	monstruo->setVida(vida);
}