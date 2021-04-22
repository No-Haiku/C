#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Calcular el promedio de los valores de una pila (usar variables)


int main()
{
    Pila origen,aux1;
    inicpila(&origen);
    inicpila(&aux1);
    int i;
    int j=0;
    int num=0;
    int numPila=0;
    int suma=0;
    int promedio=0;

    for(i=0;i<3;i++){
        num=rand()%10;
        apilar(&origen,num);
    }
    printf("Estos son los datos de origen\n");

    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&aux1,desapilar(&origen));
        numPila=tope(&aux1);
        suma=suma+numPila;
        j++;
    }
    promedio=suma/j;

    printf("El promedio de los datos de la pila es %d\n",promedio);
    return 0;
}
