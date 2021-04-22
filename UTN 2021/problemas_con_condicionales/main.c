#include <stdio.h>
#include <stdlib.h>
///Leer 2 números; si son iguales que los multiplique,
///si el primero es mayor que el segundo que los reste y si no que los sume.
int main()
{
    int num1=0;
    int num2=0;
    int total=0;
    printf("Ingrese el primer numero entero\n");
    scanf("%d",&num1);
    printf("Ingrese el segundo numero entero\n");
    scanf("%d",&num2);

    if (num1== num2){
        total=num1*num2;
        printf("Son iguales ,La multiplicacion es %d\n",total);
    }
    else if(num1>num2){
        total=num1-num2;
        printf("El primero es mayor,La resta es %d \n",total);
    }
    else  {
        total= num1+num2;
        printf("Este es el else, La suma es %d",total);
    }
    return 0;
}
