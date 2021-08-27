#include <stdio.h>
#include <stdlib.h>

int potenciaRecu(int val,int elevado);
int main()
{
    int val = 2;
    int elevado = 3;
    int rta;
    rta = potenciaRecu(2,3);
    printf("%d",rta);
    int arreglo []={1,2,3};
    return 0;
}

int potenciaRecu(int val,int elevado){
    int rta=1;
    if(elevado> 0){
    rta = val * potenciaRecu(val,elevado-1);
    }
return rta;
}

int arregloRecu(int arreglo[]){

    int i;

    if(i== 0){
    rta = val * arreglo(val,elevado-1);
    }else if(arreglo[i]== '/0'){
        printf("arreglo %d",arreglo[i]);
    }
return
}
