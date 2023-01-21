#include "menuservicios.h"

MenuServicios::MenuServicios(){

    //CONSTRUCTOR

}

//-------------------------------------CARGA LIBROS DEL ARCHIVO AL CONTENEDOR---------------------------------------------------------------------

void MenuServicios::procesar_archivo_entrada(string origen, Contenedor<Libro> &contenedorLibros){
//PROCESA EL ARCHIVO CON LA INFORMACION DE LOS LIBROS , EN LA CLASE LIBRO Y LOS AGREGA AL CONTENEDOR
   ifstream archivo(origen.c_str() );
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        unsigned int cantidad_libros = atoi(linea.c_str());

        //Leemos de una linea completa por vez (getline).

        while (getline(archivo, linea)) {
            //Primer posici�n del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(',');

            //Informacion entre pos_inicial y pos_final
            string idLibro = linea.substr(pos_inicial, pos_final);

             //Segunda posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string editorial = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Quinta posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            unsigned int anio = atoi (linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Sexta posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            unsigned int nro_edicion = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());


            //Septima posici�n del separador ; Contenedor de GENEROS

            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string lst_generos = linea.substr(pos_inicial, pos_final - pos_inicial);

            string generos = lst_generos.substr(1, lst_generos.size()-2);
            Contenedor<string> ContenedorGeneros;//CONTENEDOR CON LOS GENEROS
            int pos_inicial_generos = 0, pos_final_generos = 0;
            int nroGenero = 0;
            while (pos_final_generos != -1) {
                pos_final_generos = generos.find('|', pos_inicial_generos);
                ContenedorGeneros.insertOrdenado(generos.substr(pos_inicial_generos, pos_final_generos - pos_inicial_generos));
                pos_inicial_generos = pos_final_generos + 1;
                nroGenero++;
            }

            //Octava posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            unsigned int nro_paginas = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());


            //Novena posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            unsigned int ejemplares_vendidos = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

             //Decima posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());


            Libro l;
            //INICIALIZO LIBRO l
            l.crearLibro (idLibro , titulo , autor , editorial , anio , nro_edicion ,ContenedorGeneros, nro_paginas , ejemplares_vendidos , precio);
            //CREO LIBRO CON LOS DATOS DEL LIBRO
            contenedorLibros.insertOrdenado(l);
            //AGREGO ORDENADO POR TITULO DE LIBRO AL CONTENEDOR
        }
    }
}

//------------------------------------FIN DE CARGA DE LIBROS AL CONTENEDOR---------------------------------------------------------
//----------------------------------------------INICIO SERVICIO 1------------------------------------------------------------------

void MenuServicios:: datosServicio1(string &tituloBuscado){

    cout << "                                    INGRESE EL TITULO DEL LIBRO: " << endl;
    cout << endl;
    cout << "                                    OPCIONES: "<<endl;
    cout << "                                    (1) INGRESE UN '*' POR UNA PALABRA ENTERA "<<endl;
    cout << "                                    (2) INGRESE UN '?' POR UN SOLO CARACTER "<<endl;
    cout << endl;

    cin.ignore();
    getline(cin, tituloBuscado);
}

bool MenuServicios::coincidenTitulos(string tituloBuscado, string tituloLibro)const{

    int i=0;//INDICE DEL STRING DEL TITULO INGRESADO
    int j=0;//INDICE DEL STRING DEL TITULO QUE ESTA EN EL CONTENEDOR
    bool iguales=true;//DE CONTROL Y EL QUE RETORNA LA FUNCION
    while ((iguales==true)&&((i<tituloBuscado.size()||(j<tituloLibro.size())))){//SI EL BOOL IGUALES ES VERDADERO, SI LOS INDICES SON MENORES QUE EL TAMANIO DEL STRING
        if (tituloBuscado[i]==tituloLibro[j]){// Y SI SON IGUALES LOS CARACTERES DE AMBOS TITULOS
            i++;                              //AVANZAN AMBOS INDICES
            j++;
        }else if (tituloBuscado[i]=='*') { //SI ENCUENTRO UN ASTERISCO
            while((j<tituloLibro.size())&&(tituloLibro[j]!=' ')){// EL INDICE DEL TITULO DEL LIBRO ACTUAL NO LLEGO A SU FINAL Y NO ES UN ESPACIO EN BLANCO, NO TERMINO LA PALABRA
                j++;                                              //AVANZO CON EL INDICE DEL TITULO ACTUAL HASTA EL FIN DE LA PALABRA
            }
            i++; //AVANZO LUEGO DEL ASTERISCO EN EL INDICE DEL TITULO BUSCADO
        }else if (tituloBuscado[i]=='?'){//CONSIDERO UN ESPACIO EN BLANCO CON UN CARACTER POR ESO AVANZO CON LOS DOS INDICES
            i++;
            j++;
        }else{
            iguales=false;// SINO SE CUMPLEN ALGUNA DE LAS ANTERIORES CONDICIONES EL BOOLEAN SE VUELVE FALSO
        }
    }
    if (((i==tituloBuscado.size())&&(j<tituloLibro.size()))|| ((i<tituloBuscado.size()&&(j==tituloLibro.size())))){ //SI SOLO UNO DE LOS TITULOS LLEGO A SU FIN Y EL OTRO NO
            iguales=false;                                                                                          //IGUALES SE VUELVE FALSO
    }
    return iguales;// RETORNO BOOLEAN IGUALES
}

Contenedor<int> MenuServicios::elLibro(string tituloBuscado, Contenedor<Libro> & contenedorLibros){

    Contenedor<int> buscado;//INICIALIZO UN CONTENEDOR DE ENTEROS
    for(int index = 1; index <= contenedorLibros.getCant(); index++){//RECORRO DESDE EL INICIO HASTA EL FIN DEL CONTENEDOR
        string tituloLibro = contenedorLibros.getElement(index).getTitulo();//OBTENGO EL TITULO DEL LIBRO CON EL NUMERO DE INDEX
    if(coincidenTitulos(tituloBuscado, tituloLibro))//SI LOS TITULOS COINCIDEN
        buscado.addFirst(contenedorLibros.getNumero(index));////AGREGO EL NUMERO AL CONTENEDOR DE BUSCADO
    }
    return buscado;//DEVUELVO EL CONTENEDOR DE ENTEROS
}

void MenuServicios:: mostrarLibroBuscado(Contenedor<int> libroBuscado,Contenedor<Libro> contenedorLibros)const{

    if(libroBuscado.esVacio())//SI EL CONTENEDOR CON LOS NUMEROS DEL TITULO BUSCADO ES VACIO
        cout << "                               NO HAY UN LIBRO CON ESE TITULO EN LA BASE DE DATOS" << endl;//IMPRIMO POR PANTALLA
    else{
        cout << "                               SE ENCONTRO/ARON = " << libroBuscado.getCant() << "  COINCIDENCIA/S " << endl;
    for(int index = 1; index<= libroBuscado.getCant(); index++){//SINO LLAMO A MOSTRAR LIBROS CON EL NUMERO OBTENIDO DEL CONTENEDOR DE BUSCADO
        int index2 = libroBuscado.getElement(index);
        mostrarLibros(contenedorLibros, index2);
        }
    }
}

void MenuServicios:: buscarPorTitulo(Contenedor<Libro> contenedorLibros){

    string tituloBuscado;
    Contenedor<int> libroBuscado;
    datosServicio1(tituloBuscado);
    libroBuscado = elLibro(tituloBuscado, contenedorLibros);//EL CONTENEDOR DE ENTEROS SE VUELVE EL QUE RETORNA EL LIBRO
    mostrarLibroBuscado(libroBuscado,contenedorLibros);//LLAMO A MOSTRAR LIBRO BUSCADO CON EL CONTENEDOR DE LIBROS Y CON EL CONTENEDOR DE NUMEROS DE LIBRO BUSCADO
}

//---------------------------------------------FIN SERVICIO 1--------------------------------------------------------------------
//--------------------------------------------INICIO SERVICIO 2-------------------------------------------------------------------

void  MenuServicios:: datosServicio2(int &anio, int &anio2){

    cout << endl;
    cout << "                                    INGRESE DOS ANIOS DISTINTOS PARA BUSCAR EN ESE RANGO: " << endl;
    cout << "                                    PRIMER ANIO(el menor de los dos anios)= ";
    cin >> anio;
    cout << endl;
    cout<<  "                                    SEGUNDO ANIO= ";
    cin >> anio2;
    cout << endl;

}

bool MenuServicios:: esMenor(int anio, int anio2){
//DEVUELVE VERDADERO SI EL ANIO INGRESADO PRIMERO ES MENOR QUE ES SEGUNDO
    if(anio<anio2){
        return true;
    }else{
        return false;
    }
}

void MenuServicios:: contAnio(int anio, int anio2, Contenedor<Libro> contenedorLibros,Contenedor<int> &contPorRango){
//RECORRE EL CONTENEDOR DE LIBROS, OBTIENE EL LIBRO Y SU ANIO DE EDICION
    for(int index = 1; index <= contenedorLibros.getCant(); index++){
        int anioLibro = contenedorLibros.getElement(index).getAnioEdicion();
    if((anioLibro >= anio) && (anioLibro <= anio2))//COMPARA EL ANIO DE EDICION CON LOS INGRESADOS Y SI ESTA DENTRO DEL RANGO
        contPorRango.addFirst(contenedorLibros.getNumero(index));// AGREGA AL CONTENEDOR EL NUMERO DEL LIBRO
    }
    return;
}

void  MenuServicios:: mostrarRango(Contenedor<int> contPorRango,Contenedor<Libro>  contenedorLibros){

    if(contPorRango.esVacio())//SI EL CONTENEDOR QUE NUMEROS DE LIBROS DENTRO DEL RANGO ESTA VACIO
        cout << "                                NO HAY LIBROS EN ESE RANGO EN LA BASE DE DATOS " << endl;//LO IMPRIME POR PANTALLA
    else{
        cout << "                                HAY " << contPorRango.getCant() << " LIBRO/S  " << endl;//SINO IMPRIME LA CANTIDAD TOTAL
        for(int index = 1; index <= contPorRango.getCant(); index++){
                int index2 = contPorRango.getElement(index);
                mostrarLibros(contenedorLibros, index2);//LLAMA AL MOSTRAR LIBRO CON EL CONTENEDOR DE LIBROS Y EL NUMERO DEL LIBRO
        }
    }
}

void MenuServicios:: buscarPorRangoAnios( Contenedor<Libro> contenedorLibros){

    Contenedor<int> contPorRango;
    int anio, anio2;
    datosServicio2(anio,anio2);
    if(esMenor(anio,anio2)){//SI EL RANGO ES VALIDO EL ANIO 1 ES MENOR QUE EL ANIO 2
        contAnio(anio, anio2, contenedorLibros,contPorRango);//DEVUELVE EL CONTENEDOR CON LOS NUMEROS DE LIBRO QUE ESTAN DENTRO DEL RANGO DE ANIOS
        mostrarRango(contPorRango,contenedorLibros);//LLAMA AL MOSTRAR RANGO CON EL CONTENEDOR POR RANGO Y EL CONTENEDOR DE LIBROS
    }else{
        cout<< "                                 LOS ANIOS INGRESADOS SON INCORRECTOS " << endl;
    }
}

//----------------------------------------------FIN SERVICIO 2-------------------------------------------------------------------------------------
//---------------------------------------------INICIO SERVICIO 3-----------------------------------------------------------------

void MenuServicios:: datosServicio3(string &genero){

    cout << "                                    INGRESE EL GENERO (con minusculas): " << endl;
    cin.ignore();
    getline(cin, genero);
    cout << endl;
}

Contenedor<int> MenuServicios::actualizaVendidos( Contenedor<Libro> contenedorLibros, Contenedor<int> librosMasVendidos,int pos){
//DEVUELVE EL CONTENEDOR CON LOS NUMEROS DE LOS LIBROS MAS VENDIDOS DEL GENERO ACTUALIZADO, SI YA HAY 10 AGREGADOS, COMPARA LOS
//LIBROS VENDIDOS CON EL ACTUAL Y SI ES MAYOS EN VENTAS QUE ALGUN LIBRO LO ELIMINA Y LO AGREGA

    for (int i=1; i<10; i++){//DESDE LA POSICION 1 A LA 10 DEL CONTENEDOR
        if(contenedorLibros.getElement(librosMasVendidos.getElement(i)).getCantEjemplares()< contenedorLibros.getElement(pos).getCantEjemplares() )
            librosMasVendidos.clear(i);//SI ENCUENTRA UN LIBRO DEL GENERO BUSCADO CON MENOS EJEMPLATES VENDIDOS, LO ELIMINA
            librosMasVendidos.addFirst(contenedorLibros.getNumero(pos));//Y AGREGA EL NUEVO
        return librosMasVendidos;
    }
}

Contenedor <int> MenuServicios::contMasVendidos(string genero, Contenedor<Libro>  contenedorLibros, Contenedor<int> librosMasVendidos){
//DEVUELVE EL CONTENEDOR CON LA POSICION EN EL CONTENEDOR DE LIBROS DE LOS 10 LIBROS MAS VENDIDOS DEL GENERO INGRESADO
    for(int index=1; index <=contenedorLibros.getCant(); index++){//RECORRE EL CONTENEDOR DE LIBROS
        for(int index2=1; index2 <= contenedorLibros.getElement(index).ContenedorGeneros().getCant(); index2++){
            if ((genero == contenedorLibros.getElement(index).ContenedorGeneros().getElement(index2)&&(librosMasVendidos.getCant()< 10))) {
                //SI EL GENERO INGRESADO COINCIDE CON LOS DEL CONTENEDOR DE GENEROS Y LA CANTIDAD DE ELEMENTOS DEL CONTENEDOR CON LOS MAS VENDIDOS
                //ES MENOR QUE 10 AGREGO LA POSICION AL CONTENEDOR
                librosMasVendidos.addFirst(contenedorLibros.getNumero(index));
            }else{//SI ES IGUAL A 10 Y HAY OTRO LIBRO MAS DEL GENERO, EL CONTENEDOR SE ACTUALIZA CON ACTUALIZA VENDIDOS
             if ((genero == contenedorLibros.getElement(index).ContenedorGeneros().getElement(index2)&&(librosMasVendidos.getCant()== 10))){
                librosMasVendidos=actualizaVendidos(contenedorLibros,librosMasVendidos,contenedorLibros.getNumero(index));
                }
            }
        }
    }
    return librosMasVendidos;
}

void MenuServicios:: mostrarLibrosMasVendidos(Contenedor<Libro> contenedorLibros, Contenedor<int> masVendidos, string genero){
//LLAMA AL MOSTRAR LIBROS CON EL CONTENEDOR DE POSICIONES DE LIBROS MAS VENDIDOS
    if(masVendidos.esVacio())
        cout << "                                NO HAY LIBROS DE ESE GENERO EN ESTE MOMENTO EN LA LIBRERIA " << endl;
    else{
        cout << "                                EL/LOS LIBROS MAS VENDIDOS DEL GENERO "<< genero << " ES/SON : "<< endl;
    for(int index = 1; index <= masVendidos.getCant(); index++){
        int index2 = masVendidos.getElement(index);
        mostrarLibros(contenedorLibros, index2);
        }
    }
}

void MenuServicios:: masVendidos(Contenedor<Libro> contenedorLibros){

    string genero;
    Contenedor<int> librosMasVendidos;
    Contenedor<int> masVendidos;
    datosServicio3(genero);
    masVendidos= contMasVendidos(genero, contenedorLibros, librosMasVendidos);//EL CONTENEDOR MAS VENDIDOS SE VUELVE QUE RETORNA CONT MAS VENDIDOS
    mostrarLibrosMasVendidos(contenedorLibros, masVendidos,genero);//LLAMA A MOSTRAR CON EL CONTENEDOR DE LIBROS Y EL DE MAS VENDIDOS

}

//------------------------------------------------FIN SERVICIO 3----------------------------------------------------------------------
//----------------------------------------IMPRESION DE DATOS DE LOS LIBROS------------------------------------------------------------

void MenuServicios::  muestraGenero(Contenedor<Libro> & contenedorLibros, int i) const{
//RECORRE EL CONTENEDOR DEGENEROS Y MUESTRA POR PANTALLA AL QUE COINDICE CON CADA LIBRO

   for(int index= 1; index <= contenedorLibros.getElementNum(i).ContenedorGeneros().getCant(); index++){
    if(index != contenedorLibros.getElementNum(i).ContenedorGeneros().getCant())
        cout << contenedorLibros.getElementNum(i).ContenedorGeneros().getElement(index) << ", ";
    else
        cout << contenedorLibros.getElementNum(i).ContenedorGeneros().getElement(index) << "." << endl;
    }
}

void MenuServicios:: mostrarLibros(Contenedor<Libro> & contenedorLibros, int i)const{
//MUESTRA LOS DATOS DEL LIBRO

    cout<<endl;
    cout << "                              - ISBN = " << contenedorLibros.getElementNum(i).getISBN() << "." <<endl;
    cout << "                              - TITULO = " << contenedorLibros.getElementNum(i).getTitulo() << "." <<endl;
    cout << "                              - AUTOR = " << contenedorLibros.getElementNum(i).getAutor() << "." <<endl;
    cout << "                              - EDITORIAL = " << contenedorLibros.getElementNum(i).getEditorial() << "." <<endl;
    cout << "                              - ANIO DE EDICION = " << contenedorLibros.getElementNum(i).getAnioEdicion() << "." <<endl;
    cout << "                              - # DE EDICION = " << contenedorLibros.getElementNum(i).getNumEdicion() << "." <<endl;
    cout << "                              - # DE PAGINAS = " << contenedorLibros.getElementNum(i).getNumPaginas() << "." <<endl;
    cout << "                              - # DE LIBROS VENDIDOS = " << contenedorLibros.getElementNum(i).getCantEjemplares() << "." <<endl;
    cout << "                              - PRECIO DEL LIBRO = $" << contenedorLibros.getElementNum(i).getPrecio() << "." <<endl;
    cout << "                              - PERTENECE A EL/LOS GENERO/S = " ;

    muestraGenero(contenedorLibros,i);//IMPRIME GENEROS

}

//------------------------------------------INICIO MENU DE SERVICIOS------------------------------------------------------------

void MenuServicios:: menu(int &opcion)const {

        cout<<"-------------------------------------------  ELIJA UNA OPCION  -------------------------------------------------------"<<endl;
        cout << endl;
        cout<<"                                     (1) BUSCAR LIBRO POR TITULO"<<endl;
        cout << endl;
        cout<<"                                     (2) BUSCAR LIBROS EN UN RANGO DE ANIOS"<<endl;
        cout << endl;
        cout<<"                                     (3) TOP 10 LIBROS MAS VENDIDOS POR GENERO"<<endl;
        cout << endl;
        cout<<"                                     (4) EXIT"<<endl;
        cout << endl;
        cout<<"                                    INGRESE UNA OPCION -numero y NO caracter-:  "<<endl;
        cin >> opcion;
        cout << endl;
}

void MenuServicios:: menuServicios(Contenedor<Libro>  contenedorLibros){

//MENU DE LOS 3 SERVICIOS DE LA LIBRERIA VIRTUAL

    bool salir = false;
    int opcion;
    while(!salir){
        menu(opcion);
        switch(opcion){

            case 1: buscarPorTitulo(contenedorLibros);break;
            case 2: buscarPorRangoAnios( contenedorLibros);break;
            case 3: masVendidos(contenedorLibros);break;
            case 4:salir=true;break;
            default:cout<<"                                             OPCION NO VALIDA "<<endl;
        }
    }
    cout << "                                                 GOOD BYE         " << endl;
}

//------------------------------------------FIN MENU DE SERVICIOS------------------------------------------------------------------------------

MenuServicios::~MenuServicios(){

    //DESTRUCTOR

}
