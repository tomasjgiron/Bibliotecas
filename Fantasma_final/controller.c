#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ventas.h"
#include "Controller.h"
#include "parser.h"
#include "arraynuevo.h"
#define TRIES 3


/** \brief Alta de venta
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int

 */
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
            newVenta = venta_newParametros(bufferId,bufferFecha,bufferTipo,bufferCantidad,bufferPrecio,bufferCuit);
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

/** \brief Baja de venta
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
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
        if(getStringNumerosInt(bufferId,"Ingrese el ID de la venta que desea bajar: ","Error\n",TRIES) == 0)
        {
            auxId = atoi(bufferId);
            for (i=0; i<size; i++)
            {
                pVentas = ll_get(pArrayListVentas,i);
                if(auxId == venta_getId(pVentas,&idBuscado))
                {
                    ll_remove(pArrayListVentas,i);
                    venta_delete(pVentas);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Listar ventas
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_listVenta(LinkedList* pArrayListVentas)
{
    Ventas* pV;
    int auxId;
    float auxPrecio;
    int auxCantidad;
    char auxTipo[1500];
    char auxFecha[1500];
    char auxCuit[1500];
    int size;
    int i;

    if(pArrayListVentas != NULL)
    {
        size = ll_len(pArrayListVentas);
        for(i=0; i<size; i++)
        {
            pV = ll_get(pArrayListVentas,i);
            venta_getId(pV,&auxId);
            venta_getTipo(pV,auxTipo);
            venta_getCantidad(pV,&auxCantidad);
            venta_getPrecio(pV,&auxPrecio);
            venta_getFecha(pV,auxFecha);
            venta_getCuit(pV,auxCuit);
            if(pV != NULL)
            {
                printf("%d\t %s\t %s\t %d\t %f/t %s/n",auxId,
                       auxFecha,
                       auxTipo,
                       auxCantidad,
                       auxPrecio,
                       auxCuit);
            }
        }
    }
    return 0;
}
