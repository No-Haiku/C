#include <stdio.h>
#include <stdlib.h>
#include <math.h>
///fabs() pasa de negativo a positivo
///Leer 15 números negativos y convertirlos en positivos e imprimir dichos números.
int main()
{
    int vueltas=15;
    float arreglo[vueltas];
    float numero=0;
    int i=0;

    while(i<vueltas){
        printf("ingrese un numero negativo\n");
        scanf("%f",&numero);
        if (numero<0){
            printf("El numero negativo ingresado fue %2.f convertido a positivo es %2.f\n",numero,fabs(numero));
        }
        i++;
    }
    return 0;
}
