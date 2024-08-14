#pragma once
#include "NodoLibro.h"
class NodoListaT_L
{

private:
	int ISBN;
	NodoListaT_L* sgte;
	NodoListaT_L* ante;

	NodoLibro* salto;

public:
	NodoListaT_L();
	NodoListaT_L(int, NodoLibro*);

	void setISBN(int);
	int getISBN();


	void setSgte(NodoListaT_L*);
	void setAnte(NodoListaT_L*);
	void setSalto(NodoLibro*);

	NodoLibro* getSalto();
	NodoListaT_L* getSgte();
	NodoListaT_L* getAnte();


};

