#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int id;
    char fechaNacimiento[50];
    char nombre[50];
    char apellido[50];
    char cuit[50];
    char lugarTrabajo[50];
    int horasTrabajadas;
    float sueldo;

} Empleado;

Empleado* empleado_new();
Empleado* empleado_newParametros(char* idStr,char* fechaStr,char* nombreStr,
                                 char* apellidoStr,char* cuitStr,
                                char* lugarTrabajoStr, char* horasTrabajadasStr,
                                char* sueldoStr);
int empleado_delete(Empleado* this);

int empleado_setIdStr(Empleado* this, char* value);
///int empleado_setId(Empleado* this,int value);
int empleado_getId(Empleado* this,int* value);

int empleado_setFechaNacimiento(Empleado* this, char* value);
int empleado_getFechaNacimiento(Empleado* this, char* value);

int empleado_setNombre(Empleado* this,char* value);
int empleado_getNombre(Empleado* this,char* value);

int empleado_setApellido(Empleado* this, char* value);
int empleado_getApellido(Empleado* this, char* value);

int empleado_setCuit(Empleado* this, char* value);
int empleado_getCuit(Empleado* this, char* value);

int empleado_setLugarTrabajo(Empleado* this, char* value);
int empleado_getLugarTrabajo(Empleado* this, char* value);

int empleado_setHorasTrabajadas(Empleado* this,char* value);
int empleado_getHorasTrabajadas(Empleado* this,int* value);

int empleado_setSueldo(Empleado* this,char* value);
int empleado_getSueldo(Empleado* this,float* value);

int empleado_contarMayor45(void* pFirstEmpleado);
int empleado_contarMenor30(void* pFirstEmpleado);
int empleado_contarSueldo(void* pFirstEmpleado);
int empleado_contarEstrada(void* pFirstEmpleado);

//int empleado_sortByTipo(void* pFirstEmpleado,void* pSecondEmpleado);
//int empleado_contarByTipoSTD(void* pEmpleado);
//int empleado_contarByTipoEXP(void* pFirstEmpleado);
//int empleado_contarByTipoECO(void* pFirstEmpleado);
//int empleado_contarCantidad(void* pFirstEmpleado);
//int empleado_contarPeso(void* pFirstEmpleado);
//int empleado_contarMayor300(void* pFirstEmpleado);
//int empleado_contarMayor150(void* pFirstEmpleado);
//int empleado_contarPolaroid(void* pFirstEmpleado);

#endif // EMPLEADO_H_INCLUDED
