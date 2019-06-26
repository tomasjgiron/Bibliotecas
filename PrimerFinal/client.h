#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include "arraynuevo.h"

typedef struct
{
    int idClient; /// se va autoincrementando
    char name[50];
    char surname[50];
    char dni[15];

}Client;

Client* client_new();
Client* client_newParametros(char* idStr,char* nombreStr,char* surnameStr,char* dniStr);
int client_delete(Client* this);

int client_setId(Client* this, char* value);
int client_getId(Client* this,int* value);

int client_setNombre(Client* this,char* value);
int client_getNombre(Client* this,char* value);

int client_setApellido(Client* this,char* value);
int client_getApellido(Client* this,char* value);

int client_setDni(Client* this,char* value);
int client_getDni(Client* this,char* value);

int client_sortByName(void* pFirstClient,void* pSecondClient);

#endif // CLIENT_H_INCLUDED
