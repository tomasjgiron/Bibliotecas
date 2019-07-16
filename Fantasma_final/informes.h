#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "LinkedList.h"

int generarArchivoInformes(char* fileName,LinkedList* listaVentas);
///int generarArchivoInformes(char* fileName,LinkedList* listaEmpleado);
///int generarArchivoInformes(char* fileName,LinkedList* listaPersona);
///int generarArchivoInformes(char* fileName,LinkedList* listaOrquesta);
///int generarArchivoInformes(char* fileName,LinkedList* listaPaciente);


///--VENTAS--

int informe_cantidadTotalFotos(LinkedList* pArrayListVentas);///cantidad de fotos reveladas totales
int informe_cantidadVentasMayor150(LinkedList* pArrayListVentas);///cantidad de ventas por un monto mayor a 150
int informe_cantidadVentasMayor300(LinkedList* pArrayListVentas);///cantidad de ventas por un monto mayor a 300
int informe_cantidadPolaroids(LinkedList* pArrayListVentas);///cantidad de fotos polaroids reveladas

///--EMPLEADO--

int informe_promedioSueldos(LinkedList* pArrayListEmpleado);
int informe_cantidadEmpleadoHorasMayor45(LinkedList* pArrayListEmpleado);
int informe_cantidadEmpleadoHorasMenor30(LinkedList* pArrayListEmpleado);
int informe_cantidadEmpleadosPorLugar(LinkedList* pArrayListEmpleado);
int informe_EmpleadoSueldoMaximo(LinkedList* pArrayListEmpleado);

///--PERSONA--

int informe_cantidadTotalPersonas(LinkedList* pArrayListPersona);
int informe_cantidadPersonasPorEstadoCivil(LinkedList* pArrayListPersona,int estadoCivil);
int informe_cantidadPersonasDniMayor(LinkedList* pArrayListPersona);
int informe_cantidadPersonasEdadMayor15(LinkedList* pArrayListPersona);
int informe_cantidadPersonasEdadMenor60(LinkedList* pArrayListPersona);

///--ORQUESTA--

int informe_cantidadMusicosPorOrquesta(LinkedList* pArrayListOrquesta);
int informe_cantidadOrquestaPorNacionalidad(LinkedList* pArrayListOrquesta,int nacionalidad);
int informe_cantidadTotalOrquestas(LinkedList* pArrayListOrquesta);
int informe_orquestaConMenosMusicos(LinkedList* pArrayListOrquesta);

///--PACIENTE--

int informe_promedioAltura(LinkedList* pArrayListPaciente);
int informe_promedioPeso(LinkedList* pArrayListPaciente);
int informe_pacienteMenorEdad(LinkedList* pArrayListPaciente);
int informe_pacienteMayorEdad(LinkedList* pArrayListPaciente);
int informe_cantidadPacientesPorObraSocial(LinkedList* pArrayListPaciente);

#endif // INFORMES_H_INCLUDED
