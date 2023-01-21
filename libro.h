#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>

#include "contenedor.h"

using namespace std;


class Libro
{
    public:
        Libro();//CONSTRUCTOR

        crearLibro(string ISBN , string titulo , string autor , string editorial , unsigned int anio_edicion ,
              unsigned int num_edicion , Contenedor<string> generos , unsigned int num_paginas ,
              unsigned int cant_ejemplares , float precio);//CREA EL LIBRO CON LOS DATOS
         string getISBN () const ;//RETORNA EL ISBN
         string getTitulo() const ;//RETORNA EL ISBN
         string getAutor() const ;//RETORNA EL ISBN
         string getEditorial() const ;//RETORNA EL ISBN
         Contenedor<string> ContenedorGeneros() const;//RETORNA EL ISBN
         unsigned int getAnioEdicion() const;//RETORNA EL ANIO EN QUE FUE EDITADO
         unsigned int getNumEdicion() const;//RETORNA EL NUMERO DE EDICION
         unsigned int getNumPaginas() const;//RETORNA EL NUMERO DE PAGINAS QUE TIENE
         unsigned int getCantEjemplares() const;//RETORNA LA CANTIDAD DE EJEMPLARES VENDIDOS
         float getPrecio() const;//RETORNA EL PRECIO DEL LIBRO
         bool operator< (const Libro & l) const;//DEVUELVE SI UN LIBRO ES MENOR QUE OTRO

         ~Libro();//DESTRUCTOR

//--------------------------------------ESTRUCTURA PIVADA DE LIBRO--------------------------------------------------------
    private:
        string ISBN;
        string titulo;
        string autor;
        string editorial;
        Contenedor<string> generos;
        unsigned int anio_edicion;
        unsigned int num_edicion;
        unsigned int num_paginas;
        unsigned int cant_ejemplares;
        float precio;
};

#endif // LIBRO_H
