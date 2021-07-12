#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carga
{
    char razon_social[50];
    int cuit;
    char categoria[2];
    char zona[6];
    int facturado;

} STcarga;


int valida_categoria(STcarga a[],int v);
int valida_zona(STcarga a[],int v);
int carga_Clientes(STcarga a[],int v,int tam);
void muestraArreglo(STcarga a[],int v);
int main()
{
    int tam=5;
    STcarga a[tam];
    int validos=0;
    printf("Carga clientes\n");
    validos=carga_Clientes(a,validos,tam);

    printf("Muestra clientes\n");
    muestraArreglo(a,validos);

    return 0;
}
///ESTA FUNCION CARGA CLIENTES
int carga_Clientes(STcarga a[],int v,int tam)
{

    char opcion=0;
    int VCate;

    while(opcion!=27 && v<tam)
    {
        printf("Ingrese razon social\n");
        fflush(stdin);
        scanf("%s",a[v].razon_social);
        printf("Ingrese cuit \n");
        scanf("%d",&a[v].cuit);
        printf("Ingrese categoria-A-B-C\n");
        fflush(stdin);
        scanf("%s",a[v].categoria);
        VCate=valida_categoria(a,v);
        if(VCate!=1)
        {
            while(valida_categoria(a,v)!=1)
            {
                printf("Ingrese categoria-A-B-C\n");
                fflush(stdin);
                scanf("%s",a[v].categoria);
                valida_categoria(a,v);

            }
        }
        printf("Ingrese zona N para norte o S para sur\n");
        fflush(stdin);
        scanf("%s",a[v].zona);
        if(valida_zona(a,v)!=1)
        {
            while(valida_zona(a,v)!=1)
            {
                printf("Ingrese zona N para norte o S para sur\n");
                fflush(stdin);
                scanf("%s",a[v].zona);
                valida_zona(a,v);

            }
        }
        printf("Ingrese importe facturado\n");
        scanf("%d",&a[v].facturado);

        v++;
        printf("Precione ESC para salir o cualquier tecla para continuar\n");
        opcion=getch();///Esto toma un caracter
    }

    return v;
}



///ESTA FUNCION VALIDA LAS CATEFORIAS
int valida_categoria(STcarga a[],int v)
{

    int flag=0;

    if(strcmp(a[v].categoria,"a")!=0||strcmp(a[v].categoria,"A")!=0||strcmp(a[v].categoria,"b")!=0||strcmp(a[v].categoria,"B")!=0||strcmp(a[v].categoria,"c")!=0||strcmp(a[v].categoria,"C"!=0))
    {
        flag=1;
    }
    return flag;
}
///ESTA FUNCION VALIDA LAS ZONAS
int valida_zona(STcarga a[],int v)
{

    int flag=0;

    if(strcmp(a[v].zona,"n")!=0||strcmp(a[v].zona,"N")!=0||strcmp(a[v].zona,"s")!=0||strcmp(a[v].zona,"S")!=0)
    {
        flag=1;
    }
    return flag;
}
///ESTA FUNCION MUESTRA EL ARREGLO
void muestraArreglo(STcarga a[],int v)
{

    for(int i=0; i<v; i++)
    {
        printf("Razon social %s\n",a[i].razon_social);
        printf("Cuit %d\n",a[i].cuit);
        printf("Categoria %s\n",a[i].categoria);
        printf("Zona %s\n",a[i].zona);
        printf("Facturacion %d",a[i].facturado);
    }

}

void menu_Principal(STcarga a[],int v,int tam){
    printf("Seleccione una opcion \n-1para cargar clientes\n")
    switch(opcion){
case 1:
    printf("Carga clientes\n");
    v=carga_Clientes(a,v,tam);
    break;
case 2:
    break;


    }

}


