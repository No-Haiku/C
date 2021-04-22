#include <stdio.h>
#include <stdlib.h>

int main()
{
    int caliNum=0 ;
    int suma=0 ;
    int totaldeSuma=0 ;
    int i=0 ;
    int vueltas=7 ;
    for (i=0; i<7; i++)
    {

        printf("ingrese la nota del alumno\n");
        scanf("%d", &caliNum);
        suma= suma+caliNum;
        ///suma+=califiNum;
    }
    totaldeSuma=suma/i;
    printf("el promedio es %d\n", totaldeSuma);
    return 0;
}
