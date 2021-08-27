#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cargaArreglo(int a[],int dim, int v);
int cargaArreglouser(int a[],int dim,int v);
void calculaPromedio(int v, int s);
int sumaArregloo(int a[],int dim);
char cargaCaracterArreglo(char a[],int dim , int v);
void muestraUnCaracter(char a[],int v);
char invierteCaracterArreglo(char a[],int v,int dim);
int retornaDecimal(int a[],int v);
int main()
{
    int dim =10;
    int arreglo[dim];
    int v=0;
//    int s=0;
//    v=cargaArreglo(arreglo,dim,v);
//    muestraArreglo(arreglo,v);
//    v=0;
//    v=cargaArreglouser(arreglo,dim,v);
//    muestraArreglo(arreglo,v);
//    s=sumaArregloo(arreglo,dim);
//    calculaPromedio(v,s);
///ejercicio 2
//int dim =4;
//char arregloC[dim];
//int v=0;
//v=cargaCaracterArreglo(arregloC,dim,v);
//
//muestraUnCaracter(arregloC,v);
//
//invierteCaracterArreglo(arregloC,v,dim);
//printf("arreglo invertido caracter\n");
//muestraUnCaracter(arregloC,v);
///EJERCICIO3
 v=cargaArreglo(arreglo,dim,v);
 printf("Retorna un decimal %d\n",retornaDecimal(arreglo,v));

    return 0;
}
//1. Se tiene un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:
//a. Hacer una función que inicialice las celdas del arreglo en –1.
//b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
//c. Hacer una función que sume el contenido del arreglo y lo retorne.
//d. Hacer una función que cuente la cantidad de valores ingresados.
//e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio
//usando las funciones anteriores (c y d).
//f. Hacer la función main correspondiente.

//int cargaArreglo(int a[],int dim, int v)
//{
//    for(int i=0; i<dim; i++)
//    {
//        a[i]=-1;
//        v=i;
//    }
//    return v;
//}
//void muestraArreglo(int a[],int v)
//{
//
//    for(int i=0; i<v; i++)
//    {
//        printf("[%d]\n",a[i]);
//    }
//}
//int cargaArreglouser(int a[],int dim,int v)
//{
//    char opcion=0;
//    int i=v;
//    int num=0;
//    while(i<dim&&opcion!=27)
//    {
//        printf("ingrese un numero positivo\n");
//        scanf("%d",&num);
//        if(num<0)
//        {
//            while(num<0)
//            {
//                printf("ERROR ingrese un numero positivo\n");
//                scanf("%d",&num);
//            }
//        }
//        a[i]=num;
//        i++;
//        printf("print i %d y dim %d\n",i,dim);
//        printf("Escape pasa salir\n");
//        opcion=getch();
//    }
//    v=i;
//    return v;
//}
//int sumaArregloo(int a[],int dim)
//{
//    int suma=0;
//    for(int i=0; i<dim; i++)
//    {
//        printf("[%d]\n",a[i]);
//        if(a[i]>0){
//            suma+=a[i];
//        }
//    }
//    return suma;
//}
//void calculaPromedio(int v,int s){
//    int promedio=0;
//    promedio=s/v;
//
//    printf("El promedio es %d\n", promedio);
//
//
///EJERCICIO 2
//2. Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
//a. Hacer una función para la carga del arreglo.
//b. Hacer una función para invertir el arreglo.
//c. Hacer una función para mostrar el contenido del arreglo.
//d. Hacer la función main con el menú correspondiente.

//char cargaCaracterArreglo(char a[],int dim , int v){
//    int i=0;
//
//    for(i=v; i<dim;i++){
//        printf("ingrese un caracter\n");
//        fflush(stdin);
//        scanf("%c",&a[i]);
//
//    }
//    v=i;
//    return v;
//}
//void muestraUnCaracter(char a[],int v){
//    printf("hola");
//    for(int i=0;i<v;i++){
//        printf("\n [%c]",a[i]);
//    }
//}
//
//char invierteCaracterArreglo(char a[],int v,int dim){
//
//    char tempAr [dim];
//    int j=0;
//    printf("validos %d\n",v);
//    for(int i=v-1;i>-1;--i){
//    printf("valor de i %d\n",i);
//       tempAr[j]=a[i];
//       j++;
//
//    }
//    //muestraUnCaracter(tempAr,v);
//    for(int k=0; k<v;k++){
//
//        a[k]=tempAr[k];
//    }
//
//}
///EJERCICIO 3
///3. Hacer una función que reciba como parámetro un arreglo de números enteros de un dígito y retorne el valor decimal
/// de dicho número. Por ejemplo, un arreglo que tiene cargados los valores 3, 2, 8 y 9, la fn retorna el valor 3289.


int cargaArreglo(int a[],int dim, int v){

    char opcion=0;

    while(v<dim && opcion!=27){
        printf("ingrese un numero\n");
        scanf("%d",&a[v]);
        v++;
        printf("precione ESC para salir\n");
        opcion=getch();

    }

    return v;
}

int retornaDecimal(int a[],int v){

    int numdecimal=0;

    for(int i=0;i<v;i++){

        numdecimal+=a[i];
            if(i<v-1){
        numdecimal*=10;
            }
    }

    return numdecimal;
}

