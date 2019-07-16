#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "llamado.h"
#include "Controller.h"
#include "parser.h"
#include "arraynuevo.h"
#define TRIES 3

/*
* \brief Alta de llamado
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int


int controller_addVenta(LinkedList* pArrayListVenta)
{
    Ventas* newVenta;
    char bufferId[1500];
    char bufferTipo[1500];
    char bufferCantidad[1500];
    char bufferPrecio[1500];
    char bufferFecha[1500];
    char bufferCuit[1500];
    int retorno = -1;

    if(pArrayListVenta != NULL)
    {
        if((getStringNumerosInt(bufferId,"Ingrese id: ","Error",TRIES)== 0)
                &&(getStringAlphanumeric(bufferTipo,"Ingrese tipo: ","Error",TRIES) == 0)
                &&(getStringNumerosInt(bufferCantidad,"Ingrese cantidad: ","Error",TRIES) == 0)
                &&(getStringNumerosFloat(bufferPrecio,"Ingrese precio: ","Error",TRIES == 0)
                   && getCuit(bufferCuit,"Ingrese cuit: ","Error",TRIES)== 0))
        {
            newVenta = llamado_newParametros(bufferId,bufferFecha,bufferTipo,bufferCantidad,bufferPrecio,bufferCuit);
            if(newVenta != NULL)
            {
                if(ll_add(pArrayListVenta,newVenta) == 0)
                {
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

* \brief Baja de llamado
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *

int controller_removeVenta(LinkedList* pArrayListVentas)
{
    Ventas* pVentas;
    int retorno = -1;
    int size;
    char bufferId[1500];
    int auxId;
    int idBuscado;
    int i;

    if (pArrayListVentas != NULL)
    {
        size = ll_len(pArrayListVentas);
        if(getStringNumerosInt(bufferId,"Ingrese el ID de la llamado que desea bajar: ","Error\n",TRIES) == 0)
        {
            auxId = atoi(bufferId);
            for (i=0; i<size; i++)
            {
                pVentas = ll_get(pArrayListVentas,i);
                if(auxId == llamado_getId(pVentas,&idBuscado))
                {
                    ll_remove(pArrayListVentas,i);
                    llamado_delete(pVentas);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}
*/
/** \brief Listar llamados
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_listLlamado(LinkedList* pArrayListLlamado)
{
    Llamado* pLl;
    int auxId;
    char auxFecha[1500];
    int auxNumeroCliente;
    int auxIdProblema;
    char auxSolucionado[1500];
    int size;
    int i;

    if(pArrayListLlamado != NULL)
    {
        size = ll_len(pArrayListLlamado);
        for(i=0; i<size; i++)
        {
            pLl = ll_get(pArrayListLlamado,i);
            llamado_getId(pLl,&auxId);
            llamado_getFecha(pLl,auxFecha);
            llamado_getNumeroCliente(pLl,&auxNumeroCliente);
            llamado_getIdProblema(pLl,&auxIdProblema);
            llamado_getSolucionado(pLl,auxSolucionado);
            if(pLl != NULL)
            {
                printf("%d\t %s\t %d\t %s\n",
                       auxId,
                       auxFecha,
                       auxNumeroCliente,
                       auxSolucionado);
                llamado_printProblema(auxIdProblema);
                printf("--------\n");
            }
        }
    }
    return 0;
}
