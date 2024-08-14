#include "NodoE.h"
NodoE::NodoE()
{
	this->editorial = "";
	this->sgte = NULL;
	this->ante = NULL;
	this->subLista = NULL;
}

NodoE::NodoE(string pEditorial)
{
	this->editorial = pEditorial;
	this->sgte = NULL;
	this->ante = NULL;
	this->subLista = new SubListaT_L();

}

void NodoE::setDato(string pEditorial)
{
	this->editorial = pEditorial;
}

void NodoE::setSgte(NodoE* ptr)
{
	this->sgte = ptr;
}

void NodoE::setAnte(NodoE* ptr)
{
	this->ante = ptr;
}

string NodoE::getEditorial()
{
	return this->editorial;
}

NodoE* NodoE::getAnte()
{
	return this->ante;
}

NodoE* NodoE::getSgte()
{
	return this->sgte;
}

SubListaT_L* NodoE::getSubLista()
{
	return this->subLista;
}

void NodoE::setSubLista(SubListaT_L* pSubLista)
{
	this->subLista = pSubLista;
}