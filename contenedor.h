#ifndef CONTENEDOR_H
#define CONTENEDOR_H


template <typename L>
class Contenedor
{
    public:

        Contenedor(); //CONSTRUCTOR

        void addFirst(const L & element);//AGREGA UN ELEMENTO EN LA PRIMERA POSICION DEL CONTENEDOR
        void insertOrdenado(const L & element);//INSERTA UN ELEMENTO ORDENADO EN EL CONTENEDOR
        const L & getElement(int i) const;//DEVUELVE UN ELEMENTO EN UNA POSICION DEL CONTENEDOR
        const L & getElementNum(int i) const;//DEVUELVE UN ELEMENTO CON UN NUMERO DEL CONTENEDOR
        int getCant() const;//DA LA CANTIDAD DE ELEMENTOS DEL CONTENEDOR
        int getNumero(int i) const;//DA EL NUMERO DE UN ELEMENTO EN UNA POSICION
        bool esVacio() const;//RETORNA SI ES CONTENEDOR ESTA VACIO
        void clear(int i);//ELIMINA UN ELEMENTO EN UNA POSICION

        ~Contenedor(); //DESTRUCTOR

//------------------------------------------------ESTRUCTURA DEL NODO-------------------------------------------------------------
    private:

        struct nodo
        {
            L element; //ELEMENTO
            int num; //NUMERO DE ELEMENTO
            nodo*next; //PUNTERO AL SIGUIENTE
        };
        nodo * first; //PUNTERO AL PRIMERO
        int size; //TAMANIO
};


#endif // CONTENEDOR_H
