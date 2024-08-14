#pragma once
#include <stdlib.h>
#include <iostream>

#include <string>
#include "SubListaT_L.h"

class NodoAutores
{

private:
	string nombre;
	string apellido;
	NodoAutores* sgte;
	NodoAutores* ante;

	SubListaT_L* subLista;


public:
	NodoAutores();
	NodoAutores(string, string);

	void setAutor(string, string);
	string getAutor();
	string getNombre();
	string getApellido();

	void setSgte(NodoAutores*);
	void setAnte(NodoAutores*);

	NodoAutores* getSgte();
	NodoAutores* getAnte();

	SubListaT_L* getSubLista();
	void setSubLista(SubListaT_L*);
};

