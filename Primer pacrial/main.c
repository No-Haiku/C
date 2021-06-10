#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int cargaTempArreglo(int a[],int v, int dim);
void copiaAPilas(Pila *mayores,Pila *menores, int a[], int v);
void muestraArreglo(int a[],int v);
void muestraPila(Pila p);
int retornaTempMinimo(int a[],int v);
int cuentaTempPila(Pila p, int dato);
int sumaPilaMayoresADato(Pila p,int dato);
int retornaPorcentajeM(Pila p, int dato);
int main()
{
    Pila aux1,aux2;
    inicpila(&aux1);
    inicpila(&aux2);
    int dim=50;
    int arreglo[dim];
    int validos=0;
    int tempMinimo;
    int dato=0;
    int porcentaje;
    int suma;
    int cuenta;
    validos=cargaTempArreglo(arreglo,validos,dim);
    muestraArreglo(arreglo,validos);
    copiaAPilas(&aux1,&aux2,arreglo,validos);
    ///mostrar(&aux1);}
    printf("muestra mayores\n");
    muestraPila(aux1);
    tempMinimo=retornaTempMinimo(arreglo,validos);
    printf("\n");
    printf("minimo es %d\n",tempMinimo);
    ///CAMBIAR EL VALOR DE DATO PARA LAS DIFERENTES FUNCIONES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    dato=0;
    cuenta=cuentaTempPila(aux1,dato);
    printf("cuenta datos pila %d\n",cuenta);
    suma=sumaPilaMayoresADato(aux1,dato);
    printf("suma datos pila %d \n",suma);
    porcentaje=retornaPorcentajeM(aux1,dato);
    printf("EL porcentaje es %d\n",porcentaje);

    return 0;
}

///Hacer una función para cargar un arreglo de temperaturas con intervención del usuario validando que estén dentro
///del rango de valores -100 a 60
///CARGA UN ARREGLO CON TEMPERATURAS MENORES A 60° hasta -100
int cargaTempArreglo(int a[],int v, int dim)
{

    char opcion=0;
    int num;
    while(opcion!=27&&v<dim)
    {
        printf("Ingrese una tempreratura entre -100° y 60°, ESC para salir, cualquier tecla para continuar\n");
        opcion=getch();
        if(opcion!=27)
        {
            printf("Ingrese una temperatura a cargar\n");
            scanf("%d",&num);
            if(num >=-100 && num <=60)
            {
                a[v]=num;
                v++;
            }
            else
            {
                printf("Ingrese una temperatura a cargar\n");
                scanf("%d",&num);
            }
        }

    }
    return v;
}

///Hacer una función que muestre el arreglo de las temperaturas.
///MUESTRA LAS TEMPERATURAS DEL ARREGLO
void muestraArreglo(int a[],int v)
{

    printf("Muestra temperaturas\n");
    for(int i=0; i<v; i++)
    {
        printf("[%d]\n",a[i]);
    }
    printf("\n");
}

///Hacer una función que copie a una pila menores las temperaturas <= 0 y a una pila mayores el resto de las
///temperaturas.

///COPIAS LOS DATOS MENORES A 0 A LA PILA MENORES Y EL RESTO A MAYORES

void copiaAPilas(Pila *mayores,Pila *menores, int a[], int v)
{


    for(int i=0; i<v; i++)
    {
        if(a[i]<=0)
        {
            apilar(menores,a[i]);
        }
        else
        {

            apilar(mayores,a[i]);
        }
    }

}

///Hacer una función que muestre una pila (no usar la función mostrar() de pila).
/// MUESTRA PILA
void muestraPila(Pila p)
{

    int num=0;
    while(!pilavacia(&p))
    {
        num=desapilar(&p);
        printf("[%d]",num);
    }
}
///Hacer una función que encuentre la temperatura mínima en el arreglo y la retorne.
///MUESTRA LA TEMPERATURA MINIMA
int retornaTempMinimo(int a[],int v)
{

int i=0;
int minimo=0;
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
    i=0;
    minimo=a[i];
    return minimo;
}
///Hacer una función que cuente las temperaturas de una pila, mayores a un valor dado (el valor se recibe por
///parámetro).
///PASA A LA VARIABLE CONT LOS VALORES MAYORES A DATO
int cuentaTempPila(Pila p, int dato)
{

    int cont=0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&p))
    {
        apilar(&aux,desapilar(&p));
        if (dato<tope(&aux))
        {
            cont++;
        }
    }
    return cont;
}
///Hacer una función que sume las temperaturas de una pila, mayores a un valor dado (el valor se recibe por
///parámetro).
/// SUMA EN LA VARIABLE SUMA TODOS LAS TEMPERATURAS  MAYORES A DATO, LUEGO LA RETORNA
int sumaPilaMayoresADato(Pila p,int dato)
{

    int suma=0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&p))
    {
        apilar(&aux,desapilar(&p));
        if (dato<tope(&aux))
        {
            suma+=tope(&aux);
        }
    }

    return suma;
}
///Hacer una función que me retorne que porcentaje del total de temperaturas de una pila representan las
///temperaturas mayores a un valor dado (recibido por parámetro).

///RETORNA EL PROMEDIO DE MAYORES
int retornaPorcentajeM(Pila p, int dato){

    int contMatores=0;
    int contTotal=0;
    int promedioMayores=0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&p))
    {
        apilar(&aux,desapilar(&p));
        if (dato<tope(&aux))
        {
            contMatores++;
        }
        contTotal++;
    }
    promedioMayores= contTotal /100 *10;
    return promedioMayores;
}

