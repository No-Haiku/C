#include <stdio.h>
#include <stdlib.h>
int calculaFactorial(int dato);
int calculaPotencia(int base, int exponente);
void recorreArreglo(int a[],int v,int i);
void retornaCapicua(int a[],int v, int i, int j);
int main()
{
    int arreglo[]={2,2,1,2};
    int v=4;
    for(int i=0;i<v;i++){
        printf("-%d-\n",arreglo[i]);
    }
    printf("Calcula factorial %d\n",calculaFactorial(6));
    printf("Calcula exponente %d\n",calculaPotencia(5,2));
    printf("---------------------------\n");
    recorreArreglo(arreglo,v,0);
    retornaCapicua(arreglo,v,0,v-1);
    return 0;
}

///1. Calcular el factorial de un número en forma recursiva.

int calculaFactorial(int dato){
    int respuesta;

    if(dato ==0){
        respuesta=1;
    }else{

        respuesta=dato*calculaFactorial(dato-1);
    }

return respuesta;
}
///2. Calcular la potencia de un número en forma recursiva.
int calculaPotencia(int base, int exponente){

    int respuesta=base;

    if(exponente!=1){

        respuesta*=calculaPotencia(base,exponente-1);
    }

    return respuesta;
}
///3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.

void recorreArreglo(int a[],int v,int i){

    if(i!=v){

        printf("arreglo recursivo %d\n",a[i]);
        recorreArreglo(a,v,i+1);
///4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).

        printf("\n\n arreglo recursivo %d\n",a[i]);

    }


}
///5. Determinar en forma recursiva si un arreglo es capicúa.
void retornaCapicua(int a[],int v, int i, int j){

    int flag=-1;

   if(j>-1&&i!=v&&a[i]==a[j]){

        printf("a sub i %d, a sub j%d\n",a[i],a[j]);

        retornaCapicua(a,v,i+1,j-1);


    }
    if(a[i]!=a[j]&&j>0){
        printf("False\n");
    }else{
        printf("True\n");
    }



}
