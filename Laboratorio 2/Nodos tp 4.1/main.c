#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEmpleados.h"

nodo* archivo2lista(nodo* lista, char archivo[]);

int main()
{
    nodo* lista = inicLista();
    nodo* lista2 = inicLista();
    nodo* nuevo = inicLista();
    nodo* listaIntercalada=inicLista();
    printf("Carga un empleado\n");
    //cargaEmpleadoArchivo("Empleados.dat");

    lista=archivo2lista(lista,"Empleados.dat");
    lista2=archivo2lista(lista2,"Empleados.dat");
    printf("Muestra nodo lista\n");
    mostrarLista(lista);
///Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.

    printf("Retorna 1 si Existe dato 0 sino: %d \n",retornaUNOoCero(lista,"juan"));

    intercalaListas(lista,lista2,&listaIntercalada);
    printf("lista intercalada\n");
    mostrarLista(listaIntercalada);


    return 0;
}
///Hacer un programa que lea de un archivo datos y los inserte en una lista.
///Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.

nodo* archivo2lista(nodo* lista, char archivo[]){
    FILE *archi = fopen(archivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado), 1, archi)>0){

                nodo *nuevo = crearNodo(e);
                ///lista = agregarAlFinal(lista, nuevo);
                lista = agregarAlPrincipio(lista, nuevo);

        }
        fclose(archi);
    }

    return lista;
}
