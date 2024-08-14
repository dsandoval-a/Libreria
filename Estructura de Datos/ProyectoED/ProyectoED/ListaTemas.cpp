#include "ListaTemas.h"
#include <iostream>
#include <stdlib.h>
#include "ListaLibro.h"

using namespace std;
ListaTemas::ListaTemas() {
	this->cab = NULL;
	this->largo = 0;
}

ListaTemas::~ListaTemas()
{
}

Nodo* ListaTemas::getCab()
{
	return this->cab;
}

int ListaTemas::getLargo()
{
	return this->largo;
}

void ListaTemas::setCab(Nodo* pCab)
{
	this->cab = pCab;
}

void ListaTemas::setLargo(int pLargo)
{
	this->largo = pLargo;
}

Nodo* ListaTemas::dirNodo(string pTema)
{
	int cont = 0;
	if (esVacia())
		return NULL;
	else {
		Nodo* aux = getCab();

		while (aux != NULL) {

			if (aux->getTema() == pTema)
			{
				return aux;
			}

			aux = aux->getSgte(); //permite pasar al siguiente nodo

		}

	}

	return NULL;
}

bool ListaTemas::agregarTema(string tema)
{
	bool agregado = false;
	Nodo* nuevo = new Nodo(tema);
	if (!esVacia()) {
		Nodo* aux = getCab();
		Nodo* ant = aux;

		if (getCab()->getTema() == tema) {
			return false;
		}
		else if (getCab()->getTema() > tema) {
			agregarInicio(tema);
			return true;
		}

		while (agregado == false) {

			if (aux->getTema() == tema) {
				setLargo(getLargo() + 1);
				return false;
			}
			else if (aux->getTema() > tema) {
				nuevo->setSgte(aux);
				ant->setSgte(nuevo);
				setLargo(getLargo() + 1);
				return true;
			}
			else if (aux->getTema() < tema && aux->getSgte() == NULL) {
				aux->setSgte(nuevo);
				setLargo(getLargo() + 1);
				return true;
			}

			ant = aux;
			aux = aux->getSgte();

		}
	}
	else {
		setCab(nuevo);
		setLargo(getLargo() + 1);
		return true;
	}

	return true;
}


void ListaTemas::eliminarTema(string pTema)
{
	bool removido = true;
	if (!esVacia()) {
		Nodo* aux = NULL;
		if (getCab()->getTema() == pTema) {
			aux = getCab();
			setCab(aux->getSgte());
			setLargo(getLargo() - 1);
			delete aux;
			removido = true;
		}
		else {
			Nodo* ant = dirAnterior(pTema);
			if (ant != NULL) {
				aux = ant->getSgte();
				ant->setSgte(aux->getSgte());
				setLargo(getLargo() - 1);
				delete aux;
				removido = true;
				std::cout << "Se elimino el tema: " << pTema << "\n";
			}
		}
	}
}

void ListaTemas::listarTemas()
{
	int cont = 0;
	if (esVacia())
		std::cout << "La lista está vacía...";
	else {
		Nodo* aux = getCab();

		while (aux != NULL) {

			std::cout << "El tema es: " << aux->getTema() << " con: " << aux->getSubLista()->getLargo() << " libros." << endl;

			aux = aux->getSgte(); //permite pasar al siguiente nodo
			cont++;
		}
		//std::cout << "Fin " << cont;
		std::cout << "\n";
	}
}

void ListaTemas::agregarInicio(string tema)
{
	Nodo* nuevo = new Nodo(tema);

	if (!esVacia())
		nuevo->setSgte(getCab());
	setCab(nuevo);
	setLargo(getLargo() + 1);
}

Nodo* ListaTemas::dirAnterior(string pTema)
{
	bool encontrado = false;
	Nodo* aux = NULL;
	if (getLargo() > 1) {
		aux = getCab();
		while ((aux->getSgte() != NULL) && (!encontrado)) {
			if (aux->getSgte()->getTema() == pTema)
				encontrado = true;
			else
				aux = aux->getSgte();
		}

	}

	if (encontrado)
		return aux;
	else
		return NULL;
}



bool ListaTemas::esVacia()
{
	return this->cab == NULL;
}

bool ListaTemas::modificarTema(Libro* LSL)
{

	if (esVacia())
		return false;
	else {
		Nodo* aux = getCab();
		do {
			Nodo* tema = dirNodo(LSL->getTema());
			if (tema != NULL)
			{
				return false;
			}
			else {

				bool existe = aux->getSubLista()->consultarCod(LSL->getISBN());
				if (existe)
				{
					aux->setTema(LSL->getTema());
					return true;
				}
				else {
					return false;
				}

			}
			aux = aux->getSgte();
		} while (aux != getCab());

	}

}


// Devuelve 1 si se agrego exitosamente, 2 si el tema no existe no lo agrega, 3 no lo agrega por que el libro no existe, 4 no lo agrega por que el libro ya fue agregado
int ListaTemas::agregarLibroTema(int pISBN, string pTema, ListaLibro* LSL)
{
	//Agregar dirNodo(string) Jonathan Lista tema
	Nodo* auxTema = dirNodo(pTema); //Localizamos el nodo del tema

	int valor = 0;
	//Primero busca tema
	if (auxTema == NULL) {
		valor = 2;
	}
	else {
		NodoListaT_L* auxSubL = auxTema->getSubLista()->dirNodo(pISBN);

		if (auxSubL != NULL) { //Ya existe el libro en la sub-lista
			valor = 4;
		}
		else {
			NodoLibro* auxLibro = LSL->dirNodo(pISBN); //localizar la direccion del nodo en el catalogo(ListaLibro)

			if (auxLibro == NULL) {//Si no existe en el catalogo
				valor = 3;
			}
			else {
				auxTema->getSubLista()->agregar(pISBN, auxLibro);
				valor = 1;
			}
		}

	}

	return valor;
}

int ListaTemas::eliminarLibroTema(int pISBN, string pTema, ListaLibro* LSL)
{
	Nodo* auxTema = dirNodo(pTema); //Localizamos el nodo del tema

	int valor = 0;
	//Primero busca autor
	if (auxTema == NULL) {
		valor = 2;
	}
	else {
		NodoListaT_L* auxSubL = auxTema->getSubLista()->dirNodo(pISBN);

		if (auxSubL == NULL) { //Ya no existe el libro en la sub-lista

			valor = 4;
		}
		else {
			NodoLibro* auxLibro = LSL->dirNodo(pISBN); //localizar la direccion del nodo en el catalogo(ListaLibro)

			if (auxLibro == NULL) {//Si no existe en el catalogo
				valor = 3;
			}
			else {
				auxTema->getSubLista()->eliminar(pISBN);
				valor = 1;
			}
		}

	}

	return valor;
}

void ListaTemas::desplegarLibros(string pTema)
{

	Nodo* auxTema = dirNodo(pTema); //Localizamos el nodo del tema

	int valor = 0;
	//Primero busca autor
	if (auxTema == NULL) {
		cout << "No existe el tema" << endl;
	}
	else {
		SubListaT_L* auxSubL = auxTema->getSubLista();

		if (auxSubL != NULL) {//Si no existe en el catalogo
			cout << "El tema " << pTema << " posee: " << auxTema->getSubLista()->getLargo() << " libros." << endl;

			auxSubL->desplegarLista();

		}
	}

}


