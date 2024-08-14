#pragma once
#include <iostream>
#include <stdlib.h>
#include "SubListaT_L.h"

class Nodo
{
private:
	string tema;
	Nodo* sgte;

	SubListaT_L* subLista;

public:
	Nodo();
	Nodo(string);

	void setTema(string);
	void setSgte(Nodo*);

	string getTema();
	int getCantLibros();
	Nodo* getSgte();

	SubListaT_L* getSubLista();
	void setSubLista(SubListaT_L*);

};
