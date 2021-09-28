#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED
#include "empleados.h"

typedef struct _nodo{
    stEmpleado dato;
    struct _nodo *siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stEmpleado dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
void muestraUnNodo(nodo* lista);
void mostrarLista(nodo* lista);
int retornaUNOoCero(nodo* lista, char dato[]);
void intercalaListas(nodo* lista, nodo* lista2, nodo** lista3);

#endif // LISTAEMPLEADOS_H_INCLUDED
