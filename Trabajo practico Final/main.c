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
void muestaArchivoClientes(char archivo[]);
void modificaCliente(char archivo[],int nroClnt);
void muestraUnCliente(stCliente a);
void filtraClientes(char archivo[],char archivoConsumo);
void modificaConsumo(char archivo[],int nroClnt);
void muestraXAnio(char consumos[],stCliente b);
void muestraXRangoDeAnios(char consumos[],stCliente b);
void muestraXMes(char consumos[],stCliente b);
void muestraXDatosConsumosFiltro(char consumos[],stCliente b,int datoanio,int datoanio2,int datomes,int datomes2,int datodia,int datodia2);
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
///CARGA DE DATOS CLIENTE
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
            validos=a.id;///CAMBIAR POR FSEEK Y VALIDAR EL ULTIMO ID CARGADO
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
///MUESTRA ELA RCHIVO CLIENTES
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
                    if(datoConsumo=='s')
                    {
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
        int opcion=0;
        int opcion2=0;
        int dato2=0;
        int datomes=0;
        int datomes2=0;
        int datoanio=0;
        int datoanio2=0;
        int datodia=0;
        int datodia2=0;
        char opciones=-1;
        printf("Fliltro\n*ID opcion 1\n*Anio-*Mes-*Dia-*2n");
        switch(opcion)
        {
        case 1:
            printf("Muestra por ID\n");
            while(fread(&a,sizeof(stConsumos),1,archi)>0)
            {
                if(a.idCliente==b.id)
                {
                    muestraUnConsumo(a);
                }

            }
            break;
        case 2:

            printf("muestra anio 0 rango de anios\n");
            printf("ingrese -s- para buscar por anio -r- para buscar por rango de anios -x- para saltar opcion e ir a la siguiente\n");

            opciones=getch();
            if(opciones=='s'||opciones=='S')
            {
                printf("ingrese anio a buscar\n");
                scanf("%d",&datoanio);
                datoanio2==datoanio;
                if(datoanio<1||datoanio>7)
                {
                    while(datoanio<1||datoanio>7)
                    {
                        printf("ingrese anio a buscar\n");
                        scanf("%d",&datoanio);
                        datoanio2==datoanio;
                    }
                }
            }
            if(opciones=='r'||opciones=='R')
            {
                printf("ingrese rango de anios a buscar\n");
                printf("desde...\n");
                scanf("%d",&datoanio);
                printf("hasta..");
                scanf("%d",&datoanio2);
                if(datoanio>datoanio2)
                {
                    while(datoanio>datoanio2)
                    {
                        printf("ingrese rango de anios a buscar\n");
                        printf("desde...\n");
                        scanf("%d",&datoanio);
                        printf("hasta..");
                        scanf("%d",&datoanio2);
                    }

                }

            }
            printf("muestra mes o rango de meses\n");
            printf("ingrese -s- para buscar por mes -r- para buscar por rango de meses -x- para saltar opcion e ir a la siguiente\n");
            opciones=getch();
            if(opciones=='s'||opciones=='S')
            {
                printf("ingrese mes a buscar\n");
                scanf("%d",&datomes);
                datomes2==datomes;
                if(datomes<1||datomes>7)
                {
                    while(datomes<1||datomes>7)
                    {
                        printf("ingrese mes a buscar\n");
                        scanf("%d",&datomes);
                        datomes2==datomes;
                    }
                }
            }
            if(opciones=='r'||opciones=='R')
            {
                printf("ingrese rango de meses a buscar\n");
                printf("desde...\n");
                scanf("%d",&datomes);
                printf("hasta..");
                scanf("%d",&datomes2);
                if(datomes>datomes2|| datomes <1||datomes>12||datomes2<1||datomes2>12)
                {
                    while(datomes>datomes2|| datomes <1||datomes>12||datomes2<1||datomes2>12)
                    {
                        printf("ingrese rango de meses a buscar\n");
                        printf("desde...\n");
                        scanf("%d",&datomes);
                        printf("hasta..");
                        scanf("%d",&datomes2);
                    }

                }
                printf("muestra dia o rango de dias");
                printf("ingrese -s- para buscar por mes -r- para buscar por rango de meses -x- para saltar opcion e ir a la siguiente\n");
                opciones=getch();
                if(opciones=='s'||opciones=='S')
                {
                    printf("ingrese dia a buscar\n");
                    scanf("%d",&datodia);
                    datodia2==datodia;
                    if(datodia<1||datodia>7)
                    {
                        while(datodia<1||datodia>7)
                        {
                            printf("ingrese dia a buscar\n");
                            scanf("%d",&datodia);
                            datodia2==datodia;
                        }
                    }
                }
                if(opciones=='r'||opciones=='R')
                {
                    printf("ingrese rango de dias a buscar\n");
                    printf("desde...\n");
                    scanf("%d",&datodia);
                    printf("hasta..");
                    scanf("%d",&datodia2);
                    if(datodia>datodia2|| datodia <1||datodia>7||datodia2<1||datodia2>7)
                    {
                        while(datodia>datodia2|| datodia <1||datodia>7||datodia2<1||datodia2>7)
                        {
                            printf("ingrese rango de dias a buscar\n");
                            printf("desde...\n");
                            scanf("%d",&datodia);
                            printf("hasta..");
                            scanf("%d",&datodia2);
                        }

                    }
///************************DEFAULT****************************************************
/// si algunos de los datos estan en 0 les otorga un valor como default de esta manera
///si el usuario quiere ver un dia en especifico sin importar los años o un rango de años sin umportar los dias
/// lo puede hacer ademas que me ahorro crear una funcion diferente para cada funcion especifica
                    if(datoanio==0)
                    {
                        datoanio=1;
                    }
                    if(datoanio2==0)
                    {
                        datoanio2=99999999;
                    }
                    if(datomes==0)
                    {
                        datomes=1;
                    }
                    if(datomes2==0)
                    {
                        datomes2=12;
                    }
                    if(datodia==0)
                    {
                        datoanio=1;
                    }
                    if(datodia2==0)
                    {
                        datodia2=7;
                    }
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    muestraXDatosConsumosFiltro(archi,b,datoanio,datoanio2,datomes,datomes2,datodia,datodia2);
                    break;

                }

                fclose(archi);
            }
        }
    }
}
///muestras por anio funcion en desuso
//void muestraXAnio(char consumos[],stCliente b)
//{
//    stConsumos a;
//    FILE *archi=fopen(consumos,"rb");
//    int dato=0;
//    if(archi)
//    {
//        printf("Ingrese Anio a buscar\n");
//
//        scanf("%d",&dato);
//        while(fread(&a,sizeof(stConsumos),1,archi)>0)
//        {
//            if(a.anio==dato&&a.idCliente==b.id)
//            {
//                muestraUnConsumo(a);
//            }
//        }
//    }
//}
///muestra por rango de años funcion en desuso
//void muestraXRangoDeAnios(char consumos[],stCliente b)
//{
//    stConsumos a;
//    FILE *archi=fopen(consumos,"rb");
//    if(archi)
//    {
//        int dato=0;
//        int dato2=0;
//        printf("Ingrese rango de anios\n");
//        printf("De...\n");
//        scanf("%d",&dato);
//        printf("Hasta...\n");
//        scanf("%d",&dato2);
//        if(dato>dato2)
//        {
//            printf("Ingrese rango de anios\n");
//            printf("De...\n");
//            scanf("%d",&dato);
//            printf("Hasta...\n");
//            scanf("%d",&dato2);
//        }
//        while(fread(&a,sizeof(stConsumos),1,archi)>0)
//        {
//            if(a.anio<=dato2&&a.anio>=dato&&a.idCliente==b.id)
//            {
//                muestraUnConsumo(a);
//            }
//        }
//    }
//}
///MUESTRA X MES
//void muestraXMes(char consumos[],stCliente b)
//{
//    stConsumos a;
//    FILE *archi=fopen(consumos,"rb");
//    int dato=0;
//
//    if(archi)
//    {
//        printf("Ingrese Mes a buscar\n");
//        scanf("%d",&dato);
//        if(dato >12&& dato <1)
//        {
//            printf("Ingrese Mes a buscar\n");
//
//            scanf("%d",&dato);
//        }
//        while(fread(&a,sizeof(stConsumos),1,archi)>0)
//        {
//            if(a.mes==dato&&a.idCliente==b.id)
//            {
//                muestraUnConsumo(a);
//            }
//        }
//    }
//
//}
///MUESTRA TODOS LOS DATOS DE STCONSUMOS CON LA FUNCION DE FILTROS
void muestraXDatosConsumosFiltro(char consumos[],stCliente b,int datoanio,int datoanio2,int datomes,int datomes2,int datodia,int datodia2)
{

    stConsumos a;
    FILE *archi=fopen(consumos,"rb");

    if(archi)
    {


        while(fread(&a,sizeof(stConsumos),1,archi)>0)
        {
            if(a.idCliente==b.id&&a.anio>=datoanio&&a.anio<=datoanio2&&a.mes>=datomes&&a.mes<=datomes2&&a.dia>=datodia&&a.dia<=datodia2)
            {
                muestraUnConsumo(a);
            }
        }
    }
    fclose(archi);
}


///CARGA CONSUMOS
int cargaDatosConsumo(char archivoConsumo[],int validos,stCliente b)///pasar id de cliente
{
    char opcion=0;
    stConsumos a;
    int comprueba=fopen(archivoConsumo,"r");///comprueba si el archivo existe xon anterioridad
    FILE *archi=fopen(archivoConsumo,"ab");

    if(archi)
    {
        if(comprueba>0) ///si el archivo ya existia le asigna el valor del id a validos
        {
            validos=a.id;///CAMBIAR POR FSEEK Y VALIDAR EL ULTIMO ID CARGADO
        }
        while(opcion!=27)
        {
            a.idCliente=b.id;
            printf("Ingrese anio de consumo \n");
            scanf("%d",&a.anio);
            printf("Ingrese mes\n");
            scanf("%d",a.mes);
            printf("Ingrese dia\n");
            scanf("%d",a.dia);
            printf("Ingrese datos consumidos\n");
            scanf("%d",a.datosConsumidos);
            a.baja=0;
            a.id=validos;
            validos++;
            fwrite(&a,sizeof(stConsumos),1,archi);
            printf("Precione ESC para salir ,Cualquier tecla para continuar\n");
            opcion=getch();

        }
        fclose(archi);
    }
    return validos;
}
