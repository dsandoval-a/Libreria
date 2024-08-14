#include "ListaAutores.h"
#include "NodoListaT_L.h"
#include "ListaTemas.h"

ListaAutores::ListaAutores()
{
	this->cab = NULL;
	this->largo = 0;
}

ListaAutores::~ListaAutores()
{
}

NodoAutores* ListaAutores::getCab()
{
	return this->cab;
}

int ListaAutores::getLargo()
{
	return this->largo;
}

void ListaAutores::setCab(NodoAutores* ptr)
{
	this->cab = ptr;
}

void ListaAutores::setLargo(int pLargo)
{
	this->largo = pLargo;
}

NodoAutores* ListaAutores::dirNodo(string pNombre, string pApellido)
{ //Devuelve la dirección del nodo cuyo valor sea x
	NodoAutores* aux = NULL;
	bool encontrado = false;

	if (!esVacia()) {
		aux = getCab();
		do {
			if (aux->getNombre() == pNombre && aux->getApellido() == pApellido) encontrado = true;
			else aux = aux->getSgte();
		} while (aux != getCab() && !encontrado);

	}
	if (encontrado) return aux;
	else return NULL;
}

NodoAutores* ListaAutores::dirAnterior(string pNombre, string pApellido)
{ //Devuelve la dirección del nodo anterior al nodo cuyo valor sea x

	NodoAutores* anterior = NULL;

	if (!esVacia()) {
		NodoAutores* aux = dirNodo(pNombre, pApellido);
		if (aux != NULL)
			anterior = aux->getAnte();
	}
	return anterior;
}

NodoAutores* ListaAutores::dirUltimo()
{  /*Devuelve la dirección del último nodo, si la lista está vacía devuelve NULL*/

	if (!esVacia()) return getCab()->getAnte();
	else return NULL;

}


bool ListaAutores::esVacia()
{
	return cab == NULL;
}


void ListaAutores::agregarInicio(string pNombre, string pApellido)
{
	agregarFinal(pNombre, pApellido);
	//Paso 3. Reacomodar la lista con el nuevo nodo
	if (getLargo() > 1) setCab(getCab()->getAnte());

}

void ListaAutores::agregarFinal(string pNombre, string pApellido)
{   //Agrega al final de la lista un nodo con el valor de _dato
	//Si la lista está vacía siempre se agrega

	NodoAutores* nuevo = new NodoAutores(pNombre, pApellido); //Paso #1 crear el nodo

	if (esVacia()) {
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
		setCab(nuevo);
	}
	else {
		NodoAutores* ult = getCab()->getAnte();

		//Paso 2. Enlazar el nuevo nodo a la lista
		nuevo->setSgte(getCab());
		nuevo->setAnte(ult);

		//Paso 3. Reacomodar la lista con el nuevo nodo
		ult->setSgte(nuevo);
		getCab()->setAnte(nuevo);
	}

	setLargo(getLargo() + 1);
}


int ListaAutores::agregarAscendente(string pNombre, string pApellido)
{  //Ir agregando los datos a la lista en forma ascendente, es decir, de menor a mayor
	//Si el dato ya existe, no se agrega, retorna false
	bool agregado = false;
	bool repetido = false;
	NodoAutores* nuevo = new NodoAutores( pNombre, pApellido);  //Paso #1 crear el nuevo nodo
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

		if (pNombre[0] < getCab()->getNombre()[0]) {
			agregarInicio(pNombre, pApellido);
			agregado = true;
		}
		else {
			if (pNombre[0] > getCab()->getAnte()->getNombre()[0]) {
				agregarFinal(pNombre, pApellido);
				agregado = true;
			}
			else {
				NodoAutores* aux = getCab();
				do {
					if (pNombre[0] == aux->getNombre()[0] && pApellido[0] == aux->getApellido()[0])
						repetido = true;
					else if (pNombre[0] > aux->getSgte()->getNombre()[0]) {

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

	return 0;
}


bool ListaAutores::eliminar(string pNombre, string pApellido)
{ //Eliminar el primer nodo cuyo valor sea igual a _dato
	bool removido = false;
	NodoAutores* aux = dirNodo(pNombre, pApellido); //Localizar el nodo de _dato
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

bool ListaAutores::modificarAutores(Libro* LSL)
{

	if (esVacia())
		return false;
	else {
		NodoAutores* aux = getCab();
		do {
			NodoAutores* autor = dirNodo(LSL->getNombreAutor(), LSL->getApellidoAutor());
			if (autor != NULL)
			{
				return false;
			}
			else {

				bool existe = aux->getSubLista()->consultarCod(LSL->getISBN());
				if (existe)
				{
					aux->setAutor(LSL->getNombreAutor(), LSL->getApellidoAutor());
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

// Devuelve 1 si se agrego exitosamente, 2 si el autor no existe no lo agrega, 3 no lo agrega por que el libro no existe, 4 no lo agrega por que el libro ya fue agregado
int ListaAutores::agregarLibroAutor(int pISBN, string pNombre, string pApellido, ListaLibro* LSL)
{
	NodoAutores* auxAutor = dirNodo(pNombre, pApellido); //Localizamos el nodo del autor

	int valor = 0;
	//Primero busca autor
	if (auxAutor == NULL) {
		valor = 2;
	}
	else {
		NodoListaT_L* auxSubL = auxAutor->getSubLista()->dirNodo(pISBN);

		if (auxSubL != NULL) { //Ya existe el libro en la sub-lista
			valor = 4;
		}
		else {
			NodoLibro* auxLibro = LSL->dirNodo(pISBN); //localizar la direccion del nodo en el catalogo(ListaLibro)

			if (auxLibro == NULL) {//Si no existe en el catalogo
				valor = 3;
			}
			else {
				auxAutor->getSubLista()->agregar(pISBN, auxLibro);
				valor = 1;
			}
		}

	}

	return valor;
}
// Devuelve 1 si se elimina exitosamente, 2 si el autor no existe no lo elimina, 3 no lo elimina por que el libro no existe, 4 no lo agrega por que el libro no esta en la lista

int ListaAutores::eliminarLibroAutor(int pISBN, string pNombre, string pApellido, ListaLibro* LSL)
{
	NodoAutores* auxAutor = dirNodo(pNombre, pApellido); //Localizamos el nodo del autor

	int valor = 0;
	//Primero busca autor
	if (auxAutor == NULL) {
		valor = 2;
	}
	else {
		NodoListaT_L* auxSubL = auxAutor->getSubLista()->dirNodo(pISBN);

		if (auxSubL == NULL) { //Ya no existe el libro en la sub-lista

			valor = 4;
		}
		else {
			NodoLibro* auxLibro = LSL->dirNodo(pISBN); //localizar la direccion del nodo en el catalogo(ListaLibro)

			if (auxLibro == NULL) {//Si no existe en el catalogo
				valor = 3;
			}
			else {
				auxAutor->getSubLista()->eliminar(pISBN);
				valor = 1;
			}
		}

	}

	return valor;
}

void ListaAutores::desplegarLista()
{
	if (esVacia())
		std::cout << "La lista está vacia...";
	else {
		NodoAutores* aux = getCab();
		do {
			std::cout << aux->getNombre() << " " << aux->getApellido() << "-" << "con: " << aux->getSubLista()->getLargo() << " Libros";
			aux = aux->getSgte();
		} while (aux != getCab());
		std::cout << "\nFin de la lista \n";
	}
}

void ListaAutores::desplegarLibros(string pNombre, string pApellido)
{

	NodoAutores* auxAutores = dirNodo(pNombre, pApellido); //Localizamos el nodo del tema

	int valor = 0;
	//Primero busca autor
	if (auxAutores == NULL) {
		cout << "No existe el tema" << endl;
	}
	else {

		SubListaT_L* auxSubL = auxAutores->getSubLista();

		if (auxSubL != NULL) {//Si no existe en el catalogo
			cout << "El autor " << pNombre << " " << pApellido << " posee: " << auxAutores->getSubLista()->getLargo() << " libros." << endl;
			auxSubL->desplegarLista();

		}
	}

}