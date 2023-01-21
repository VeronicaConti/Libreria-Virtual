#include <iostream>

#include "contenedor.h"
#include "libro.h"


using namespace std;

template <typename L>
Contenedor<L>::Contenedor(){
    first = NULL;
    size= 0;
}

template <typename L>
void Contenedor<L>::addFirst(const L & element){
    size++;
    nodo * aux = new nodo;
    aux->element = element;
    aux->next = first;
    aux->num = size;
    first = aux;
}

template <typename L>
void Contenedor<L>::insertOrdenado(const L & element){
    if((first == NULL)||(first->element < element))
        addFirst(element);
    else{
        nodo * cursor;
        cursor = first;
        while((cursor->next != NULL) && !(cursor->next->element < element))
            cursor=cursor->next;
        size++;
        nodo * aux = new nodo;
        aux->element = element;
        aux->next = cursor->next;
        aux->num = size;
        cursor->next = aux;
    }
}

template <typename L>
const L & Contenedor<L>::getElement(int i) const{
    int j=1;
    if (j==i){
        return first->element;
    }else {
        nodo * aux;
        aux = first->next;
        while (j+1 != i){
            aux=aux->next;
            j++;
        }
        return aux->element;
    }
}

template <typename L>
const L & Contenedor<L>::getElementNum(int i) const{
    if((!esVacio()) && (i<=size)){
        if(i == first->num)
            return first->element;
        else{
            nodo * aux;
            aux = first->next;
            while(aux->num != i)
                aux = aux->next;
            return aux->element;
        }
    }
}

template <typename L>
int Contenedor<L>::getCant() const{
    return size;
}

template <typename L>
int Contenedor<L>::getNumero(int i) const{
    int j=1;
    if (j==i){
        return first->num;
    }else {
        nodo * aux;
        aux = first->next;
        while (j+1 != i){
            aux=aux->next;
            j++;
        }
        return aux->num;
    }
}

template <typename L>
bool Contenedor<L>::esVacio() const{
    if(first == NULL)
        return true;
    else
        return false;
}

template <typename L>
void Contenedor<L>::clear(int i){
    int j=1;
    if(first != NULL){
        nodo * descartar;
        nodo * prev;
        prev = NULL;
        descartar = first;
        while((descartar != NULL) && (j != i)){
            prev = descartar;
            descartar = descartar->next;
            j++;
        } if(prev == NULL){
            first = first->next;
            delete descartar;
        }else{
            prev->next = descartar->next;
            delete descartar;
        }
    }
}

template <typename L>
Contenedor<L>::~Contenedor(){
    //DESTRUCTOR
}


template class Contenedor<int>;
template class Contenedor<string>;
template class Contenedor<Libro>;
