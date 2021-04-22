#include <stdio.h>
#include <stdlib.h>
///Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor.
int menor_Y_mayor(x,y,z);
int main()
{
    int a=0;
    int b=0;
    int c=0;
    printf("ingrese un numero\n");
    scanf("%d",&a);
    printf("ingrese un numero\n");
    scanf("%d",&b);
    printf("ingrese un numero\n");
    scanf("%d",&c);

    menor_Y_mayor(a,b,c);
    return 0;
}

int menor_Y_mayor(x,y,z)
{
    int result;

    if(x>z && x>y && z<y)
    {

        result=printf("el numero mayor es %d el menor es %d\n",x,z);
    }
    else if(x>z && x>y && y<z)
    {

        result=printf("el numero mayor es %d el menor es %d\n",x,y);
    }
    else if(z>x && z>y && x<y)
    {

        result=printf("el numero mayor es %d el menor es %d\n",z,x);
    }
    else if(z>x && z>y && y<x)
    {

        result=printf("el numero mayor es %d el menor es %d\n",z,y);
    }
    else if(y>z && y>x && z<x)
    {

        result=printf("el numero mayor es %d el menor es %d\n",y,z);
    }
    else if(y>z && y>x && x<z)
    {

        result=printf("el numero mayor es %d el menor es %d\n",y,x);
    }
    else
    {
        result=printf("son iguales tosdos\n");
    }

    return result;
}
