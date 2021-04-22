#include <stdio.h>
#include <stdlib.h>
///Hacer un algoritmo que calcule el total a pagar por la compra de camisas.
///Si se compran tres camisas o más se aplica un descuento del 20% sobre el total de la compra
/// y si son menos de tres camisas un descuento del 10%



int main()
{
    int totCamisas=0;
    float totPrecio=0;
    int promo3Camisas=3;
    int descuento3=20;
    int descuento2=10;

    printf("Ingrese el total de camisas que compra \n");
    scanf("%d",&totCamisas);
    printf("Ingrese el precio total de las camisas\n");
    scanf("%f",&totPrecio);

    if (totCamisas >= promo3Camisas){
        descuento3= totPrecio *descuento3 /100;
        totPrecio= totPrecio-descuento3;

        printf("EL precio con descuento de 20%% es %.2f", totPrecio);
    }
    else{
        descuento2= totPrecio *descuento2 /100;
        totPrecio= totPrecio-descuento2;
        printf("Descuento del 10%% paga %.2f",totPrecio);
    }
    return 0;
}
