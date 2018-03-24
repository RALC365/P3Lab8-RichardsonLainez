#include "Adulto.h"
#include "ArcoFlecha.h"
#include "Bomba.h"
#include "Boomerang.h"
#include "Comun.h"
#include "Heroe.h"
#include "Item.h"
#include "Jefe.h"
#include "Joven.h"
#include "Monstruo.h"
#include "Semijefe.h"


#include <fstream>
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

int menu();
void cargarHeroe(Heroe*&);
void guardarHeroe(Heroe*&);
void agregarItem(vector<Item*>&);
int buscarItem(vector<Item*>);
void agregarMonstruo(vector<Monstruo*>&);
void eliminarMonstruo(vector<Monstruo*>&);
int buscarMonstruo(vector<Monstruo*>);
bool batallar(Heroe*&, Monstruo*&);

using namespace std;

int main()
{
	string tempNombreHeroe;
	cout << "Ingrese el nombre del héroe, por favor:";
	cin >> tempNombreHeroe;
	Heroe* heroe = new Joven(tempNombreHeroe);
	vector<Monstruo*> baseMonstruos;
	vector<Item*> baseItems;
	bool modoBatalla = false;
	int opcion, pos;
	do{

		cout << "\nMENU PRINCIPAL\n"
			<< "1.-Guardar\n"
			<< "2.-Cargar\n"
			<< "3.-Añadir Item\n"
			<< "4.-Añadir monstruo\n"
			<< "5.-Eliminar monstruo\n"
			<< "6.-Comprar corazones\n"
			<< "7.-Invocar la Master Sword\n"
			<< "8.-Guardar la Master Sword\n"
			<< "9.-¡A luchar!\n"
			<< "10.-Cambiar de item\n"
			<< "11.-¿Qué tiene el héroe?\n"
			<< "0.-¡Vamonos!\n"
			<< "Elija una opciósn: ";
		cin >> opcion;
		switch (opcion)
		{
			case 1:
				guardarHeroe(heroe);
				break;

			case 2:
				cargarHeroe(heroe);
				break;

			case 3:
				agregarItem(baseItems);
				break;

			case 4:
				agregarMonstruo(baseMonstruos);
				break;

			case 5:
				if (baseMonstruos.size() > 0){
					eliminarMonstruo(baseMonstruos);
				}else{
					cout << "No hay monstruos... cree más para eliminarlos" << endl;
				}
				break;

			case 6:
				heroe->comprar();
				break;

			case 7:
				if (dynamic_cast<Joven*>(heroe) != NULL && heroe->puedeCrecer()){
					Heroe* tempHeroe = new Adulto(heroe->getNombre());
					tempHeroe->setVida(heroe->getVida());
					tempHeroe->setVidaMax(heroe->getVidaMax());
					tempHeroe->setJefesDerrotados(heroe->getJefesDerrotados());
					tempHeroe->setDinero(heroe->getDinero());
					delete heroe;
					heroe = tempHeroe;
				}else{
					cout << "No cumple los requisitos para sacar la Master Sword... sorry!" << endl;
				}
				break;

			case 8:
				if (dynamic_cast<Adulto*>(heroe) != NULL){
					Heroe* tempHeroe = new Joven(heroe->getNombre());
					tempHeroe->setVida(heroe->getVida());
					tempHeroe->setVidaMax(heroe->getVidaMax());
					tempHeroe->setJefesDerrotados(heroe->getJefesDerrotados());
					tempHeroe->setDinero(heroe->getDinero());
					delete heroe;
					heroe = tempHeroe;
				}else{
					cout << "No se puede guardar... sorry!" << endl;
				}
				break;

			case 9:
				if (baseMonstruos.size() > 0){
					pos = buscarMonstruo(baseMonstruos);
					if (!batallar(heroe, baseMonstruos[pos])){
						heroe->derrotado();
					}
					else{
						baseMonstruos[pos]->derrotado(heroe);
						delete baseMonstruos[pos];
						baseMonstruos.erase(baseMonstruos.begin() + pos);
					}
				}else{
					cout << "No hay monstruos... cree más" << endl;
				}
				break;

			case 10:
				if (baseItems.size() > 0){
					pos = buscarItem(baseItems);
					heroe->setItem(baseItems[pos]);
				}else{
					cout << "No hay items... cree más" << endl;
				}
				break;

			case 11:
				cout << "INFORMACIÓN" << endl
					<< "JUGADOR: " << heroe->getNombre() << endl
					<< "VIDA MÁXIMA: " << heroe->getVidaMax() << endl
					<< "MONEY: " << heroe->getDinero() << endl
					<< "JEFES QUE HA DERROTADOS " << heroe->getJefesDerrotados() << endl;
				break;

			case 0:
				cout << "HAKUNA MATATA" << endl;
				break;

			default:
				cout << "Ese número no está en las opciones... escogé uno que sí esté :v" << endl;
				break;
		}
	}
	while(opcion != 0);
	return 0;
}

void guardarHeroe(Heroe*& heroe){
	ofstream archivo("ArchivoBinario.P3Lab8", ios::binary);
	heroe->guardar(archivo);
	archivo.close();
}

void cargarHeroe(Heroe*& heroe){
	ifstream archivo("ArchivoBinario.P3Lab8", ios::binary);
	heroe->cargar(archivo);
	archivo.close();
}

void agregarItem(vector<Item*>& items){
	string tempNombre, tempColor;
	int tipoItem;

	cout << "Ingrese el nombre del nuevo item: ";
	cin >> tempNombre;

	cout << "Ingrese el color del item:";
	cin >> tempColor;

	do
	{
		cout << "Escoja el tipo de item:\n"
			<< "1.-Boomerang\n"
			<< "2.-Arco y flecha\n"
			<< "3.-Bomba\n"
			<< "Escoja un item: ";
		cin >> tipoItem;
	}
	while (tipoItem != 1 && tipoItem != 2 && tipoItem != 3);


	if (tipoItem == 1)
		items.push_back(new Boomerang(tempNombre, tempColor));
	else if (tipoItem == 2)
		items.push_back(new ArcoFlecha(tempNombre, tempColor));
	else
		items.push_back(new Bomba(tempNombre, tempColor));
}

int buscarItem(vector<Item*> items){
	int pos;
	cout << "Items que están disponibles: " << endl;
	for (int i = 0; i < items.size(); i++)
		if (dynamic_cast<Bomba*>(items[i]) != NULL)
			cout << i << ") Bomba " << items[i]->getNombre() << endl;

		else if (dynamic_cast<Boomerang*>(items[i]) != NULL)
			cout << i << ") Boomerang " << items[i]->getNombre() << endl;

		else if (dynamic_cast<ArcoFlecha*>(items[i]) != NULL)
			cout << i << ") Arco y flecha " << items[i]->getNombre() << endl;

	cout << "Escoja una opción: ";
	do
		cin >> pos;
	while (pos < 0 || pos >= items.size());
	return pos;
}

void agregarMonstruo(vector<Monstruo*>& monstruos){
	string tempNombre, tempDebilidadStr;
	int tempVida, tempDebilidad, tipoMonstruo;

	do{
		cout << "Ingrese el tipo de monstruo:\n"
			<< "1.-Común\n"
			<< "2.-Semi Jefe\n"
			<< "3.-Jefe\n";
		cin >> tipoMonstruo;
	}while (tipoMonstruo != 1 && tipoMonstruo != 2 && tipoMonstruo != 3);

	cout << "Ingrese el nombre del monstruo: ";
	cin >> tempNombre;

	do{
		cout << "Ingrese la debilidad del monstruo:\n"
			<< "1.-Boomerang\n"
			<< "2.-Bomba\n"
			<< "3.-Arco y felchas\n";
		cin >> tempDebilidad;
	}while (tempDebilidad != 1 && tempDebilidad != 2 && tempDebilidad != 3);

	if (tempDebilidad == 1)
		tempDebilidadStr = "boomerang";
	else if (tempDebilidad == 2)
		tempDebilidadStr = "bomba";
	else
		tempDebilidadStr = "ArcoFlecha";

	if (tipoMonstruo == 1){
		cout << "Ingrese la vida del monstruo (4-12): ";
		do
			cin >> tempVida;
		while (tempVida < 4 || tempVida > 12);
		monstruos.push_back(new Comun(tempNombre, tempDebilidadStr, tempVida));
	}
	else if (tipoMonstruo == 2){
		cout << "Ingrese la vida del monstruo (12-26): ";
		do
			cin >> tempVida;
		while (tempVida < 12 || tempVida > 26);
		monstruos.push_back(new Semijefe(tempNombre, tempDebilidadStr, tempVida));
	}
	else{
		cout << "Ingrese la vida del monstruo (26-40): ";
		do
			cin >> tempVida;
		while (tempVida < 26 || tempVida > 40);
		monstruos.push_back(new Jefe(tempNombre, tempDebilidadStr, tempVida));
	}
}

void eliminarMonstruo(vector<Monstruo*>& monstruos){
	int pos;
	cout << "Monstruos disponibles: " << endl;
	for (int i = 0; i < monstruos.size(); i++)
		if (dynamic_cast<Comun*>(monstruos[i]) != NULL)
			cout << i << ") Monstruo Común " << monstruos[i]->getNombre() << endl;

		else if (dynamic_cast<Semijefe*>(monstruos[i]) != NULL)
			cout << i << ") Semi Jefe " << monstruos[i]->getNombre() << endl;

		else if (dynamic_cast<Jefe*>(monstruos[i]) != NULL)
			cout << i << ") Jefe " << monstruos[i]->getNombre() << endl;

	cout << "Escoja una posición: ";
	do
		cin >> pos;
	while (pos < 0 || pos >= monstruos.size());

	delete monstruos[pos]; 
	monstruos.erase(monstruos.begin() + pos);
}

int buscarMonstruo(vector<Monstruo*> monstruos){
	int pos;
	cout << "Monstruos disponibles: " << endl;
	for (int i = 0; i < monstruos.size(); i++)
		if (dynamic_cast<Comun*>(monstruos[i]) != NULL)
			cout << i << ") Monstruo Común " << monstruos[i]->getNombre() << endl;

		else if (dynamic_cast<Semijefe*>(monstruos[i]) != NULL)
			cout << i << ") Semi Jefe " << monstruos[i]->getNombre() << endl;

		else if (dynamic_cast<Jefe*>(monstruos[i]) != NULL)
			cout << i << ") Jefe " << monstruos[i]->getNombre() << endl;

	cout << "Seleccione una posición: ";
	do
		cin >> pos;
	while (pos < 0 || pos >= monstruos.size());
	return pos;
}

bool batallar(Heroe*& heroe, Monstruo*& monstruo){
	int opcion;
	do{
		cout << "\nMENÚ BATALLA\n"
			<< "1) Ataque Normal\n"
			<< "2) Ataque Especial\n"
			<< "3) Ataque Item\n"
			<< "Escoja una opción: ";
		cin >> opcion;
		switch (opcion){
			case 1:
				heroe->atacar(monstruo);
				break;

			case 2:
				heroe->atacarEspecial(monstruo);
				break;

			case 3:
				if (heroe->getItem() != NULL)
					heroe->getItem()->utilizar(heroe, monstruo);
				else
					cout << "No tiene un item... sorry!" << endl;
				break;

			default:
				cout << "Lo que ingresó no está en el menú... ingrese algo del menú :V" << endl;
				break;
		}
		monstruo->atacar(heroe);
	}while (heroe->getVida() > 0 && monstruo->getVida() > 0);

	if (heroe->getVida() > 0){
		cout << "Has Ganado... felicidades" << endl;
		heroe->curar();
		return true;
	}
	else{
		cout << "Ijole, perdiste... que verguenza" << endl;
		heroe->curar();
		return false;
	}
}
