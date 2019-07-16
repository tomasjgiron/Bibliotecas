#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

typedef struct
{
    int id;
    char fechaNacimiento[50];
    char nombre[50];
    char apellido[50];
    char obraSocial[50];
    float altura;
    float peso;
    int edad;

} Paciente;

Paciente* paciente_new();
Paciente* paciente_newParametros(char* idStr,char* fechaStr,char* nombreStr,
                                 char* apellidoStr,char* obraSocialStr,
                                char* alturaStr, char* pesoStr,char* edadStr);
int paciente_delete(Paciente* this);

int paciente_setIdStr(Paciente* this, char* value);
///int paciente_setId(Paciente* this,int value);
int paciente_getId(Paciente* this,int* value);

int paciente_setFechaNacimiento(Paciente* this, char* value);
int paciente_getFechaNacimiento(Paciente* this, char* value);

int paciente_setNombre(Paciente* this,char* value);
int paciente_getNombre(Paciente* this,char* value);

int paciente_setApellido(Paciente* this, char* value);
int paciente_getApellido(Paciente* this, char* value);

int paciente_setObraSocial(Paciente* this, char* value);
int paciente_getObraSocial(Paciente* this, char* value);

int paciente_setAltura(Paciente* this, char* value);
int paciente_getAltura(Paciente* this, float* value);

int paciente_setPeso(Paciente* this, char* value);
int paciente_getPeso(Paciente* this, float* value);

int paciente_setEdad(Paciente* this,char* value);
int paciente_getEdad(Paciente* this,int* value);

int paciente_contarObsba(void* pFirstPaciente);
int paciente_contarPeso(void* pFirstPaciente);
int paciente_contarAltura(void* pFirstPaciente);


//int paciente_sortByTipo(void* pFirstPaciente,void* pSecondPaciente);
//int paciente_contarByTipoSTD(void* pPaciente);
//int paciente_contarByTipoEXP(void* pFirstPaciente);
//int paciente_contarByTipoECO(void* pFirstPaciente);
//int paciente_contarCantidad(void* pFirstPaciente);
//int paciente_contarPeso(void* pFirstPaciente);
//int paciente_contarMayor300(void* pFirstPaciente);
//int paciente_contarMayor150(void* pFirstPaciente);
//int paciente_contarPolaroid(void* pFirstPaciente);

#endif // PACIENTE_H_INCLUDED
