#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define ESC 27

///10. Comparar las pilas A y B, evaluando si son completamente iguales
///(en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.



int main()
{
    Pila a,b,aux1,aux2;
    inicpila(&a);
    inicpila(&b);
    inicpila(&aux1);
    inicpila(&aux2);
    int num;
    char opcion;
    int bolean=0;

   for(int i=0; i<10;i++){
        ///num=rand()%10;
        num=i;
        apilar(&a,num);
    }
    printf("Datos en pila A\n");
    mostrar(&a);

    for(int i=0; i<10;i++){
        ///num=rand()%10;
        num=i;
        apilar(&b,num);
    }
    printf("Datos en pila B\n");
    mostrar(&b);

    while(!pilavacia(&a) && !pilavacia(&b) && bolean==0)
    {
        if(tope(&a)== tope(&b))
        {
            apilar(&aux1,desapilar(&a));
            apilar(&aux2,desapilar(&b));
        }

        bolean=1;
        printf("boleano =1\n");


    }

    if(!pilavacia(&a)&&!pilavacia(&b)&& bolean ==0){
        printf("Las pilas son diferentes!!!\n");
    }else(printf("Las pilas son igualees!!!\n"));


    return 0;
}
