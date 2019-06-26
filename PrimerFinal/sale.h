#ifndef SALE_H_INCLUDED
#define SALE_H_INCLUDED
#include "client.h"
#include "arraynuevo.h"

typedef struct
{
    int idSale;/// se va autoincrementando
    int idClient;
    int codProduct;
    int cantidad;
    float precioUnitario;

}Sale;

Sale* sale_new();
Sale* sale_newParametros(char* idStr,char* idCStr,char* codProductStr,char* cantidadStr,char* precioUnitarioStr);
int sale_delete();

int sale_setId(Sale* this, char* value);
int sale_getId(Sale* this,int* value);

int sale_setIdC(Sale* this, char* value);
int sale_getIdC(Sale* this,int* value);

int sale_setCodProduct(Sale* this,char* value);
int sale_getCodProduct(Sale* this,int* value);

int sale_setCantidad(Sale* this,char* value);
int sale_getCantidad(Sale* this,int* value);

float sale_setPrecioUnitario(Sale* this,char* value);
float sale_getPrecioUnitario(Sale* this,float* value);

int sale_sortByName(void* pFirstSale,void* pSecondSale);

#endif // SALE_H_INCLUDED
