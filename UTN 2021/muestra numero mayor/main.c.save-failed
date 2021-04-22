#include <stdio.h>
#include <stdlib.h>
///Leer tres números diferentes e imprimir el número mayor de los tres.


int main()
{
    int tam=3;/// 0 1 2
    int arreglo[tam];
    int temp;
    int num=0;
    int i,j;
    ///carga numeros dentro del arreglo
    for(i=0;i<tam;i++)
    {
        printf("Ingrese los numeros para el arreglo\n");
        scanf("%d",&num);
        arreglo[i]=num;
    }
    for(i=0;i<tam;i++){
        for(j=0;j<tam -1; j++){
            if (arreglo[j]< arreglo[j+1]){
                temp=arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=temp;
            }
        }
    }

    ///muestra los numeros dentro del arreglo
    for(i=0;i<tam;i++){
        printf("Numeros dentro del arreglo %d \n",arreglo[i]);
    }
    printf("EL numero mas grande es %d \n",arreglo[0]);
    return 0;
}
