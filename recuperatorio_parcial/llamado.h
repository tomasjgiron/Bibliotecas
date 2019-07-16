#ifndef LLAMADO_H_INCLUDED
#define LLAMADO_H_INCLUDED

typedef struct
{
    int id;
    char fecha[50];
    int numeroCliente;
    int idProblema;
    char solucionado[50];

} Llamado; ///también puede variar en Producto

Llamado* llamado_new();
Llamado* llamado_newParametros(char* idStr,char* fechaStr,char* numeroClienteStr,char* idProblemaStr,char* SolucionadoStr);
//Llamado* llamado_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr);
int llamado_delete(Llamado* this);

int llamado_setIdStr(Llamado* this, char* value);
//int llamado_setId(Llamado* this,int value);
int llamado_getId(Llamado* this,int* value);

int llamado_setFecha(Llamado* this, char* value);
int llamado_getFecha(Llamado* this, char* value);

int llamado_setSolucionado(Llamado* this,char* value);
int llamado_getSolucionado(Llamado* this,char* value);

int llamado_setNumeroCliente(Llamado* this,char* value);
int llamado_getNumeroCliente(Llamado* this,int* value);

int llamado_setIdProblema(Llamado* this, char* value);
int llamado_getIdProblema(Llamado* this, int* value);

//int llamado_sortByTipo(void* pFirstLlamado,void* pSecondLlamado);
//int llamado_contarByTipoSTD(void* pLlamado);
//int llamado_contarByTipoEXP(void* pFirstLlamado);
//int llamado_contarByTipoECO(void* pFirstLlamado);
int llamado_contarCantidad(void* pFirstLlamado);
int llamado_contarPrecio(void* pFirstLlamado);
int llamado_contarMayor300(void* pFirstLlamado);
int llamado_contarMayor150(void* pFirstLlamado);
int llamado_contarPolaroid(void* pFirstLlamado);
int llamado_printProblema(int problemaLlamado);
int llamado_filterByProblema(void* pEmpleado);


#endif // LLAMADO_H_INCLUDED
