#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

void menu();
void CargaPilaUno(Pila *x);
void pasaDeUnaPilaAOtra(Pila *x,Pila *y);
///int PilaACopia();
int buscaMenor(Pila *x);
void nuevaPila5(Pila A,Pila *B);
int main()
{
    Pila aux1,aux2,aux3;
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);
    menu(CargaPilaUno,&aux1,&aux2,pasaDeUnaPilaAOtra,buscaMenor,nuevaPila5,&aux3);
///***********************************************************
    ///CargaPilaUno(&aux1);
    ///pasaDeUnaPilaAOtra(Pila *x,Pila *y)
    printf("Estos son los datos de Aux1 FINAL DE PROCESO\n");
    mostrar(&aux1);
    printf("Estos son los datos de Aux2 FINAL DE PROCESO\n");
    mostrar(&aux2);

    ///printf("PILA A COPIA %d \n",PilaACopia());



    return 0;
}

void menu(void CargaPilaUno(),Pila *a1, Pila *a2,void pasaDeUnaPilaAOtra(),int buscaMenor(),void nuevaPila5(),Pila *a3)
{
    int num;
    char opcion;
    do
    {
        printf("*********************MENU INICIAL*********************************\n");
        printf("Precione ESC para salir, cualquier tecla para continuar\n");
        opcion=getch();
        system("pause");
        system("cls");
        if(opcion!=27)
        {
            printf("Precione un numero del 1 al 9 para elegir el ejercicio\n");
            scanf("%d",&num);
            system("pause");
            system("cls");
            switch(num)
            {
            case 1:
                printf("Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el usuario.\n\n");
                CargaPilaUno(a1);
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Hacer una función que pase todos los elementos de una pila a otra.\n\n ");
                pasaDeUnaPilaAOtra(a1,a2);
                system("pause");
                system("cls");
                break;
            case 4:
                printf(" Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.\n");
                printf("\n");
                CargaPilaUno(a1);
                printf("Datos cargados en A1 del menu\n");
                mostrar(a1);
                printf("Este es el dato de menor %d\n",buscaMenor(a1));
                printf("datos de Aux1 origen\n");
                mostrar(a1);
                break;
            case 5:
                printf("Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección) \n");
                mostrar(a1);
                nuevaPila5(a1,a3);
                printf("Esta es la copia de la pila del ejer 4 \n");
                mostrar(a3);

                break;

            }

        }




    }
    while(opcion!=27);
}
///carga pila AUX1 se puede mejorar dividiendo la funcion de carga
void CargaPilaUno(Pila *x)
{
    int num;
    printf("Ingrese el tamanio de la pila AUX1\n");
    scanf("%d",&num);

    for(int i=1; i<num; i++)
    {
        apilar(x,rand()%1000);///rand()%10
    }
    printf("Datos cargados en carga pila uno\n");
    mostrar(x);

    system("pause");
}
/// pasa de AUX1 a Aux2-inicia llamando a la funcion cargaPilaUno
void pasaDeUnaPilaAOtra(Pila *x,Pila *y)
{
    ///ESTO ES LA FUNCION DE ARRIBA  QUE ME CARGA UNA PILA
    CargaPilaUno(x);
    printf("pila X puntero de Aux1 despues de carga\n");
    mostrar(x);
    printf("pila Y puntero de Aux2 antes de carga\n");
    mostrar(y);

    while(!pilavacia(x))
    {
        apilar(y,desapilar(x));
    }
    printf("pila X puntero de Aux1 despues de carga a AUX2\n");
    mostrar(x);
    printf("pila Y puntero de Aux2 CARGADA\n");
    mostrar(y);

    system("pause");
}

///Hacer una función que encuentre el menor elemento de una pila y lo retorna.
///La misma debe eliminar ese dato de la pila.

int buscaMenor(Pila *x)
{

    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(x))
    {
        menor=desapilar(x);

        while(!pilavacia(x))
        {

            if(tope(x)<menor)
            {
                apilar(&aux,menor);
                menor=desapilar(x);

            }
            else
            {

                apilar(&aux,desapilar(x));
            }

        }
    }


    while(!pilavacia(&aux))
    {
        apilar(x,desapilar(&aux));
    }
    return menor;
}

///Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
/// Usar la función del ejercicio 4. (Ordenamiento por selección)

void nuevaPila5(Pila A,Pila *B){
    while(!pilavacia(&A)){
        apilar(B,desapilar(&A));
    }

}
