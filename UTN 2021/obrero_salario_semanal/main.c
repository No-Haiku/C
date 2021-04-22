#include <stdio.h>
#include <stdlib.h>
///Un obrero necesita calcular su salario semanal, el cual se obtiene de la sig. manera: Si trabaja 40 horas o menos
///se le paga $300 por hora Si trabaja más de 40 horas se le paga $300 por cada una de las primeras 40 horas y $400
/// por cada hora extra.
int main()
{
    float horasPlusCobro=0;
    float horasSemanales=0;
    float semanalesMinima=40;
    float horasMinimo=300;
    float horasExtra=400;
    float totalSemanal=0;
    printf("Ingrese la cantidad de hrs semanales trabajadas\n");
    scanf("%f",&horasSemanales);
    ///Horas semanasles mas horas extra total ganancia
    if (horasSemanales> semanalesMinima){
        horasPlusCobro= horasSemanales-semanalesMinima;
        horasPlusCobro= horasPlusCobro*horasExtra;
        semanalesMinima=semanalesMinima*horasMinimo;
        totalSemanal= horasPlusCobro+semanalesMinima;

        printf("Total horas semanales con extras es %2.f $\n", totalSemanal);
    }
    else {
        printf("no hay horas extra\n");
    }
    return 0;
}
