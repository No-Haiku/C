#include <stdio.h>
#include <stdlib.h>

///Dise�e una funci�n que reciba un n�mero entero N y realice la suma de los n�meros enteros positivos menores que N
///y lo retorne. N es un  dato ingresado por el usuario en el main.


int main()
{
    int num;
    printf("ingrese un numero\n");
    scanf("%d",&num);

    retorna_nrs_menores_aN(num);
    return 0;
}

int retorna_nrs_menores_aN(x){

        int resultado;
        for(int i=0; i<x; i++){
            resultado=printf("%d",i);
        }
        return resultado;
}
