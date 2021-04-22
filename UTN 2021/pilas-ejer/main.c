#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Pasar el primer elemento (tope) de la pila DADA a su última posición (base),
/// dejando los restantes elementos en el mismo orden.

int main()

{
    Pila origen,aux1,aux2;
    inicpila(&origen);
    inicpila(&aux1);
    inicpila(&aux2);

    int num;
    char opcion;

    do
    {
        printf("\nIngrese los datos a la pia origen\n");
        scanf("%d",&num);
        apilar(&origen,num);
        system("cls");
        printf("\nPara continuar, escape para salir\n");
        opcion=getch();
        system("cls");
    }
    while(opcion!=27);

    mostrar(&origen);

    apilar(&aux1,desapilar(&origen));
    printf("Esta es la pila origen sin tope\n");
    mostrar(&origen);
    printf("Esta es auxiliar 1 guarda el tope de origen\n");
    mostrar(&aux1);
    /// origen ya no tiene mas el  la segunda posicion pasa a ser el tope

    while(!pilavacia(&origen))
    {
        apilar(&aux2,desapilar(&origen));
    }

    printf("Estra es auxiliar 2 con los datos de origen invertidos");
    mostrar(&aux2);
    /// apilamos de aux1 a origen y queda como base
    apilar(&origen,desapilar(&aux1));

    /// este ciclo pode en orden los datos que ya estuvieron en origen
        while(!pilavacia(&aux2))
    {
        apilar(&origen,desapilar(&aux2));
    }

    printf("Esto es la pila origen con el tope en la base\n");
    mostrar(&origen);


    return 0;
}
