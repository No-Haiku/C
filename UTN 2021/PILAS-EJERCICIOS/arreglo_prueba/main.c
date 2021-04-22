#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int cargaUnArregloRandom();
void muestraArreglo();
int main()
{
    int validos=0;
    int arreglo[DIM];

    validos=cargaUnArregloRandom(arreglo,validos,DIM);
    printf("Muestra Validos %d\n",validos);
    printf("Muestra arreglo\n");
    muestraArreglo(arreglo,validos);
    return 0;
}



int cargaUnArregloRandom(int a[],int validos,int dim)
{
    int i;
    for(i=validos; i<dim; i++)
    {
        a[i]=i;///rand()%100
    }
    return i;
}

void muestraArreglo(int arreglo[], int v)
{
    for(int i=0; i<v; i++)
    {
        printf("%d - ", arreglo[i]);
    }
}
