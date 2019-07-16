#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "orquesta.h"

//static int generarId(void);

Orquesta* orquesta_new()
{
    return (Orquesta*) malloc(sizeof(Orquesta));
}

Orquesta* orquesta_newParametros(char* idStr,char* nombreStr,char* tipoStr,
                                 char* lugarStr,char* nacionalidadStr,
                                char* cantidadMusicosStr)
{
    Orquesta* orq = orquesta_new();
    if(orq != NULL)
    {
        orquesta_setIdStr(orq,idStr);
        orquesta_setNombre(orq,nombreStr);
        orquesta_setTipo(orq,tipoStr);
        orquesta_setLugar(orq,lugarStr);
        orquesta_setNacionalidad(orq,nacionalidadStr);
        orquesta_setCantidadMusicos(orq,cantidadMusicosStr);
    }
    return orq;
}

int orquesta_delete(Orquesta* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int orquesta_setIdStr(Orquesta* this, char* value)
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

/*int orquesta_setId(Orquesta* this,int value)
{
    int retorno  =-1;
    if (this!=NULL && value > 0)
    {
        this->idOrquesta = value;
        retorno = 0;
    }
    return retorno;
}*/

int orquesta_setNombre(Orquesta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->nombre,value,sizeof(this->nombre));
            retorno = 0;
        }
    }
    return retorno;
}


int orquesta_setCantidadMusicos(Orquesta* this,char* value)
{
    int retorno = -1;
    int auxCantidad;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxCantidad = atoi(value);
        if(auxCantidad > 0)
        {
            this->cantidadMusicos = auxCantidad;
            retorno = 0;
        }
    }
    return retorno;
}

int orquesta_setTipo(Orquesta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->tipo,value,sizeof(this->tipo));
            retorno = 0;
        }
    }
    return retorno;
}

int orquesta_setLugar(Orquesta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isAlphanumeric(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->lugar,value,sizeof(this->lugar));
            retorno = 0;
        }
    }
    return retorno;
}

int orquesta_setNacionalidad(Orquesta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->nacionalidad,value,sizeof(this->nacionalidad));
            retorno = 0;
        }
    }
    return retorno;
}

int orquesta_getNombre(Orquesta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int orquesta_getCantidadMusicos(Orquesta* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->cantidadMusicos;
        retorno = 0;
    }
    return retorno;
}

int orquesta_getId(Orquesta* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}

int orquesta_getTipo(Orquesta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int orquesta_getLugar(Orquesta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->lugar,sizeof(this->lugar));
        retorno = 0;
    }
    return retorno;
}

int orquesta_getNacionalidad(Orquesta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->nacionalidad,sizeof(this->nacionalidad));
        retorno = 0;
    }
    return retorno;
}

int orquesta_initArray(Orquesta* arrayOrquesta[],int lenOrquesta)
{
    int i;
    int retorno = -1;
    if(arrayOrquesta != NULL && lenOrquesta > 0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            arrayOrquesta[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int orquesta_findFree(Orquesta* arrayOrquesta[], int lenOrquesta)
{
    int i;
    int ret = -1;
    if(arrayOrquesta != NULL && lenOrquesta > 0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            if(arrayOrquesta[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}

int orquesta_contarByJaponesa(void* pFirstOrquesta)
{
    int retorno = 0;
    Orquesta* pOrquesta;

    pOrquesta = (Orquesta*) pFirstOrquesta;

    if(strcmp(pOrquesta->nacionalidad,"Japonesa") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int orquesta_contarByArgentina(void* pFirstOrquesta)
{
    int retorno = 0;
    Orquesta* pOrquesta;

    pOrquesta = (Orquesta*) pFirstOrquesta;

    if(strcmp(pOrquesta->nacionalidad,"Argentina") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int orquesta_contarByHolandesa(void* pFirstOrquesta)
{
    int retorno = 0;
    Orquesta* pOrquesta;

    pOrquesta = (Orquesta*) pFirstOrquesta;

    if(strcmp(pOrquesta->nacionalidad,"Holandesa") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int orquesta_contarCantidadMusicos(void* pFirstOrquesta)
{
    int retorno = -1;
    Orquesta* pOrquesta;
    pOrquesta = (Orquesta*) pFirstOrquesta;

    if(pOrquesta != NULL && pOrquesta->cantidadMusicos > 0)
    {
        retorno = pOrquesta->cantidadMusicos;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

/*int orquesta_sortByTipo(void* pFirstOrquesta,void* pSecondOrquesta)
{
    int retorno;
    Orquesta* pOrquestaA;
    Orquesta* pOrquestaB;

    pOrquestaA = (Orquesta*) pFirstOrquesta;
    pOrquestaB = (Orquesta*) pSecondOrquesta;

    if(strcmp(pOrquestaA->tipo,pOrquestaB->tipo) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pOrquestaA->tipo,pOrquestaB->tipo) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}

int orquesta_contarByTipoSTD(void* pFirstVenta)
{
    int retorno = 0;
    Orquesta* pOrquesta;

    pOrquesta = (Orquesta*) pFirstVenta;

    if(strcmp(pOrquesta->tipo,"STD") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int orquesta_contarByTipoEXP(void* pFirstVenta)
{
    int retorno = 0;
    Orquesta* pOrquesta;

    pOrquesta = (Orquesta*) pFirstVenta;

    if(strcmp(pOrquesta->tipo,"EXP") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int orquesta_contarByTipoECO(void* pFirstVenta)
{
    int retorno = 0;
    Orquesta* pOrquesta;

    pOrquesta = (Orquesta*) pFirstVenta;

    if(strcmp(pOrquesta->tipo,"ECO") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int orquesta_contarCantidad(void* pFirstVenta)
{
    int retorno = -1;
    Orquesta* pOrquesta;
    pOrquesta = (Orquesta*) pFirstVenta;

    if(pOrquesta != NULL && pOrquesta->cantidad > 0)
    {
        retorno = pOrquesta->cantidad;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int orquesta_contarMayor150(void* pFirstVenta)
{
    int retorno = 0;
    Orquesta* pOrquesta;
    int orquestaTotal;
    pOrquesta = (Orquesta*) pFirstVenta;

    if(pOrquesta != NULL && pOrquesta->cantidad > 0)
    {
        orquestaTotal = pOrquesta->cantidad * pOrquesta->precioUnitario;
    }
    if(orquestaTotal > 150)
    {
        retorno = 1;
    }
    return retorno;
}

int orquesta_contarMayor300(void* pFirstVenta)
{
    int retorno = 0;
    Orquesta* pOrquesta;
    int orquestaTotal;
    pOrquesta = (Orquesta*) pFirstVenta;

    if(pOrquesta != NULL && pOrquesta->cantidad > 0)
    {
        orquestaTotal = pOrquesta->cantidad * pOrquesta->precioUnitario;
    }
    if(orquestaTotal > 300)
    {
        retorno = 1;
    }
    return retorno;
}

int orquesta_contarPrecio(void* pFirstVenta)
{
    int retorno = -1;
    Orquesta* pOrquesta;
    pOrquesta = (Orquesta*) pFirstVenta;

    if(pOrquesta != NULL && pOrquesta->precioUnitario >= 0)
    {
        retorno = pOrquesta->precioUnitario;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int orquesta_contarPolaroid(void* pFirstVenta)
{
    int retorno = 0;
    Orquesta* pOrquesta;

    pOrquesta = (Orquesta*) pFirstVenta;

    if((strcmp(pOrquesta->tipo,"POLAROID_11x9") == 0) ||
            (strcmp(pOrquesta->tipo,"POLAROID_10x10") == 0))
    {
        retorno = 1;
    }
    return retorno;
}

static int generarId(void)
{
    static int id=1;
    return id++;
}*/
