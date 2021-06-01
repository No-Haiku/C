#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
} stAlumno;
void leerArchivoAlumnos(char archivo[]);
void cargaAlumnoArchivo(char archivo[]);
int cuentaRegistros(char archivo[], int tamanioSt);
void cargaYcomprueba(char archivo[]);
void cargaArchivoExistente(char archivo[]);
int pasaLegajoMayores(Pila *pila,char archivo[]);
void muestraNombreSegunEdad(char archivo[]);
void muestraTodosLosdatosEspecificoInt(char archivo[],int dato,int cont);
void muestaUnAlumno(stAlumno a);
int muestraDatoXAnio(char archivo[],int anio);
int main()
{
    Pila origen;
    inicpila(&origen);
    stAlumno alumnos;
    int cuenta;
    int cuentaMayor;
    ///cargaAlumnoArchivo("alumnos.bin");
    leerArchivoAlumnos("alumnos.bin");
    cuenta=cuentaRegistros("alumnos.bin",sizeof(stAlumno));
    printf("cantidad de datos cargados %d\n",cuenta);
    cargaYcomprueba("prueba.bin");
    ///cargaArchivoExistente("alumnos.bin");
    cuentaMayor=pasaLegajoMayores(&origen,"alumnos.bin");
    printf("Pila Origen\n");
    mostrar(&origen);
    printf("Cantidad de mayores de edad %d\n",cuentaMayor);
    printf("Muestra nombre segun edad de 17 a 25\n");
    muestraNombreSegunEdad("alumnos.bin");
    printf("Muestra alumnos especificos segun edad\n");
    muestraTodosLosdatosEspecificoInt("alumnos.bin",18,cuenta);
    printf("%d\n",cuenta);
    printf("Muestra datos x anio espacifico\n");
    cuenta=muestraDatoXAnio("alumnos.bin",2020);
    printf("datos validos %d de anio",cuenta);
    return 0;
}

void cargaAlumnoArchivo(char archivo[])
{

    stAlumno a;
    FILE *archi;
    char opcion=0;

    archi=fopen(archivo,"ab");
    if(archi!=NULL)
    {
        while(opcion!=27)
        {
            printf("Ingrese legajo\n");
            scanf("%d",&a.legajo);
            printf("Ingrese nombre y apellido\n");
            fflush(stdin);
            scanf("%s",a.nombreYapellido);
            printf("Ingrese edad\n");
            scanf("%d",&a.edad);
            printf("Ingrese anio\n");
            scanf("%d",&a.anio);

            fwrite(&a,sizeof(stAlumno),1,archi);
            printf("Precione ESC para salir o cualquier tecla para continuar \n");
            opcion=getch();
        }
        fclose(archi);

    }



}

void leerArchivoAlumnos(char archivo[])
{

    stAlumno a;
    FILE *archi;
    archi=fopen(archivo,"rb");
    int i=0;
    if(archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&a,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                printf("\n*************************\n");
                printf("Archivo numero %d\n",i++);
                printf("Legajo %d \n",a.legajo);
                printf("Nombre y apellido %s\n",a.nombreYapellido);
                printf("Edad %d\n",a.edad);
                printf("Anio %d\n",a.anio);
                printf("\n*************************\n");
            }
        }
        fclose(archi);
    }
}


///Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.
int cuentaRegistros(char archivo[], int tamanioSt)
{
    int cantidadDeReguistros;
    FILE *archi=fopen(archivo,"rb");
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        cantidadDeReguistros=ftell(archi)/tamanioSt;
        fclose(archi);
    }
    return cantidadDeReguistros;
}
///Crear una función que cargue un archivo de alumnos.
///Abrirlo de manera tal de verificar si el archivo ya está creado previamente.
///Cargar el archivo con 5 datos. Cerrarlo dentro de la función
void cargaYcomprueba(char archivo[])
{
    printf("carga y prueba\n");
    int comprueba;
    comprueba=fopen(archivo,"r");
    FILE *archi;
    stAlumno a;
    if(comprueba>0)
    {
        archi=fopen(archivo,"ab");
        for(int i=0; i<5; i++)
        {
            printf("Ingrese legajo\n");
            scanf("%d",&a.legajo);
            printf("Ingrese nombre y apellido\n");
            fflush(stdin);
            scanf("%s",a.nombreYapellido);
            printf("Ingrese edad\n");
            scanf("%d",&a.edad);
            printf("Ingrese anio\n");
            scanf("%d",&a.anio);
            fwrite(&a,sizeof(stAlumno),1,archi);
        }
        fclose(archi);


    }
    else
    {
        printf("El archivo no Existe!!!\n");
    }
}

///Crear una función que permita agregar de a un elemento al final del archivo.
///O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno),
///se escribe en el archivo y se cierra.

void cargaArchivoExistente(char archivo[])
{
    int comprueba=fopen(archivo,"r");

    if(comprueba>0)
    {
        cargaAlumnoArchivo(archivo);

        fclose(archivo);
    }
    else
    {

        printf("NO EXISTE!!\n");
    }

}
///Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.
int pasaLegajoMayores(Pila *pila,char archivo[])
{
    stAlumno a;
    int i=0;
    int comprueba=fopen(archivo,"r");
    if(comprueba>0)
    {
        FILE *archi=fopen(archivo,"r");
        while(!feof(archi))
        {
            fread(&a,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(a.edad>18)
                {
                    apilar(pila,a.legajo);
                    i++;
                }
            }
        }
    fclose(archi);
    }
    else
    {
        printf("El archivo no Existe\n");
    }
    return i;
}

///Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades
/// específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar

void muestraNombreSegunEdad(char archivo[])
{
    int comprueba=fopen(archivo,"r");
    stAlumno a;
    if(comprueba>0)
    {
        FILE *archi=fopen(archivo,"rb");
        if(archi!=NULL)
        {
            while(!feof(archi))
            {
                fread(&a,sizeof(stAlumno),1,archi);
                if(!feof(archi))
                {
                    if(a.edad>=17 && a.edad<=25)
                    {
                        printf("Nombre %s\n",a.nombreYapellido);
                    }
                }
            }
            fclose(archi);
        }
    }

}
void muestraTodosLosdatosEspecificoInt(char archivo[],int dato,int cont){
    stAlumno a;
    int comprueba=fopen(archivo,"r");
    int i=0;
    if(comprueba>0){
        FILE *archi=fopen(archivo,"rb");
        while(!feof(archi)){
            fread(&a,sizeof(stAlumno),1,archi);
            if(!feof(archi)){
                if(a.edad>=dato){
                    muestaUnAlumno(a);
                    i++;
                }
            }
        }
        fclose(archi);
    }else{
        printf("El archivo no existe\n");
        }

    cont =i;
}
void muestaUnAlumno(stAlumno a)
{
    printf("\n*************************\n");
    printf("Legajo %d \n",a.legajo);
    printf("Nombre y apellido %s\n",a.nombreYapellido);
    printf("Edad %d\n",a.edad);
    printf("Anio %d\n",a.anio);
    printf("\n*************************\n");
}

int muestraDatoXAnio(char archivo[],int anio){

    int comprueba=fopen(archivo,"r");
    stAlumno a;
    int i=0;
    if(comprueba>0){
        FILE *archi=fopen(archivo,"rb");
        if(archi!=NULL){
            while(!feof(archi)){
                fread(&a,sizeof(stAlumno),1,archi);
                if(!feof(archi)){
                    if(a.anio==anio){
                        muestaUnAlumno(a);
                        i++;
                    }
                }
            }
            fclose(archi);
        }
    }
    return i;
}
