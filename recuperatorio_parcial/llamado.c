#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "llamado.h"

//static int generarId(void);

Llamado* llamado_new()
{
    return (Llamado*) malloc(sizeof(Llamado));
}

Llamado* llamado_newParametros(char* idStr,char* fechaStr,char* numeroClienteStr,char* idProblemaStr,char* SolucionadoStr)
{
    Llamado* llam = llamado_new();
    if(llam != NULL)
    {
        llamado_setIdStr(llam,idStr);
        llamado_setFecha(llam,fechaStr);
        llamado_setNumeroCliente(llam,numeroClienteStr);
        llamado_setIdProblema(llam,idProblemaStr);
        llamado_setSolucionado(llam,SolucionadoStr);
    }
    return llam;
}

/*Llamado* llamado_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr)
{

    Llamado* cli = llamado_new();
    if(cli!=NULL)
    {
        llamado_setId(cli,id);
        llamado_setTipo(cli,nombreStr);
        llamado_setCantidad(cli,apellidoStr);
        llamado_setPeso(cli,dniStr);
    }
    return cli;
}*/

int llamado_delete(Llamado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int llamado_setIdStr(Llamado* this, char* value)
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

/*int llamado_setId(Llamado* this,int value)
{
    int retorno  =-1;
    if (this!=NULL && value > 0)
    {
        this->idLlamado = value;
        retorno = 0;
    }
    return retorno;
}*/

int llamado_setFecha(Llamado* this, char* value)
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

int llamado_setNumeroCliente(Llamado* this,char* value)
{
    int retorno = -1;
    int auxNumeroCliente;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxNumeroCliente = atoi(value);
        if(auxNumeroCliente > 0)
        {
            this->numeroCliente = auxNumeroCliente;
            retorno = 0;
        }
    }
    return retorno;
}

int llamado_setIdProblema(Llamado* this, char* value)
{
    int retorno = -1;
    int auxIdProblema;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxIdProblema = atoi(value);
        if(auxIdProblema > 0)
        {
            this->idProblema = auxIdProblema;
            retorno = 0;
        }
    }
    return retorno;
}


int llamado_setSolucionado(Llamado* this,char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->solucionado,value,sizeof(this->solucionado));
            retorno = 0;
        }
    }
    return retorno;
}

int llamado_getSolucionado(Llamado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->solucionado,sizeof(this->solucionado));
        retorno = 0;
    }
    return retorno;
}

int llamado_getNumeroCliente(Llamado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->numeroCliente;
        retorno = 0;
    }
    return retorno;
}

int llamado_getIdProblema(Llamado* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->idProblema;
        retorno = 0;
    }
    return retorno;
}

int llamado_getId(Llamado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}

int llamado_getFecha(Llamado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}

int llamado_initArray(Llamado* arrayLlamado[],int lenLlamado)
{
    int i;
    int retorno = -1;
    if(arrayLlamado != NULL && lenLlamado > 0)
    {
        for(i=0; i<lenLlamado; i++)
        {
            arrayLlamado[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int llamado_findFree(Llamado* arrayLlamado[], int lenLlamado)
{
    int i;
    int ret = -1;
    if(arrayLlamado != NULL && lenLlamado > 0)
    {
        for(i=0; i<lenLlamado; i++)
        {
            if(arrayLlamado[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}

int llamado_filterByProblema(void* pLlamado)
{
    int returnAux = 0;
    Llamado* auxLlamado = pLlamado;

    if(auxLlamado->idProblema > 0 && auxLlamado->idProblema < 6)
    {
        returnAux = 1;
    }
    return returnAux;
}

int llamado_printProblema(int problemaLlamado)
{
    switch (problemaLlamado)
    {
        case 1:
            printf("Problema: No enciende PC\n");
            break;
        case 2:
            printf("Problema: No funciona mouse\n");
            break;
        case 3:
            printf("Problema: No funciona teclado\n");
            break;
        case 4:
            printf("Problema: No hay internet\n");
            break;
        case 5:
            printf("Problema: No funciona telefono\n");
            break;
    }
    return 0;
}

/*
int llamado_sortByTipo(void* pFirstLlamado,void* pSecondLlamado)
{
    int retorno;
    Llamado* pLlamadoA;
    Llamado* pLlamadoB;

    pLlamadoA = (Llamado*) pFirstLlamado;
    pLlamadoB = (Llamado*) pSecondLlamado;

    if(strcmp(pLlamadoA->tipo,pLlamadoB->tipo) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pLlamadoA->tipo,pLlamadoB->tipo) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}

int llamado_contarByTipoSTD(void* pFirstLlamado)
{
    int retorno = 0;
    Llamado* pLlamado;

    pLlamado = (Llamado*) pFirstLlamado;

    if(strcmp(pLlamado->tipo,"STD") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int llamado_contarByTipoEXP(void* pFirstLlamado)
{
    int retorno = 0;
    Llamado* pLlamado;

    pLlamado = (Llamado*) pFirstLlamado;

    if(strcmp(pLlamado->tipo,"EXP") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int llamado_contarByTipoECO(void* pFirstLlamado)
{
    int retorno = 0;
    Llamado* pLlamado;

    pLlamado = (Llamado*) pFirstLlamado;

    if(strcmp(pLlamado->tipo,"ECO") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int llamado_contarCantidad(void* pFirstLlamado)
{
    int retorno = -1;
    Llamado* pLlamado;
    pLlamado = (Llamado*) pFirstLlamado;

    if(pLlamado != NULL && pLlamado->cantidad > 0)
    {
        retorno = pLlamado->cantidad;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int llamado_contarMayor150(void* pFirstLlamado)
{
    int retorno = 0;
    Llamado* pLlamado;
    int llamadoTotal;
    pLlamado = (Llamado*) pFirstLlamado;

    if(pLlamado != NULL && pLlamado->cantidad > 0)
    {
        llamadoTotal = pLlamado->cantidad * pLlamado->precioUnitario;
    }
    if(llamadoTotal > 150)
    {
        retorno = 1;
    }
    return retorno;
}

int llamado_contarMayor300(void* pFirstLlamado)
{
    int retorno = 0;
    Llamado* pLlamado;
    int llamadoTotal;
    pLlamado = (Llamado*) pFirstLlamado;

    if(pLlamado != NULL && pLlamado->cantidad > 0)
    {
        llamadoTotal = pLlamado->cantidad * pLlamado->precioUnitario;
    }
    if(llamadoTotal > 300)
    {
        retorno = 1;
    }
    return retorno;
}

int llamado_contarPrecio(void* pFirstLlamado)
{
    int retorno = -1;
    Llamado* pLlamado;
    pLlamado = (Llamado*) pFirstLlamado;

    if(pLlamado != NULL && pLlamado->precioUnitario >= 0)
    {
        retorno = pLlamado->precioUnitario;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int llamado_contarPolaroid(void* pFirstLlamado)
{
    int retorno = 0;
    Llamado* pLlamado;

    pLlamado = (Llamado*) pFirstLlamado;

    if((strcmp(pLlamado->tipo,"POLAROID_11x9") == 0) ||
            (strcmp(pLlamado->tipo,"POLAROID_10x10") == 0))
    {
        retorno = 1;
    }
    return retorno;
}

int llamado_printTipo(int tipoLlamado)
{
    switch (tipoLlamado)
    {
        case 1:
            printf("Tipo: No enciende PC\n");
            break;
        case 2:
            printf("Tipo: No funciona mouse\n");
            break;
        case 3:
            printf("Tipo: No funciona teclado\n");
            break;
        case 4:
            printf("Tipo: No hay internet\n");
            break;
        case 5:
            printf("Tipo: No funciona telefono\n");
            break;
    }
    return 0;
}

static int generarId(void)
{
    static int id=1;
    return id++;
}*/
