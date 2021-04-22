#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define ESC 27

///1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos
/// que se encuentren en el tope a la pila AUX1 y los restantes a la pila AUX2, ambas pilas inicializadas.

int main()
{
    Pila dada,aux1,aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    int num;
    char opcion;

    do{
        printf("ingrese un entero \n");
        scanf("%d",&num);
        apilar(&dada,num);
        printf("Precione cualquier tecla para continuar-ESC para salir");
        opcion=getch();
        system("cls");
    }while(opcion != ESC);
      mostrar(&dada);
    /// Desapila el tope 3 veces
    if(!pilavacia(&dada)){
        apilar(&aux1,desapilar(&dada));
    }
    if(!pilavacia(&dada)){
        apilar(&aux1,desapilar(&dada));
    }
    if(!pilavacia(&dada)){
        apilar(&aux1,desapilar(&dada));
    }
    /// pasa el resto de elemento a aux2
    while(!pilavacia(&dada)){
        apilar(&aux2,desapilar(&dada));
    }

    printf("Datos en auxilar 1");
    mostrar(&aux1);
    printf("Datos en aux2");
    mostrar(&aux2);
    printf("Datos en dada");
    mostrar(&dada);
    return 0;
}
