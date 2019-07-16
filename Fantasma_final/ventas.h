#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED

typedef struct
{
    int id;
    char fecha[15];
    char tipo[30];
    int cantidad;
    float precioUnitario;
    char cuit[20];

} Ventas; ///también puede variar en Producto

Ventas* venta_new();
Ventas* venta_newParametros(char* idStr,char* fechaStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr);
//Ventas* venta_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr);
int venta_delete(Ventas* this);

int venta_setIdStr(Ventas* this, char* value);
int venta_setId(Ventas* this,int value);
int venta_getId(Ventas* this,int* value);

int venta_setTipo(Ventas* this,char* value);
int venta_getTipo(Ventas* this,char* value);

int venta_setCantidad(Ventas* this,char* value);
int venta_getCantidad(Ventas* this,int* value);

int venta_setPrecio(Ventas* this,char* value);
int venta_getPrecio(Ventas* this,float* value);

int venta_setFecha(Ventas* this, char* value);
int venta_getFecha(Ventas* this, char* value);

int venta_setCuit(Ventas* this, char* value);
int venta_getCuit(Ventas* this, char* value);

//int venta_sortByTipo(void* pFirstVentas,void* pSecondVentas);
//int venta_contarByTipoSTD(void* pVenta);
//int venta_contarByTipoEXP(void* pFirstVenta);
//int venta_contarByTipoECO(void* pFirstVenta);
int venta_contarCantidad(void* pFirstVenta);
int venta_contarPrecio(void* pFirstVenta);
int venta_contarMayor300(void* pFirstVenta);
int venta_contarMayor150(void* pFirstVenta);
int venta_contarPolaroid(void* pFirstVenta);


#endif // ENTREGAS_H_INCLUDED
