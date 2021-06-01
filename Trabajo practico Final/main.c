#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char movil[12];
    int baja; /// 0 si está activo - 1 si está eliminado
} stCliente;

typedef struct
{
    int id; /// campo único y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a … dependiendo del mes
    int datosConsumidos; /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
} stConsumos;

void cargaNombreYapellido(char archivo[]);
void muestraArchivo(char archivo[]);
int main()
{
    ///cargaNombreYapellido("nomb_ape.bin");
    muestraArchivo("nomb_ape.bin");
    return 0;
}

void cargaNombreYapellido(char archivo[]){

    char opcion=0;
    stCliente a;
    FILE *archi=fopen(archivo,"ab");
    int i=1;

    if(archi!=NULL){

        while(opcion!=27){
            printf("Veces cargado %d\n",i);
            printf("Ingrese Nombre\n");
            fflush(stdin);
            scanf("%s",a.nombre);
            printf("Ingrese Apellido\n");
            fflush(stdin);
            scanf("%s",a.apellido);
            i++;
            fwrite(&a,sizeof(stCliente),1,archi);

            printf("precione ESC para salir,cualquier tecla para continuar\n");
            opcion=getch();

        }
        fclose(archi);
    }



}

void muestraArchivo(char archivo[]){

    stCliente a;

    FILE *archi=fopen(archivo,"rb");

    if(archi!=NULL){
        while(!feof(archi)){
                fread(&a,sizeof(stCliente),1,archi);
            if(!feof(archi)){

        printf("Nombre %s\n",a.nombre);
        printf("Apellido %s\n",a.apellido);
            }
        }

    fclose(archi);
    }

}
