EJECUTABLE: main.o Adulto.o Comun.o Heroe.o ArcoFlecha.o Jefe.o Joven.o Monstruo.o Semijefe.o Bomba.o Boomerang.o Item.o
	g++ main.o Adulto.o Comun.o Heroe.o ArcoFlecha.o Jefe.o Joven.o Monstruo.o Semijefe.o Bomba.o Boomerang.o Item.o -o EJECUTABLE

main.o: main.cpp Adulto.h ArcoFlecha.h Bomba.h Boomerang.h Comun.h Heroe.h Item.h Jefe.h Joven.h Monstruo.h Semijefe.h
	g++ -c main.cpp

Heroe.o: Heroe.h Heroe.cpp Item.h Monstruo.h 
	g++ -c Heroe.cpp

Adulto.o: Adulto.h Adulto.cpp Heroe.h 
	g++ -c Adulto.cpp

Joven.o: Joven.h Joven.cpp Heroe.h 
	g++ -c Joven.cpp

Item.o: Item.h Item.cpp Heroe.h Monstruo.h 
	g++ -c Item.cpp

Arco.o: ArcoFlecha.h ArcoFlecha.cpp Item.h Heroe.h Monstruo.h 
	g++ -c Arco.cpp

Bomba.o: Bomba.h Bomba.cpp Item.h Heroe.h Monstruo.h 
	g++ -c Bomba.cpp

Boomerang.o: Boomerang.h Boomerang.cpp Item.h Heroe.h Monstruo.h 
	g++ -c Boomerang.cpp

Monstruo.o: Monstruo.h Monstruo.cpp Heroe.h 
	g++ -c Monstruo.cpp

Comun.o: Comun.h Comun.cpp Heroe.h Monstruo.h 
	g++ -c Comun.cpp

Jefe.o: Jefe.h Jefe.cpp Heroe.h Monstruo.h 
	g++ -c Jefe.cpp

Semijefe.o: Semijefe.h Semijefe.cpp Monstruo.h 
	g++ -c Semijefe.cpp

