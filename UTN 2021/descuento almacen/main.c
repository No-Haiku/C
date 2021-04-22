#include <stdio.h>
#include <stdlib.h>
///En un almacén se hace un 20% de descuento a los clientes cuya compra supere los
/// $5000 ¿Cuál será la cantidad que pagara una persona por su compra?

int main()
{
    float descuento=20;
    float montoAPagar=0;
    float reglaDeTres=0;
    float totalAPagar=0;
    float entraEnDescuento=5000;
    char comando='s';

    while (comando == 's')
    {
        printf("Bienvenido ingrese el monto de su compra!\n");
        scanf("%f",&montoAPagar);

        if (montoAPagar >= entraEnDescuento)
        {
            reglaDeTres= montoAPagar * descuento/100;
            totalAPagar= montoAPagar-reglaDeTres;
            printf("El total con descuento es: %.2f\n",totalAPagar);
        }
        else
        {
            printf("no hay descuento\n");
        }

        printf("Para continuar precione s ");
        fflush(stdin);
        scanf("%c",&comando);





    }

    return 0;
}
