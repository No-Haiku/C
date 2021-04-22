#include <stdio.h>
#include <stdlib.h>
#include <math.h>
///pow() sacar potencia
///Leer 10 números y obtener su cubo y su cuarta.
int main()
{
    int vueltas=10;
    float arreglo[vueltas];
    float numero=0;
    int  potenciaCubo=3;
    int potenciaCuarta=4;
    int i=0;
    float totalPotencia3=0;
    float totalPotencia4=0;

    while(i<vueltas){
        printf("intentos %d de 10\n",i+1);
        printf("Ingree los numeros \n");
        scanf("%f",&numero);
        arreglo[i]=numero;
        totalPotencia3= pow(arreglo[i],potenciaCubo);
        printf("la potencia al cuadrado de %2.f es %2.f\n",numero,totalPotencia3);
        totalPotencia4= pow(arreglo[i],potenciaCuarta);
        printf("la potencia a la cuarta de %2.f es %2.f\n",numero,totalPotencia4);
        i++;
    }

    return 0;
}
