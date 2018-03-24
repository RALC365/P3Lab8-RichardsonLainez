#include "Jefe.h"

Jefe::Jefe(string nombre, string debilidad, int vida){
	this->nombre = nombre;
	this->debilidad = debilidad;
	this->vida = vida;
	this->defensa = 2;
	this->ataque = 9;
}

void Jefe::derrotado(Heroe* heroe){
	int derrotados = heroe->getJefesDerrotados();
	int vidaMax = heroe->getVidaMax();

	derrotados++;
	vidaMax += 4;

	heroe->setJefesDerrotados(derrotados);
	heroe->setVidaMax(vidaMax);
}
