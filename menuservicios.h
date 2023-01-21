#ifndef MENUSERVICIOS_H
#define MENUSERVICIOS_H
#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Contenedor.h"
#include "Libro.h"

using namespace std;

class MenuServicios
{
    public:

        MenuServicios();//CONSTRUCTOR

        void procesar_archivo_entrada(string origen, Contenedor<Libro> &contenedorLibros);//PROCESA LOS LIBROS DEL ARCHIVO Y LOS CARGA EN EL CONTENEDOR UNA SOLA VEZ
        void buscarPorTitulo( Contenedor<Libro> contenedorLibros);//SERVICIO 1
        void buscarPorRangoAnios( Contenedor<Libro> contenedorLibros);//SERVICIO 2
        void masVendidos(Contenedor<Libro> contenedorLibros);//SERVICIO 3
        void menuServicios(Contenedor<Libro> contenedorLibros);//MENU DE SERVICIOS

        virtual ~MenuServicios();//DESTRUCTOR

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    private:

        Contenedor<Libro> contenedorLibros;
        void menu(int &opcion)const;//COUT PARA LAS OPCIONES DEL MENU DE SERVICIOS
        void muestraGenero(Contenedor<Libro> & contenedorLibros, int i) const;//MUESTRA EL O LOS GENEROS AL QUE PERTENECE EL LIBRO
        void mostrarLibros(Contenedor<Libro> & contenedorLibros, int i) const; //IMPRIME PORPANTALLA LA INFORMACION DEL LIBRO

        void datosServicio1(string &titulo);//COUTS Y TITULO DEL LIBRO A BUSCAR QUE SE PIDE
        void mostrarLibroBuscado(Contenedor<int> libroBuscado,Contenedor<Libro> contenedorLibros)const;//SE LLAMA AL MOSTRARLIBRO CON EL CONTENEDOR DE ENTEROS QUE SE GUARDO LOS NUMEROS DEL LIBRO BUSCADO EN EL CONTENEDOR DE LIBROS, SI EXISTE
        bool coincidenTitulos(string titulo1, string titulo2) const;// RETORNA TRUE SI EL TITULO DEL LIBRO BUSCADO COINCIDE CON EL QUE SE ESTA COMPARANDO
        Contenedor<int>elLibro(string titulo, Contenedor<Libro> & contenedorLibros);//DEVUELVE UN CONTENEDOR DE INTEGER CON LOS NUMEROS DE LOS LIBROS QUE COINCIDEN CON EL TITULO BUSCADO

        void datosServicio2(int &anio, int &anio2);//COUTS Y ANIOS QUE SE PIDEN PARA BUSCAR EN ESE RANGO LOS LIBROS EDITADOS
        bool esMenor(int anio, int anio2);//RETORNA TRUE SI EL ANIO INGRESADO PRIMERO ES MENOR QUE EL SEGUNDO
        void contAnio(int anio,int anio2, Contenedor<Libro> contenedorLibros,Contenedor<int> &contPorRango);//RECORRE EL CONTENEDOR COMPARANDO EL ANIO DE CADA LIBRO CON EL DELOS INGRESADOS Y SI ESTA  DENTRO DEL RANGO AGREGA SU NUMERO A UN CONTENEDOR DE ENTEROS
        void mostrarRango(Contenedor<int> contPorRango,Contenedor<Libro>  contenedorLibros);//RECIBE EL CONTEDOR DE LOS NUMEROS DE LOS LIBROS EDITADOS DENTRO DEL RANGO DE ANIOS

        void datosServicio3(string &genero);//COUTS Y GENERO PEDIDO PARA BUSCAR LOS 10 LIBROS MAS VENDIDOS DEL MISMO
        Contenedor<int> actualizaVendidos( Contenedor<Libro>  contenedorLibros, Contenedor<int> librosMasVendidos,int pos);//RECIBE EL CONTENEDOR DE NUMEROS DE LOS 10 LIBROS MAS VENDIDOS DEL GENERO COMPLETO Y CON EL NUMERO 11 RECORRE EL CONTENEDOR COMPARANDO LA CANTIDAD DE VENTAS, SI ES MAYOR QUE ALGUNO SE LO ELIMINA, Y SE AGREGA EL NUMERO DEL ACTUAL
        Contenedor <int> contMasVendidos(string genero, Contenedor<Libro>  contenedorLibros, Contenedor<int> librosMasVendidos);//RECORRE LOS LIBROS DEL CONTENEDOR Y SI ENCUENTRA UNO QUE COINCIDA CON EL GENERO INGRESADO SE AGREGA EL NUMERO AL CONTENEDOR
        void mostrarLibrosMasVendidos(Contenedor<Libro> contenedorLibros, Contenedor<int> listaLibrosVendidos,string genero);//MUESTRA POR PANTALLA HASTA 10 LIBROS MAS VENDIDOS DEL GENERO INGRESADO
};

#endif // MENUSERVICIOS_H
