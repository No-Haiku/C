#include <stdio.h>
#include <stdlib.h>
///Realizar una funci�n que reciba un n�mero positivo entero por par�metro por referencia, y cambie su signo a negativo.


int main()
{
   int num;
    printf("ingrese un numero\n");
    scanf("%d",&num);
    negativo_num(num);
    return 0;
}

negativo_num(x){

    int resultado;
    int negativo;
    negativo = 0-x;

    resultado=printf("En negativo es %d",negativo);

    return resultado;

}
