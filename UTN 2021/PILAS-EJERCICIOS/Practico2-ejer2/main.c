#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Contar los elementos de una pila (usar variables)
int main()
{
    Pila origen,aux1;
    inicpila(&origen);
    inicpila(&aux1);
    int i;
    int j=0;
    int num;

    for(i=0;i<10;i++){
        num=rand()%10;
        apilar(&origen,num);
    }
    printf("Estos son los elementos de la pila origen\n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&aux1,desapilar(&origen));
        j++;
    }
    printf("La pila origen contine %d: elementos\n",j);

    return 0;
}
