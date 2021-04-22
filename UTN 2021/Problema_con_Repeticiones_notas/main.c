#include <stdio.h>
#include <stdlib.h>
///Calcular el promedio de un alumno que tiene 7 calificaciones en la materia de Programación 1

int main()
{
    int vueltas=7;
    int calificaciones[vueltas];
    int dameNota=0;
    char continuar='s';
    int suma=0;
    int i=0;
    int promedio=0;

    while(i<vueltas){
        printf("\n ingrese la primer nota \n");
        scanf("%d",&dameNota);
        calificaciones[i]=dameNota;
        suma+=calificaciones[i];
        i++;
        printf("\n La suma es: %d \n",suma);

        if (i == vueltas){
            promedio=suma/i;

            printf("\n El promedio es :%d",promedio);
        }
    }
    return 0;
}
