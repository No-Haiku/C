#include <stdio.h>
#include <stdlib.h>

int main()
{
    char palabra[20];
    int cantidad=0;
    int i=0;
    printf("Hello world!\n");
    gets(&palabra);

    while(palabra[i]!='\0'){
        i++;
        printf("hola\n");
    }
    printf("cantidad de letras %d",i);
    return 0;
}
