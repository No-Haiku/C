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
void modificaCliente(char archivo[],int nroClnt);
void muestraUnCliente(stCliente a);
void filtraClientes(char archivo[],char archivoConsumo);
void modificaConsumo(char archivo[],int nroClnt);
int main()
{
    ///cargaNombreYapellido("nomb_ape.bin");
    // muestraArchivo("nomb_ape.bin");
    int vldsCrgaClnt=0;
    //vldsCrgaClnt=cargaDatosCliente("clientes.bin",vldsCrgaClnt);
    // printf("validos %d\n",vldsCrgaClnt);
    printf("muestra clientes\n");
    muestaArchivoClientes("clientes.bin");
    ///modificaCliente("clientes.bin",1);
    /// muestaArchivoClientes("clientes.bin");
    printf("\nFiltra clientes\n");
    filtraClientes("clientes.bin","consumo.bin");
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

void modificaCliente(char archivo[],int nroClnt)
{

    stCliente a;
    FILE *archi=fopen(archivo,"r+b");
    int cont=0;
    int opcion=0;
    if(archi)
    {
        printf("\t\t\nPara modificar precione\n*1 para alta\n*2 para baja\n*3 Nombre\n*4 para apellido\n*5 D.N.I\n*6 para Email\n*7 para domicilio\n*8 para movil\n");
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
                case 3:
                    printf("Ingrese Nombre\n");
                    scanf("%s",a.nombre);
                    break;
                case 4:
                    printf("Ingrese apellido\n");
                    scanf("%s",a.apellido);
                    break;
                case 5:
                    printf("Ingrese D.N.I\n");
                    scanf("%s",a.dni);
                    break;
                case 6:
                    printf("Ingrese email\n");
                    scanf("%s",a.email);
                    if(strchr(a.email, '@' )==NULL)
                    {
                        printf("Email\n");
                        scanf("%s",a.email);
                        fflush(stdin);
                    }
                    break;
                case 7:
                    printf("Ingrese domicilio\n");
                    scanf("%s",a.domicilio);
                    break;
                case 8:
                    printf("Ingrese movil\n");
                    scanf("%s",a.movil);
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

void muestraUnCliente(stCliente a)
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

void filtraClientes(char archivo[],char archivoConsumo)
{
    stCliente a;
    int opcion;

    FILE *archi=fopen(archivo,"rb");

    printf("ingrese una opcion\n");
    scanf("%d",&opcion);

    if(archi)
    {

        char mander[50];
        int dato;
        char datoConsumo=0;
        switch(opcion)
        {
        case 1:
            printf("Ingrese el numero de cliente a buscar\n");
            scanf("%d",&dato);
            printf("Ver consumo? precione s para si\n");
            datoConsumo=getch();
            while(fread(&a,sizeof(stCliente),1,archi)>0)
            {
                if(a.nroCliente== dato)
                {

                    muestraUnCliente(a);
                if(datoConsumo=='s'){
                    printf("********Consumos*********\n");
                    muestraUnConsumo(archivoConsumo,a.id);
                }
                }
            }
            system("pause");
            system("cls");
            break;
        case 2:
            fflush(stdin);
            printf("Ingrese nombre de cliente a buscar\n");
            fflush(stdin);
            scanf("%s",mander);
            while(fread(&a,sizeof(stCliente),1,archi)>0)
            {
                if(strcmp(a.nombre,mander)==0)
                {
                    muestraUnCliente(a);
                }
            }
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Ingrese apellido de cliente a buscar\n");
            fflush(stdin);
            scanf("%s",mander);
            while(fread(&a,sizeof(stCliente),1,archi)>0)
            {
                if(strcmp(a.apellido,mander)==0)
                {
                    muestraUnCliente(a);
                }
            }
            system("pause");
            system("cls");
            break;
        case 4:
            printf("Ingrese D.N.I de cliente a buscar\n");
            fflush(stdin);
            scanf("%s",mander);
            while(fread(&a,sizeof(stCliente),1,archi)>0)
            {
                if(strcmp(a.dni,mander)==0)
                {
                    muestraUnCliente(a);
                }
            }
            system("pause");
            system("cls");
            break;
        case 5:
            printf("Ingrese email de cliente a buscar\n");
            fflush(stdin);
            scanf("%s",mander);
            if(strchr(mander, '@' )==NULL)
            {
                printf("Ingrese email de cliente a buscar\n");
                scanf("%s",mander);
                fflush(stdin);
            }
            while(fread(&a,sizeof(stCliente),1,archi)>0)
            {
                if(strcmp(a.email,mander)==0)
                {
                    muestraUnCliente(a);
                }
            }
            system("pause");
            system("cls");
            break;
        case 6:
            printf("Ingrese domicilio de cliente a buscar\n");
            fflush(stdin);
            scanf("%s",mander);
            while(fread(&a,sizeof(stCliente),1,archi)>0)
            {
                if(strcmp(a.domicilio,mander)==0)
                {
                    muestraUnCliente(a);
                }
            }
            system("pause");
            system("cls");
            break;
        case 7:
            printf("Ingrese numero de movil de cliente a buscar\n");
            fflush(stdin);
            scanf("%s",mander);
            while(fread(&a,sizeof(stCliente),1,archi)>0)
            {
                if(strcmp(a.movil,mander)==0)
                {
                    muestraUnCliente(a);
                }
            }
            system("pause");
            system("cls");
            break;
        }


        fclose(archi);
    }

}

void modificaConsumo(char archivo[],int nroClnt)
{

    stConsumos a;
    FILE *archi=fopen(archivo,"r+b");
    int cont=0;
    int opcion=0;
    if(archi)
    {
        printf("\t\t\nPara modificar precione\n*1 para alta\n*2 para baja\n*3 para anio\n*4 para mes\n*5 para dia\n*6 para datos consumidos");
        scanf("%d",&opcion);
        while(fread(&a,sizeof(stConsumos),1,archi)>0)
        {
            if(a.idCliente==nroClnt)
            {

                switch(opcion)
                {
                case 1:
                    a.baja=0;
                    break;
                case 2:
                    a.baja=-1;
                    break;
                case 3:
                    printf("Ingrese anio\n");
                    scanf("%d",a.anio);
                    break;
                case 4:
                    printf("Ingrese mes\n");
                    scanf("%d",a.mes);
                    break;
                case 5:
                    printf("Ingrese dia\n");
                    scanf("%d",a.dia);
                    break;
                case 6:
                    printf("Ingrese datos consumidos /mb\n");
                    scanf("%d",a.datosConsumidos);


                }

                fseek(archi,-1*sizeof(stConsumos),SEEK_CUR);
                fwrite(&a,sizeof(stConsumos),1,archi);
                cont++;
                fseek(archi,sizeof(stConsumos)*cont,SEEK_SET);
            }
        }
        fclose(archi);
    }

}
///MUESTRA CONSUMOS
void muestraUnConsumo(stConsumos a){
    printf("ID -%d-\n",a.id);
    printf("Numero de cliente: %d\n",a.idCliente);
    printf("Anio: %d\n",a.anio);
    printf("Mes: %d\n",a.mes);
    printf("Dia: %d\n",a.dia);
    printf("Datos consumidos %d mb\n",a.datosConsumidos);
    printf("Estado %d\n",a.baja);
}
/// MUESTRA CONSUMOS SEGUN FILTRO
void muestraConsumoConFiltro(char consumos[],stCliente b)
{   FILE *archi=fopen(consumos,"rb");
    stConsumos a;

if(archi){
    int opcion=0;
    printf("Fliltro\n*ID\n*Anio\n*Mes\n*Dia\n*Consumo\n*Alta\n*Baja\n");
    switch(opcion){
case 1:
    while(fread(&a,sizeof(stConsumos),1,archi)>0){
    if(a.idCliente==b.id){
    muestraUnConsumo(a);
    }

    }
    break;
    }

fclose(archi);
}
}
///CARGA CONSUMOS
