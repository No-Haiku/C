#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///14. Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX
///a la pila PAR y si es impar pasar el tope a la pila IMPAR.

int main()
{
    Pila dada,aux1,par,impar;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&par);
    inicpila(&impar);
    int i;
    int j=0;
    int num;
    int resultado;
    for(i=0; i<11; i++)
    {
        num=i;
        apilar(&dada,num);
    }
    printf("Datos en la pila DADA");
    mostrar(&dada);
    while(!pilavacia(&dada))
    {
        apilar(&aux1,desapilar(&dada));
        j++;
    }
    printf("J %d\n",j);
    resultado=j%2;

    printf("Resultado %d\n",resultado);
    if(resultado==0)
    {
        apilar(&par,tope(&aux1));
        printf("Datos en la pila son PAR\n");
        printf("TOPE de PAR\n");
        mostrar(&par);
    }else{
    apilar(&impar,tope(&aux1));
    printf("Datos en la pila son IMPAR\n");
    printf("TOPE de IMPAR\n");
    mostrar(&impar);
    }


    return 0;
}
