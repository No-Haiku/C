#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "listaEmpleados.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stEmpleado dato){
    nodo* nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    return nuevo;

}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo){
    nuevoNodo->siguiente=lista;
    return nuevoNodo;
}
void muestraUnNodo(nodo* lista){
    muestraUnEmpleado(lista->dato);
}
void mostrarLista(nodo* lista){
    nodo* seg=lista;
    while(seg!=NULL){
        muestraUnNodo(seg);
        seg=seg->siguiente;
    }
}
///Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.

int retornaUNOoCero(nodo* lista, char dato[]){
    nodo* seg=lista;

    int flag=0;
    while(seg!=NULL&& flag !=1){
        if(strcmp(seg->dato.nombre, dato)==0){
            flag=1;
        }
        seg=seg->siguiente;
    }
    return flag;
}
///Hacer una función que intercale en orden los elementos de dos listas ordenadas
///generando una nueva lista. Se deben redireccionar los punteros, no se deben crear nuevos nodos.

void intercalaListas(nodo* lista, nodo* lista2, nodo** lista3){
//
//    nodo* seg=lista;
//    nodo* seg2=lista2;
//    nodo* aux=inicLista();
//
//
//    printf("holaaaaa\n");
//
//    while(seg!=NULL&& seg2!=NULL){
//
//        aux->siguiente=seg;
//         seg=seg->siguiente;
//         seg2=seg2->siguiente;
//    }
//    printf("holaaaaa3\n");
//    system("pause");

}

