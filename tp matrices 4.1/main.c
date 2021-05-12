#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cargaPalabras(char palabras[][20], int dim);
void muestraPalabras(char palabras [][20],int v);
int compraraString(char palabras[][20],char palabra[],int v);
int main()
{
   int dim=100;
   char palabras [dim] [20];
   int validos=0;
   char palabra[dim];
   int compara;
   validos=cargaPalabras(palabras,dim);
   muestraPalabras(palabras,validos);
   printf("carga un strin para luego ser comparado con la base de datos\n");
   scanf("%s",palabra);
   compara=compraraString(palabras,palabra,validos);

   if(compara==0){
    printf("Dato encontrado\n");
   }else{
    printf("Dato no encontrado\n");
   }

    return 0;
}



///Hacer una función que cargue un arreglo de palabras (strings). La función debe retornar cuantas palabras se cargaron.

int cargaPalabras(char palabras[][20], int dim){
    int i=0;
    char opcion=0;
    while(i<dim && opcion!=27){
        printf("Precione ESC Para salir cualquier tecla para continuar \n");
        opcion=getch();
        if(opcion!=27){
            printf("ingrese un texto\n");
            scanf("%s",palabras[i]);
            i++;
        }

    }
    return i;
}
///Hacer una función que muestre un arreglo de palabras.

void muestraPalabras(char palabras [][20],int v){

    for (int i=0; i<v; i++){
        printf("[%s]\n",palabras[i]);
    }
}
///Hacer una función que determine si una palabra se encuentra dentro de un arreglo de palabras. La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar.

int compraraString(char palabras[][20],char palabra[],int v){

    int i=0;
    int valido=-1;
    while(valido!=0 && i<v){
        valido=strcmp(palabras[i],palabra);
        i++;
    }


    return valido;
}
