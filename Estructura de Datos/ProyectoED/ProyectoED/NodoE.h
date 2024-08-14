#pragma once
#include <stdlib.h>
#include <iostream>
#include "SubListaT_L.h"

using namespace std;

class NodoE
{
private:
	string editorial;

	NodoE* sgte;
	NodoE* ante;

	SubListaT_L* subLista;

public:
	NodoE();
	NodoE(string);

	void setDato(string);
	void setSgte(NodoE*);
	void setAnte(NodoE*);
	string getEditorial();
	NodoE* getSgte();
	NodoE* getAnte();

	SubListaT_L* getSubLista();
	void setSubLista(SubListaT_L*);
};

