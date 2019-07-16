#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "persona.h"

//static int generarId(void);

Persona* persona_new()
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* persona_newParametros(char* idStr,char* fechaStr,char* nombreStr,
                                 char* apellidoStr,char* dniStr,
                                char* estadoCivilStr,char* direccionStr,
                                 char* edadStr)
{
    Persona* per = persona_new();
    if(per != NULL)
    {
        persona_setIdStr(per,idStr);
        persona_setFechaNacimiento(per,fechaStr);
        persona_setNombre(per,nombreStr);
        persona_setApellido(per,apellidoStr);
        persona_setDni(per,dniStr);
        persona_setEstadoCivil(per,estadoCivilStr);
        persona_setDireccion(per,direccionStr);
        persona_setEdad(per,edadStr);
    }
    return per;
}

int persona_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int persona_setIdStr(Persona* this, char* value)
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

/*int persona_setId(Persona* this,int value)
{
    int retorno  =-1;
    if (this!=NULL && value > 0)
    {
        this->idPersona = value;
        retorno = 0;
    }
    return retorno;
}*/

int persona_setFechaNacimiento(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isFechaBarra(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->fechaNacimiento,value,sizeof(this->fechaNacimiento));
            retorno = 0;
        }
    }
    return retorno;
}

int persona_setNombre(Persona* this, char* value)
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


int persona_setEdad(Persona* this,char* value)
{
    int retorno = -1;
    int auxEdad;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxEdad = atoi(value);
        if(auxEdad > 0 && auxEdad < 110)
        {
            this->edad = auxEdad;
            retorno = 0;
        }
    }
    return retorno;
}

int persona_setApellido(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->apellido,value,sizeof(this->apellido));
            retorno = 0;
        }
    }
    return retorno;
}

int persona_setDni(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isDni(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->dni,value,sizeof(this->dni));
            retorno = 0;
        }
    }
    return retorno;
}

int persona_setEstadoCivil(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->estadoCivil,value,sizeof(this->estadoCivil));
            retorno = 0;
        }
    }
    return retorno;
}

int persona_setDireccion(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isAlphanumeric(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->direccion,value,sizeof(this->direccion));
            retorno = 0;
        }
    }
    return retorno;
}

int persona_getNombre(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int persona_getEdad(Persona* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->edad;
        retorno = 0;
    }
    return retorno;
}

int persona_getId(Persona* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}

int persona_getFechaNacimiento(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->fechaNacimiento,sizeof(this->fechaNacimiento));
        retorno = 0;
    }
    return retorno;
}

int persona_getApellido(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int persona_getDni(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->dni,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int persona_getEstadoCivil(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->estadoCivil,sizeof(this->estadoCivil));
        retorno = 0;
    }
    return retorno;
}

int persona_getDireccion(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->direccion,sizeof(this->direccion));
        retorno = 0;
    }
    return retorno;
}

int persona_initArray(Persona* arrayPersona[],int lenPersona)
{
    int i;
    int retorno = -1;
    if(arrayPersona != NULL && lenPersona > 0)
    {
        for(i=0; i<lenPersona; i++)
        {
            arrayPersona[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int persona_findFree(Persona* arrayPersona[], int lenPersona)
{
    int i;
    int ret = -1;
    if(arrayPersona != NULL && lenPersona > 0)
    {
        for(i=0; i<lenPersona; i++)
        {
            if(arrayPersona[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}

int persona_contarBySoltero(void* pFirstPersona)
{
    int retorno = 0;
    Persona* pPersona;

    pPersona = (Persona*) pFirstPersona;

    if(strcmp(pPersona->estadoCivil,"Soltero") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int persona_contarByCasado(void* pFirstPersona)
{
    int retorno = 0;
    Persona* pPersona;

    pPersona = (Persona*) pFirstPersona;

    if(strcmp(pPersona->estadoCivil,"Casado") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int persona_contarByDivorciado(void* pFirstPersona)
{
    int retorno = 0;
    Persona* pPersona;

    pPersona = (Persona*) pFirstPersona;

    if(strcmp(pPersona->estadoCivil,"Divorciado") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int persona_contarDniMayor(void* pFirstPersona)
{
    int retorno = 0;
    Persona* pPersona;
    pPersona = (Persona*) pFirstPersona;

    if(strcmp(pPersona->estadoCivil,"38998038") > 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int persona_contarEdadMayor15(void* pFirstPersona)
{
    int retorno = 0;
    Persona* pPersona;
    pPersona = (Persona*) pFirstPersona;

    if(pPersona != NULL && pPersona->edad > 15)
    {
        retorno = 1;
    }
    return retorno;
}

int persona_contarEdadMenor60(void* pFirstPersona)
{
    int retorno = 0;
    Persona* pPersona;
    pPersona = (Persona*) pFirstPersona;

    if(pPersona != NULL && pPersona->edad < 60)
    {
        retorno = 1;
    }
    return retorno;
}

/*int persona_sortByTipo(void* pFirstPersona,void* pSecondPersona)
{
    int retorno;
    Persona* pPersonaA;
    Persona* pPersonaB;

    pPersonaA = (Persona*) pFirstPersona;
    pPersonaB = (Persona*) pSecondPersona;

    if(strcmp(pPersonaA->tipo,pPersonaB->tipo) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pPersonaA->tipo,pPersonaB->tipo) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}

int persona_contarByTipoSTD(void* pFirstVenta)
{
    int retorno = 0;
    Persona* pPersona;

    pPersona = (Persona*) pFirstVenta;

    if(strcmp(pPersona->tipo,"STD") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int persona_contarByTipoEXP(void* pFirstVenta)
{
    int retorno = 0;
    Persona* pPersona;

    pPersona = (Persona*) pFirstVenta;

    if(strcmp(pPersona->tipo,"EXP") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int persona_contarByTipoECO(void* pFirstVenta)
{
    int retorno = 0;
    Persona* pPersona;

    pPersona = (Persona*) pFirstVenta;

    if(strcmp(pPersona->tipo,"ECO") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int persona_contarCantidad(void* pFirstVenta)
{
    int retorno = -1;
    Persona* pPersona;
    pPersona = (Persona*) pFirstVenta;

    if(pPersona != NULL && pPersona->cantidad > 0)
    {
        retorno = pPersona->cantidad;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int persona_contarMayor150(void* pFirstVenta)
{
    int retorno = 0;
    Persona* pPersona;
    int personaTotal;
    pPersona = (Persona*) pFirstVenta;

    if(pPersona != NULL && pPersona->cantidad > 0)
    {
        personaTotal = pPersona->cantidad * pPersona->precioUnitario;
    }
    if(personaTotal > 150)
    {
        retorno = 1;
    }
    return retorno;
}

int persona_contarMayor300(void* pFirstVenta)
{
    int retorno = 0;
    Persona* pPersona;
    int personaTotal;
    pPersona = (Persona*) pFirstVenta;

    if(pPersona != NULL && pPersona->cantidad > 0)
    {
        personaTotal = pPersona->cantidad * pPersona->precioUnitario;
    }
    if(personaTotal > 300)
    {
        retorno = 1;
    }
    return retorno;
}

int persona_contarPrecio(void* pFirstVenta)
{
    int retorno = -1;
    Persona* pPersona;
    pPersona = (Persona*) pFirstVenta;

    if(pPersona != NULL && pPersona->precioUnitario >= 0)
    {
        retorno = pPersona->precioUnitario;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int persona_contarPolaroid(void* pFirstVenta)
{
    int retorno = 0;
    Persona* pPersona;

    pPersona = (Persona*) pFirstVenta;

    if((strcmp(pPersona->tipo,"POLAROID_11x9") == 0) ||
            (strcmp(pPersona->tipo,"POLAROID_10x10") == 0))
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
