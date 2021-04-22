#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define ESC 27

///6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base)
///, dejando los restantes elementos en el mismo orden.

int main()
{
    Pila origen,destino,aux1;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux1);
    int tope;
    int num;
    char opcion;

    do{
       printf("Ingrese un entero\n");
       scanf("%d",&num);
       apilar(&origen,num);
       printf("Precione cualquier tecla para continuar--ESC para salir\n");
       opcion=getch();
       system("cls");
    }while(opcion!=ESC);
    printf("Estos son los datos en origen\n");
    mostrar(&origen);

    if(!pilavacia(&origen)){
       tope=desapilar(&origen);
    }
    printf("Estos son los datos de origen sin el tope\n");
    mostrar(&origen);
    ///pasamos los datos a destino en orden inverso
    while(!pilavacia(&origen)){
        apilar(&destino,desapilar(&origen));
    }
    ///pasamos el tope que guaramos en la bariablo tope a la base de origen
    if(pilavacia(&origen)){
        apilar(&origen,tope);
    }
    ///pasamos el resto de datos de destino a tope ,quedan con el orden inicial
    while(!pilavacia(&destino)){
        apilar(&origen,desapilar(&destino));
    }
    printf("Estos son los datos de origen con el tope en la base\n");
    mostrar(&origen);
    return 0;
}
