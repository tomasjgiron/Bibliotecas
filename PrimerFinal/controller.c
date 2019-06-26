#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "client.h"
#include "sale.h"
#include "Controller.h"
#include "parser.h"
#include "arraynuevo.h"
#define TRIES 3


/** \brief Carga los datos de los clientes desde el archivo clientes.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_loadClientFromText(char* path,LinkedList* pArrayListClient)
{
    FILE* pFile;
    int retorno = -1;
    if(pArrayListClient != NULL)
    {
        pFile = fopen(path,"r");
        if(pFile != NULL)
        {
            parser_parseClientesText(pFile,pArrayListClient);
            fclose(pFile);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Carga los datos de las ventas desde el archivo ventas.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListSale LinkedList*
 * \return int
 *
 */
int controller_loadSaleFromText(char* path,LinkedList* pArrayListSale)
{
    FILE* pFile;
    int retorno = -1;
    if(pArrayListSale != NULL)
    {
        pFile = fopen(path,"r");
        if(pFile != NULL)
        {
            parser_parseVentasText(pFile,pArrayListSale);
            fclose(pFile);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Alta de cliente
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int

 */
int controller_addClient(LinkedList* pArrayListClient)
{
    Client* newClient;
    char bufferId[1500];
    char bufferNombre[1500];
    char bufferApellido[1500];
    char bufferDni[1500];
    int retorno = -1;

    if(pArrayListClient != NULL)
    {
        if((getStringNumerosInt(bufferId,"Ingrese ID:","Error\n",TRIES) == 0)
                &&(getStringLetras(bufferNombre,"Ingrese nombre: ","Error",TRIES) == 0)
                &&(getStringLetras(bufferApellido,"Ingrese apellido: ","Error",TRIES) == 0)
                &&(getDni(bufferDni,"Ingrese dni: ","Error",TRIES == 0)))
        {
            newClient = client_newParametros(bufferId,bufferNombre,bufferApellido,bufferDni);
            if(newClient != NULL)
            {
                if(ll_add(pArrayListClient,newClient) == 0)
                    {
                       retorno = 0;
                    }
            }
        }
    }
    return retorno;
}

/** \brief Modificar datos de cliente
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_modifyClient(LinkedList* pArrayListClient)
{
    Client* pClient;
    int retorno = -1;
    int size;
    char bufferId[1500];
    int auxId;
    int idBuscado;
    char bufferNombre[1500];
    char bufferApellido[1500];
    char bufferDni[1500];
    int i;
    int option;

    if (pArrayListClient != NULL)
    {
        size = ll_len(pArrayListClient);
        if(getStringNumerosInt(bufferId,"Ingrese el ID del cliente que desea modificar: ","Error\n",TRIES) == 0)
        {
            auxId = atoi(bufferId);
            for (i=0; i<size; i++)
            {
                pClient = ll_get(pArrayListClient,i);
                if(auxId == client_getId(pClient,&idBuscado))
                {
                    do
                    {
                        printf("Elija que desea modificar: \n");
                        printf("1- Nombre del cliente\n2- Apellido del cliente\n"
                               "3- Dni del cliente\n4- Salir\n");
                        getIntInRange(&option,"Ingrese Opcion: ","Error\n",1,4,TRIES);
                        switch (option)
                        {
                        case 1:
                            if(getStringLetras(bufferNombre,"Ingrese nuevo nombre: ","Error\n",TRIES) == 0)
                            {
                                client_setNombre(pClient,bufferNombre);
                                retorno = 0;
                            }
                            break;
                        case 2:
                            if(getStringLetras(bufferApellido,"Ingrese nuevo apellido: ","Error\n",TRIES) == 0)
                            {
                                client_setApellido(pClient,bufferApellido);
                                retorno = 0;
                            }
                            break;
                        case 3:
                            if(getDni(bufferDni,"Ingrese nuevo dni: ","Error\n",TRIES) == 0)
                            {
                                client_setDni(pClient,bufferDni);
                                retorno = 0;
                            }
                            break;
                        }
                    }
                    while (option != 4);
                }
            }
        }
    }
    return retorno;
}

/** \brief Baja de cliente
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_removeClient(LinkedList* pArrayListClient)
{
    Client* pClient;
    int retorno = -1;
    int size;
    char bufferId[1500];
    int auxId;
    int idBuscado;
    int i;

    if (pArrayListClient != NULL)
    {
        size = ll_len(pArrayListClient);
        if(getStringNumerosInt(bufferId,"Ingrese el ID del cliente que desea bajar: ","Error\n",TRIES) == 0)
        {
            auxId = atoi(bufferId);
            for (i=0; i<size; i++)
            {
                pClient = ll_get(pArrayListClient,i);
                if(auxId == client_getId(pClient,&idBuscado))
                {
                    ll_remove(pArrayListClient,i);
                    client_delete(pClient);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Listar clientes
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_listClient(LinkedList* pArrayListClient)
{
    Client* pC;
    int auxId;
    char auxDni[1500];
    char auxApellido[1500];
    char auxNombre[1500];
    int size;
    int i;

    if(pArrayListClient != NULL)
    {
        size = ll_len(pArrayListClient);
        for(i=0; i<size; i++)
        {
            pC = ll_get(pArrayListClient,i);
            client_getId(pC,&auxId);
            client_getNombre(pC,auxNombre);
            client_getApellido(pC,auxApellido);
            client_getDni(pC,auxDni);
            if(pC != NULL)
            {
                printf("%d\t %s\t %s\t %s\n",auxId,
                                            auxNombre,
                                            auxApellido,
                                            auxDni);
            }
        }
    }
    return 0;
}

/** \brief Ordenar clientes
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_sortClient(LinkedList* pArrayListClient)
{
    int retorno = -1;

    if(pArrayListClient != NULL)
    {
        ll_sort(pArrayListClient,client_sortByName,1);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los clientes en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListClient)
{
    Client* pC;
    int auxId;
    char auxDni[1500];
    char auxApellido[1500];
    char auxNombre[1500];
    int size;
    int i;
    int retorno = 1;

    FILE* fp = fopen(path,"a+");
    if(fp != NULL && pArrayListClient != NULL)
    {
        fprintf(fp,"id,nombre,apellido,dni\n");

        size = ll_len(pArrayListClient);

        for(i=0;i<size;i++)
        {
            pC = ll_get(pArrayListClient,i);
            client_getId(pC,&auxId);
            client_getNombre(pC,auxNombre);
            client_getApellido(pC,auxApellido);
            client_getDni(pC,auxDni);
            if(pC != NULL)
            {
                fprintf(fp,"%d,%s,%s,%s\n",auxId,
                                            auxNombre,
                                            auxApellido,
                                            auxDni);
            }
        }
        fclose(fp);
        retorno = 0;
    }
    return retorno;
}
