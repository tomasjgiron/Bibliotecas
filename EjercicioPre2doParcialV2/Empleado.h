#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

int em_calcularSueldo(void* pEmpleado);

Empleado* employee_new();
Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
int employee_delete();

int employee_setId(Empleado* this, char* value);
int employee_getId(Empleado* this,int* value);

int employee_setNombre(Empleado* this,char* value);
int employee_getNombre(Empleado* this,char* value);

int employee_setHorasTrabajadas(Empleado* this,char* value);
int employee_getHorasTrabajadas(Empleado* this,int* value);

int employee_setSueldoStr(Empleado* this,char* value);
int employee_setSueldoInt(Empleado* this,int sueldo);
int employee_getSueldo(Empleado* this,int* value);

int employee_sortByName(void* pFirstEmployee,void* pSecondEmployee);

int employee_reduceBySueldo(void* pEmpleado);
int employee_filterBySueldo(void* pEmpleado);

#endif // EMPLEADO_H_INCLUDED
