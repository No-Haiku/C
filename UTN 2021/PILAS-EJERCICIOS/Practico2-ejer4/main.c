#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)


int main()
{
    Pila origen,destino,menor,mayor,basura;
    inicpila(&basura);
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&menor);
    inicpila(&mayor);
    int num=0;
    int i;

    for(i=4;i<10;i++){
        num=i;///rand()%10;
        apilar(&origen,num);
    }
    printf("Datos de la pila origen\n");
    mostrar(&origen);
    apilar(&origen,3);
    mostrar(&origen);
    for(i=15;i<20;i++){
        num=i;///rand()%10;
        apilar(&origen,num);
    }

    if(!pilavacia(&origen)){
        apilar(&destino,tope(&origen));
    }
     while(!pilavacia(&origen)){
            apilar(&basura,desapilar(&origen));
          if(tope(&basura)<tope(&destino)){
            apilar(&destino,tope(&basura));
          }

    }
    if(!pilavacia(&destino)){
        apilar(&menor,tope(&destino));
    }

   ///printf("Datos de la pila mayor \n");
  /// mostrar(&mayor);
   printf("datos de la pila menor\n");
   mostrar(&menor);

    return 0;
}
