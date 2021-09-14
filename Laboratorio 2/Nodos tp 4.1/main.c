#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int edad;
    char nombre[20];
} stPersona;
typedef struct
{
    stPersona dato;
    struct nodo *siguiente;
} nodo;

nodo* inicLista();
nodo* crearNodo(stPersona dato);
nodo* agregarAlPrincipio(nodo* lista,nodo* nuevoNodo);
void muestraPersona(stPersona a);
void mostrarLista(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* buscaCoicidencia(nodo* lista,stPersona dato);

int main()
{
    stPersona persona;
    stPersona dato;
    int resultado;
    printf("Nombre a cargar\n");
    fflush(stdin);
    scanf("%s",&persona.nombre);
    printf("Edad a cargar\n");
    scanf("%d",&persona.edad);
    nodo* lista=inicLista();
    nodo* nuevo=inicLista();
    nuevo=crearNodo(persona);
    lista=agregarAlPrincipio(lista,nuevo);

    printf("Nombre a cargar\n",persona.nombre);
    fflush(stdin);
    scanf("%s",&persona.nombre);
    printf("Edad a cargar\n",persona.edad);
    scanf("%d",&persona.edad);

    nuevo=crearNodo(persona);
    lista=agregarAlPrincipio(lista,nuevo);

    mostrarLista(lista);

    printf("\nMuestra al final\n");

    //lista=agregarAlFinal(lista,nuevo);

    //mostrarLista(lista);
    printf("Busca coincidencia retorna 1 si encuentra\n");
    printf("Nombre a cargar\n");
    fflush(stdin);
    scanf("%s",&dato.nombre);
    printf("Edad a cargar\n");
    scanf("%d",&dato.edad);

    resultado=buscaCoicidencia(lista,dato);
    printf("EL resultado de la busqueda es %d\n",resultado);
    return 0;
}

///Hacer un programa que lea de un archivo datos y los inserte en una lista.

nodo* inicLista()
{
    return NULL;
}
nodo* crearNodo(stPersona dato)
{
    nodo* nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->siguiente;

}
nodo* agregarAlPrincipio(nodo* lista,nodo* nuevoNodo)
{
    nuevoNodo->siguiente=lista;

    return nuevoNodo;
}

void mostrarLista(nodo* lista){

    nodo* seg=lista;
    while(seg!=NULL){
        muestraPersona(seg->dato);
        seg=seg->siguiente;
    }
}
void muestraPersona(stPersona a){

    printf("Nombre %s\n",a.nombre);
    printf("Edad %d\n",a.edad);
}

///Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada

nodo* buscaUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente!=NULL){
        seg=seg->siguiente;
    }
    return seg;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(lista == NULL){
        lista = nuevo;
    }else{
        nodo* ultimo = buscaUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}
///Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.

nodo* buscaCoicidencia(nodo* lista,stPersona dato){
    int flag=0;
        while(lista!=NULL){
        if(strcmp(lista->dato.nombre,dato.nombre)>0&&lista->dato.edad==dato.edad){
            flag=1;
        }
        lista=lista->siguiente;
    }
    return flag;
}

