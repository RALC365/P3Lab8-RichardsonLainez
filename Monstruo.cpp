#include "Monstruo.h"

void Monstruo::atacar(Heroe* heroe)
{
	int vidaHeroe = heroe->getVida();
	vidaHeroe -= (ataque - heroe->getDefensa());
	heroe->setVida(vidaHeroe);
}

string Monstruo::getNombre()
{
	return nombre;
}

string Monstruo::getDebilidad()
{
	return debilidad;
}

int Monstruo::getAtaque()
{
	return ataque;
}

void Monstruo::setAtaque(int ataque)
{
	this->ataque = ataque;
}

int Monstruo::getVida()
{
	return vida;
}

void Monstruo::setVida(int vida)
{
	this->vida = vida;
}

int Monstruo::getDefensa()
{
	return defensa;
}

void Monstruo::setDefensa(int defensa)
{
	this->defensa = defensa;
}
