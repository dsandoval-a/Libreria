#pragma once
#include "nodo.h"
#include "SubListaT_L.h"
#include "ListaLibro.h"

class ListaTemas
{
private:
	Nodo* cab;
	int largo;

public:
	ListaTemas();
	~ListaTemas();

	Nodo* getCab();
	int getLargo();

	void setCab(Nodo*);
	void setLargo(int);
	Nodo* dirNodo(string);
	Nodo* dirAnterior(string);

	bool agregarTema(string);
	void eliminarTema(string);
	void listarTemas();
	void agregarInicio(string);
	
	
	bool esVacia();
	bool modificarTema(Libro*);

	//Sublista
	int agregarLibroTema(int, string, ListaLibro*);
	int eliminarLibroTema(int, string, ListaLibro*);
	void desplegarLibros(string);
};

