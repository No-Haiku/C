#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "empleados.h"



void cargaEmpleadoArchivo(char archivo[])
{

    stEmpleado a;
    FILE *archi;
    char opcion=0;

    archi=fopen(archivo,"ab");
    if(archi!=NULL)
    {
        while(opcion!=27)
        {

            printf("Ingrese Nombre \n");
            fflush(stdin);
            scanf("%s",a.nombre);
            printf("Ingrese Apellido \n");
            fflush(stdin);
            scanf("%s",a.apellido);
            printf("Ingrese Domicilio\n");
            scanf("%s",&a.domicilio);
            printf("Ingrese Movil\n");
            scanf("%s",&a.movil);

            fwrite(&a,sizeof(stEmpleado),1,archi);
            printf("Precione ESC para salir o cualquier tecla para continuar \n");
            opcion=getch();
        }
        fclose(archi);

    }
}


void leerArchivoEmpleados(char archivo[])
{

    stEmpleado a;
    FILE *archi;
    archi=fopen(archivo,"rb");
    int i=0;
    if(archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&a,sizeof(stEmpleado),1,archi);
            if(!feof(archi))
            {
            muestraUnEmpleado(a);
            }
        }
        fclose(archi);
    }
}
void muestraUnEmpleado(stEmpleado e){
    printf("\nNombre.........................: %s", e.nombre);
    printf("\nApellido.....................: %s", e.apellido);
    printf("\nDomicilio......................: %s", e.domicilio);
    printf("\nMovil......................: %s", e.movil);
}
