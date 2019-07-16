#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "informes.h"
#include "controller.h"
#include "llamado.h"
#include "parser.h"
#include "LinkedList.h"

int main()
{
    // Definir lista de llamados
    int option;
    LinkedList* listaLlamados = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();

    // Leer llamados de archivo data.csv
    if(parser_parseLlamadoText("data.csv",listaLlamados) == 1)
    {
        printf("Crea una lista nueva con todos los problemas de los llamados\n");
        getIntInRange(&option,"Ingrese un numero","Error",1,5,3);
        listaFiltrada = ll_filter(listaLlamados,llamado_filterByProblema);
        controller_listLlamado(listaLlamados);

        // Generar archivo de salida
        if(generarArchivoLlamados("filter.csv",listaFiltrada) == 1)
        {
            printf("Archivo filtrado generado correctamente\n");
        }
        else
        {
            printf("Error generando archivo filtrado\n");
        }
    }
    else
    {
        printf("Error leyendo llamados\n");
    }
    return 0;
}
