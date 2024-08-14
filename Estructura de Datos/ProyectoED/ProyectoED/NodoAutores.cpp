#include "NodoAutores.h"
#include <string>

using namespace std;


NodoAutores::NodoAutores()
{
	this->nombre = "";
	this->apellido = "";
	this->sgte = NULL;
	this->ante = NULL;
	this->subLista = NULL;
}

NodoAutores::NodoAutores(string pNombre, string pApellido)
{
	this->nombre = pNombre;
	this->apellido = pApellido;
	this->sgte = NULL;
	this->ante = NULL;
	this->subLista = new SubListaT_L();
}

void NodoAutores::setAutor( string pNombre, string pApellido)
{
	this->nombre=pNombre;
	this->apellido=pApellido;;
}


void NodoAutores::setSgte(NodoAutores* ptr)
{
	this->sgte = ptr;
}

void NodoAutores::setAnte(NodoAutores* ptr)
{
	this->ante = ptr;
}

string NodoAutores::getAutor()
{
	return this->nombre + apellido;
}

string NodoAutores::getNombre()
{
	return this->nombre;
}

string NodoAutores::getApellido()
{
	return this->apellido;
}


NodoAutores* NodoAutores::getAnte()
{
	return this->ante;
}

SubListaT_L* NodoAutores::getSubLista()
{
	return this->subLista;
}

void NodoAutores::setSubLista(SubListaT_L* pSubLista)
{
	this->subLista = pSubLista;
}

NodoAutores* NodoAutores::getSgte()
{
	return this->sgte;
}
