#include "ListaEditoriales.h"
ListaEditoriales::ListaEditoriales()
{
	this->cab = NULL;
	this->largo = 0;
}

ListaEditoriales::~ListaEditoriales()
{
}

NodoE* ListaEditoriales::getCab()
{
	return this->cab;
}

int ListaEditoriales::getLargo()
{
	return this->largo;
}

void ListaEditoriales::setCab(NodoE* ptr)
{
	this->cab = ptr;
}

void ListaEditoriales::setLargo(int pLargo)
{
	this->largo = pLargo;
}

NodoE* ListaEditoriales::dirNodo(string pEditorial)
{ //Devuelve la dirección del nodo cuyo valor sea _dato
	NodoE* aux = NULL;

	if (!esVacia()) {
		aux = getCab();
		while (aux != NULL && (aux->getEditorial() != pEditorial)) {
			aux = aux->getSgte();
		}
	}
	return aux;

}

NodoE* ListaEditoriales::dirAnterior(string pEditorial)
{ //Devuelve la dirección del nodo anterior al nodo cuyo valor sea _dato
	NodoE* anterior = NULL;

	if (!esVacia()) {
		anterior = dirNodo(pEditorial)->getAnte();
	}

	return anterior;
}

NodoE* ListaEditoriales::dirUltimo()
{  /*Devuelve la dirección del último nodo, si la lista está vacía devuelve NULL*/

	if (!esVacia()) {
		NodoE* aux = getCab();
		NodoE* aux2 = NULL;
		while (aux->getSgte() != NULL) {
			aux2 = aux->getSgte();
			aux = aux2;
		}
		return aux;
	}
	else {
		return NULL;
	}

}

bool ListaEditoriales::esVacia()
{
	return cab == NULL;
}

void ListaEditoriales::agregarInicio(string pEditorial)
{
	NodoE* nuevo = new NodoE(pEditorial); //Paso #1 crear el nodo

	if (!esVacia()) {
		//Paso #2 Enlazar el nuevo nodo a la lista
		nuevo->setSgte(getCab());
		//Paso #3 Reacomodar la lista con el nuevo nodo
		getCab()->setAnte(nuevo);
	}

	setCab(nuevo);
	setLargo(getLargo() + 1);

}

void ListaEditoriales::agregarFinal(string pEditorial)
{   //Agrega al final de la lista un nodo con el valor de _dato

	//Paso #1 crear el nodo
	NodoE* nuevo = new NodoE(pEditorial);

	if (esVacia()) {
		//Paso #3 Reacomodar la lista con el nuevo nodo
		setCab(nuevo);
	}
	else {
		//Paso #2 Enlazar el nuevo nodo a la lista
		NodoE* ult = dirUltimo();
		nuevo->setAnte(ult);
		//Paso #3 Reacomodar la lista con el nuevo nodo
		ult->setSgte(nuevo);
	}
	setLargo(getLargo() + 1);
}

bool ListaEditoriales::agregarAntesDe(string pEditorial, string _ref)
{ //Agregar un nodo con el valor _dato antes de nodo cuyo valor sea _ref
	bool agregado = false;
	NodoE* aux = dirNodo(_ref);

	if (aux != NULL) { //encontró a ref
		if (aux == getCab())
			agregarInicio(pEditorial);
		else {
			NodoE* ant = aux->getAnte();
			//Paso #1. Crear el nodo
			NodoE* nuevo = new NodoE(pEditorial);
			//Paso #2. Enlazar el nuevo nodo a la lista
			nuevo->setSgte(aux);
			nuevo->setAnte(ant);
			//Paso #3. Reacomodar la lista con el nuevo nodo.
			ant->setSgte(nuevo);
			aux->setAnte(nuevo);
			setLargo(this->largo + 1);
		}
		agregado = true;

	}
	return agregado;

}

bool ListaEditoriales::agregarDespuesDe(string pEditorial, string _ref)
{
	//Agregar un nodo con el valor _dato despues de nodo cuyo valor sea _ref
	bool agregado = false;
	NodoE* aux = dirNodo(_ref);

	if (aux != NULL) { //encontró a ref
		if (aux == getCab())
			agregarInicio(pEditorial);
		else {
			NodoE* ant = aux->getSgte();
			if (ant == NULL)
			{
				agregarFinal(pEditorial);
			}
			else {
	//Paso #1. Crear el nodo
			NodoE* nuevo = new NodoE(pEditorial);
			//Paso #2. Enlazar el nuevo nodo a la lista
			nuevo->setAnte(aux);
			nuevo->setSgte(ant);
			//Paso #3. Reacomodar la lista con el nuevo nodo.
			ant->setAnte(nuevo);
			aux->setSgte(nuevo);
			setLargo(this->largo + 1);
			}
		}
		agregado = true;
	}
	return agregado;
}

bool ListaEditoriales::agregarEditorial(string pEditorial)
{
	//Ir agregando los datos a la lista en forma ascendente, es decir, de menor a mayor
   //Si el dato ya existe, no se agrega, retorna false
	bool agregado = false;
	bool repetido = false;
	if (esVacia()) {
		NodoE* nuevo = new NodoE(pEditorial);//Paso #1, crear el nodo
		//Paso #2, enlazar el nuevo a la lista
		nuevo->setSgte(NULL);
		nuevo->setAnte(NULL);
		//Paso #3, Reacomodar la lista con el nuevo nodo
		setCab(nuevo);
		setLargo(1);
		agregado = true;
	}
	else {

		if (pEditorial[0] < getCab()->getEditorial()[0]) {
			agregarInicio(pEditorial);
			agregado = true;
		}
		else {
			if (pEditorial[0] > dirUltimo()->getEditorial()[0]) {
				agregarFinal(pEditorial);
				agregado = true;
			}
			else {
				NodoE* aux = getCab();
				do {
					if (pEditorial[0] == aux->getEditorial()[0])
						repetido = true;
					else if (pEditorial[0] > aux->getEditorial()[0]) {
						NodoE* nuevo = new NodoE(pEditorial);  //Paso #1 crear el nuevo nodo
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
		std::cout << "Ya existe el autor";

	return agregado;

}

bool ListaEditoriales::eliminar(string pEditorial)
{ //Eliminar el primer nodo cuyo valor sea igual a _dato
	bool removido = false;

	NodoE* aux = dirNodo(pEditorial); //Paso #1: Apunte el nodo a eliminar

	if (aux != NULL) {

		//Paso #2: reacomodar la lista sin el nodo
		if (aux->getAnte() != NULL)
			aux->getAnte()->setSgte(aux->getSgte());
		if (aux->getSgte() != NULL)
			aux->getSgte()->setAnte(aux->getAnte());
		if (aux == getCab()) {
			if (this->largo == 0) setCab(NULL);
			else setCab(getCab()->getSgte());
		}

		//Paso #3: Eliminar el nodo
		delete aux;
		setLargo(getLargo() - 1);

		removido = true;
	}

	return removido;

}

void ListaEditoriales::desplegarLista()
{

	if (esVacia())
		std::cout << "La lista está vacía...";
	else {
		NodoE* aux = getCab();
		while (aux != NULL) {
			std::cout << aux->getEditorial() << "-";
			aux = aux->getSgte(); //permite pasar al siguiente nodo
		}
		std::cout << " \nFin de la lista \n";

	}
}

bool ListaEditoriales::modificarEditorial(Libro* LSL)
{

	if (esVacia())
		return false;
	else {
		NodoE* aux = getCab();
		do {
			NodoE* editorial = dirNodo(LSL->getEditorial());
			if (editorial != NULL)
			{
				return false;
			}
			else {

				bool existe = aux->getSubLista()->consultarCod(LSL->getISBN());
				if (existe)
				{
					aux->setDato(LSL->getEditorial());
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
// Devuelve 1 si se agrego exitosamente, 2 si la eeditorial no existe no lo agrega, 3 no lo agrega por que el libro no existe, 4 no lo agrega por que el libro ya fue agregado
int ListaEditoriales::agregarLibroEditorial(int pISBN, string pEditorial, ListaLibro* LSL)
{
	
	NodoE* auxEdit = dirNodo(pEditorial); //Localizamos el nodo del tema

	int valor = 0;
	//Primero busca tema
	if (auxEdit == NULL) {
		valor = 2;
	}
	else {
		NodoListaT_L* auxSubL = auxEdit->getSubLista()->dirNodo(pISBN);

		if (auxSubL != NULL) { //Ya existe el libro en la sub-lista
			valor = 4;
		}
		else {
			NodoLibro* auxLibro = LSL->dirNodo(pISBN); //localizar la direccion del nodo en el catalogo(ListaLibro)

			if (auxLibro == NULL) {//Si no existe en el catalogo
				valor = 3;
			}
			else {
				auxEdit->getSubLista()->agregar(pISBN, auxLibro);
				valor = 1;
			}
		}

	}

	return valor;
}

int ListaEditoriales::eliminarLibroEditorial(int pISBN, string pTema, ListaLibro* LSL)
{
	NodoE* auxEdit = dirNodo(pTema); //Localizamos el nodo del tema

	int valor = 0;
	//Primero busca autor
	if (auxEdit == NULL) {
		valor = 2;
	}
	else {
		NodoListaT_L* auxSubL = auxEdit->getSubLista()->dirNodo(pISBN);

		if (auxSubL == NULL) { //Ya no existe el libro en la sub-lista

			valor = 4;
		}
		else {
			NodoLibro* auxLibro = LSL->dirNodo(pISBN); //localizar la direccion del nodo en el catalogo(ListaLibro)

			if (auxLibro == NULL) {//Si no existe en el catalogo
				valor = 3;
			}
			else {
				auxEdit->getSubLista()->eliminar(pISBN);
				valor = 1;
			}
		}

	}

	return valor;
}

void ListaEditoriales::desplegarLibros(string pTema)
{

	NodoE* auxEdit= dirNodo(pTema); //Localizamos el nodo del tema

	int valor = 0;
	//Primero busca autor
	if (auxEdit == NULL) {
		cout << "No existe el tema" << endl;
	}
	else {
		SubListaT_L* auxSubL = auxEdit->getSubLista();

		if (auxSubL != NULL) {//Si no existe en el catalogo
			cout << "La editorial " << pTema << " posee: " << auxEdit->getSubLista()->getLargo() << " libros." << endl;

			auxSubL->desplegarLista();

		}
	}

}