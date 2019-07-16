#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "llamado.h"
#include "arraynuevo.h"

int parser_parseLlamadoText(char* fileName, LinkedList* listaLlamado)
{
    char bufferId[1500];
    char bufferFecha[1500];
    char bufferNumeroCliente[1500];
    char bufferIdProblema[1500];
    char bufferSolucionado[1500];
    int cantidadDatos;
    Llamado* pLlamado;
    int retorno = -1;

    FILE* pFile = fopen(fileName,"r");

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
               bufferId,
               bufferFecha,
               bufferNumeroCliente,
               bufferIdProblema,
               bufferSolucionado);
        do
        {
            cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                   bufferId,
                                   bufferFecha,
                                   bufferNumeroCliente,
                                   bufferIdProblema,
                                   bufferSolucionado);
            if(cantidadDatos == 5)
            {
                pLlamado = llamado_newParametros(bufferId,
                                                bufferFecha,
                                                bufferNumeroCliente,
                                                bufferIdProblema,
                                                bufferSolucionado);

                if(pLlamado != NULL)
                {
                    if(ll_add(listaLlamado,pLlamado) == 0)
                    {
                        retorno = 1;
                    }
                }
            }
        }
        while(!feof(pFile));
    }
    fclose(pFile);
    return retorno; // OK
}
