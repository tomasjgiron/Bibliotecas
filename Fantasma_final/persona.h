#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int id;
    char fechaNacimiento[50];
    char nombre[50];
    char apellido[50];
    char dni[50];
    char estadoCivil[50];
    char direccion[50];
    int edad;

} Persona;

Persona* persona_new();
Persona* persona_newParametros(char* idStr,char* fechaStr,char* nombreStr,
                                 char* apellidoStr,char* dniStr,
                                char* estadoCivilStr,char* direccionStr,
                                 char* edadStr);
int persona_delete(Persona* this);

int persona_setIdStr(Persona* this, char* value);
///int persona_setId(Persona* this,int value);
int persona_getId(Persona* this,int* value);

int persona_setFechaNacimiento(Persona* this, char* value);
int persona_getFechaNacimiento(Persona* this, char* value);

int persona_setNombre(Persona* this,char* value);
int persona_getNombre(Persona* this,char* value);

int persona_setApellido(Persona* this, char* value);
int persona_getApellido(Persona* this, char* value);

int persona_setDni(Persona* this, char* value);
int persona_getDni(Persona* this, char* value);

int persona_setEstadoCivil(Persona* this, char* value);
int persona_getEstadoCivil(Persona* this, char* value);

int persona_setDireccion(Persona* this, char* value);
int persona_getDireccion(Persona* this, char* value);

int persona_setEdad(Persona* this,char* value);
int persona_getEdad(Persona* this,int* value);

int persona_contarEdadMenor60(void* pFirstPersona);
int persona_contarEdadMayor15(void* pFirstPersona);
int persona_contarDniMayor(void* pFirstPersona);
int persona_contarByDivorciado(void* pFirstPersona);
int persona_contarByCasado(void* pFirstPersona);
int persona_contarBySoltero(void* pFirstPersona);


//int persona_sortByTipo(void* pFirstPersona,void* pSecondPersona);
//int persona_contarByTipoSTD(void* pPersona);
//int persona_contarByTipoEXP(void* pFirstPersona);
//int persona_contarByTipoECO(void* pFirstPersona);
//int persona_contarCantidad(void* pFirstPersona);
//int persona_contarPeso(void* pFirstPersona);
//int persona_contarMayor300(void* pFirstPersona);
//int persona_contarMayor150(void* pFirstPersona);
//int persona_contarPolaroid(void* pFirstPersona);

#endif // PERSONA_H_INCLUDED
