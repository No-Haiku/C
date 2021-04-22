#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define ESC 27
///5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga
///los elementos cargados originalmente en ella, pero en orden inverso.


int main()
{
    Pila origen,destino,aux1;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux1);
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

    ///pasamos los datos invertidos a destino
    while(!pilavacia(&origen)){
        apilar(&destino,desapilar(&origen));
    }
    ///pasamos los datos a AUX1 en el orden primario de origen
    while(!pilavacia(&destino)){
        apilar(&aux1,desapilar(&destino));
    }
    ///pasamos los datos a Origen invertidos
    while(!pilavacia(&aux1)){
        apilar(&origen,desapilar(&aux1));
    }
    printf("Estos son los datos de origen invertidos");
    mostrar(&origen);

    return 0;
}
