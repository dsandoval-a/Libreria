#include "NodoLibro.h"
#include <string>
#include <stdlib.h>

using namespace std;

NodoLibro::NodoLibro()
{
	this->sgte = NULL;
	this->ante = NULL;
	this->libro = new Libro();

}

NodoLibro::NodoLibro(Libro* pLibro)
{
	this->libro = pLibro;
	this->sgte = NULL;
	this->ante = NULL;
}


void NodoLibro::setSgte(NodoLibro* pNodo)
{
	this->sgte = pNodo;
}

void NodoLibro::setAnte(NodoLibro* pAnte)
{
	this->ante = pAnte;
}

void NodoLibro::setLibro(Libro* pLibro)
{
	this->libro = pLibro;
}

Libro* NodoLibro::getLibro()
{
	return libro;
}

NodoLibro* NodoLibro::getSgte()
{
	return this->sgte;
}

NodoLibro* NodoLibro::getAnte()
{
	return this->ante;
}
