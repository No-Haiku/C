#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma
/// tal que la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.


int main()
{
    Pila origen,destino,menor,mayor,basura,pilaMenorBase,aux1,mayor2,descarte;
    inicpila(&descarte);
    inicpila(&aux1);
    inicpila(&basura);
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&menor);
    inicpila(&mayor);
    int temp=0;
    int tam=20;
    int arreglo[20];
    int num=0;
    int i;
    int j=0;
    int q=0;
    int r=0;
    int almacena=0;

    for(i=0; i<tam; i++)
    {
        num=rand()%10;
        apilar(&origen,num);
    }
    printf("Datos de la pila origen segundo for\n");
    mostrar(&origen);

    if(!pilavacia(&origen))
    {
        apilar(&destino,tope(&origen));
    }
    while(!pilavacia(&origen))
    {
        apilar(&basura,desapilar(&origen));
        if(tope(&basura)<tope(&destino))
        {
            apilar(&destino,tope(&basura));
        }

    }
    printf("Datos de basura\n");
    mostrar(&basura);
    if(!pilavacia(&destino))
    {
        apilar(&menor,tope(&destino));
        apilar(&mayor,tope(&destino));
    }
    ///pasar datos de basura a un arreglo
    printf("hola");
    printf("Datos de descarte\n");
    mostrar(&descarte);

    while(!pilavacia(&basura)){

        apilar(&descarte,desapilar(&basura));
        almacena=tope(&descarte);
        arreglo[j]=almacena;
        j++;

    }
    for(j=0; j<tam;j++){

        printf("Datos de arreglo %d \n",arreglo[j]);
    }

    printf("menor datos");
    mostrar(&menor);

    for(q=0; q<tam;q++){
        for(r=0;r<tam-1;r++){
            if (arreglo[r]>arreglo[r+1]){
                temp=arreglo[r];
                arreglo[r]=arreglo[r+1];
                arreglo[r+1]=temp;
            }
        }
    }

        for(int s=0; s<tam;s++){

        printf("Datos de arreglo %d \n",arreglo[s]);
        apilar(&aux1,arreglo[s]);
    }
    printf("aux 1 menor base mayor tope \n");
    mostrar(&aux1);

    return 0;
}
