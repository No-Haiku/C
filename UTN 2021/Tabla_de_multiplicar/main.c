#include <stdio.h>
#include <stdlib.h>
///Calcular e imprimir la tabla de multiplicar de un número cualquiera.
///Imprimir el multiplicando, el multiplicador y el producto.
int main()
{
    int numeros=10;
    int arregloNumeros[numeros];
    int multiplicador=2;
    int producto=0;

    for(int i=0;i<=numeros;i++){
        arregloNumeros[i]=i*multiplicador;
        printf("\nEl multiplicado es %d el multiplicador es %d y el producto es %d ",i,multiplicador,arregloNumeros[i]);
    }
    return 0;
}
