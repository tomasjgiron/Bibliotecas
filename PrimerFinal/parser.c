#include "LinkedList.h"
#include "client.h"
#include "sale.h"
#include <stdio.h>
#include <stdlib.h>
#include "arraynuevo.h"

int parser_parseClientesText(char* fileName, LinkedList* listaClientes)
{
    char bufferId[1500];
    char bufferNombre[1500];
    char bufferApellido[1500];
    char bufferDni[1500];
    int cantidadDatos;
    Client* pClient;
    int retorno = -1;

    FILE* pFile = fopen(fileName,"r");

            if(pFile != NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                bufferId,
                                bufferNombre,
                                bufferApellido,
                                bufferDni);
                do
                {
                    cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                                        bufferId,
                                                                        bufferNombre,
                                                                        bufferApellido,
                                                                        bufferDni);
                    if(cantidadDatos == 4)
                    {
                        pClient = client_newParametros(bufferId,
                                                        bufferNombre,
                                                        bufferApellido,
                                                        bufferDni);
                        if(pClient != NULL)
                        {
                            if(ll_add(listaClientes,pClient) == 0)
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

int parser_parseVentasText(char* fileName, LinkedList* listaVentas)
{
    char bufferId[1500];
    char bufferIdC[1500];
    char bufferCodProducto[1500];
    char bufferCantidad[1500];
    char bufferPrecioUnitario[1500];
    int cantidadDatos;
    Sale* pSale;
    int retorno = -1;

    FILE* pFile = fopen(fileName,"r");

            if(pFile != NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                bufferId,
                                bufferIdC,
                                bufferCodProducto,
                                bufferCantidad,
                                bufferPrecioUnitario);
                do
                {
                    cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                                                            bufferId,
                                                                            bufferIdC,
                                                                            bufferCodProducto,
                                                                            bufferCantidad,
                                                                            bufferPrecioUnitario);
                    if(cantidadDatos == 5)
                    {
                        pSale = sale_newParametros(bufferId,
                                                    bufferIdC,
                                                    bufferCodProducto,
                                                    bufferCantidad,
                                                    bufferPrecioUnitario);
                        if(pSale != NULL)
                        {
                            if(ll_add(listaVentas,pSale) == 0)
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

