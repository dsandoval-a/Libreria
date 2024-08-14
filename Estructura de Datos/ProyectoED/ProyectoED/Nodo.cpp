#include "Nodo.h"

Nodo::Nodo()
{
	this->tema = "Prueba";
	this->sgte = NULL;
	this->subLista = NULL;
}

Nodo::Nodo(string pTema)
{
	this->tema = pTema;
	this->sgte = NULL;
	this->subLista = new SubListaT_L();
}

void Nodo::setTema(string pTema)
{
	this->tema = pTema;
}

void Nodo::setSgte(Nodo* ptr)
{
	this->sgte = ptr;
}

string Nodo::getTema()
{
	return this->tema;
}

Nodo* Nodo::getSgte()
{
	return this->sgte;
}

SubListaT_L* Nodo::getSubLista()
{
	return this->subLista;
}

void Nodo::setSubLista(SubListaT_L* pSubLista)
{
	this->subLista = pSubLista;
}

