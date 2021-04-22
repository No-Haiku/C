#include <stdio.h>
#include <stdlib.h>
///CALCULAR PROMEDIO DECALIFICACIONES
int main()
{
    int nota[3];
    int nota1=0;
    int resultado=0;
    int sumatoria=0;
    int notaActual=0;

    for (int i=1;i<=3;i++){
     printf("Ingrese la %d nota :\n",i);
     scanf("%d",&nota1);
        nota[i]=nota1;
        notaActual=nota[i];
        sumatoria +=notaActual;
        printf("La sumatoria %d :\n",sumatoria);
        printf("--------------------------------");
        printf("Nota en nota i del contador en arreglo %d : \n ",nota[i]);
        ///r++;


    }
    resultado= sumatoria/3;
    printf("EL PROMEDIO ES %d :", resultado);




    return 0;
}
