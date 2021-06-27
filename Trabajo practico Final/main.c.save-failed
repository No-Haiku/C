#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANIO_ACTUAL 2021

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
void cargaDatosCliente(char archivo[]);
void muestaArchivoClientes(char archivo[]);
void modificaCliente(char archivo[],int nroClnt);
void muestraUnCliente(stCliente a);
void filtraClientes(char archivo[],char archivoConsumo[]);
void modificaConsumo(char archivo[],int nroClnt);
void muestraXAnio(char consumos[],stCliente b);
void muestraXRangoDeAnios(char consumos[],stCliente b);
void muestraXMes(char consumos[],stCliente b);
void muestraXDatosConsumosFiltro(char consumos[],stCliente b,stConsumos c);
void cargaDatosConsumo(char archivoConsumo[],stCliente b);
void muestraUnConsumo(stConsumos a);
int verificaSiRepiteDatoCliente(char archivo[],int id,stCliente a);
int cuentaRegistros(char archivo[], int tamanioSt);
void guardaNroClienteMemoriaDinamica(int arreglo[],int dim,int validos,int dato);
int verificaArregloNroClte(int arreglo[],int validos,int dato);
void guardaDniMemoriaDinamica(stCliente arreglo[],int validos,stCliente a);
int verificaArregloDni(stCliente arreglo[],int validos,stCliente a);
stConsumos agregaConsumosDias(char archivo[],stConsumos a,int dato);
int anioBisiesto(stConsumos a);
int mesesYdias(stConsumos a,int flag);
void muestaArchivoConsumos(char archivoConsumos[]);
int randomClientesNroId(char archivoClientes[]);
int numeroRandomint(int minimo, int maximo);
void cargaRandomConsumos(char archivoConsumos[],char archivoClientes[]);
int main()
{
    ///cargaNombreYapellido("nomb_ape.bin");
    // muestraArchivo("nomb_ape.bin");
    int numerC=0;
    stCliente b;
    char opcion=0;
    int opcion2=0;
    //
    printf("muestra clientes\n");

    ///modificaCliente("clientes.bin",1);
    /// muestaArchivoClientes("clientes.bin");
    printf("\nFiltra clientes\n");

//    printf("muestra consumo con filtro\n");
//    muestraConsumoConFiltro("consumo.bin",b);
//printf("carga consumos\n");
//cargaDatosConsumo("consumo.bin",vldsCrgaConsu,1);

    /* do
     {
         printf("                    ********************BIENVENIDO AL GESTOR DE CLIENTES********************************\n\n");
         printf("*-OPCION 1 ->FILTRA CLIENTES AGREGA CONSUMOS Y MODIFICA POR ID\n\n");
         printf("*-OPCION 2 ->CONSUMOS BUSQUEDA NRO DE CLIENTE Y FECHA\n\n");
         printf("*-OPCION 3 -> VER TODOS LOS CLIENTES\n\n");
         printf("*-OPCION 4 -> CARGA CLIENTES\n\n");
         printf("*-OPCION 5 -> VER TODOS LOS CONSUMOS\n\n");
         printf("*-OPCION 6 -> MODIFICAR CLIENTE\n\n");


         scanf("%d",&opcion2);


         switch(opcion2)
         {
         case 1:
             filtraClientes("clientes.bin","consumo.bin");
             system("pause");
             system("cls");
             break;
         case 2:
             printf("                ********************************FILTRA CONSUMOS*********************\n");
             printf("Ingrese el numero de cliente\n");
             scanf("%d",&b.nroCliente);
             muestraConsumoConFiltro("consumo.bin",b);
             system("pause");
             system("cls");
             break;
         case 3:
             printf("               **********************LISTA DE TODOS LOS CLIENTES********************\n");
             muestaArchivoClientes("clientes.bin");
             system("pause");
             system("cls");
             break;
         case 4:
             printf("               ***************************CARGAR CLIENTES*****************************\n");
             cargaDatosCliente("clientes.bin");
             break;
         case 5:
             printf("               **********************LISTA DE TODOS LOS CONSUMOS********************\n");
             muestaArchivoConsumos("consumo.bin");
             break;
         case 6:
             printf("               **********************MODIFICA CLIENTES********************\n");
             printf("Ingrese el numero de cliente para modificar\n");
             scanf("%d",&numerC);
             modificaCliente("clientes.bin",numerC);
             break;

         }

         printf("                        **************************PRECIONES ESC PARA SALIR************************\n");
         opcion=getch();
     }
     while(opcion!=27);*/
    //printf("\n manin---->%d",randomClientesNroId("clientes.bin"));
    cargaRandomConsumos("consumo.bin","clientes.bin");
    muestaArchivoConsumos("consumo.bin");

    return 0;
}


///CARGA DE DATOS CLIENTE
void cargaDatosCliente(char archivo[])
{
    char opcion=0;
    stCliente a;
    int validos=cuentaRegistros(archivo, sizeof(stCliente));
    int comprueba=fopen(archivo,"r");///comprueba si el archivo existe xon anterioridad
    FILE *archi=fopen(archivo,"ab");
    int guardaNroCli;
    int flag=-1;
    int flag2=-1;
    int flag3=-1;
    int dim=100;
    int validosNroClt=0;
    int validosDni=0;
    int arregloNroCliente [100];
    stCliente arregloDni  [100];

    if(archi)
    {
        while(opcion!=27)
        {
            printf("Numero de cliente \n");
            scanf("%d",&a.nroCliente);
            guardaNroCli=a.nroCliente;
            validosNroClt++;
            guardaNroClienteMemoriaDinamica(arregloNroCliente,dim,validosNroClt,guardaNroCli);
            flag2=verificaArregloNroClte(arregloNroCliente,validosNroClt,guardaNroCli);
            fflush(stdin);
            printf("Nombre\n");
            scanf("%s",a.nombre);
            fflush(stdin);
            printf("Apellido\n");
            scanf("%s",a.apellido);
            fflush(stdin);
            printf("D.N.I\n");
            scanf("%s",a.dni);
            validosDni++;
            guardaDniMemoriaDinamica(arregloDni,validosDni,a);
            flag3=verificaArregloDni(arregloDni,validosDni,a);
            printf("Este el flag 3 dni %d\n",flag3);
            fflush(stdin);
            printf("Email\n");
            scanf("%s",a.email);
            fflush(stdin);
            if(strchr(a.email, '@' )==NULL)
            {
                while(strchr(a.email, '@')==NULL )
                {
                    printf("Email\n");
                    scanf("%s",a.email);
                    fflush(stdin);
                }
            }
            printf("Domicilio\n");
            scanf("%d",a.domicilio);///si uso[^\n] me genera un error en la carga
            printf("Movil\n");
            scanf("%s",a.movil);
            a.baja=0;
            flag=verificaSiRepiteDatoCliente(archivo,guardaNroCli,a);///pasar directamente archivo , archi no me lo leia
            printf("dato de flag %d\n",flag);
            printf("numero cliente guardado %d\n",guardaNroCli);
            if(flag==0&&flag2<=1&&flag3<=1)///aca verifico que no exista mas de una copia de los datos si esta todo ok guarda el archivo
            {
                a.id=validos;
                validos++;
                printf("Agregar datos de consumo? s/n\n");
                opcion=getch();
                if(opcion=='s'||opcion=='S')
                {
                    printf("****************carga consumos!!!!!!!!!!!!!\n");
                    cargaDatosConsumo("consumo.bin",a);
                }
                fwrite(&a,sizeof(stCliente),1,archi);
            }
            if(flag==1||flag2>1||flag3>1)
            {
                printf("ERROR LOS DATOS NO SERAN GUARDADOS REVISE QUE EL NUMERO DE CLIENTE O EL USUARIO DNI NO EXISTA!!!\n");
                printf("VUELVA A INTENTARLO DE NUEVO A ACONTINUACION...");
            }


            printf("Precione ESC para salir ,Cualquier tecla para continuar\n");
            opcion=getch();

        }
        fclose(archi);
    }
}
///comprueba que el numero de cliente no aya sido escrito es para solucionar el error que no lo reconoce en sesion activa
///ESTA FUNCION GUARDA EL NUMERO DE CLIENTE DE LA MEMORIA DINAMICA EN UN ARREGLO
void guardaNroClienteMemoriaDinamica(int arreglo[],int dim,int validos,int dato)
{
    int i;
    for(i=0; i<validos; i++)
    {
        arreglo[i]=dato;
    }

}

/// ESTA FUNCION VERIFICA QUE EN LA SESION ACTUAL NO SE AYA REPETIDO EL DATO
int verificaArregloNroClte(int arreglo[],int validos,int dato)
{
    int i=0;
    int flag=0;
    while(i<validos)
    {

        if(arreglo[i]==dato)
        {
            flag++;
        }
        i++;
    }
    return flag;
}
///ESTA FUNCION GUARDA EL NUMERO DE DNI*ESTRUCTURA COMPLETA EN OTRA ESTRUCTURA* DE LA MEMORIA DINAMICA EN UN ARREGLO
void guardaDniMemoriaDinamica(stCliente arreglo[],int validos,stCliente a)
{
    int i;
    printf("hola %s\n",a.dni);
    printf("hola\n");
    for(i=0; i<validos; i++)
    {
        arreglo[i]=a;
        printf("hola2\n");
    }
    printf("hola3\n");
    for(i=0; i<validos; i++)
    {

        printf("hola %s\n",arreglo[i].dni);
    }
}
/// PENSANDOLO MEJOR PUDE CREAR UNA SOLA FUNCION PARA TODO COMPROBANDO LA ESTRUCTURA DIRECTAMENDE
/// LO DEJO PARA DESPUES PRIMERO TENGO QUE CUMPLIR LAS CONSIGNAR DESPUES LO PULIMOS XD
/// ESTA FUNCION VERIFICA QUE EN LA SESION ACTUAL NO SE AYA REPETIDO EL DATO
int verificaArregloDni(stCliente arreglo[],int validos,stCliente a)
{
    int i=0;
    int flag=0;
    int comprueba;
    while(i<validos)
    {
        comprueba=strcmp(arreglo[i].dni,a.dni);
        if(comprueba==0)
        {
            flag++;
        }
        i++;
    }
    return flag;
}
///verifica si el dni o el nmero de cliente se repite en el archivo
int verificaSiRepiteDatoCliente(char archivo[],int nrc,stCliente a)///pasar file *archi
{
    stCliente c;
    int flag=0;
    int compara;
    FILE *archi=fopen(archivo,"rb");///rewin() agregar
    fseek(archi,0,SEEK_SET);
    if(archi)
    {
        while(fread(&c,sizeof(stCliente),1,archi)>0)///poner
        {
            compara=strcmp(c.dni,a.dni);
            if(c.nroCliente==nrc||compara==0)
            {
                flag=1;
            }
        }
    }
    fclose(archi);
    return flag;
}
///MUESTRA ELA RCHIVO CLIENTES
void muestaArchivoClientes(char archivo[])
{

    //int comp=fopen(archivo,"r");
    stCliente a;

    // if(comp>0)
    //{
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
    //}
    else
    {
        printf("EL archivo no existe o esta dañado!!!\n");
    }
}
///MODIFICA DATOS DEL CLIENTE
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
///Filtra los clientes
void filtraClientes(char archivo[],char archivoConsumo[])
{
    stCliente a;
    stConsumos b;
    int opcion;
    char continuar=0;
    FILE *archi=fopen(archivo,"rb");
    FILE *archicon=fopen(archivoConsumo,"rb");
    while(continuar!=27)
    {
        FILE *archi=fopen(archivo,"rb");
        FILE *archicon=fopen(archivoConsumo,"rb");
        printf("***********************Preciones ESC para salir cualquier tecla para continuar****************************\n");
        fflush(stdin);
        continuar=getch();
        if(continuar!=27)
        {
            printf("                        ***************Ingrese una opcion**************\n");
            printf("* Id cliente->1\n");
            printf("* Nombre->2\n");
            printf("* Apellido->3\n");
            printf("* D.n.i->4\n");
            printf("* Email->5\n");
            printf("* Domicilio->6\n");
            printf("* Nmro de movil->7\n");
            printf("* Volver al menu principial->8\n");
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
                    printf("*************Opciones de busqueda y carga****************************\n");
                    printf("\n");
                    printf("\n*Ver todos los consumos? precione s\n\n*Filtral por fecha precione f\n");
                    printf("\n*Cargar nuevos datos de consumo precione c\n");
                    printf("\n*Precione escape para salir o cualquier tecla para omitir\n");
                    printf("\n*Precione M para volver al menu anterior\n");
                    printf("\n");
                    printf("************************************************************************\n");
                    datoConsumo=getch();
                    continuar=datoConsumo;
                    if(datoConsumo=='m'||datoConsumo=='M')
                    {
                        filtraClientes(archivo,archivoConsumo);
                    }
                    while(fread(&a,sizeof(stCliente),1,archi)>0)
                    {
                        if(a.nroCliente== dato)
                        {

                            muestraUnCliente(a);
                            if(datoConsumo=='c'||datoConsumo=='C')
                            {
                                printf("******Carga datos consumo*******\n");

                                cargaDatosConsumo(archivoConsumo,a);
                            }

                            if(datoConsumo=='f'||datoConsumo=='F')
                            {
                                muestraConsumoConFiltro(archivoConsumo,a);
                            }
                            if(datoConsumo=='s'||datoConsumo=='S')
                            {
                                printf("********Consumos*********\n");
                                while(fread(&b,sizeof(stConsumos),1,archicon)>0)
                                {
                                    if(a.nroCliente==b.idCliente)
                                    {
                                        muestraUnConsumo(b);

                                    }
                                }

                            }
                        }
                    }
                    printf("Precione ESC para salir \n");
                    fflush(stdin);
                    continuar=getch();
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    fflush(stdin);
                    printf("Ingrese nombre de cliente a buscar\n");
                    fflush(stdin);
                    scanf("%s",mander);
                    printf("*************Opciones****************************\n");
                    printf("\n");
                    printf("\n*Precione ESC para salir,Enter para continuar \n");
                    printf("\n*Precione M para volver al menu anterior\n");
                    printf("\n");
                    printf("************************************************************************\n");
                    datoConsumo=getch();
                    continuar=datoConsumo;
                    if(datoConsumo=='m'||datoConsumo=='M')
                    {
                        filtraClientes(archivo,archivoConsumo);
                    }

                    while(fread(&a,sizeof(stCliente),1,archi)>0)
                    {
                        if(strcmp(a.nombre,mander)==0)
                        {
                            muestraUnCliente(a);
                        }

                    }//fclose(archi);

                    system("pause");
                    system("cls");
                    break;
                case 3:
                    printf("Ingrese apellido de cliente a buscar\n");
                    fflush(stdin);
                    scanf("%s",mander);
                    printf("Ver consumo? precione s para si\n");
                    datoConsumo=getch();
                    while(fread(&a,sizeof(stCliente),1,archi)>0)
                    {
                        if(strcmp(a.apellido,mander)==0)
                        {
                            muestraUnCliente(a);
                            if(datoConsumo=='s')
                            {
                                printf("********Consumos*********\n");
                                muestraUnConsumo(b);
                            }
                        }
                    }
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    printf("Ingrese D.N.I de cliente a buscar\n");
                    fflush(stdin);
                    scanf("%s",mander);
                    printf("Ver consumo? precione s para si\n");
                    datoConsumo=getch();
                    while(fread(&a,sizeof(stCliente),1,archi)>0)
                    {
                        if(strcmp(a.dni,mander)==0)
                        {
                            muestraUnCliente(a);
                            if(datoConsumo=='s')
                            {
                                printf("********Consumos*********\n");
                                muestraUnConsumo(b);
                            }
                        }
                    }
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    printf("Ingrese email de cliente a buscar\n");
                    fflush(stdin);
                    scanf("%s",mander);
                    printf("Ver consumo? precione s para si\n");
                    datoConsumo=getch();
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
                            if(datoConsumo=='s')
                            {
                                printf("********Consumos*********\n");
                                muestraUnConsumo(b);
                            }
                        }
                    }
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    printf("Ingrese domicilio de cliente a buscar\n");
                    fflush(stdin);
                    scanf("%s",mander);
                    printf("Ver consumo? precione s para si\n");
                    datoConsumo=getch();
                    while(fread(&a,sizeof(stCliente),1,archi)>0)
                    {
                        if(strcmp(a.domicilio,mander)==0)
                        {
                            muestraUnCliente(a);
                            if(datoConsumo=='s')
                            {
                                printf("********Consumos*********\n");
                                muestraUnConsumo(b);
                            }
                        }
                    }
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    printf("Ingrese numero de movil de cliente a buscar\n");
                    fflush(stdin);
                    scanf("%s",mander);
                    printf("Ver todos los consumos? precione s para si\n");
                    datoConsumo=getch();
                    while(fread(&a,sizeof(stCliente),1,archi)>0)
                    {
                        if(strcmp(a.movil,mander)==0)
                        {
                            muestraUnCliente(a);
                            if(datoConsumo=='s')
                            {
                                printf("********Consumos*********\n");
                                muestraUnConsumo(b);
                            }
                        }
                    }
                    system("pause");
                    system("cls");
                    break;
                case 8:
                    main();
                    system("pause");
                    system("cls");
                    break;

                }


                fclose(archi);
            }
        }
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
void muestraUnConsumo(stConsumos a)
{
    printf("ID -%d-\n",a.id);
    printf("Numero de cliente: %d\n",a.idCliente);
    printf("Anio: %d\n",a.anio);
    printf("Mes: %d\n",a.mes);
    printf("Dia: %d\n",a.dia);
    printf("Datos consumidos %d mb\n",a.datosConsumidos);
    printf("Estado %d\n",a.baja);
}
/// MUESTRA CONSUMOS SEGUN FILTRO
void muestraConsumoConFiltro(char consumos[],stCliente b)///STCLIENTE PASAR SOLO EL ID RECORDATORIO-CRAR UN MENU E INTEGRAR TODO
{
    FILE *archi=fopen(consumos,"rb");
    stConsumos a;

    if(archi)
    {
        printf("archivo abierto!!!\n");
        printf("**********Ingrese la fecha a buscar********\n");
        printf("ingrse anio\n");
        scanf("%d", &a.anio);
        printf("ingrse mes\n");
        scanf("%d",&a.mes);
        printf("ingrse dia\n");
        scanf("%d",&a.dia);
        muestraXDatosConsumosFiltro(consumos,b,a);
        system("pause");
    }

    fclose(archi);

}

///MUESTRA TODOS LOS DATOS DE STCONSUMOS CON LA FUNCION DE FILTROS
void muestraXDatosConsumosFiltro(char consumos[],stCliente b,stConsumos c)
{
    stConsumos a;
    FILE *archi=fopen(consumos,"rb");

    if(archi)
    {

        while(fread(&a,sizeof(stConsumos),1,archi)>0)
        {
            if(a.idCliente==b.nroCliente&&a.anio==c.anio&&a.mes==c.mes&&a.dia==c.dia)
            {
                muestraUnConsumo(a);
            }
        }
    }
    fclose(archi);
}


///CARGA CONSUMOS
void cargaDatosConsumo(char archivoConsumo[],stCliente b)
{
    char opcion=0;
    stConsumos a;
    int dato=0;
    int validos=cuentaRegistros(archivoConsumo, sizeof(stConsumos));

    FILE *archi=fopen(archivoConsumo,"a+b");
    int flag=0;
    int mesesDiasCuenta;
    if(archi)
    {
        while(opcion!=27)
        {
            a.idCliente=b.nroCliente;
            printf("Ingrese anio de consumo \n");
            scanf("%d",&a.anio);
            if(a.anio>ANIO_ACTUAL)
            {
                while(a.anio>ANIO_ACTUAL)
                {
                    printf("Ingrese anio de consumo \n");
                    scanf("%d",&a.anio);
                }
            }
            flag=anioBisiesto(a);
            printf("Ingrese mes\n");
            scanf("%d",&a.mes);
            if(a.mes<1||a.mes>12)
            {
                while(a.mes<1||a.mes>12)
                {
                    printf("Ingrese mes\n");
                    scanf("%d",&a.mes);
                }
            }

            printf("Ingrese dia\n");
            scanf("%d",&a.dia);
            /// calcula el mes y los dias
            mesesDiasCuenta=mesesYdias(a,flag);
            if(flag==1&&a.mes==2&&a.dia<1||a.dia>29)
            {
                while(a.dia<1||a.dia>29)
                {
                    printf("Ingrese dia\n");
                    scanf("%d",&a.dia);
                }
            }
            if(mesesDiasCuenta==2&&a.dia<1||a.dia>28)
            {
                while(a.dia<1||a.dia>28)
                {
                    printf("Ingrese dia\n");
                    scanf("%d",&a.dia);
                }
            }
            if(mesesDiasCuenta==3&&a.dia<1||a.dia>30)
            {
                while(a.dia<1||a.dia>30)
                {
                    printf("Ingrese dia\n");
                    scanf("%d",&a.dia);
                }
            }
            if(mesesDiasCuenta==4&&a.dia<1||a.dia>31)
            {
                while(a.dia<1||a.dia>31)
                {
                    printf("Ingrese dia\n");
                    scanf("%d",&a.dia);
                }
            }
            printf("Ingrese datos consumidos\n");
            scanf("%d",&a.datosConsumidos);
            dato=a.datosConsumidos;
            a.baja=0;
            a.id=validos;
            validos++;

            a=agregaConsumosDias(archivoConsumo,a,dato);
            fwrite(&a,sizeof(stConsumos),1,archi);

            printf("Precione ESC para salir ,Cualquier tecla para continuar cargando consumos\n");
            opcion=getch();

        }
        fclose(archi);
        filtraClientes("clientes.bin",archivoConsumo);
    }
}
int mesesYdias(stConsumos a,int flag)
{
    int valB;
    int dias=0;
    int febreroB [29];
    valB=anioBisiesto(a);///29 dias febrero
    if(valB!=0)
    {
        dias=1;
    }
    else if(valB==0&&a.mes==2) ///28 diasfebrero
    {
        dias=2;
    }
    else if(a.mes==4||a.mes==6||a.mes==9||a.mes==11)///meses de 30 dias
    {
        dias=3;
    }
    else
    {
        dias=4;///meses 31 dias
    }
    return dias;
}
int anioBisiesto(stConsumos a)
{
    int flag=0;
    if ( a.anio % 4 == 0 && a.anio % 100 != 0 || a.anio % 400 == 0 )
    {
        flag=1;
    }
    return flag;
}
///DEvuelve la suma de todos los consumos en la misma fecha
stConsumos agregaConsumosDias(char archivo[],stConsumos a,int dato)
{
    stConsumos b;
    int compara;
    FILE *archi=fopen(archivo,"r+b");
    int suma=0;
    int flag=0;
    ///rewind(archi);
    if(archi)
    {
        while(fread(&b,sizeof(stConsumos),1,archi)>0)
        {

            if(b.idCliente==a.idCliente&&b.anio==a.anio&&b.mes==a.mes&&b.dia==a.dia)
            {

                suma=b.datosConsumidos+dato;




            }
            else
            {
                suma=dato;
            }

        }
        a.datosConsumidos=suma;
//                fseek(archi, -1 * sizeof(stConsumos), SEEK_CUR);
//                fwrite(&b, sizeof(stConsumos), 1, archi);
//
//                fseek(archi, sizeof(stCliente), SEEK_CUR);
    }
    fclose(archi);
    return a;
}
int cuentaRegistros(char archivo[], int tamanioSt)
{
    int cantidadRegistros = 0;
    FILE *p = fopen(archivo, "rb");
    if(p!=NULL)
    {
        fseek(p, 0, SEEK_END);
        cantidadRegistros=ftell(p)/tamanioSt;
        fclose(p);
    }

    return cantidadRegistros;
}
///MUESTRA EL ARCHIVO DE CONSUMOS
void muestaArchivoConsumos(char archivoConsumos[])
{

    //int comp=fopen(archivo,"r");
    stConsumos a;

    // if(comp>0)
    //{
    FILE *archi=fopen(archivoConsumos,"rb");
    if(archi)
    {
        while(fread(&a,sizeof(stConsumos),1,archi)>0)
        {


            muestraUnConsumo(a);

        }
        fclose(archi);
    }
}

int randomClientesNroId(char archivoClientes[])
{
    int total=cuentaRegistros(archivoClientes,sizeof(stCliente));
    int numeroRandomC;
    numeroRandomC= numeroRandom(0, total);

    return numeroRandomC;
}
void cargaRandomConsumos(char archivoConsumos[],char archivoClientes[])
{
    printf("hola\n");
    stCliente a;
    stConsumos b;
    printf("hola2\n");
    FILE *archiCli=fopen(archivoClientes,"rb");
    printf("hola2\n");
    FILE *archiConsu=fopen(archivoConsumos,"ab");
    printf("hola2\n");
    int validarID=cuentaRegistros(archivoConsumos,sizeof(stConsumos));
    int ClienteRandom;
    int datoConsu;


    if(archiCli&&archiConsu)
    {
        for(int i=0; i<1000; i++)
        {
            ClienteRandom=randomClientesNroId(archivoClientes);
            printf("Cliente random%d\n",ClienteRandom);
            while(fread(&a,sizeof(stCliente),1,archiCli)>0)
            {
                if(a.id==ClienteRandom)
                {
                    b.anio=numeroRandom(1990,2021);
                    b.mes=numeroRandom(1,12);
                    b.dia=numeroRandom(1,28);
                    datoConsu=b.datosConsumidos=numeroRandom(0,1000);
                    b.baja=numeroRandom(0,1);
                    b.idCliente=a.id;
                    validarID++;
                    b.id=validarID;
                    b=agregaConsumosDias(archivoConsumos,b,datoConsu);
                    fwrite(&b,sizeof(stConsumos),1,archiConsu);

                }
            }
            rewind(archiCli);

        }
        fclose(archiCli);
        fclose(archiConsu);
    }

}
int numeroRandom(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
/*cuando escribimos este codigo solo dios y nosotros sabiamos lo que hacia
ahora solo dios sabe*/
