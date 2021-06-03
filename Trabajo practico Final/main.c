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
int cargaDatosCliente(char archivo[],int validos);
int main()
{
    ///cargaNombreYapellido("nomb_ape.bin");
    muestraArchivo("nomb_ape.bin");
    int vldsCrgaClnt=0;
    vldsCrgaClnt=cargaDatosCliente("clientes.bin",vldsCrgaClnt);
    printf("validos %d\n",vldsCrgaClnt);
    return 0;
}

void cargaNombreYapellido(char archivo[])
{

    char opcion=0;
    stCliente a;
    FILE *archi=fopen(archivo,"ab");
    int i=1;

    if(archi!=NULL)
    {

        while(opcion!=27)
        {
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

void muestraArchivo(char archivo[])
{

    stCliente a;

    FILE *archi=fopen(archivo,"rb");

    if(archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&a,sizeof(stCliente),1,archi);
            if(!feof(archi))
            {

                printf("Nombre %s\n",a.nombre);
                printf("Apellido %s\n",a.apellido);
            }
        }

        fclose(archi);
    }

}

int cargaDatosCliente(char archivo[],int validos)
{
    char opcion=0;
    stCliente a;
    int comprueba=fopen(archivo,"r");///comprueba si el archivo existe xon anterioridad
    FILE *archi=fopen(archivo,"ab");

    if(archi)
    {
        if(comprueba>0){///si el archivo ya existia le asigna el valor del id a validos
            validos=a.id;
        }
        while(opcion!=27)
        {
            printf("Numero de cliente \n");
            scanf("%d",&a.nroCliente);
            fflush(stdin);
            printf("Nombre\n");
            scanf("%s",a.nombre);
            fflush(stdin);
            printf("Apellido\n");
            scanf("%s",a.apellido);
            fflush(stdin);
            printf("D.N.I\n");
            scanf("%s",a.dni);
            fflush(stdin);
            printf("Email\n");
            scanf("%s",a.email);
            fflush(stdin);
            if(strchr(a.email, '@' )==NULL)
            {
                printf("Email\n");
                scanf("%s",a.email);
                fflush(stdin);
            }
            printf("Domicilio\n");
            scanf("%s",a.domicilio);
            printf("Movil\n");
            scanf("%s",a.movil);
            a.baja=0;
            a.id=validos;
            validos++;
            fwrite(&a,sizeof(stCliente),1,archi);
            printf("Precione ESC para salir ,Cualquier tecla para continuar\n");
            opcion=getch();

        }
        fclose(archi);
    }
    return validos;
}

void muestaArchivoClientes(char archivo[]){


}
