#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define DIM 10

int cargaUnArregloRandom();
void muestraArreglo();
int sumaArreglo();
int cargaPilaXArreglo();
void muestraPila();
float cargaArregloFloatR();
void muestraArregloFloast();
char cargaCharArreglo();
void muestraArregloC();
int main()
{
    Pila aux,aux2,aux3;
    inicpila(&aux);
    inicpila(&aux2);
    inicpila(&aux3);
    int validos=0;
    int arreglo[DIM];
    int opcion=0;
    int num;




    do
    {
        printf("**************menu*************\n");
        printf("Precione ESC para salir, calquier tecla para continuar\n");
        opcion=getch();


        if(opcion!=27)
        {

            printf("Precione un numero del 1 al 12 para elegir el ejercicio\n");
            scanf("%d",&num);

            switch(num)
            {
            case 1:
                printf("Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).\n");
                validos=0;
                validos=cargaUnArregloRandom(arreglo,validos,DIM);
                printf("Muestra Validos %d\n",validos);
                printf("Muestra arreglo\n");
                muestraArreglo(arreglo,validos);
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.\n");
                validos=0;
                validos=cargaUnArregloRandom(arreglo,validos,DIM);
                printf("\n");
                printf("Validos %d\n",validos);
                printf("Muestra arreglo \n");
                muestraArreglo(arreglo,validos);
                system("pause");
                system("cls");
                break;
            case 3:
                printf("Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos. \n");
                validos=0;
                int suma=0;
                validos=cargaUnArregloRandom(arreglo,validos,DIM);
                printf("\n");
                printf("Validos %d\n",validos);
                printf("Muetra arreglo \n");
                muestraArreglo(arreglo,validos);
                suma=sumaArreglo(arreglo,validos);
                printf("LA suma de los valores del arreglo es %d \n",suma);
                system("pause");
                system("cls");

                break;
            case 4:
                printf("Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.\n");
                validos=0;
                int recibePila;
                validos=cargaUnArregloRandom(arreglo,validos,DIM);
                printf("Validos %d\n",validos);
                printf("Muestra arreglo \n");
                muestraArreglo(arreglo,validos);
                recibePila=cargaPilaXArreglo(arreglo,&aux,validos);
                printf("Los datos almacenados en la pila son \n");
                muestraPila(recibePila);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                printf("Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. \n(se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)\n");
                validos=0;
                float arreglo[DIM];
                validos=cargaArregloFloatR(arreglo,validos,DIM);

                printf("\nLos datos en el arreglo FLOTANTE son\n");
                muestraArregloFloast(arreglo,validos);
                system("pause");
                system("cls");
                break;
            case 6:
                printf("Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres. \n");

                char arregloC[DIM];
                validos=0;
                validos=cargaCharArreglo(arregloC,validos,DIM);
                printf("Estos son los datos dentro del arreglo\n");

                muestraArregloC(arreglo,validos);

            }

        }

    }
    while(opcion!=27);

    return 0;
}



int cargaUnArregloRandom(int a[],int validos,int dim)
{
    int i;
    for(i=validos; i<dim; i++)
    {
        a[i]=i;///rand()%100
    }
    return i;
}

void muestraArreglo(int arreglo[], int v)
{
    for(int i=0; i<v; i++)
    {
        printf("%d - ", arreglo[i]);
    }
    printf("\n");
}
int sumaArreglo(int a[],int v)
{

    int suma=0;
    for(int i=0; i<v; i++)
    {
        suma+=a[i];
    }
    return suma;
}

int cargaPilaXArreglo(int a[],Pila *b,int v)
{

    for (int i=0; i<v; i++)
    {
        apilar(b,a[i]);
    }

    return b;
}

void muestraPila(Pila *a)
{

    mostrar(a);
}

float cargaArregloFloatR(float a[],int v,int dim)
{
    int i=0;
    for(i=v; i<dim; i++)
    {
        a[i]=rand()%7500 / 1000.0f;
    }
    return i;
}
void muestraArregloFloast(float a[],int v)
{
    int i=0;
    for(i=0; i<v; i++)
    {
        printf("-- %.3f --",a[i]);
    }
    printf("\n");
}

char cargaCharArreglo(char a[],int v, int dim){
    int i=0;
     int opcion=0;
     char letra=0;
    while (i<dim && opcion != 27){
        system("cls");
        printf("Ingrese un caracter para guardar en el arreglo\n");
        fflush(stdin);
        scanf("%s",&a[i]);
        ///a[i]=letra;

        printf("Precione ESC para salir \n");
        opcion=getch();
        i++;

    }
    return i;

}

void muestraArregloC(int arreglo[], int v)
{
    for(int i=0; i<v; i++)
    {
        printf("%s - ", arreglo[i]);
    }
    printf("\n");
}
