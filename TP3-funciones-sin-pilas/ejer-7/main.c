#include <stdio.h>
#include <stdlib.h>
///Realizar una funci�n que reciba dos n�meros enteros por par�metro por referencia
///y cargue sus valores el usuario dentro de la funci�n.
void user(x,y);
int main()
{   int a,b;
    printf("Hello world!\n");
    user(a,b);
    user();
    return 0;
}

void user(x,y){

    printf("ingrese un valor para el primer numero entero\n");
    scanf("%d",&x);
    printf("ingrese un valor para el segundo numero entero\n");
    scanf("%d",&y);

    printf("los numeros cargados son %d y %d\n",x,y);

}
