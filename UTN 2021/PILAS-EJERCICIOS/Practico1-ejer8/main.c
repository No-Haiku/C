#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define ESC 27

///8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.


int main()
{
    Pila mazo,jugador1,jugador2,sobra,aux1,aux2;
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&sobra);
    int num;
    char opcion;

    do
    {
        printf("Ingrese un entero\n");
        scanf("%d",&num);
        apilar(&mazo,num);
        printf("Precione cualquier tecla para continuar--ESC para salir\n");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);
    printf("Estos son los datos en mazo\n");
    mostrar(&mazo);

    while(!pilavacia(&mazo))
    {
        apilar(&aux1,desapilar(&mazo));
        apilar(&aux2,desapilar(&mazo));
        if(!pilavacia(&mazo)){
            apilar(&sobra,desapilar(&mazo));
        }
    }
    printf("Estos son los datos en mazo vacio\n");
    mostrar(&mazo);

    printf("Estos son los datos de jugador 1\n");
    mostrar(&aux1);
    printf("Estos son los datos de jugador2\n");
    mostrar(&aux2);
    system("pause");


    return 0;
}
