#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    int a,b;
    int resultado;
    printf("Ingrese un numero entero\n");
    scanf("%d",&a);

    printf("Ingrese un numero entero\n");
    scanf("%d",&b);
    resultado=suma(sumaA(5,6),sumaB(40,4));
    printf("El resultado de la suma es %d\n",resultado);
    return 0;
}

int suma(int y,int x){

    int respuesta;
    respuesta=x+y;
    return respuesta;
}

int sumaA(int y,int x){

    int respuesta;
    respuesta=x+y;
    return respuesta;
}

int sumaB(int y,int x){

    int respuesta;
    respuesta=x+y;
    return respuesta;
}
