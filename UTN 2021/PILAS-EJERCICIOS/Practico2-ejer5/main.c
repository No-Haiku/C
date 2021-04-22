#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Insertar un elemento en una pila ordenada de menor (tope) a mayor (base)
/// de forma tal que se conserve el orden. (sin variables, solo pilas)


int main()
{
    Pila origen,aux1,mayorbase,topemenor,orden;
    inicpila(&orden);
    inicpila(&origen);
    inicpila(&aux1);
    inicpila(&mayorbase);
    inicpila(&topemenor);
    int i;
    int num;
    int numCarga;

    for(i=0; i<10; i++)
    {
        num=i;
        apilar(&origen,num);
    }

    printf("Datos de origen\n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&orden,desapilar(&origen));
    }
    printf("Pila orden");
    mostrar(&orden);

    leer(&aux1);

    while(!pilavacia(&aux1)){

        if (tope(&aux1)<tope(&orden)){
            apilar(&orden,desapilar(&aux1));
        }else if(tope(&aux1)> tope(&orden)){
        apilar(&mayorbase,desapilar(&orden));
        }else
        apilar(&orden,desapilar(&aux1));
    }
    while(!pilavacia(&mayorbase)){
        apilar(&orden,desapilar(&mayorbase));
    }

    printf("Pila orden final del ciclo\n");
    mostrar(&orden);

    return 0;
}
