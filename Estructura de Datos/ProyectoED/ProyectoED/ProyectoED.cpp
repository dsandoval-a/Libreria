
#include <stdlib.h>
#include <iostream>
#include <string>

#include "ListaAutores.h"
#include "ListaEditoriales.h"	
#include "ListaTemas.h"	
#include "ListaLibro.h"	
#include "Libro.h"

using namespace std;
ListaLibro* LSL = new ListaLibro();
ListaAutores* LSA = new ListaAutores();
ListaEditoriales* LSE = new ListaEditoriales();
ListaTemas* LST = new ListaTemas();
void menuAutores() {

	int opc = -1;
	string nombre = "", apellidos = "";
	while (opc != 0) {
		cout << "      MENU" << endl;
		cout << "(1) Agregar Autor" << endl;
		cout << "(2) Eliminar Autor" << endl;
		cout << "(3) Listar los libros de un Autor" << endl;
		cout << "(11) Desplegar la lista" << endl;
		cout << "(0) Finalizar" << endl;
		cout << "Opción seleccionada ->";
		cin >> opc;
		switch (opc) {
		case 1: {
			cout << "Ingrese el nombre de la persona" << endl;
			cin >> nombre;

			cin.ignore();
			cout << "Ingrese los apellidos de la persona" << endl;
			getline(cin, apellidos);

			LSA->agregarAscendente(nombre, apellidos);

			break;
		}
		case 2: {
			cout << "Ingrese el nombre de la persona" << endl;
			cin >> nombre;

			cin.ignore();
			cout << "Ingrese los apellidos de la persona" << endl;
			getline(cin, apellidos);

			if (LSA->eliminar(nombre, apellidos))
				cout << "El numero " << nombre << " " << apellidos << " ha sido eliminado exitosamente" << endl;
			else
				cout << "El numero " << nombre << " " << apellidos << " no está en la lista" << endl;
			break;
		}
		case 3: {
			cout << "Ingrese el nombre" << endl;
			cin >> nombre;
			cin.ignore();
			cout << "Ingrese los apellidos de la persona" << endl;
			getline(cin, apellidos);

			LSA->desplegarLibros(nombre, apellidos);


			break;
		}

		case 11:
			cout << "Desplegando los valores de la lista" << endl;
			LSA->desplegarLista();
			break;

		case 0:
			cout << "Finalizando el lista autores ";
			break;
		default:
			cout << "Opcion no válida..." << endl;
		}
	}
}

void menuEditorial() {

	int opc = -1;
	string editorial = "";
	while (opc != 0) {
		cout << "      MENU" << endl;
		cout << "(1) Agregar Editorial" << endl;
		cout << "(2) Eliminar Editorial" << endl;
		cout << "(11) Desplegar la lista" << endl;
		cout << "(0) Finalizar" << endl;
		cout << "Opción seleccionada ->";
		cin >> opc;
		switch (opc) {
		case 1: {
			cout << "Ingrese el nombre de la editorial" << endl;
			cin >> editorial;

			LSE->agregarEditorial(editorial);

			break;
		}
		case 2: {
			cout << "Ingrese el nombre de la persona" << endl;
			cin >> editorial;


			if (LSE->eliminar(editorial))
				cout << "La editorial " << editorial << " ha sido eliminado exitosamente" << endl;
			else
				cout << "La editorial " << editorial << " no se encuentra en la lista" << endl;
			break;
		}

		case 11:
			cout << "Desplegando los valores de la lista" << endl;
			LSE->desplegarLista();
			break;

		case 0:
			cout << "Finalizando lista editorial ";
			break;
		default:
			cout << "Opcion no válida..." << endl;
		}
	}
}

void menuTemas() {

	int opc = -1;
	string tema = "";
	while (opc != 0) {
		cout << "      MENU" << endl;
		cout << "(1) Agregar Tema" << endl;
		cout << "(2) Eliminar Tema" << endl;
		cout << "(3) Listar los libros de un tema" << endl;
		cout << "(11) Desplegar la lista" << endl;
		cout << "(0) Finalizar" << endl;
		cout << "Opción seleccionada ->";
		cin >> opc;
		switch (opc) {
		case 1: {
			cout << "Ingrese el nuevo tema" << endl;
			cin >> tema;

			LST->agregarTema(tema);

			break;
		}
		case 2: {
			cout << "Ingrese el tema" << endl;
			cin >> tema;

			LST->eliminarTema(tema);

			break;
		}
		case 3: {
			cout << "Ingrese el tema" << endl;
			cin >> tema;

			LST->desplegarLibros(tema);

			break;
		}
		case 11:
			cout << "Desplegando los valores de la lista" << endl;
			LST->listarTemas();

			break;

		case 0:
			cout << "Finalizando lista editorial ";
			break;
		default:
			cout << "Opcion no válida..." << endl;
		}
	}
}

void menuLibros() {


	int opc = -1, isbn = 0;
	string nombre = "", idioma = "", precio = "", fecha = "", nombreAu = "", apellido = "", tema = "", editorial = "";
	while (opc != 0) {
		cout << "      MENU" << endl;
		cout << "(1) Agregar Libro" << endl;
		cout << "(2) Eliminar Libro" << endl;
		cout << "(3) Modificar Libro" << endl;
		cout << "(11) Desplegar la lista de libro" << endl;
		cout << "(0) Finalizar" << endl;
		cout << "Opción seleccionada ->";
		cin >> opc;
		switch (opc) {
		case 1: {
			/*cout << "Ingrese el ISBN del libro" << endl;
			cin >> isbn;

			cin.ignore();
			cout << "Ingrese el nuevo libro" << endl;
			cin >> nombre;

			cin.ignore();
			cout << "Ingrese el idioma del libro" << endl;
			getline(cin, idioma);

			cin.ignore();
			cout << "Ingrese el precio del libro" << endl;
			getline(cin, precio);

			cin.ignore();

			cout << "Ingrese la fecha de publicacion del libro" << endl;
			getline(cin, fecha);

			cin.ignore();
			cout << "Ingrese el nombre del autor del libro" << endl;
			getline(cin, nombreAu);

			cin.ignore();
			cout << "Ingrese el apellido del autor del libro" << endl;
			getline(cin, apellido);

			cin.ignore();
			cout << "Ingrese el tema del libro" << endl;
			getline(cin, tema);

			cin.ignore();
			cout << "Ingrese el editorial del libro" << endl;
			getline(cin, editorial);*/
			isbn = 154;
			nombre = "Potter";
			idioma = "Ingles";
			precio = "25000";
			fecha = "25/05/2009";
			nombreAu = "J";
			apellido = "Marion";
			tema = "Drama";
			editorial = "Edu";


			Libro* libro = new Libro(isbn, nombre, idioma, precio, fecha, 1, nombreAu, apellido, tema, editorial);
			LST->agregarTema(tema);
			LSA->agregarAscendente(nombreAu, apellido);
			LSL->agregarAscendente(libro);
			LSE->agregarEditorial(editorial);
			int respuestaTemas = LST->agregarLibroTema(isbn, tema, LSL);
			int respuestaAutores = LSA->agregarLibroAutor(isbn, nombreAu, apellido, LSL);
			int respuestaEditorial = LSE->agregarLibroEditorial(isbn, editorial, LSL);

			if (respuestaTemas == 1)
				cout << "Agregado correctamente a temas" << endl;
			else if (respuestaTemas == 2)
				cout << "El tema no existe" << endl;
			else if (respuestaTemas == 3)
				cout << "Libro no existe con ese ISBN" << endl;
			else if (respuestaTemas == 4)
				cout << "Libro ya agregado en subLista  temas" << endl;

			if (respuestaAutores == 1)
				cout << "Agregado correctamente a autores" << endl;
			else if (respuestaAutores == 2)
				cout << "El autor no existe" << endl;
			else if (respuestaAutores == 3)
				cout << "Libro no existe con ese ISBN" << endl;
			else if (respuestaAutores == 4)
				cout << "Libro ya agregado en subLista  autores" << endl;

			if (respuestaEditorial == 1)
				cout << "Agregado correctamente a editorial" << endl;
			else if (respuestaEditorial == 2)
				cout << "La editorial no existe" << endl;
			else if (respuestaEditorial == 3)
				cout << "Libro no existe con ese ISBN" << endl;
			else if (respuestaEditorial == 4)
				cout << "Libro ya agregado en subLista editorial" << endl;
			break;
		}
		case 2: {

			isbn = 154;
			nombreAu = "JMOD";
			apellido = "MarionMOD";
			tema = "DramaMOD";
			editorial = "EduMOD";;
			/* cout << "Ingrese el ISBN" << endl;
			cin >> isbn; */

			int respuestaAutores = LSA->eliminarLibroAutor(isbn, nombreAu, apellido, LSL);
			int respuestaTema = LST->eliminarLibroTema(isbn, tema, LSL);
			int respuestaEditorial = LSE->eliminarLibroEditorial(isbn, editorial, LSL);

			LSL->eliminar(isbn);
			//Eliminar Autores subLista
			if (respuestaAutores == 1)
				cout << "Eliminado correctamente a autores" << endl;
			else if (respuestaAutores == 2)
				cout << "El autor no existe" << endl;
			else if (respuestaAutores == 3)
				cout << "Libro no existe con ese ISBN" << endl;
			else if (respuestaAutores == 4)
				cout << "Libro no existe en subLista autores" << endl;
			//Eliminar Tema subLista
			if (respuestaTema == 1)
				cout << "Eliminado correctamente a temas" << endl;
			else if (respuestaTema == 2)
				cout << "El tema no existe" << endl;
			else if (respuestaTema == 3)
				cout << "Libro no existe con ese ISBN" << endl;
			else if (respuestaTema == 4)
				cout << "Libro no existe en subLista temas" << endl;

			//Eliminar Tema subLista
			if (respuestaEditorial == 1)
				cout << "Eliminado correctamente a editorial" << endl;
			else if (respuestaEditorial == 2)
				cout << "La editorial no existe" << endl;
			else if (respuestaEditorial == 3)
				cout << "Libro no existe con ese ISBN" << endl;
			else if (respuestaEditorial == 4)
				cout << "Libro no existe en subLista editorial" << endl;
			break;
		}
		case 3: {
			/*cout << "Ingrese el ISBN del libro" << endl;
			cin >> isbn;

			cin.ignore();
			cout << "Ingrese el nuevo libro" << endl;
			cin >> nombre;

			cin.ignore();
			cout << "Ingrese el idioma del libro" << endl;
			getline(cin, idioma);

			cin.ignore();
			cout << "Ingrese el precio del libro" << endl;
			getline(cin, precio);

			cin.ignore();

			cout << "Ingrese la fecha de publicacion del libro" << endl;
			getline(cin, fecha);

			cin.ignore();
			cout << "Ingrese el nombre del autor del libro" << endl;
			getline(cin, nombreAu);

			cin.ignore();
			cout << "Ingrese el apellido del autor del libro" << endl;
			getline(cin, apellido);

			cin.ignore();
			cout << "Ingrese el tema del libro" << endl;
			getline(cin, tema);

			cin.ignore();
			cout << "Ingrese el editorial del libro" << endl;
			getline(cin, editorial);*/



			isbn = 154;
			nombre = "PotterMOD";
			idioma = "InglesMOD";
			precio = "40000";
			fecha = "01/01/2010";
			nombreAu = "JMOD";
			apellido = "MarionMOD";
			tema = "DramaMOD";
			editorial = "EduMOD";

			Libro* libro = new Libro(isbn, nombre, idioma, precio, fecha, 1, nombreAu, apellido, tema, editorial);

			LSL->modificarLibro(libro);
			bool modAutor = LSA->modificarAutores(libro);
			bool modTema = LST->modificarTema(libro);
			bool modEditorial = LSE->modificarEditorial(libro);

			if (modAutor)
				cout << "Autor modificado" << endl;
			else
				cout << "Autor no modificado" << endl;

			if (modTema)
				cout << "Tema modificado" << endl;
			else
				cout << "Tema no modificado" << endl;

			if (modEditorial)
				cout << "Editorial modificado" << endl;
			else
				cout << "Editorial no modificado" << endl;
			break;
		}
		case 11:
			cout << "Desplegando los valores de la lista" << endl;
			LSL->desplegarLista();
			break;

		case 0:
			cout << "Finalizando lista editorial ";
			break;
		default:
			cout << "Opcion no válida..." << endl;
		}
	}
}

void menuGeneral() {

	int opc = -1;
	string editorial = "";
	while (opc != 0) {
		cout << "      MENU" << endl;
		cout << "(1) Menu Temas" << endl;
		cout << "(2) Menu Autores" << endl;
		cout << "(3) Menu Editoriales" << endl;
		cout << "(4) Menu Libros" << endl;
		cout << "(0) Finalizar" << endl;
		cout << "Opción seleccionada ->";
		cin >> opc;
		switch (opc) {
		case 1: {
			menuTemas();
			break;
		}
		case 2: {
			menuAutores();
			break;
		}
		case 3: {
			menuEditorial();
			break;
		}
		case 4: {
			menuLibros();
			break;
		case 0:
			cout << "Finalizando el programa... ";
			break;
		default:
			cout << "Opcion no válida..." << endl;
		}
		}
	}
}


int main()
{
	menuGeneral();

}
