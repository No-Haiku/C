#include <stdio.h>
#include <stdlib.h>
///Leer tres números diferentes e imprimir el número mayor de los tres.
int main()
{
    int numero1=0;
    int numero2=0;
    int numero3=0;

    printf("ingrese los 3 numeros\n ");
    scanf("%d",&numero1);
    scanf("%d",&numero2);
    scanf("%d",&numero3);

    printf("los numeros ingresados son %d - %d- %d\n",numero1,numero2,numero3);

    if(numero1> numero2){
        printf(" el numero mero mayor es ");
    }

    return 0;
}
