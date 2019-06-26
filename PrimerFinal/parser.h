#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"

int parser_parseClientesText(FILE* pFile, LinkedList* listaClientes);
int parser_parseVentasText(FILE* pFile, LinkedList* listaVentas);
#endif // PARSER_H_INCLUDED
