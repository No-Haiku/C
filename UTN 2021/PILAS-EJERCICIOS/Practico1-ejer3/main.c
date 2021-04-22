#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define ESC 27
///3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8
int main()
{
    Pila dada,destino,aux1;
    inicpila(&dada);
    inicpila(&destino);
    inicpila(&aux1);
    int num;
    char opcion;

    do{
       printf("Ingrese un valor entero\n");
       scanf("%d",&num);
       apilar(&dada,num);
       printf("Precione cualquier tecla para continuar---ESC para salir");
       opcion=getch();
       system("cls");
    }while(opcion!=ESC);

    while(!pilavacia(&dada)){
        if(tope(&dada)==8){
            apilar(&aux1,desapilar(&dada));
        }
        apilar(&destino,desapilar(&dada));
    }

    printf("Estos son los datos de destino\n");
    mostrar(&destino);
    printf("Estos son los datos de AUX1 donde seguardan los 8\n");
    mostrar(&aux1);
    printf("Estos son los datos de DADA");
    mostrar(&dada);
    return 0;
}
