#include <stdio.h>
#include <stdlib.h>
///Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos.
///Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.
int main()
{
    int vueltas=5;
    int arreglo[vueltas];
    int calificacion=0;
    int promedio=0;
    int i=0;
    int j=0;
    int aux=0;

    for(i=0; i<vueltas; i++)
    {
        printf("Ingrese la calificacion\n");
        scanf("%d",&calificacion);
        arreglo[i]=calificacion;
        promedio+=arreglo[i];
    }
    for(i=0; i<vueltas; i++)
    {
        for(j=0; j<vueltas-1; j++)
        {
            if(arreglo[j]>arreglo[j+1]) /// RECORDATORIO---> EL J+1 SUMA 1 POSICION NO ES LO MISMO QUE J++
            {
                aux=arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=aux;
            }

        }
    }
    /// Promedio

    promedio=promedio/vueltas;
    printf("\nEl promedio es %d ",promedio);

    ///nota mas baja
    for(i=0; i<vueltas; i++)
    {
        if (arreglo[i]== arreglo[0])
        {
            printf("\n---Arreglo--- Nota mas baja %d",arreglo[i]);
        }



    }


    return 0;
}
