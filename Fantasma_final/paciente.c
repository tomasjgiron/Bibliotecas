#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "paciente.h"

//static int generarId(void);

Paciente* paciente_new()
{
    return (Paciente*) malloc(sizeof(Paciente));
}

Paciente* paciente_newParametros(char* idStr,char* fechaStr,char* nombreStr,
                                 char* apellidoStr,char* obraSocialStr,
                                char* alturaStr, char* pesoStr,char* edadStr)
{
    Paciente* pac = paciente_new();
    if(pac != NULL)
    {
        paciente_setIdStr(pac,idStr);
        paciente_setFechaNacimiento(pac,fechaStr);
        paciente_setNombre(pac,nombreStr);
        paciente_setApellido(pac,apellidoStr);
        paciente_setObraSocial(pac,obraSocialStr);
        paciente_setAltura(pac,alturaStr);
        paciente_setPeso(pac,pesoStr);
        paciente_setEdad(pac,edadStr);
    }
    return pac;
}

int paciente_delete(Paciente* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int paciente_setIdStr(Paciente* this, char* value)
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

/*int paciente_setId(Paciente* this,int value)
{
    int retorno  =-1;
    if (this!=NULL && value > 0)
    {
        this->idPaciente = value;
        retorno = 0;
    }
    return retorno;
}*/

int paciente_setFechaNacimiento(Paciente* this, char* value)
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

int paciente_setNombre(Paciente* this, char* value)
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


int paciente_setEdad(Paciente* this,char* value)
{
    int retorno = -1;
    int auxEdad;
    if(this != NULL && value != NULL && isNumberFloat(value))
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

int paciente_setApellido(Paciente* this, char* value)
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

int paciente_setObraSocial(Paciente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->obraSocial,value,sizeof(this->obraSocial));
            retorno = 0;
        }
    }
    return retorno;
}

int paciente_setAltura(Paciente* this,char* value)
{
    int retorno = -1;
    int auxAltura;
    if(this != NULL && value != NULL && isNumberFloat(value))
    {
        auxAltura = atof(value);
        if(auxAltura > 0)
        {
            this->altura = auxAltura;
            retorno = 0;
        }
    }
    return retorno;
}

int paciente_setPeso(Paciente* this,char* value)
{
    int retorno = -1;
    int auxPeso;
    if(this != NULL && value != NULL && isNumberFloat(value))
    {
        auxPeso = atof(value);
        if(auxPeso > 0)
        {
            this->peso = auxPeso;
            retorno = 0;
        }
    }
    return retorno;
}

int paciente_getNombre(Paciente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int paciente_getEdad(Paciente* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->edad;
        retorno = 0;
    }
    return retorno;
}

int paciente_getId(Paciente* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}

int paciente_getFechaNacimiento(Paciente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->fechaNacimiento,sizeof(this->fechaNacimiento));
        retorno = 0;
    }
    return retorno;
}

int paciente_getApellido(Paciente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int paciente_getObraSocial(Paciente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->obraSocial,sizeof(this->obraSocial));
        retorno = 0;
    }
    return retorno;
}

int paciente_getAltura(Paciente* this, float* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->altura;
        retorno = 0;
    }
    return retorno;
}

int paciente_getPeso(Paciente* this, float* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->peso;
        retorno = 0;
    }
    return retorno;
}

int paciente_initArray(Paciente* arrayPaciente[],int lenPaciente)
{
    int i;
    int retorno = -1;
    if(arrayPaciente != NULL && lenPaciente > 0)
    {
        for(i=0; i<lenPaciente; i++)
        {
            arrayPaciente[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int paciente_findFree(Paciente* arrayPaciente[], int lenPaciente)
{
    int i;
    int ret = -1;
    if(arrayPaciente != NULL && lenPaciente > 0)
    {
        for(i=0; i<lenPaciente; i++)
        {
            if(arrayPaciente[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}

int paciente_contarAltura(void* pFirstPaciente)
{
    int retorno = -1;
    Paciente* pPaciente;
    pPaciente = (Paciente*) pFirstPaciente;

    if(pPaciente != NULL && pPaciente->altura >= 0)
    {
        retorno = pPaciente->altura;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int paciente_contarPeso(void* pFirstPaciente)
{
    int retorno = -1;
    Paciente* pPaciente;
    pPaciente = (Paciente*) pFirstPaciente;

    if(pPaciente != NULL && pPaciente->peso >= 0)
    {
        retorno = pPaciente->peso;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int paciente_contarObsba(void* pFirstPaciente)
{
    int retorno = 0;
    Paciente* pPaciente;

    pPaciente = (Paciente*) pFirstPaciente;

    if(strcmp(pPaciente->obraSocial,"OBSBA") == 0)
    {
        retorno = 1;
    }
    return retorno;
}

/*int paciente_sortByTipo(void* pFirstPaciente,void* pSecondPaciente)
{
    int retorno;
    Paciente* pPacienteA;
    Paciente* pPacienteB;

    pPacienteA = (Paciente*) pFirstPaciente;
    pPacienteB = (Paciente*) pSecondPaciente;

    if(strcmp(pPacienteA->tipo,pPacienteB->tipo) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pPacienteA->tipo,pPacienteB->tipo) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}

int paciente_contarByTipoSTD(void* pFirstVenta)
{
    int retorno = 0;
    Paciente* pPaciente;

    pPaciente = (Paciente*) pFirstVenta;

    if(strcmp(pPaciente->tipo,"STD") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int paciente_contarByTipoEXP(void* pFirstVenta)
{
    int retorno = 0;
    Paciente* pPaciente;

    pPaciente = (Paciente*) pFirstVenta;

    if(strcmp(pPaciente->tipo,"EXP") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int paciente_contarByTipoECO(void* pFirstVenta)
{
    int retorno = 0;
    Paciente* pPaciente;

    pPaciente = (Paciente*) pFirstVenta;

    if(strcmp(pPaciente->tipo,"ECO") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int paciente_contarCantidad(void* pFirstVenta)
{
    int retorno = -1;
    Paciente* pPaciente;
    pPaciente = (Paciente*) pFirstVenta;

    if(pPaciente != NULL && pPaciente->cantidad > 0)
    {
        retorno = pPaciente->cantidad;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int paciente_contarMayor150(void* pFirstVenta)
{
    int retorno = 0;
    Paciente* pPaciente;
    int pacienteTotal;
    pPaciente = (Paciente*) pFirstVenta;

    if(pPaciente != NULL && pPaciente->cantidad > 0)
    {
        pacienteTotal = pPaciente->cantidad * pPaciente->precioUnitario;
    }
    if(pacienteTotal > 150)
    {
        retorno = 1;
    }
    return retorno;
}

int paciente_contarMayor300(void* pFirstVenta)
{
    int retorno = 0;
    Paciente* pPaciente;
    int pacienteTotal;
    pPaciente = (Paciente*) pFirstVenta;

    if(pPaciente != NULL && pPaciente->cantidad > 0)
    {
        pacienteTotal = pPaciente->cantidad * pPaciente->precioUnitario;
    }
    if(pacienteTotal > 300)
    {
        retorno = 1;
    }
    return retorno;
}

int paciente_contarPrecio(void* pFirstVenta)
{
    int retorno = -1;
    Paciente* pPaciente;
    pPaciente = (Paciente*) pFirstVenta;

    if(pPaciente != NULL && pPaciente->precioUnitario >= 0)
    {
        retorno = pPaciente->precioUnitario;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int paciente_contarPolaroid(void* pFirstVenta)
{
    int retorno = 0;
    Paciente* pPaciente;

    pPaciente = (Paciente*) pFirstVenta;

    if((strcmp(pPaciente->tipo,"POLAROID_11x9") == 0) ||
            (strcmp(pPaciente->tipo,"POLAROID_10x10") == 0))
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
