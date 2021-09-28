#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct{
    char nombre[30];
    char apellido[30];
    char domicilio[45];
    char movil[12];
}stEmpleado;
void cargaEmpleadoArchivo(char archivo[]);
void leerArchivoEmpleados(char archivo[]);
void muestraUnEmpleado(stEmpleado e);
#endif // EMPLEADOS_H_INCLUDED
