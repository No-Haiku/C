#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de
///la pila DADA que sean mayores o iguales que el tope de LIMITE
///a la pila MAYORES, y los elementos que sean menores a la pila MENORES.

int main()
{
    Pila limite,dada,mayores,menores;
    inicpila(&limite);
    inicpila(&dada);
    inicpila(&mayores);
    inicpila(&menores);
    int i;
    int num;

    for(i=0;i<5;i++){
        ///num=rand()%10;
        num=i;
        apilar(&limite,num);
    }
printf("Esta es la pila limite\n");
mostrar(&limite);
    for(i=0;i<10;i++){
        num=rand()%10;
        apilar(&dada,num);
    }
    printf("Esta es la pila dada antes del while\n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        if(tope(&dada)>=tope(&limite)){
            apilar(&mayores,desapilar(&dada));
        }
        apilar(&menores,desapilar(&dada));
///verifica de nuevo si los menores son menores a limite si no es verdad lo devuelve a dada
        if(tope(&menores)>= tope(&limite)){
            apilar(&dada,desapilar(&menores));
        }
    }
    printf("Esta es la pila mayores o iguales desde dada\n");
    mostrar(&mayores);
    printf("Esta es la pila menores de dada\n");
    mostrar(&menores);

    return 0;
}
