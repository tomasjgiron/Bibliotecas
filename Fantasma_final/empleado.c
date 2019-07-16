#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "empleado.h"

//static int generarId(void);

Empleado* empleado_new()
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* empleado_newParametros(char* idStr,char* fechaStr,char* nombreStr,
                                 char* apellidoStr,char* cuitStr,
                                char* lugarTrabajoStr, char* horasTrabajadasStr,
                                char* sueldoStr)
{
    Empleado* emp = empleado_new();
    if(emp != NULL)
    {
        empleado_setIdStr(emp,idStr);
        empleado_setFechaNacimiento(emp,fechaStr);
        empleado_setNombre(emp,nombreStr);
        empleado_setApellido(emp,apellidoStr);
        empleado_setCuit(emp,cuitStr);
        empleado_setLugarTrabajo(emp,lugarTrabajoStr);
        empleado_setHorasTrabajadas(emp,horasTrabajadasStr);
        empleado_setSueldo(emp,sueldoStr);
    }
    return emp;
}

int empleado_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int empleado_setIdStr(Empleado* this, char* value)
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

/*int empleado_setId(Empleado* this,int value)
{
    int retorno  =-1;
    if (this!=NULL && value > 0)
    {
        this->idEmpleado = value;
        retorno = 0;
    }
    return retorno;
}*/

int empleado_setFechaNacimiento(Empleado* this, char* value)
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

int empleado_setNombre(Empleado* this, char* value)
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


int empleado_setSueldo(Empleado* this,char* value)
{
    int retorno = -1;
    int auxSueldo;
    if(this != NULL && value != NULL && isNumberFloat(value))
    {
        auxSueldo = atof(value);
        if(auxSueldo > 0)
        {
            this->sueldo = auxSueldo;
            retorno = 0;
        }
    }
    return retorno;
}

int empleado_setApellido(Empleado* this, char* value)
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

int empleado_setCuit(Empleado* this, char* value)
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

int empleado_setLugarTrabajo(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isAlphanumeric(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->lugarTrabajo,value,sizeof(this->lugarTrabajo));
            retorno = 0;
        }
    }
    return retorno;
}

int empleado_setHorasTrabajadas(Empleado* this, char* value)
{
    int auxHoras;
    int retorno = -1;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxHoras = atoi(value);
        if(auxHoras > 0)
        {
            this->horasTrabajadas = auxHoras;
            retorno = 0;
        }
    }
    return retorno;
}

int empleado_getNombre(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int empleado_getSueldo(Empleado* this,float* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int empleado_getId(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}

int empleado_getFechaNacimiento(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->fechaNacimiento,sizeof(this->fechaNacimiento));
        retorno = 0;
    }
    return retorno;
}

int empleado_getApellido(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int empleado_getCuit(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int empleado_getLugarTrabajo(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->lugarTrabajo,sizeof(this->lugarTrabajo));
        retorno = 0;
    }
    return retorno;
}

int empleado_getHorasTrabajadas(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int empleado_initArray(Empleado* arrayEmpleado[],int lenEmpleado)
{
    int i;
    int retorno = -1;
    if(arrayEmpleado != NULL && lenEmpleado > 0)
    {
        for(i=0; i<lenEmpleado; i++)
        {
            arrayEmpleado[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int empleado_findFree(Empleado* arrayEmpleado[], int lenEmpleado)
{
    int i;
    int ret = -1;
    if(arrayEmpleado != NULL && lenEmpleado > 0)
    {
        for(i=0; i<lenEmpleado; i++)
        {
            if(arrayEmpleado[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}

int empleado_contarMayor45(void* pFirstEmpleado)
{
    int retorno = 0;
    Empleado* pEmpleado;
    pEmpleado = (Empleado*) pFirstEmpleado;

    if(pEmpleado != NULL && pEmpleado->horasTrabajadas > 45)
    {
        retorno = 1;
    }
    return retorno;
}

int empleado_contarMenor30(void* pFirstEmpleado)
{
    int retorno = 0;
    Empleado* pEmpleado;
    pEmpleado = (Empleado*) pFirstEmpleado;

    if(pEmpleado != NULL && pEmpleado->horasTrabajadas < 30)
    {
        retorno = 1;
    }
    return retorno;
}

int empleado_contarSueldo(void* pFirstEmpleado)
{
    int retorno = -1;
    Empleado* pEmpleado;
    pEmpleado = (Empleado*) pFirstEmpleado;

    if(pEmpleado != NULL && pEmpleado->sueldo >= 0)
    {
        retorno = pEmpleado->sueldo;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int empleado_contarEstrada(void* pFirstEmpleado)
{
    int retorno = 0;
    Empleado* pEmpleado;

    pEmpleado = (Empleado*) pFirstEmpleado;

    if(strcmp(pEmpleado->lugarTrabajo,"Estrada 765") == 0)
    {
        retorno = 1;
    }
    return retorno;
}

/*int empleado_sortByTipo(void* pFirstEmpleado,void* pSecondEmpleado)
{
    int retorno;
    Empleado* pEmpleadoA;
    Empleado* pEmpleadoB;

    pEmpleadoA = (Empleado*) pFirstEmpleado;
    pEmpleadoB = (Empleado*) pSecondEmpleado;

    if(strcmp(pEmpleadoA->tipo,pEmpleadoB->tipo) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pEmpleadoA->tipo,pEmpleadoB->tipo) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}

int empleado_contarByTipoSTD(void* pFirstVenta)
{
    int retorno = 0;
    Empleado* pEmpleado;

    pEmpleado = (Empleado*) pFirstVenta;

    if(strcmp(pEmpleado->tipo,"STD") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int empleado_contarByTipoEXP(void* pFirstVenta)
{
    int retorno = 0;
    Empleado* pEmpleado;

    pEmpleado = (Empleado*) pFirstVenta;

    if(strcmp(pEmpleado->tipo,"EXP") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int empleado_contarByTipoECO(void* pFirstVenta)
{
    int retorno = 0;
    Empleado* pEmpleado;

    pEmpleado = (Empleado*) pFirstVenta;

    if(strcmp(pEmpleado->tipo,"ECO") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int empleado_contarCantidad(void* pFirstVenta)
{
    int retorno = -1;
    Empleado* pEmpleado;
    pEmpleado = (Empleado*) pFirstVenta;

    if(pEmpleado != NULL && pEmpleado->cantidad > 0)
    {
        retorno = pEmpleado->cantidad;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int empleado_contarMayor150(void* pFirstVenta)
{
    int retorno = 0;
    Empleado* pEmpleado;
    int empleadoTotal;
    pEmpleado = (Empleado*) pFirstVenta;

    if(pEmpleado != NULL && pEmpleado->cantidad > 0)
    {
        empleadoTotal = pEmpleado->cantidad * pEmpleado->precioUnitario;
    }
    if(empleadoTotal > 150)
    {
        retorno = 1;
    }
    return retorno;
}

int empleado_contarMayor300(void* pFirstVenta)
{
    int retorno = 0;
    Empleado* pEmpleado;
    int empleadoTotal;
    pEmpleado = (Empleado*) pFirstVenta;

    if(pEmpleado != NULL && pEmpleado->cantidad > 0)
    {
        empleadoTotal = pEmpleado->cantidad * pEmpleado->precioUnitario;
    }
    if(empleadoTotal > 300)
    {
        retorno = 1;
    }
    return retorno;
}

int empleado_contarPrecio(void* pFirstVenta)
{
    int retorno = -1;
    Empleado* pEmpleado;
    pEmpleado = (Empleado*) pFirstVenta;

    if(pEmpleado != NULL && pEmpleado->precioUnitario >= 0)
    {
        retorno = pEmpleado->precioUnitario;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int empleado_contarPolaroid(void* pFirstVenta)
{
    int retorno = 0;
    Empleado* pEmpleado;

    pEmpleado = (Empleado*) pFirstVenta;

    if((strcmp(pEmpleado->tipo,"POLAROID_11x9") == 0) ||
            (strcmp(pEmpleado->tipo,"POLAROID_10x10") == 0))
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
