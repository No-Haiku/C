#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"
void menu();
void CargaPilaUno(Pila *x);
void pasaDeUnaPilaAOtra(Pila *x,Pila *y);
int PilaACopia();
int main()
{
    Pila aux1,aux2,aux3;
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);
    menu(CargaPilaUno,&aux1,&aux2,pasaDeUnaPilaAOtra);

    ///CargaPilaUno(&aux1);
    ///pasaDeUnaPilaAOtra(Pila *x,Pila *y)
    printf("Estos son los datos de Aux1 FINAL DE PROCESO\n");
    mostrar(&aux1);
    printf("Estos son los datos de Aux2 FINAL DE PROCESO\n");
    mostrar(&aux2);

    ///printf("PILA A COPIA %d \n",PilaACopia());



    return 0;
}

void menu(void CargaPilaUno(),Pila *a1, Pila *a2,void pasaDeUnaPilaAOtra())
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

            }

        }




    }
    while(opcion!=27);
}
///carga pila AUX1 se puede mejorar dividiendo la funcion de carga
void CargaPilaUno(Pila *x)
{
    int num=0;
    int n;
    printf("Ingrese el tamanio de la pila AUX1\n");
    scanf("%d",&num);

    for(int i=0; i<num; i++)
    {

        printf("Ingrese el entero a apilar \n");
        scanf("%d",&n);
        apilar(x,n);
    }

    system("pause");
}
/// pasa de AUX1 a Aux2-inicia llamando a la funcion cargaPilaUno
void pasaDeUnaPilaAOtra(Pila *x,Pila *y)
{

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



///Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
/// Usar la función del ejercicio 4. (Ordenamiento por selección)

/*int PilaACopia(){
    int numero =4;
    int numeroC =5;
    int resultado;

    resultado=numeroC;

    return resultado;
}/*/


