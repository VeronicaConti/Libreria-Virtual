#include "Libro.h"

using namespace std;

Libro::Libro(){

    //CONSTRUCTOR

}

Libro::crearLibro(string ISBN , string titulo , string autor , string editorial , unsigned int anio_edicion , unsigned int num_edicion ,
                    Contenedor<string> generos, unsigned int num_paginas , unsigned int cant_ejemplares , float precio){

    this->ISBN = ISBN;
    this->titulo = titulo;
    this->autor = autor;
    this->editorial = editorial;
    this->anio_edicion = anio_edicion;
    this->num_edicion = num_edicion;
    this->generos = generos;
    this->num_paginas = num_paginas;
    this->cant_ejemplares = cant_ejemplares;
    this->precio = precio;

}

string Libro::getISBN () const{

    return ISBN;
}

string Libro::getTitulo() const{

    return titulo;
}

string Libro::getAutor() const{

    return autor;
}

string Libro::getEditorial() const{
    return editorial;
}

Contenedor <string> Libro::ContenedorGeneros() const {

    return generos;
}

unsigned int Libro::getAnioEdicion() const{

    return anio_edicion;
}

unsigned int Libro::getNumEdicion() const{

    return num_edicion;
}

unsigned int Libro::getNumPaginas() const{

    return num_paginas;
}

unsigned int Libro::getCantEjemplares() const{

    return cant_ejemplares;
}

float Libro::getPrecio() const{

    return precio;
}

bool Libro::operator<(const Libro & l) const{

    return (this->titulo < l.getTitulo());
}

Libro::~Libro(){

    //DESTRUCTOR

}
