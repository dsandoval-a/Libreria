#pragma once

#include <stdlib.h>
#include <iostream>
#include "NodoE.h"
#include "ListaLibro.h"

class ListaEditoriales
{

private:
	NodoE* cab;
	int largo;

public:
	ListaEditoriales();
	~ListaEditoriales();

	NodoE* getCab();
	int getLargo();

	void setCab(NodoE*);
	void setLargo(int);

	/*UTILITARIOS */

	NodoE* dirNodo(string);
	NodoE* dirAnterior(string);
	NodoE* dirUltimo();

	bool esVacia();

	void agregarInicio(string);
	void agregarFinal(string);
	bool agregarAntesDe(string, string);
	bool agregarDespuesDe(string, string);
	bool agregarEditorial(string);
	bool eliminar(string);

	void desplegarLista();

	bool modificarEditorial(Libro*);

	//Sublista
	int agregarLibroEditorial(int, string, ListaLibro*);
	int eliminarLibroEditorial(int, string, ListaLibro*);
	void desplegarLibros(string);
};

