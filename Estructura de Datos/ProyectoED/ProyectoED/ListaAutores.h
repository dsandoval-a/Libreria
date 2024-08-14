#pragma once

#include <stdlib.h>
#include <iostream>

#include "NodoAutores.h"
class ListaLibro;

using namespace std;

class ListaAutores
{

private:
	NodoAutores* cab;
	int largo;

public:

	ListaAutores();
	~ListaAutores();

	NodoAutores* getCab();
	int getLargo();

	void setCab(NodoAutores*);
	void setLargo(int);

	/*UTILITARIOS */

	NodoAutores* dirNodo(string, string);
	NodoAutores* dirAnterior(string, string);
	NodoAutores* dirUltimo();


	bool esVacia();

	void agregarInicio(string, string);
	void agregarFinal(string, string);
	int agregarAscendente(string, string);

	void desplegarLista();
	bool eliminar(string, string);
	bool modificarAutores(Libro*);

	//Sublista
	int agregarLibroAutor(int, string, string, ListaLibro*);
	int eliminarLibroAutor(int, string, string, ListaLibro*);
	void desplegarLibros(string, string);
};

