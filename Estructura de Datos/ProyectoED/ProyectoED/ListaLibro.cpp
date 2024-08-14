#include "ListaLibro.h"

using namespace std;

ListaLibro::ListaLibro()
{
	this->cab = NULL;
	this->largo = 0;
}

ListaLibro::~ListaLibro()
{
}

NodoLibro* ListaLibro::getCab()
{
	return this->cab;
}

int ListaLibro::getLargo()
{
	return this->largo;
}

void ListaLibro::setCab(NodoLibro* ptr)
{
	this->cab = ptr;
}

void ListaLibro::setLargo(int pLargo)
{
	this->largo = pLargo;
}

NodoLibro* ListaLibro::dirNodo(int pISBN)
{ //Devuelve la dirección del nodo cuyo valor sea x
	NodoLibro* aux = NULL;
	bool encontrado = false;

	if (!esVacia()) {
		aux = getCab();
		do {
			if (aux->getLibro()->getISBN() == pISBN) encontrado = true;
			else aux = aux->getSgte();
		} while (aux != getCab() && !encontrado);

	}
	if (encontrado) return aux;
	else return NULL;
}

NodoLibro* ListaLibro::dirAnterior(int pISBN)
{ //Devuelve la dirección del nodo anterior al nodo cuyo valor sea x

	NodoLibro* anterior = NULL;

	if (!esVacia()) {
		NodoLibro* aux = dirNodo(pISBN);
		if (aux != NULL)
			anterior = aux->getAnte();
	}
	return anterior;
}

NodoLibro* ListaLibro::dirUltimo()
{  /*Devuelve la dirección del último nodo, si la lista está vacía devuelve NULL*/

	if (!esVacia()) return getCab()->getAnte();
	else return NULL;

}


bool ListaLibro::esVacia()
{
	return cab == NULL;
}


void ListaLibro::agregarInicio(Libro* pLibro)
{
	agregarFinal(pLibro);
	//Paso 3. Reacomodar la lista con el nuevo nodo
	if (getLargo() > 1) setCab(getCab()->getAnte());

}

void ListaLibro::agregarFinal(Libro* pLibro)
{   //Agrega al final de la lista un nodo con el valor de _dato
	//Si la lista está vacía siempre se agrega

	NodoLibro* nuevo = new NodoLibro(pLibro); //Paso #1 crear el nodo

	if (esVacia()) {
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
		setCab(nuevo);
	}
	else {
		NodoLibro* ult = getCab()->getAnte();

		//Paso 2. Enlazar el nuevo nodo a la lista
		nuevo->setSgte(getCab());
		nuevo->setAnte(ult);

		//Paso 3. Reacomodar la lista con el nuevo nodo
		ult->setSgte(nuevo);
		getCab()->setAnte(nuevo);
	}

	setLargo(getLargo() + 1);
}


bool ListaLibro::agregarAscendente(Libro* pLibro)
{  //Ir agregando los datos a la lista en forma ascendente, es decir, de menor a mayor
	//Si el dato ya existe, no se agrega, retorna false
	bool agregado = false;
	bool repetido = false;
	NodoLibro* nuevo = new NodoLibro(pLibro);//Paso #1, crear el nodo
	if (esVacia()) {
		
		//Paso #2, enlazar el nuevo a la lista
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
		//Paso #3, Reacomodar la lista con el nuevo nodo
		setCab(nuevo);
		setLargo(1);
		agregado = true;
		
	}
	else {

		if (pLibro->getISBN() < getCab()->getLibro()->getISBN()) {
			agregarInicio(pLibro);
			agregado = true;
		}
		else {
			if (pLibro->getISBN() > getCab()->getAnte()->getLibro()->getISBN()) {
				agregarFinal(pLibro);
				agregado = true;
			}
			else {
				NodoLibro* aux = getCab();
				do {
					if (pLibro->getISBN() == aux->getLibro()->getISBN())
						repetido = true;
					else if (pLibro->getISBN() > aux->getSgte()->getLibro()->getISBN()) {
						//Paso #2: Enlazar el nuevo a la lista
						nuevo->setSgte(aux->getSgte());
						nuevo->setAnte(aux);
						//Paso #3: Reacomodar la lista con el nuevo nodo
						aux->getSgte()->setAnte(nuevo);
						aux->setSgte(nuevo);
						setLargo(getLargo() + 1);
						agregado = true;

					}
					else {
						aux = aux->getSgte();
					}
				} while (aux != getCab() && !repetido && !agregado);
			}

		}
	}
	if (repetido)
		cout << "Ya existe el ISBN";

	return agregado;
}

bool ListaLibro::modificarLibro(Libro* pLibro)
{
	string mensaje = "";
	NodoLibro temp = pLibro;
	if (!esVacia())
	{
		NodoLibro* aux = getCab();
		do {
			if (pLibro->getISBN() == aux->getLibro()->getISBN())
				mensaje = aux->getLibro()->modificarLibro(pLibro);
			else {
				aux = aux->getSgte();
			}
		} while (aux != getCab());
	}

	if (mensaje == "")
		return false;
	else {

		cout << mensaje;
		return true;

	}
}


bool ListaLibro::eliminar(int pISBN)
{ //Eliminar el primer nodo cuyo valor sea igual a _dato
	bool removido = false;

	NodoLibro* aux = dirNodo(pISBN); //Localizar el nodo de _dato
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
		removido = true;

	}
	return removido;
}

ListaLibro* ListaLibro::getLista()
{

	return this;
}

void ListaLibro::desplegarLista()
{
	if (esVacia())
		cout << "La lista está vacia...";
	else {
		NodoLibro* aux = getCab();
		do {
			cout << aux->getLibro()->desplegarLibro() + "\n";
			aux = aux->getSgte();
		} while (aux != getCab());
		cout << "\nFin de la lista \n";
	}
}