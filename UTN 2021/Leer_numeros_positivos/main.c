#include <stdio.h>
#include <stdlib.h>
///Leer 10 números e imprimir solamente los números positivos

int main()
{
    int vueltas=10;
    int arreglo[vueltas];
    int numero=0;
    int i=0;

    while(i<vueltas){
        printf("ingrese un numero positivo o negativo\n");
        scanf("%d",&numero);
        if (numero>=0){
            printf("El numero ingresado es %d\n",numero);
        }
        i++;
    }
    return 0;
}
