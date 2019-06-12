#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_strings.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int flagArchivoTexto=0;
    int flagArchivoBinario=0;
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        getIntInRange(&option,"\n1)Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
                        "2)Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
                        "3)Alta de empleado\n4)Modificar datos de empleado\n"
                        "5)Baja de empleado\n6)MOSTRAR\n7)Ordenar empleados\n"
                        "8)Guardar datos (modo texto)\n9)Guardar datos (modo binario)\n",
                        "\nERROR\n",1,10,3);
        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\n--La carga del archivo fue exitosa (texto)--\n");
                    flagArchivoTexto=1;
                }
                else
                {
                    printf("\n--No pudo realizarse la carga del archivo(texto)--\n");
                }
                break;
            case 2:
                if(!controller_loadFromBinary("data.csv",listaEmpleados))
                {
                    printf("\n--La carga del archivo fue exitosa (Binario)--\n");
                    flagArchivoBinario=1;
                }
                else
                {
                    printf("\n--No pudo realizarse la carga del archivo(Binario)--\n");
                }
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("\n--El alta del empleado fue exitosa--\n");
                }
                else
                {
                    printf("\n--No pudo realizarse el alta--\n");
                }
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                if(flagArchivoTexto||flagArchivoBinario)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("\n--No hay Informacion disponible a mostrar--\n");
                }
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}
