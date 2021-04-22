#include <stdio.h>
#include <stdlib.h>
///Realice una pequeña calculadora, utilizando funciones (una función de suma,
///una de multiplicación, una de resta, una de división…)

int divide(x,y);
int suma(x,y);
int resta(x,y);
int multiplicar(x,y);
int main()
{
    int num;
    int n1,n2;
    printf("Ingrse 1 para suma\nIngrese 2 para resta\nIngrese 3 para multiplicar\nIngrese 4 para dividir\n");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        printf("Ingrese los numeros a sumar\n");
        printf("Primer numero:\n");
        scanf("%d",&n1);
        printf("Segundo numero:\n");
        scanf("%d",&n2);
        suma(n1,n2);

        break;
    case 2:
        printf("Ingrese los numeros a restar\n");
        printf("Primer numero:\n");
        scanf("%d",&n1);
        printf("Segundo numero:\n");
        scanf("%d",&n2);
        resta(n1,n2);

        break;

    case 3:
        printf("Ingrese los numeros a multiplicar\n");
        printf("Primer numero:\n");
        scanf("%d",&n1);
        printf("Segundo numero:\n");
        scanf("%d",&n2);
        multiplicar(n1,n2);

        break;
    case 4:
        printf("Ingrese los numeros a dividir\n");
        printf("Primer numero:\n");
        scanf("%d",&n1);
        printf("Segundo numero:\n");
        scanf("%d",&n2);
        divide(n1,n2);

        break;

    }


    return 0;
}

int suma(x,y)
{
    int resultado;
    int suma;

    suma=x+y;
    resultado=printf("El resultado de la suma es %d\n",suma);

    return resultado;

}
int resta(x,y)
{
    int resultado;
    int resta;

    resta=x-y;
    resultado=printf("El resultado de la resta es %d\n",resta);

    return resultado;

}
int multiplicar(x,y)
{
    int resultado;
    int multi;

    multi=x*y;
    resultado=printf("El resultado de la multiplicacion es %d\n",multi);

    return resultado;

}
int divide(x,y)
{
    int resultado;
    int division;
    if (y==0)
    {
       resultado=printf("no se puede dividir por 0");

    }

        division=x/y;
        resultado=printf("El resultado de la division es %d\n",division);




    return resultado;

}

