#pragma once
#include "NodoListaT_L.h"

class SubListaT_L
{
private:
	NodoListaT_L* cab;
	int largo;

public:

	SubListaT_L();
	~SubListaT_L();

	NodoListaT_L* getCab();
	int getLargo();

	void setCab(NodoListaT_L*);
	void setLargo(int);

	/*UTILITARIOS */

	NodoListaT_L* dirNodo(int);
	NodoListaT_L* dirAnterior(int);
	NodoListaT_L* dirUltimo();


	bool esVacia();

	void agregar(int, NodoLibro*);
	void eliminar(int);
	bool consultarCod(int);
	bool consultarLibro(NodoLibro*);
	void desplegarLista();
	void desplegarListaDetallada();

	bool existe(int);

};