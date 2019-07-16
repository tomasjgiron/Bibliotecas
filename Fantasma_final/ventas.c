#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "ventas.h"

//static int generarId(void);

Ventas* venta_new()
{
    return (Ventas*) malloc(sizeof(Ventas));
}

Ventas* venta_newParametros(char* idStr,char* fechaStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr)
{
    Ventas* ven = venta_new();
    if(ven != NULL)
    {
        venta_setIdStr(ven,idStr);
        venta_setFecha(ven,fechaStr);
        venta_setTipo(ven,tipoStr);
        venta_setCantidad(ven,cantidadStr);
        venta_setPrecio(ven,precioStr);
        venta_setCuit(ven,cuitStr);
    }
    return ven;
}

/*Ventas* venta_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr)
{

    Ventas* cli = venta_new();
    if(cli!=NULL)
    {
        venta_setId(cli,id);
        venta_setTipo(cli,nombreStr);
        venta_setCantidad(cli,apellidoStr);
        venta_setPeso(cli,dniStr);
    }
    return cli;
}*/

int venta_delete(Ventas* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int venta_setIdStr(Ventas* this, char* value)
{
    int auxId;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxId = atoi(value);
        if(auxId > 0)
        {
            this->id = auxId;
            retorno = 0;
        }
    }
    return retorno;
}

/*int venta_setId(Ventas* this,int value)
{
    int retorno  =-1;
    if (this!=NULL && value > 0)
    {
        this->idVentas = value;
        retorno = 0;
    }
    return retorno;
}*/

int venta_setPrecio(Ventas* this,char* value)
{
    int retorno = -1;
    float auxPrecio;

    if(this != NULL && value != NULL && isNumberFloat(value))
    {
        auxPrecio = atof(value);
        if(auxPrecio > 0)
        {
            this->precioUnitario = auxPrecio;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_setTipo(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isAlphanumeric(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->tipo,value,sizeof(this->tipo));
            retorno = 0;
        }
    }
    return retorno;
}


int venta_setCantidad(Ventas* this,char* value)
{
    int retorno = -1;
    int auxCantidad;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxCantidad = atoi(value);
        if(auxCantidad > 0)
        {
            this->cantidad = auxCantidad;
            retorno = 0;
        }
    }
    return retorno;
}


int venta_getTipo(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int venta_getPrecio(Ventas* this, float* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->precioUnitario;
        retorno = 0;
    }
    return retorno;
}

int venta_getCantidad(Ventas* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int venta_getId(Ventas* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}

int venta_setFecha(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isFechaCorto(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->fecha,value,sizeof(this->fecha));
            retorno = 0;
        }
    }
    return retorno;
}
int venta_getFecha(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}

int venta_setCuit(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isCuit(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->cuit,value,sizeof(this->cuit));
            retorno = 0;
        }
    }
    return retorno;
}
int venta_getCuit(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int venta_initArray(Ventas* arrayVentas[],int lenVentas)
{
    int i;
    int retorno = -1;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0; i<lenVentas; i++)
        {
            arrayVentas[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int venta_findFree(Ventas* arrayVentas[], int lenVentas)
{
    int i;
    int ret = -1;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0; i<lenVentas; i++)
        {
            if(arrayVentas[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}

int venta_sortByTipo(void* pFirstVentas,void* pSecondVentas)
{
    int retorno;
    Ventas* pVentasA;
    Ventas* pVentasB;

    pVentasA = (Ventas*) pFirstVentas;
    pVentasB = (Ventas*) pSecondVentas;

    if(strcmp(pVentasA->tipo,pVentasB->tipo) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pVentasA->tipo,pVentasB->tipo) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}

int venta_contarByTipoSTD(void* pFirstVenta)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas = (Ventas*) pFirstVenta;

    if(strcmp(pVentas->tipo,"STD") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int venta_contarByTipoEXP(void* pFirstVenta)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas = (Ventas*) pFirstVenta;

    if(strcmp(pVentas->tipo,"EXP") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int venta_contarByTipoECO(void* pFirstVenta)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas = (Ventas*) pFirstVenta;

    if(strcmp(pVentas->tipo,"ECO") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int venta_contarCantidad(void* pFirstVenta)
{
    int retorno = -1;
    Ventas* pVentas;
    pVentas = (Ventas*) pFirstVenta;

    if(pVentas != NULL && pVentas->cantidad > 0)
    {
        retorno = pVentas->cantidad;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int venta_contarMayor150(void* pFirstVenta)
{
    int retorno = 0;
    Ventas* pVentas;
    int ventaTotal;
    pVentas = (Ventas*) pFirstVenta;

    if(pVentas != NULL && pVentas->cantidad > 0)
    {
        ventaTotal = pVentas->cantidad * pVentas->precioUnitario;
    }
    if(ventaTotal > 150)
    {
        retorno = 1;
    }
    return retorno;
}

int venta_contarMayor300(void* pFirstVenta)
{
    int retorno = 0;
    Ventas* pVentas;
    int ventaTotal;
    pVentas = (Ventas*) pFirstVenta;

    if(pVentas != NULL && pVentas->cantidad > 0)
    {
        ventaTotal = pVentas->cantidad * pVentas->precioUnitario;
    }
    if(ventaTotal > 300)
    {
        retorno = 1;
    }
    return retorno;
}

int venta_contarPrecio(void* pFirstVenta)
{
    int retorno = -1;
    Ventas* pVentas;
    pVentas = (Ventas*) pFirstVenta;

    if(pVentas != NULL && pVentas->precioUnitario >= 0)
    {
        retorno = pVentas->precioUnitario;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int venta_contarPolaroid(void* pFirstVenta)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas = (Ventas*) pFirstVenta;

    if((strcmp(pVentas->tipo,"POLAROID_11x9") == 0) ||
            (strcmp(pVentas->tipo,"POLAROID_10x10") == 0))
    {
        retorno = 1;
    }
    return retorno;
}

/*
static int generarId(void)
{
    static int id=1;
    return id++;
}*/
