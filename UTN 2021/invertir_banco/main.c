#include <stdio.h>
#include <stdlib.h>
///INVERTIR CAPITAL EN UN BANCO / GANANCIA MENSUAL 2%
int main()
{
    int montoInvertir=0;
    int porcentajeGanancia=2;
    int totalGananciaMes=0;
    int reglaDeTres=0;

    printf("Bienvenido a el banco\n");

    printf("Ingrese monto a invertir\n");

    scanf("%d",&montoInvertir);

    reglaDeTres= montoInvertir * porcentajeGanancia /100;

    totalGananciaMes= montoInvertir+reglaDeTres;

    printf("La ganancia con una taza del 2%% mensual es %d",totalGananciaMes);

    return 0;
}
