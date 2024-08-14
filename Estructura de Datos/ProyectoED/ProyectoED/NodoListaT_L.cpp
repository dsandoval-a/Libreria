#include "NodoListaT_L.h"
using namespace std;


NodoListaT_L::NodoListaT_L()
{
	this->ISBN = 0;
	this->sgte = NULL;
	this->ante = NULL;
	this->salto = NULL;
}

NodoListaT_L::NodoListaT_L(int pISBN, NodoLibro *pSalto)
{
	this->ISBN = pISBN;
	this->sgte = NULL;
	this->ante = NULL;
	this->salto = pSalto;
}

void NodoListaT_L::setISBN(int pISBN)
{
	this->ISBN = pISBN;
}


void NodoListaT_L::setSgte(NodoListaT_L* ptr)
{
	this->sgte = ptr;
}

void NodoListaT_L::setAnte(NodoListaT_L* ptr)
{
	this->ante = ptr;
}

void NodoListaT_L::setSalto(NodoLibro* pSalto)
{
	this->salto = pSalto;
}


int NodoListaT_L::getISBN()
{
	return this->ISBN;
}


NodoListaT_L* NodoListaT_L::getAnte()
{
	return this->ante;
}

NodoLibro* NodoListaT_L::getSalto()
{
	return this->salto;
}

NodoListaT_L* NodoListaT_L::getSgte()
{
	return this->sgte;
}
