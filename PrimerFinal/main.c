#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "client.h"
#include "sale.h"
#define TRIES 3

    int main()
    {

        ///int flagCliente = 0;
        ///int flagVenta = 0;
        int opcionPrimaria = 0;
        int escapePrimario = 11;

        while(opcionPrimaria!=escapePrimario)
        {
            printf("\n1.ALTA CLIENTE\n2.MODIFICAR CLIENTE\n3.BAJA CLIENTE\n~~~"
                    "\n4.LISTAR CLIENTES\n5.ALTA VENTA\n6.BAJA VENTA\n7.LISTAR VENTAS\n~~~"
                    "\n8.INFORMAR VENTA POR PRODUCTO\n9.GENERAR INFORME DE VENTAS\n10.INFORMAR CANTIDAD DE VENTAS POR CLIENTE\n11.SALIR\n");

            getIntInRange(&opcionPrimaria,"\nIngrese opcion: ",
                          "Informacion invalida\n",1,escapePrimario,TRIES);

            switch(opcionPrimaria)
            {
                case 1:
                {

                    break;
                }
                case 2:
                {

                    break;
                }
                case 3:
                {

                    break;
                }
                case 4:
                {

                    break;
                }
                case 5:
                {

                    break;
                }
                case 6:
                {

                    break;
                }
                case 7:
                {

                    break;
                }
                case 8:
                {

                    break;
                }
                case 9:
                {

                    break;
                }
                case 10:
                {
                    break;
                }
            }
        }

        fflush(stdin);
        return 0;
    }
