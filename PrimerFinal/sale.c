#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "sale.h"

Sale* sale_new()
{
    return (Sale*) malloc(sizeof(Sale));
}

Sale* sale_newParametros(char* idStr,char* idCStr,char* codProductStr,char* cantidadStr,char* precioUnitarioStr)
{

    Sale* sale = sale_new();
    if(sale!=NULL)
    {
        sale_setId(sale,idStr);
        sale_setIdC(sale,idCStr);
        sale_setCodProduct(sale,codProductStr);
        sale_setCantidad(sale,cantidadStr);
        sale_setPrecioUnitario(sale,precioUnitarioStr);
    }
    return sale;
}

int sale_delete(Sale* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int sale_setId(Sale* this, char* value)
{
    int auxId;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxId = atoi(value);
        if(auxId >= 0)
        {
            this->idSale = auxId;
            retorno = 0;
        }
    }
    return retorno;
}

int sale_setIdC(Sale* this, char* value)
{
    int auxIdC;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxIdC = atoi(value);
        if(auxIdC >= 0)
        {
            this->idClient = auxIdC;
            retorno = 0;
        }
    }
    return retorno;
}


int sale_setCodProduct(Sale* this,char* value)
{
    int retorno = -1;
    int auxCodigo;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxCodigo = atoi(value);
        if(auxCodigo >= 0)
        {
            this->codProduct = auxCodigo;
            retorno = 0;
        }
    }
    return retorno;
}

int sale_setCantidad(Sale* this, char* value)
{
    int retorno = -1;
    int auxCantidad;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxCantidad = atoi(value);
        if(auxCantidad >= 0)
        {
            this->cantidad = auxCantidad;
            retorno = 0;
        }
    }
    return retorno;
}


float sale_setPrecioUnitario(Sale* this,char* value)
{
    int retorno = -1;
    float auxPrecio;
    if(this != NULL && value != NULL && isNumberFloat(value))
    {
        auxPrecio = atof(value);
        if(auxPrecio >= 0)
        {
            this->precioUnitario = auxPrecio;
            retorno = 0;
        }
    }
    return retorno;
}


int sale_getCodProduct(Sale* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->codProduct;
        retorno = 0;
    }
    return retorno;
}

int sale_getCantidad(Sale* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

float sale_getPrecioUnitario(Sale* this,float* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->precioUnitario;
        retorno = 0;
    }
    return retorno;
}

int sale_getId(Sale* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->idSale;
        retorno = 0;
    }
    return retorno;
}

int sale_getIdC(Sale* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->idClient;
        retorno = 0;
    }
    return retorno;
}


int sale_initArray(Sale* arraySale[],int lenSale)
{
    int i;
    int retorno = -1;
    if(arraySale != NULL && lenSale > 0)
    {
        for(i=0; i<lenSale; i++)
        {
            arraySale[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int sale_findFree(Sale* arraySale[], int lenSale)
{
    int i;
    int ret = -1;
    if(arraySale != NULL && lenSale > 0)
    {
        for(i=0; i<lenSale; i++)
        {
            if(arraySale[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}
