#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///11. Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA
///todos los elementos que sean iguales al tope de la pila MODELO.


int main()
{
    Pila modelo,dada,aux1,aux2;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    int num;
    int i=0;

    for(i=0;i<10;i++){
        num=rand()%10;
        apilar(&modelo,num);
    }
    printf("Estoe es modelo despues del ciclo while\n");
    mostrar(&modelo);
    for(i=0;i<10;i++){
        ///num=rand()%10;
        num=i;
        apilar(&dada,num);
    }
    printf("Estoe es dada despues del ciclo for\n");
    mostrar(&dada);

    while(!pilavacia(&modelo)&& !pilavacia(&dada)){
        if(tope(&modelo)==tope(&dada)){
            apilar(&aux1,desapilar(&dada));
        }
        apilar(&aux2,desapilar(&dada));
    }
    while(!pilavacia(&aux2)){
        apilar(&dada,desapilar(&aux2));
    }
    printf("Estoe es dada despues del ciclo while\n");
    mostrar(&dada);
    printf("Estoe es el numero eliminado de dada despues del ciclo while\n");
    mostrar(&aux1);


    return 0;
}
