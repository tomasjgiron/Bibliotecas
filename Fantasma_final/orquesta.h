#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char tipo[50];
    char lugar[50];
    char nacionalidad[50];
    int cantidadMusicos;

} Orquesta;

Orquesta* orquesta_new();
Orquesta* orquesta_newParametros(char* idStr,char* nombreStr,char* tipoStr,
                                 char* lugarStr,char* nacionalidadStr,
                                char* cantidadMusicosStr);
int orquesta_delete(Orquesta* this);

int orquesta_setIdStr(Orquesta* this, char* value);
///int orquesta_setId(Orquesta* this,int value);
int orquesta_getId(Orquesta* this,int* value);

int orquesta_setNombre(Orquesta* this,char* value);
int orquesta_getNombre(Orquesta* this,char* value);

int orquesta_setTipo(Orquesta* this, char* value);
int orquesta_getTipo(Orquesta* this, char* value);

int orquesta_setLugar(Orquesta* this, char* value);
int orquesta_getLugar(Orquesta* this, char* value);

int orquesta_setNacionalidad(Orquesta* this, char* value);
int orquesta_getNacionalidad(Orquesta* this, char* value);

int orquesta_setCantidadMusicos(Orquesta* this,char* value);
int orquesta_getCantidadMusicos(Orquesta* this,int* value);


int orquesta_contarCantidadMusicos(void* pFirstOrquesta);
int orquesta_contarByHolandesa(void* pFirstOrquesta);
int orquesta_contarByArgentina(void* pFirstOrquesta);
int orquesta_contarByJaponesa(void* pFirstOrquesta);

//int orquesta_sortByTipo(void* pFirstOrquesta,void* pSecondOrquesta);
//int orquesta_contarByTipoSTD(void* pOrquesta);
//int orquesta_contarByTipoEXP(void* pFirstOrquesta);
//int orquesta_contarByTipoECO(void* pFirstOrquesta);
//int orquesta_contarCantidad(void* pFirstOrquesta);
//int orquesta_contarPeso(void* pFirstOrquesta);
//int orquesta_contarMayor300(void* pFirstOrquesta);
//int orquesta_contarMayor150(void* pFirstOrquesta);
//int orquesta_contarPolaroid(void* pFirstOrquesta);

#endif // ORQUESTA_H_INCLUDED
