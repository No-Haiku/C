#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Sumar los elementos de una pila (usar variables)


int main()
{
    Pila origen,aux1;
    inicpila(&origen);
    inicpila(&aux1);
    int i;
    int suma=0;
    int num;
    int numPila=0;

    for(i=0;i<10;i++){
       num=rand()%10;
       apilar(&origen,num);
    }
    printf("Datos de ORIGEN\n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&aux1,desapilar(&origen));
        numPila=tope(&aux1);
        suma = suma + numPila;
    }
    printf("La suma de los datos de origen es: %d\n",suma);
    return 0;
}
