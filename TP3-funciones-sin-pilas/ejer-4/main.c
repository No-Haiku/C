#include <stdio.h>
#include <stdlib.h>
///Desarrollar una funci�n que muestre la tabla de multiplicar de un n�mero entero recibido por par�metro.


int main()
{
    int num;
    printf("ingrese el numero para ver la tabla de multiplicar\n");
    scanf("%d",&num);
    multiplica(num);

    return 0;
}

int multiplica(x){
    int resultado;
    for(int i=0; i<11;i++){

        resultado=printf("la multiplicacion de %d X %d es: %d \n",i,x,i*x);
    }
}
