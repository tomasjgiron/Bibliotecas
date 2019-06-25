#include "LinkedList.h"
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include "arraynuevo.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    char bufferId[1500];
    char bufferNombre[1500];
    char bufferHorasTrabajadas[1500];
    int cantidadDatos;
    Empleado* pEmpleado;
    int retorno = -1;

    FILE* pFile = fopen(fileName,"r");

            if(pFile != NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^\n]\n",
                                bufferId,
                                bufferNombre,
                                bufferHorasTrabajadas);
                do
                {
                    cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",
                                            bufferId,
                                            bufferNombre,
                                            bufferHorasTrabajadas);
                    if(cantidadDatos == 3)
                    {
                        pEmpleado = employee_newParametros( bufferId,
                                                            bufferNombre,
                                                            bufferHorasTrabajadas);
                        if(pEmpleado != NULL)
                        {
                            if(ll_add(listaEmpleados,pEmpleado) == 0)
                            {
                                retorno = 1;
                            }
                        }
                    }
                }
                while(!feof(pFile));
                fclose(pFile);
            }
    return retorno; // OK
}

