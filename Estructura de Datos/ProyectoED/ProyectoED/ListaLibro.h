#pragma once
#include "NodoLibro.h"
#include "Libro.h"
#include "ListaAutores.h"

#include <stdlib.h>
#include <iostream>

class ListaLibro
{
private:
	NodoLibro* cab;
	int largo;


public:

	ListaLibro();
	~ListaLibro();

	NodoLibro* getCab();
	int getLargo();

	void setCab(NodoLibro*);
	void setLargo(int);

	/*UTILITARIOS */

	NodoLibro* dirNodo(int);
	NodoLibro* dirAnterior(int);
	NodoLibro* dirUltimo();


	bool esVacia();

	void agregarInicio(Libro*);
	void agregarFinal(Libro*);
	bool agregarAscendente(Libro*);

	bool modificarLibro(Libro*);

	void desplegarLista();
	bool eliminar(int);

	ListaLibro* getLista();
};

