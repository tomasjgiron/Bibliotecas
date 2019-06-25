#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arraynuevo.h"
#include "Empleado.h"

int em_calcularSueldo(void* pEmpleado)
{
    /*Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350*/

    Empleado* auxEmpleado = pEmpleado;
    int returnAux = -1;
    int sueldo;
    int horasTrabajadas;
    int horasAcumuladas;

    employee_getHorasTrabajadas(auxEmpleado,&horasTrabajadas);

    if(horasTrabajadas <= 120)
    {
        sueldo = horasTrabajadas * 180;
        employee_setSueldoInt(auxEmpleado,sueldo);
        returnAux = 1;
    }
    else if(horasTrabajadas <= 160)
    {
        horasAcumuladas = 120 * 180;
        horasTrabajadas -= 120;
        sueldo = horasAcumuladas + horasTrabajadas * 240;
        employee_setSueldoInt(auxEmpleado,sueldo);
        returnAux = 1;
    }
    else if(horasTrabajadas <= 240)
    {
        horasAcumuladas = 120 * 180 + 40 * 240;
        horasTrabajadas -= 160;
        sueldo = horasAcumuladas + horasTrabajadas * 350;
        employee_setSueldoInt(auxEmpleado,sueldo);
        returnAux = 1;
    }

    return returnAux;
}

Empleado* employee_new()
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{

    Empleado* emp = employee_new();
    if(emp != NULL)
    {
        employee_setId(emp,idStr);
        employee_setNombre(emp,nombreStr);
        employee_setHorasTrabajadas(emp,horasTrabajadasStr);
    }
    return emp;
}

int employee_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Empleado* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxID = atoi(value);
        if(auxID >= 0)
        {
            this->id = auxID;
            retorno = 0;
        }
    }
    return retorno;
}


int employee_setSueldoStr(Empleado* this,char* value)
{
    int auxSueldo;
    int retorno = -1;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxSueldo = atoi(value);
        if(auxSueldo >= 0)
        {
            this->sueldo = auxSueldo;
            retorno = 0;
        }
    }
    return retorno;
}

int employee_setSueldoInt(Empleado* this,int sueldo)
{
    int retorno=-1;
    if (this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Empleado* this, char* value)
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


int employee_setHorasTrabajadas(Empleado* this,char* value)
{
    int auxHoras;
    int retorno = -1;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxHoras = atoi(value);
        if(auxHoras >= 0)
        {
            this->horasTrabajadas = auxHoras;
            retorno = 0;
        }
    }
    return retorno;
}


int employee_getNombre(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}


int employee_initArray(Empleado* arrayEmpleado[],int lenEmpleado)
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

int employee_findFree(Empleado* arrayEmpleado[], int lenEmpleado)
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

int employee_sortByName(void* pFirstEmpleado,void* pSecondEmpleado)
{
    int retorno;
    Empleado* pEmpleadoA;
    Empleado* pEmpleadoB;

    pEmpleadoA = (Empleado*) pFirstEmpleado;
    pEmpleadoB = (Empleado*) pSecondEmpleado;

    if(strcmp(pEmpleadoA->nombre,pEmpleadoB->nombre) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pEmpleadoA->nombre,pEmpleadoB->nombre) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}
