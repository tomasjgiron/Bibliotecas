#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED
#include "LinkedList.h"

//int controller_loadClientFromText(char* path,LinkedList* pArrayListClient);
//int controller_addVenta(LinkedList* pArrayListVenta);
//int controller_modifyVenta(LinkedList* pArrayListVenta);
//int controller_removeVenta(LinkedList* pArrayListVenta);
//int controller_listVenta(LinkedList* pArrayListVenta);
//int controller_sortVenta(LinkedList* pArrayListVenta);

int controller_ventaSaveAsText(char* path, LinkedList* pArrayListVenta);
///int controller_empleadoSaveAsText(char* path, LinkedList* pArrayListEmpleado);
///int controller_personaSaveAsText(char* path, LinkedList* pArrayListPersona);
///int controller_orquestaSaveAsText(char* path, LinkedList* pArrayListOrquesta);
///int controller_pacienteSaveAsText(char* path, LinkedList* pArrayListPaciente);

#endif
