#include <stdio.h>
#include <stdlib.h>

///Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.

void randomNumero();
int main()
{
    printf("Hello world!\n");
    randomNumero();
    return 0;
}

void randomNumero()
{
        int numR;
        for(int i=0;i<100;i++){
            numR= rand()%100;

            printf("El numero random es %d\n",numR);
        }

}
