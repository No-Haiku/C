#include <stdio.h>
#include <stdlib.h>
///Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente
int main()
{
    int i,j;
    int temp;///temporal
    int num;
    int numTam=4;
    int arreglo [numTam];
    ///printf("Ingrese cantidad de numeros a capturar\n");
    ///scanf("%d",&numTam);

    for(i=0; i<numTam; i++)
    {
        printf("Ingrese numero a guardar\n");
        scanf("%d",&num);
        arreglo[i]=num;
    }

    for(i=0; i<numTam; i++)
    {   ///printf("Valor de tam PRIMER for %d: \n",numTam);
        for(j=0; j<numTam-1; j++)///el -1 para iniciar numTam en 0 y no contar basura
        {
            ///printf("Valor de tam segundo for %d: \n",numTam);
            if(arreglo[j]>arreglo[j+1])/// cambia "<" a ">" para cambiar la manera de ordenar
            {
                temp=arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=temp;
            }
        }
    }

    for (i = 0; i < numTam; i++)
    {
        printf("%d ", arreglo[i]);
    }


return 0;
}
