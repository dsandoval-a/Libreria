#pragma once

#include <string>
#include <stdlib.h>

using namespace std;


class Libro
{

private:

	int ISBN;
	string nombre;
	string fechaPublicar;
	string precio;
	string idioma;

	string nombreAutor;
	string apellidoAutor;
	string tema;
	string editorial;

public:
	Libro();
	Libro(int, string, string, string, string,int, string, string, string,string);
	~Libro();

	int getISBN();
	string getNombre();
	string getFecha();
	string getPrecio();
	string getIdioma();

	string getNombreAutor();
	string getApellidoAutor();
	string getTema();
	string getEditorial();


	void setNombre(string);
	void setFecha(string);
	void setPrecio(string);
	void setIdioma(string);
	void setAutor(string, string);
	void setTema(string);
	void setEditorial(string);

	//Aqui se hace modificar libro
	string modificarLibro(Libro*);

	string desplegarLibro();
};

