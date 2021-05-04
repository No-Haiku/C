#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
int cargaArregloUser(int a[],int v, int dim);
void muestraArreglo();
int sumaAreglo(int a[],int v);
int cargaPilaxArreglo(Pila *p,int a[],int v);
char ArregloCaracteres(char a[],int v, int dim);
char encuentraCaracterArreglo(char a[],int v,char dato);
void ingresaCaracterOrdenAlfa(char a[],int v);
void muestraArregloC(char a[],int v);
int main()
{
    Pila aux;
    inicpila(&aux);

    int dim=100;
    int arreglo [dim];
    int validos=0;
    char arregloC [dim];
    int vC=0;
    int suma;

    /* validos=cargaArregloUser(arreglo,validos,dim);
     printf("Validos es %d\n",validos);

     muestraArreglo(arreglo,validos);

     suma=sumaAreglo(arreglo,validos);
     printf("suma arreglo\n La suma es %d\n",suma);

     printf("Carga pila x arreglo\n");
     cargaPilaxArreglo(&aux,arreglo,validos);
     mostrar(&aux);
     */
    vC=ArregloCaracteres(arregloC,vC,dim);
    ///printf("ingrese un texto\n");
    ///scanf("%s",arregloC);
    printf("Validos de string char es %d\n",vC);
    printf("Datos dentro del arreglo de caracteres %s\n",arregloC);

    char dato='a';
    int validacion;
    validacion=encuentraCaracterArreglo(arregloC,vC,dato);

    if(validacion>=0)
    {
        printf("El caracter se encontro en la pocicion %d\n",validacion);
    }
    else
    {
        printf("EL caracter no se encontro\n");
    }

    printf("ingrese un caracter \n");
    fflush(stdin);
    scanf("%s",&dato);
    ///dato='o';
    arregloC[vC]=dato;
    vC++;
    printf("Dato ingresado para ordenar %s\n",arregloC);
    ingresaCaracterOrdenAlfa(arregloC,vC);
    printf("Areglo con dato ingresado en orden %s",arregloC);
    muestraArreglo(arregloC,vC);

    return 0;
}

///Hacer una función que reciba como parámetro un arreglo de números enteros
///y permita que el usuario ingrese valores al mismo por teclado.
///La función debe retornar la cantidad de elementos cargados en el arreglo
///(o pueden utilizar como puntero válidos).

int cargaArregloUser(int a[],int v, int dim)
{

    char opcion=0;
    int num=0;

    while(opcion!=27)
    {
        printf("Precione ESC para salir , cualquier tecla para continuar \n");
        opcion=getch();

        if(opcion!=27)
        {
            printf("Ingrese un entero al arreglo\n");
            scanf("%d",&num);
            a[v]=num;
            v++;
        }
    }
    return v;
}

///Hacer una función que reciba como parámetro un arreglo
/// y la cantidad de elementos (válidos) cargados en él
///y los muestre por pantalla.

void muestraArreglo(int a[],int v)
{

    for(int i=0; i<v; i++)
    {
        printf("[%d]",a[i]);
    }
    printf("\n");
}
///Hacer una función que reciba como parámetro un arreglo y
///la cantidad de elementos (válidos) cargados en él
///y calcule la suma de sus elementos.

int sumaAreglo(int a[],int v)
{
    int suma=0;
    for(int i=0; i<v; i++)
    {
        a[i];
        suma+=a[i];
    }
    return suma;
}

///Hacer una función que reciba como parámetro un arreglo,
///la cantidad de elementos (válidos) cargados en él y una Pila.
///La función debe copiar los elementos del arreglo en la pila.

int cargaPilaxArreglo(Pila *p,int a[],int v)
{
    for(int i=0; i<v; i++)
    {
        apilar(p,a[i]);
    }

    return p;
}
///Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.

char ArregloCaracteres(char a[],int v, int dim)
{

    char opcion=0;
    while(opcion!=27&& v<dim)
    {
        printf("Precione ESC para salir, cualquier tecla para continar \n");
        opcion=getch();
        if(opcion!=27)
        {
            printf("ingrese un texto\n");

            scanf("%s",a);

            v=strlen(a);
        }

    }
    return v;

}
char encuentraCaracterArreglo(char a[],int v,char dato)
{

    int flag=-1;
    int i=0;
    while(i<v&&flag==-1)
    {
        if(a[i]== dato)
        {
            flag=i;
        }
        i++;
    }
    return flag;
}

///Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.

void ingresaCaracterOrdenAlfa(char a[],int v)
{
    int i=0;
    int j=0;
    int temp;
    for(i=0;i<v;i++){

            for(j=0; j<v-1; j++)///V-1 porque la ultima pocicion de V es basura
            {
                if(a[j] > a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}
void muestraArregloC(char a[],int v){

    for(int i=0; i<v;i++){
        printf("[%c]\n",a[i]);
    }
}
