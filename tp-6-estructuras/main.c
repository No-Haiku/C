#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20
typedef struct
{
    int matricula;
    char nombre [30];
    char genero;
} stalumno;

int cargaAlumnosAr(stalumno a[],int dim,int v);
void muestraArreglo(stalumno a[],int v);
int buscaAlumno(stalumno a[],int dato,int v);
int devuelveMatricula(stalumno a);
void ordenaAlumnos(stalumno a[],int validos);
char devuelveGenero(stalumno a);
void muestraGenero(stalumno a[],int v, char dato);
void insertaEnArOrdenado(stalumno a[],int validos);
char devuelveNombre(stalumno a);
void ordenaPorNombre(stalumno a[],int validos);
int main()
{
    stalumno arAlumnos[DIM];
    int validos=0;
    int id;

    validos=cargaAlumnosAr(arAlumnos,DIM,validos);
    muestraArreglo(arAlumnos,validos);
    id=buscaAlumno(arAlumnos,5,validos);
    if(id>=0)
    {
        printf("Datos encontrados\n");
        printf("Numero de matricula %d \n",arAlumnos[id].matricula);
        printf("Nombre %s\n",arAlumnos[id].nombre);
        printf("Genero %c\n",arAlumnos[id].genero);
    }
    else
    {
        printf("No se encontro el alumno\n");
    }
   /* printf("\n Ordena alumnos\n");
    ordenaAlumnos(arAlumnos,validos);
    muestraArreglo(arAlumnos,validos);
    printf("muestra Genero\n");
    char dato='o';
    muestraGenero(arAlumnos,validos,dato);
    printf("\n");
    printf("Inserta dato enarreglo ordenado y lo devuelve ordenado\n");
    insertaEnArOrdenado(arAlumnos,validos);*/
    printf("\n Oredena por nombre\n");
    ordenaPorNombre(arAlumnos,validos);

    muestraArreglo(arAlumnos,validos);
    return 0;
}



int cargaAlumnosAr(stalumno a[],int dim,int v)
{

    int i=v;
    char opcion=0;

    while(i<dim&& opcion!=27)
    {
        printf("Carga matricula\n");
        scanf("%d",&a[i].matricula);
        printf("Ingrese nombre\n");
        fflush(stdin);
        scanf("%s",a[i].nombre);
        printf("Ingrese el genero -M-F-O-\n");
        fflush(stdin);
        scanf("%c",&a[i].genero);
        i++;
        printf("Precione ESC para salir o cualquier tecla para continuar \n");
        opcion=getch();
        system("cls");
    }

    return i;
}

void muestraArreglo(stalumno a[],int v)
{

    for(int i=0; i<v; i++)
    {
        printf("Numero de matricula %d \n",a[i].matricula);
        printf("Nombre %s\n",a[i].nombre);
        printf("Genero %c\n",a[i].genero);
    }

}
///Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.

int buscaAlumno(stalumno a[],int dato,int v)
{

    int flag=-1;

    for(int i=0; i<v; i++)
    {

        if(a[i].matricula==dato)
        {
            flag=i;
        }
    }
    return flag;
}
///Hacer una función que ordene el arreglo de alumnos por medio del método de selección.
/// El criterio de ordenación es el número de matrícula.
void ordenaAlumnos(stalumno a[],int validos)
{

    stalumno temp;
    int i,j;
    for(i=0; i<validos; i++)
    {
        for(j=0; j<validos-1; j++)
        {
            /// comp=strcmp(a[j].matricula,a[j+1].matricula);

            if(devuelveMatricula(a[j])>devuelveMatricula(a[j+1]))///cambiar elsigno <> para acendente o decendente
            {
                temp=a[j];
                ///strcpy(temp,a[j]);
                ///strcpy(a[j],a[j+1]);
                a[j]=a[j+1];
                a[j+1]=temp;
                ///strcpy(a[j+1],temp);
            }
        }

    }

}

int devuelveMatricula(stalumno a)
{
    int matricula;
    matricula=a.matricula;

    return matricula;
}

///Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.
void muestraGenero(stalumno a[],int v, char dato)
{

    for(int i=0; i<v; i++)
    {
        if (dato == devuelveGenero(a[i]) )
        {
            printf("Numero de matricula %d \n",a[i].matricula);
            printf("Nombre %s\n",a[i].nombre);
            printf("Genero %c\n",a[i].genero);
        }
    }

}
char devuelveGenero(stalumno a)
{
    char genero;
    genero=a.genero;
    return genero;
}
///Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
void insertaEnArOrdenado(stalumno a[],int validos)
{
    validos=cargaAlumnosAr(a,DIM,validos);
    ordenaAlumnos(a,validos);
    muestraArreglo(a,validos);
}
///Hacer una función que ordene el arreglo de alumnos por medio del método de inserción.
///El criterio de ordenación es el nombre.
void ordenaPorNombre(stalumno a[],int validos)
{
///NO FUNCIONA NO RETORNA NOMBRE
    stalumno temp;
    int comp;
    int i,j;
    for(i=0; i<validos; i++)
    {
        for(j=0; j<validos-1; j++)
        {

            if(strcmp(devuelveNombre(a[j]),devuelveNombre(a[j+1]))>0)///cambiar elsigno <> para acendente o decendente
            {
                temp=a[j];
                ///strcpy(temp,a[j]);
                ///strcpy(a[j],a[j+1]);
               a[j]=a[j+1];
                a[j+1]=temp;
                ///strcpy(a[j+1],temp);
            }
        }

    }

}

char devuelveNombre(stalumno a){

    char nombre;
    nombre=a.nombre;
    return nombre;
}
