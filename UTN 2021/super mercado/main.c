#include <stdio.h>
#include <stdlib.h>

/// un supermercado ofrece un descuento del 15% en el total de la compra

int main()
{
    int porcentajeDescuento=15;
    int descuento=0;
    int totCompra=0;
    int totApagar=0;
    printf("ingrese el total de su compra\n");
    scanf("%i", &totCompra);
    descuento = totCompra *porcentajeDescuento/100;

    totApagar= totCompra - descuento;

    printf("El total a pagar es %i",totApagar);
    return 0;
}
