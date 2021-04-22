#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
///Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.

#define ESC 27
int main()
{
    Pila origen,destino;
    inicpila(&origen);
    inicpila(&destino);
    int num;
    char opcion;

    do{
        printf("Ingrese los enteros para cargae en origen\n");
        scanf("%d",&num);
        apilar(&origen,num),
        printf("PREcione cualquier tecla para continuar---ESC para salir\n");
        opcion=getch();
        system("cls");
    }while(opcion != ESC);
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&destino,desapilar(&origen));
    }
    printf("Esta es la pila Destino\n");
    mostrar(&destino);
    return 0;
}
