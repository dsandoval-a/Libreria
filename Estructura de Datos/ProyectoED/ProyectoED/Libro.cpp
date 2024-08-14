#include "Libro.h"

Libro::Libro()
{
	this->ISBN = 0;
	this->nombre = "";
	this->idioma = "";
	this->fechaPublicar = "";
	this->precio = "";

	this->nombreAutor = "";
	this->apellidoAutor = "";
	this->tema = "";
	this->editorial = "";
}

Libro::Libro(int pISBN, string pNombre, string pIdioma, string pPrecio, string pFecha, int pIdAutores, string pNombreAu, string pApellido, string pTema, string pEditorial)
{
	this->ISBN = pISBN;
	this->nombre = pNombre;
	this->idioma = pIdioma;
	this->fechaPublicar = pFecha;
	this->precio = pPrecio;

	this->nombreAutor = pNombreAu;
	this->apellidoAutor = pApellido;
	this->tema = pTema;
	this->editorial = pEditorial;
}

Libro::~Libro()
{
}

int Libro::getISBN()
{
	return this->ISBN;
}

string Libro::getNombre()
{
	return this->nombre;
}

string Libro::getFecha()
{
	return this->fechaPublicar;
}

string Libro::getPrecio()
{
	return this->precio;
}

string Libro::getIdioma()
{
	return this->idioma;
}

string Libro::getNombreAutor()
{
	return this->nombreAutor;
}
string Libro::getApellidoAutor()
{
	return this->apellidoAutor;
}


string Libro::getTema()
{
	return this->tema;
}

string Libro::getEditorial()
{
	return this->editorial;
}

void Libro::setNombre(string pNombre)
{
	this->nombre = pNombre;
}

void Libro::setFecha(string pFecha)
{
	this->fechaPublicar = pFecha;
}

void Libro::setPrecio(string pPrecio)
{
	this->precio = pPrecio;
}

void Libro::setIdioma(string pIdioma)
{
	this->idioma = pIdioma;
}

void Libro::setAutor(string pNombre, string pApellido)
{
	this->nombreAutor = pNombre;
	this->apellidoAutor = pApellido;
}


void Libro::setTema(string pTema)
{
	this->tema = pTema;
}

void Libro::setEditorial(string pEditorial)
{
	this->editorial = pEditorial;
}

string Libro::modificarLibro(Libro* pLibro)
{
	string modificado = "";

	if (pLibro->getNombre() != this->nombre)
	{
		setNombre(pLibro->getNombre());
		modificado += "Nombre modificado a" + pLibro->getNombre() + "\n";
	}
	if (pLibro->getFecha() != this->fechaPublicar) {
		setFecha(pLibro->getFecha());
		modificado += "Fecha de publicacion modificado a" + pLibro->getFecha() + "\n";
	}
	if (pLibro->getPrecio() != this->precio) {
		setPrecio(pLibro->getPrecio());
		modificado += "Precio modificado a" + pLibro->getPrecio() + "\n";
	}
	if (pLibro->getNombreAutor() != this->nombreAutor) {
		setAutor(pLibro->getNombreAutor(),pLibro->getApellidoAutor());
		modificado += "El autor se ha modificado a" + pLibro->getNombreAutor() + " "+ pLibro->getApellidoAutor();
	}

	if (pLibro->getTema() != this->tema) {
		setTema(pLibro->getTema());
		modificado += "El tema se ha modificado a" + pLibro->getTema() + "\n";
	}
	if (pLibro->getIdioma() != this->idioma) {
		setIdioma(pLibro->getIdioma());
		modificado += "El idioma se ha modificado a" + pLibro->getIdioma() + "\n";
	}
	if (pLibro->getEditorial() != this->editorial) {
		setEditorial(pLibro->getEditorial());
		modificado += "La editorial se ha modificado a" + pLibro->getEditorial() + "\n";
	}

	if (modificado == "")
	{
		modificado = "No se ha modificado la informacion del libro";
	}

	return modificado;
}

string Libro::desplegarLibro()
{
	return "Nombre del libro: " + this->nombre + " ,fecha de publicacion: " + this->fechaPublicar + " ,idioma: " + this->idioma + " ,precio: " + this->precio + " \n" +
		" ,tema: " + this->tema + " ,editorial: " + this->editorial + " ,nombre autor: "+ this->nombreAutor + " ,apellido autor: "+ this->apellidoAutor;
}
