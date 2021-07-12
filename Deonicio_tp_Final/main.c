#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
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
void muestras_mas_facturado(STcarga a[],int v);
void busca_x_categoria(STcarga a[],int v);
int main()
{
    int tam=5;
    STcarga a[tam];
    int validos=0;
    char dato;
    printf("Carga clientes\n");
    validos=carga_Clientes(a,validos,tam);

    printf("Muestra clientes\n");
    muestraArreglo(a,validos);

    muestras_mas_facturado(a,validos);
    printf("Busca por categoria\n");

    busca_x_categoria(a,validos);

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

    if(strcmp(a[v].categoria,"a")==0||strcmp(a[v].categoria,"A")==0)
    {
        flag=1;
    }else if (strcmp(a[v].categoria,"b")==0||strcmp(a[v].categoria,"B")==0)
    {
        flag=1;
    }else if (strcmp(a[v].categoria,"c")==0||strcmp(a[v].categoria,"C")==0)
    {
        flag=1;
    }

    return flag;
}
///ESTA FUNCION VALIDA LAS ZONAS
int valida_zona(STcarga a[],int v)
{

    int flag=0;

    if(strcmp(a[v].zona,"n")==0||strcmp(a[v].zona,"N")==0)
    {
        flag=1;
    }else if (strcmp(a[v].zona,"s")==0||strcmp(a[v].zona,"S")==0)
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
        printf("Facturacion %d\n",a[i].facturado);
    }

}

/*void menu_Principal(STcarga a[],int v,int tam){
    printf("Seleccione una opcion \n-1para cargar clientes\n")
    switch(opcion){
case 1:
    printf("Carga clientes\n");
    v=carga_Clientes(a,v,tam);
    break;
case 2:
    break;


    }

}*/
///ESTA FUNCION MUESTRA Y BUSCA EL CLIENTE QUE MAS FACTURO
void muestras_mas_facturado(STcarga a[],int v){
    printf("Muestra facturado inicio\n");
    int i=0;
    STcarga aux[1];
    int minimo=0;

    while(i<v){
    if(i==0){
     minimo=a[i].facturado;
    }
    if(minimo<=a[i].facturado){
        aux[0]=a[i];
    }
    i++;
    }

    printf("\n\nEl maximo facturado pertenece a\n");
    muestraArreglo(aux,1);

//        printf("Razon social %s\n",aux[0].razon_social);
//        printf("Cuit %d\n",aux[0].cuit);
//        printf("Categoria %s\n",aux[0].categoria);
//        printf("Zona %s\n",aux[0].zona);
//        printf("Facturacion %d\n",aux[0].facturado);

}
void busca_x_categoria(STcarga a[],int v){
    STcarga dato[1];
    printf("ingrese dato a buscar\n");
    fflush(stdin);
    scanf("%c",dato[0].categoria);
    int compara;
    STcarga dato2[1];
    int flag=0;
    for(int i=0; i<v;i++){

        compara=strcmp(dato[0].categoria,a[i].categoria);
        if(compara==0){
        printf("Razon social %s\n",a[i].razon_social);
        printf("Cuit %d\n",a[i].cuit);
        printf("Categoria %s\n",a[i].categoria);
        printf("Zona %s\n",a[i].zona);
        printf("Facturacion %d\n",a[i].facturado);
        flag=1;
        }
    }
    if(flag==0){
        printf("No hay datos que coinidan\n");
    }

}



