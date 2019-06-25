#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca LinkedList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados = ll_newLinkedList();

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados) == 1)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        ll_map(listaEmpleados,em_calcularSueldo);

        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados) == 1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyando empleados\n");


    return 0;
}

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    Empleado* pE;
    int auxId;
    int auxSueldo;
    int auxHoras;
    char auxNombre[1500];
    int size;
    int i;
    int retorno = -1;

    FILE* fp = fopen(fileName,"w+");
    if(fp != NULL && listaEmpleados != NULL)
    {
        fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");

        size = ll_len(listaEmpleados);

        for(i=0;i<size;i++)
        {
            pE = ll_get(listaEmpleados,i);
            employee_getId(pE,&auxId);
            employee_getNombre(pE,auxNombre);
            employee_getHorasTrabajadas(pE,&auxHoras);
            employee_getSueldo(pE,&auxSueldo);
            if(pE != NULL)
            {
                fprintf(fp,"%d,%s,%d,%d\n",auxId,
                                            auxNombre,
                                            auxHoras,
                                            auxSueldo);
            }
        }
        fclose(fp);
        retorno = 1;
    }
    return retorno;
}
