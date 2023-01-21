#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "menuservicios.h"
#include "Contenedor.h"
#include "Libro.h"


using namespace std;



int main()
{
    MenuServicios MenuLibros;
    Contenedor<Libro> contenedorLibros;
    cout << endl;
    cout << "-------------------------------------------  LIBRERIA VIRTUAL  -------------------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------------------------------  ¡BIENVENIDO!  ----------------------------------------------------------" << endl;
    cout << endl;
    MenuLibros.procesar_archivo_entrada("Libros.csv", contenedorLibros);
    MenuLibros.menuServicios(contenedorLibros);
    return 0;
}


