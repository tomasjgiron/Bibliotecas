#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "informes.h"
#include "controller.h"
#include "ventas.h"
#include "persona.h"
#include "empleado.h"
#include "orquesta.h"
#include "paciente.h"
#include "parser.h"

int generarArchivoInformes(char* fileName,LinkedList* listaVentas)
{
    int retorno = -1;
    int cantidadFotos;
    int ventasPolaroid;
    int ventaMayor150;
    int ventaMayor300;

    FILE* fp = fopen(fileName,"w+");
    if(fp != NULL && listaVentas!= NULL)
    {
        cantidadFotos = informe_cantidadTotalFotos(listaVentas);
        ventaMayor150 = informe_cantidadVentasMayor150(listaVentas);
        ventaMayor300 = informe_cantidadVentasMayor300(listaVentas);
        ventasPolaroid = informe_cantidadPolaroids(listaVentas);


        fprintf(fp,"*******************\n");
        fprintf(fp,"Informe de ventas\n");
        fprintf(fp,"*******************\n");
        fprintf(fp,"- Cantidad de fotos reveladas: %d\n",cantidadFotos);
        fprintf(fp,"- Cantidad de ventas por un monto mayor a $150: %d\n",ventaMayor150);
        fprintf(fp,"- Cantidad de ventas por un monto mayor a $180: %d\n",ventaMayor300);
        fprintf(fp,"- Cantidad de fotos polaroid reveladas: %d\n",ventasPolaroid);
        fprintf(fp,"*******************");


        fclose(fp);
        retorno = 1;
    }
    return retorno;
}

int informe_cantidadTotalFotos(LinkedList* pArrayListVentas)///cantidad de fotos reveladas totales
{
    int auxReturn = -1;

    if(pArrayListVentas != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListVentas,venta_contarCantidad);
    }
    return auxReturn;
}

int informe_cantidadVentasMayor150(LinkedList* pArrayListVentas)///cantidad de ventas por un monto mayor a 150
{
    int auxReturn = -1;

    if(pArrayListVentas != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListVentas,venta_contarMayor150);
    }
    return auxReturn;
}

int informe_cantidadVentasMayor300(LinkedList* pArrayListVentas)///cantidad de ventas por un monto mayor a 300
{
    int auxReturn = -1;

    if(pArrayListVentas != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListVentas,venta_contarMayor300);
    }
    return auxReturn;
}

int informe_cantidadPolaroids(LinkedList* pArrayListVentas)///cantidad de fotos polaroids reveladas
{
    int auxReturn = -1;

    if(pArrayListVentas != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListVentas,venta_contarPolaroid);
    }
    return auxReturn;
}

int informe_promedioSueldos(LinkedList* pArrayListEmpleado)
{
    int auxReturn = -1;
    int size;
    float cantidadTotal;
    float promedio;

    if(pArrayListEmpleado != NULL)
    {
        size = ll_len(pArrayListEmpleado);
        if(size > 0)
        {
            cantidadTotal = ll_contarFloat(pArrayListEmpleado,empleado_contarSueldo);
            promedio = cantidadTotal/size;
            auxReturn = promedio;
        }
    }
    return auxReturn;
}
int informe_cantidadEmpleadoHorasMayor45(LinkedList* pArrayListEmpleado)
{
    int auxReturn = -1;
    if(pArrayListEmpleado != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListEmpleado,empleado_contarMayor45);
    }
    return auxReturn;
}
int informe_cantidadEmpleadoHorasMenor30(LinkedList* pArrayListEmpleado)
{
    int auxReturn = -1;
    if(pArrayListEmpleado != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListEmpleado,empleado_contarMenor30);
    }
    return auxReturn;
}
int informe_cantidadEmpleadosPorLugar(LinkedList* pArrayListEmpleado)///SENILLOSA 431 = 1 - CABRERA 5354 = 2 - ESTRADA 765 = 3
{
    int auxReturn = -1;
    if(pArrayListEmpleado != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListEmpleado,empleado_contarEstrada);
    }
    return auxReturn;
}
int informe_EmpleadoSueldoMaximo(LinkedList* pArrayListEmpleado)
{
    int auxReturn = -1;
    int i;
    int size;
    Empleado* pEmpleado;
    int maximo = 0;

    if(pArrayListEmpleado != NULL)
    {
        size = ll_len(pArrayListEmpleado);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pEmpleado = ll_get(pArrayListEmpleado,i);
            if(pEmpleado != NULL && pEmpleado->sueldo > maximo)
            {
                maximo = pEmpleado->sueldo;
            }
        }
        auxReturn = maximo;
    }
    return auxReturn;
}

int informe_cantidadTotalPersonas(LinkedList* pArrayListPersona)
{
    int auxReturn = -1;
    int size;

    if(pArrayListPersona != NULL)
    {
        size = ll_len(pArrayListPersona);
        auxReturn = size;
    }
    return auxReturn;
}
int informe_cantidadPersonasPorEstadoCivil(LinkedList* pArrayListPersona,int estadoCivil)///SOLTERO = 1 - CASADO = 2 - DIVORCIADO = 3
{
    int auxReturn = -1;
    int i;
    int size;

    if(pArrayListPersona != NULL && (estadoCivil >= 1 || estadoCivil <= 3))
    {
        size = ll_len(pArrayListPersona);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            if(estadoCivil == 1)
            {
                auxReturn = ll_contar(pArrayListPersona,persona_contarBySoltero);
            }
            else if(estadoCivil == 2)
            {
                auxReturn = ll_contar(pArrayListPersona,persona_contarByCasado);
            }
            else
            {
                auxReturn = ll_contar(pArrayListPersona,persona_contarByDivorciado);
            }
        }
    }
    return auxReturn;
}
int informe_cantidadPersonasDniMayor(LinkedList* pArrayListPersona)
{
    int auxReturn = -1;
    if(pArrayListPersona != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListPersona,persona_contarDniMayor);
    }
    return auxReturn;
}
int informe_cantidadPersonasEdadMayor15(LinkedList* pArrayListPersona)
{
    int auxReturn = -1;
    if(pArrayListPersona != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListPersona,persona_contarEdadMayor15);
    }
    return auxReturn;
}
int informe_cantidadPersonasEdadMenor60(LinkedList* pArrayListPersona)
{
    int auxReturn = -1;
    if(pArrayListPersona != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListPersona,persona_contarEdadMenor60);
    }
    return auxReturn;
}

int informe_cantidadMusicosPorOrquesta(LinkedList* pArrayListOrquesta)
{
    int auxReturn = -1;
    if(pArrayListOrquesta != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListOrquesta,orquesta_contarCantidadMusicos);
    }
    return auxReturn;
}
int informe_cantidadOrquestaPorNacionalidad(LinkedList* pArrayListOrquesta,int nacionalidad)///JAPONESA = 1 - ARGENTINA = 2 - HOLANDESA = 3
{
    int auxReturn = -1;
    int i;
    int size;

    if(pArrayListOrquesta != NULL && (nacionalidad >= 1 || nacionalidad <= 3))
    {
        size = ll_len(pArrayListOrquesta);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            if(nacionalidad == 1)
            {
                auxReturn = ll_contar(pArrayListOrquesta,orquesta_contarByJaponesa);
            }
            else if(nacionalidad == 2)
            {
                auxReturn = ll_contar(pArrayListOrquesta,orquesta_contarByArgentina);
            }
            else
            {
                auxReturn = ll_contar(pArrayListOrquesta,orquesta_contarByHolandesa);
            }
        }
    }
    return auxReturn;
}
int informe_cantidadTotalOrquestas(LinkedList* pArrayListOrquesta)
{
    int auxReturn = -1;
    int size;

    if(pArrayListOrquesta != NULL)
    {
        size = ll_len(pArrayListOrquesta);
        auxReturn = size;
    }
    return auxReturn;
}
int informe_orquestaConMenosMusicos(LinkedList* pArrayListOrquesta)
{
    int auxReturn = -1;
    int i;
    int size;
    Orquesta* pOrquesta;
    int minimo = 1000000;

    if(pArrayListOrquesta != NULL)
    {
        size = ll_len(pArrayListOrquesta);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pOrquesta = ll_get(pArrayListOrquesta,i);
            if(pOrquesta != NULL && pOrquesta->cantidadMusicos < minimo)
            {
                minimo = pOrquesta->cantidadMusicos;
            }
        }
        auxReturn = minimo;
    }
    return auxReturn;
}

int informe_promedioAltura(LinkedList* pArrayListPaciente)
{
    int auxReturn = -1;
    int size;
    float cantidadTotal;
    float promedio;

    if(pArrayListPaciente != NULL)
    {
        size = ll_len(pArrayListPaciente);
        if(size > 0)
        {
            cantidadTotal = ll_contarFloat(pArrayListPaciente,paciente_contarAltura);
            promedio = cantidadTotal/size;
            auxReturn = promedio;
        }
    }
    return auxReturn;
}
int informe_promedioPeso(LinkedList* pArrayListPaciente)
{
    int auxReturn = -1;
    int size;
    float cantidadTotal;
    float promedio;

    if(pArrayListPaciente != NULL)
    {
        size = ll_len(pArrayListPaciente);
        if(size > 0)
        {
            cantidadTotal = ll_contarFloat(pArrayListPaciente,paciente_contarPeso);
            promedio = cantidadTotal/size;
            auxReturn = promedio;
        }
    }
    return auxReturn;
}
int informe_pacienteMenorEdad(LinkedList* pArrayListPaciente)
{
    int auxReturn = -1;
    int i;
    int size;
    Paciente* pPaciente;
    int minimo = 1000000;

    if(pArrayListPaciente != NULL)
    {
        size = ll_len(pArrayListPaciente);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pPaciente = ll_get(pArrayListPaciente,i);
            if(pPaciente != NULL && pPaciente->edad < minimo)
            {
                minimo = pPaciente->edad;
            }
        }
        auxReturn = minimo;
    }
    return auxReturn;
}
int informe_pacienteMayorEdad(LinkedList* pArrayListPaciente)
{
    int auxReturn = -1;
    int i;
    int size;
    Paciente* pPaciente;
    int maximo = 0;

    if(pArrayListPaciente != NULL)
    {
        size = ll_len(pArrayListPaciente);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pPaciente = ll_get(pArrayListPaciente,i);
            if(pPaciente != NULL && pPaciente->edad > maximo)
            {
                maximo = pPaciente->edad;
            }
        }
        auxReturn = maximo;
    }
    return auxReturn;
}
int informe_cantidadPacientesPorObraSocial(LinkedList* pArrayListPaciente)///OSDE = 1 - OBSBA = 2 - GALENO = 3
{
    int auxReturn = -1;
    if(pArrayListPaciente != NULL)
    {
        auxReturn = 0;
        auxReturn += ll_contar(pArrayListPaciente,paciente_contarObsba);
    }
    return auxReturn;
}
