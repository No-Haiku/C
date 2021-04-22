#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///12. Suponiendo la existencia de una pila MODELO (vacía o no),
///eliminar de la pila DADA todos los elementos que existan en MODELO.

int main()
{
    Pila modelo,dada,aux1,aux2,aux3;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);
    int num;
    int i;

    for(i=0;i<5;i++){
        num=rand()%15;
        apilar(&modelo,num);
    }
    printf("Datos de modelo antes del while\n");
    mostrar(&modelo);
    for(i=0;i<10;i++){
        ///num=rand()%10;
        num=i;
        apilar(&dada,num);
    }
    printf("Datos de dada antes del while\n");
    mostrar(&dada);
///comprueba si el tope de dada es igual a modelo
    while(!pilavacia(&modelo)){
    ///desapila dada y verifica si contiene los mismo elementos de modelo
        while(!pilavacia(&dada)){

            if(tope(&modelo)==tope(&dada)){
                apilar(&aux1,desapilar(&dada));
            }else///de lo contrario lo manda a AUX2
                  apilar(&aux2,desapilar(&dada));

                                                }///Si AUX2 tiene datos lo devuelve a dada para volver a revisar
        while(!pilavacia(&aux2)){
                    apilar(&dada,desapilar(&aux2));
                  }///despues del ciclo de dada desapilo modelo
    apilar(&aux3,desapilar(&modelo));
    }
    printf("***Datos eliminados de dada pasados a AUX1\n");
    mostrar(&aux1);
    printf("****Datos no iguales de dada \n");
    mostrar(&dada);
    printf("******Datos eliminados de MODELO pasados a AUX3\n");
    mostrar(&aux3);


    return 0;
}
