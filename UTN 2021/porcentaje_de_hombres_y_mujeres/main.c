#include <stdio.h>
#include <stdlib.h>
///CALCULAR EL PORCENTAJE DE HOMBRES Y MUJERES

int main()
{
    int totalHombres=0;
    int totalMujeres=0;
    int totalAlumnos=0;
    int porcentajeHombres=0;
    int porcentajeMujeres=0;
    int resultadoHombres=0;

    printf("Ingrese el total de hombres\n");
    scanf("%d",&totalHombres);
    printf("Ingrese el total de mujeres\n");
    scanf("%d",&totalMujeres);

    totalAlumnos= totalHombres+totalMujeres;

    porcentajeHombres= totalHombres*100/totalAlumnos;
    porcentajeMujeres= totalMujeres*100/totalAlumnos;


    printf("El total de hombres es %d %% \n",porcentajeHombres);
    printf("El total de mujeres es %d %% \n",porcentajeMujeres);
    return 0;
}
