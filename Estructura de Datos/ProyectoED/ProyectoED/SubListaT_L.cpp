#include "SubListaT_L.h"
#include <iostream>
SubListaT_L::SubListaT_L()
{
	this->cab = NULL;
	this->largo = 0;
}

SubListaT_L::~SubListaT_L()
{
}

NodoListaT_L* SubListaT_L::getCab()
{
	return this->cab;
}

int SubListaT_L::getLargo()
{
	return this->largo;
}

void SubListaT_L::setCab(NodoListaT_L* ptr)
{
	this->cab = ptr;
}

void SubListaT_L::setLargo(int pLargo)
{
	this->largo = pLargo;
}

NodoListaT_L* SubListaT_L::dirNodo(int pISBN)
{ //Devuelve la dirección del nodo cuyo valor sea x
	NodoListaT_L* aux = NULL;
	bool encontrado = false;

	if (!esVacia()) {
		aux = getCab();
		do {
			if (aux->getISBN() == pISBN) encontrado = true;
			else aux = aux->getSgte();
		} while (aux != getCab() && !encontrado);

	}
	if (encontrado) return aux;
	else return NULL;
}

NodoListaT_L* SubListaT_L::dirAnterior(int pISBN)
{ //Devuelve la dirección del nodo anterior al nodo cuyo valor sea x

	NodoListaT_L* anterior = NULL;

	if (!esVacia()) {
		NodoListaT_L* aux = dirNodo(pISBN);
		if (aux != NULL)
			anterior = aux->getAnte();
	}
	return anterior;
}

NodoListaT_L* SubListaT_L::dirUltimo()
{  /*Devuelve la dirección del último nodo, si la lista está vacía devuelve NULL*/

	if (!esVacia()) return getCab()->getAnte();
	else return NULL;

}


bool SubListaT_L::esVacia()
{
	return cab == NULL;
}


void SubListaT_L::agregar(int pISBN, NodoLibro* pLibro)
{   //Agrega al final de la lista un nodo con el valor de _dato
	//Si la lista está vacía siempre se agrega

	NodoListaT_L* nuevo = new NodoListaT_L(pISBN, pLibro); //Paso #1 crear el nodo

	if (esVacia()) {
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
		setCab(nuevo);
	}
	else {
		NodoListaT_L* ult = getCab()->getAnte();

		//Paso 2. Enlazar el nuevo nodo a la lista
		nuevo->setSgte(getCab());
		nuevo->setAnte(ult);

		//Paso 3. Reacomodar la lista con el nuevo nodo
		ult->setSgte(nuevo);
		getCab()->setAnte(nuevo);
	}

	setLargo(getLargo() + 1);
}



void SubListaT_L::eliminar(int pISBN)
{ //Eliminar el primer nodo cuyo valor sea igual a _dato

	NodoListaT_L* aux = dirNodo(pISBN); //Localizar el nodo de _dato
	if (aux != NULL) {
		if (getLargo() == 1) {
			setCab(NULL);
		}
		else {

			if (aux == getCab()) setCab(getCab()->getSgte());

			aux->getAnte()->setSgte(aux->getSgte());
			aux->getSgte()->setAnte(aux->getAnte());
		}
		delete aux;
		setLargo(getLargo() - 1);

	}
}

bool SubListaT_L::consultarCod(int pISBN)
{
	if (esVacia())
		return false;
	else {
		NodoListaT_L* aux = dirNodo(pISBN);
		if (aux != NULL)
		{
			return true;
		}
	}
	return false;

}

bool SubListaT_L::consultarLibro(NodoLibro* pLibro)
{
	NodoListaT_L* aux = NULL;
	bool encontrado = false;

	if (!esVacia()) {
		aux = getCab();
		do {
			if (aux->getSalto() == pLibro) encontrado = true;
			else aux = aux->getSgte();
		} while (aux != getCab() && !encontrado);

	}
	return encontrado;

}


void SubListaT_L::desplegarLista()
{
	if (esVacia())
		std::cout << "La lista está vacia...";
	else {
		NodoListaT_L* aux = getCab();
		do {
			std::cout << aux->getSalto()->getLibro()->desplegarLibro() << endl;
			aux = aux->getSgte();
		} while (aux != getCab());
		std::cout << "\nFin de la lista \n";
	}
}

bool SubListaT_L::existe(int pISBN)
{
	bool existe = false;

	if (dirNodo(pISBN) != NULL)
		existe = true;

	return existe;
}
