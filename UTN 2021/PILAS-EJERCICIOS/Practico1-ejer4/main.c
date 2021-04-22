#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define ESC 27

///4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
///Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.

int main()
{
    Pila origen,destino,aux1;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux1);
    int num;
    char opcion;

    do{
       printf("Ingrese un entero\n");
       scanf("%d",&num);
       apilar(&origen,num);
       printf("Precione cualquier tecla para continuar--ESC para salir\n");
       opcion=getch();
       system("cls");
    }while(opcion!=ESC);
    printf("Estos son los datos en origen\n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&aux1,desapilar(&origen));
    }
    while(!pilavacia(&aux1)){
        apilar(&destino,desapilar(&aux1));
    }
    printf("Estos son los datos de DESTINO ordenados como origen\n");
    mostrar(&destino);
    return 0;
}
