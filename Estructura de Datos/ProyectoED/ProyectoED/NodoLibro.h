#pragma once

#include <string>
#include <stdlib.h>
#include "Libro.h"

using namespace std;

class NodoLibro
{
private:
	Libro* libro;
	NodoLibro* sgte;
	NodoLibro* ante;

public:

	NodoLibro();
	NodoLibro(Libro*);

	void setSgte(NodoLibro*);
	void setAnte(NodoLibro*);

	void setLibro(Libro*);

	Libro* getLibro();
	NodoLibro* getSgte();
	NodoLibro* getAnte();


};

