#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id; /// campo �nico y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char movil[12];
    int baja; /// 0 si est� activo - 1 si est� eliminado
} stCliente;

typedef struct
{
    int id; /// campo �nico y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a � dependiendo del mes
    int datosConsumidos; /// expresados en mb.
    int baja; /// 0 si est� activo - 1 si est� eliminado
} stConsumos;

void cargaNombreYapellido(char archivo[]);
void muestraArchivo(char archivo[]);
int cargaDatosCliente(char archivo[],int validos);
void muestaArchivoClientes(char archivo[]);
void darDeBaja(char archivo[],int nroClnt);
int main()
{
    ///cargaNombreYapellido("nomb_ape.bin");
    // muestraArchivo("nomb_ape.bin");
    int vldsCrgaClnt=0;
    //vldsCrgaClnt=cargaDatosCliente("clientes.bin",vldsCrgaClnt);
    // printf("validos %d\n",vldsCrgaClnt);
    printf("muestra clientes\n");
    muestaArchivoClientes("clientes.bin");
    //darDeBaja("clientes.bin",1);
    /// muestaArchivoClientes("clientes.bin");
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
        if(comprueba>0) ///si el archivo ya existia le asigna el valor del id a validos
        {
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

void muestaArchivoClientes(char archivo[])
{

    int comp=fopen(archivo,"r");
    stCliente a;

    if(comp>0)
    {
        FILE *archi=fopen(archivo,"rb");
        if(archi)
        {
            while(fread(&a,sizeof(stCliente),1,archi)>0)
            {
                printf("ID -%d-\n",a.id);
                printf("Numero de cliente: %d\n",a.nroCliente);
                printf("Nombre: %s\n",a.nombre);
                printf("Apellido: %s\n",a.apellido);
                printf("D.N.I: %s\n",a.dni);
                printf("Email: %s\n",a.email);
                printf("Domicilio: %s\n",a.domicilio);
                printf("Movil: %s\n",a.movil);

                printf("Estado %d\n",a.baja);

            }
            fclose(archi);
        }
    }
    else
    {
        printf("EL archivo no existe o esta da�ado!!!\n");
    }
}

void darDeBaja(char archivo[],int nroClnt)
{

    stCliente a;
    FILE *archi=fopen(archivo,"r+b");
    int cont=0;
    int opcion=0;
    if(archi)
    {
        printf("Precione 1 para alta o 2 para baja\n");
        scanf("%d",&opcion);
        while(fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if(a.nroCliente==nroClnt)
            {

                switch(opcion)
                {
                case 1:
                    a.baja=0;
                    break;
                case 2:
                    a.baja=-1;
                    break;
                }

                fseek(archi,-1*sizeof(stCliente),SEEK_CUR);
                fwrite(&a,sizeof(stCliente),1,archi);
                cont++;
                fseek(archi,sizeof(stCliente)*cont,SEEK_SET);
            }
        }
        fclose(archi);
    }

}
