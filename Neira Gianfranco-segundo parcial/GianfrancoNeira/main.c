#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[15];
    float temperatura;
} stPaciente;
void muestraArchivo(char archivo[]);
int buscaXDni(char archivo[],int dato);
int cargaDatosCliente(char archivo[],int validos);
void muestaUnPaciente(stPaciente a);
int cuentaRegistrosPaciente(char archivo[], int tamanioSt);
void muestraArchivoPacientes(char archivo[]);
void pasaDearregloArchivoSanos(char archivo[],stPaciente arregloP[],int dato,int v,char archiEnfer[]);
void porcentajeDeSanosEnfer(char sanos[],char enfermos[]);
int main()
{
    stPaciente arregloP[5][30];
    int dim=30;
    int validos=0;
    int pacientes=0;
    int porcentaje=0;
    validos=cargaDatosCliente("archivopacientes.bin",validos);

    muestraArchivoPacientes("archivopacientes.bin");
    ///buscaXDni("archivopacientes.bin",123);
    archvoToArregloPacientes("archivopacientes.bin",arregloP,dim,validos);
    pacientes=cuentaRegistrosPaciente("archivopacientes.bin",sizeof(stPaciente));
    printf("pacientes total %d\n",pacientes);
    pasaDearregloArchivoSanos("sanos.bin",arregloP,37,validos,"enfermos.bin");
    porcentajeDeSanosEnfer("sanos.bin","enfermos.bin");
    printf("Hello world!\n");
    return 0;
}
///Hacer una función que verifique si un dato existe en un archivo buscando por dni. Retornará v ó f.

int buscaXDni(char archivo[],int dato)
{

    stPaciente a;

    FILE *archi=fopen(archivo,"rb");
    int flag=-1;
    if(archi)
    {

        while(fread(&a,sizeof(stPaciente),1,archi)&& flag==-1)
        {

            if(a.dni==dato)
            {
                flag=1;
            }
        }
        fclose(archi);
    }

    return flag;
}

///Hacer una función que cargue pacientes en un archivo validando que sean únicos y que la temperatura sea válida,
///también deberá generar un id único y autoincremental. Modularizar.


int cargaDatosCliente(char archivo[],int validos)
{
    char opcion=0;
    stPaciente a;
    char dniflag[15];
    int flag=0;
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

            printf("Nombre\n");
            scanf("%s",a.nombre);
            fflush(stdin);
            printf("Apellido\n");
            scanf("%s",a.apellido);
            fflush(stdin);
            printf("D.N.I\n");
            scanf("%s",a.dni);
            strcpy(dniflag,a.dni);
            fflush(stdin);
            printf("Temperatura\n");
            scanf("%f",a.temperatura);
            if(a.temperatura<35 && a.temperatura>40)
            {
                printf("Temperatura\n");
                scanf("%f",a.temperatura);
            }
            while(fread(&a,sizeof(stPaciente),1,archi))
            {
                if(strcmp(a.dni,dniflag)==0)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                a.id=validos;
                validos++;
                fwrite(&a,sizeof(stPaciente),1,archi);
            }
            printf("Precione ESC para salir ,Cualquier tecla para continuar\n");
            opcion=getch();

        }
        fclose(archi);
    }
    return validos;
}

///Hacer una función que muestre los pacientes del archivo. Modularizar.

void muestaUnPaciente(stPaciente a)
{
    printf("Nombre %s\n",a.nombre);
    printf("Apellido %s\n",a.apellido);
    printf("D.N.I\n",a.dni);
    printf("Tempratura %f\n",a.temperatura);


}
void muestraArchivoPacientes(char archivo[])
{

    stPaciente a;

    FILE *archi=fopen(archivo,"rb");

    if(archi)
    {
        while(!feof(archi))
        {
            fread(&a,sizeof(stPaciente),1,archi);
            if(!feof(archi))
            {

                muestaUnPaciente(a);
            }
        }

        fclose(archi);
    }

}
///Hacer una función que pase el archivo a un arreglo de Pacientes.

int archvoToArregloPacientes(char archivo[],stPaciente arregloP[],int dim,int v)
{

    FILE *archi=fopen(archivo,"rb");
    stPaciente a;
    int i=v;
    if(archi)
    {
        while(fread(&a,sizeof(stPaciente),1,archi)&& i<dim)
        {
            arregloP[i]=a;

            i++;
        }
        fclose(archi);
    }
    return i;
}
///Hacer una función que retorne la cantidad de pacientes existentes en un archivo.

int cuentaRegistrosPaciente(char archivo[], int tamanioSt)
{
    int cantDeReguistros;
    FILE *archi=fopen(archivo,"rb");
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        cantDeReguistros=ftell(archi)/tamanioSt;
        fclose(archi);
    }
    return cantDeReguistros;
}
///Hacer una función que pase del arreglo al archivo de sanos todos aquellos pacientes cuya temperatura sea menor o
///igual a un dato recibido (no usamos como límite una temperatura fija porque es un dato que puede variar) y el resto
///al archivo de enfermos.

void pasaDearregloArchivoSanos(char archivo[],stPaciente arregloP[],int dato,int v,char archiEnfer[])
{

    FILE *archi=fopen(archivo,"rb");
    FILE *archi2=fopen(archiEnfer,"rb");
    stPaciente a;
    int i=0;
    if(archi)
    {
        while(i<v)
        {

            if(arregloP[i].temperatura>=dato)
            {
                a=arregloP[i];

                fwrite(&a,sizeof(stPaciente),1,archi);
            }
            else
            {
                a=arregloP[i];

                fwrite(&a,sizeof(stPaciente),1,archi2);

            }
        }
        fclose(archi);
        fclose(archi2);
    }

}

///Hacer una función que muestre el porcentaje de sanos y enfermos, para ello deberá usar la función que calcula el
///total de pacientes para cada archivo.
void porcentajeDeSanosEnfer(char sanos[],char enfermos[])
{
    FILE *archi=fopen(sanos,"rb");
    FILE *archi2=fopen(enfermos,"rb");
    int san=0;
    int enf=0;
    int total=0;
    int promediosan=0;
    int promedioenfer=0;
    if(archi){
      san=cuentaRegistrosPaciente(sanos,sizeof(stPaciente));
      enf=cuentaRegistrosPaciente(enfermos,sizeof(stPaciente));
      total=san+enf;
      promediosan=san*100/total;
      promedioenfer=enf*100/total;
      printf("Promedio sanos %d\n",promediosan);
      printf("Promedio enfermos %d\n",promedioenfer);

    }

}
