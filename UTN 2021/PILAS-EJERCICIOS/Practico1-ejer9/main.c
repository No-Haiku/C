#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define ESC 27
///9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.
int main()
{
    Pila a,b,aux1,aux2,sobra;
    inicpila(&a);
    inicpila(&b);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&sobra);
    int i=0;
    int num;
    char opcion;

    do
    {

        if(opcion!= ESC){
        printf("Ingrese un entero a la pila A\n");
        scanf("%d",&num);
        apilar(&a,num);
        printf("Precione cualquier tecla para continuar--ESC para salir\n");
        opcion=getch();
        system("cls");
        }
        if(opcion != ESC){
        printf("Ingrese un entero a la pila B\n");
        scanf("%d",&num);
        apilar(&b,num);
        printf("Precione cualquier tecla para continuar--ESC para salir\n");
        opcion=getch();
        system("cls");
        }


    }
    while(opcion!=ESC);
    printf("Estos son los datos en A\n");
    mostrar(&a);
    printf("Estos son los datos en B\n");
    mostrar(&b);

    while(!pilavacia(&a) && !pilavacia(&b))
    {
        apilar(&aux1,desapilar(&a));
        apilar(&aux2,desapilar(&b));
        if(!pilavacia(&a)){
            printf("**********A es mayor que B**********");
            apilar(&sobra,desapilar(&a));
        }
        else if (!pilavacia(&b)){
            printf("***********B es mayor que A***********");
            apilar(&sobra,desapilar(&b));
        }
        else(printf("**************Las pilas son iguales***************"));
    }
    return 0;
}
