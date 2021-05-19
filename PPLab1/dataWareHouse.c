#include "dataWareHouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nombres[10][20]={
    "Candela",
    "Juan",
    "Valentina",
    "Abril",
    "Leo",
    "Sofia",
    "Micaela",
    "Milena",
    "Fabricio",
    "Leandro"
};

char sexos[10]={'f','m','f','f','m','f','f','f','m','m'};

int edades[10]={17, 29, 16, 17, 17, 16, 20, 54, 21, 22};

float sueldos[10]={30000, 15000, 100000, 50000, 130000, 40000, 60000, 80000, 80000, 170000};

eFecha fechas[10] = {
    {1, 3, 2004},
    {2, 3, 2005},
    {12, 4, 1990},
    {15, 6, 2000},
    {27, 2, 1999},
    {12, 4, 1990},
    {15, 6, 2000},
    {27, 2, 1999},
    {12, 4, 1990},
    {15, 6, 2000}

};

int id[10]={501, 504, 502, 504, 503, 504, 501, 504, 502, 504};

int hardcodearEmpleados(eEmpleado lista[], int tam, int cant, int *pLegajo)
{
    int cantidad = 0;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pLegajo != NULL)
    {
        for(int i=0; i<cant; i++)
        {
            lista[i].legajo = *pLegajo;
            (*pLegajo)++;

            strcpy(lista[i].nombre, nombres[i]);
            lista[i].edad = edades[i];
            lista[i].sexo = sexos[i];
            lista[i].sueldo = sueldos[i];
            lista[i].fIngreso = fechas[i];
            lista[i].idSector = id[i];
            lista[i].isEmpty = 0;
            cantidad++;
        }

    }
    return cantidad;
}


eFecha fechas2[] = {
    {1,1,2021},//6
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},//5
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {3,1,2021}, // 6
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {4,1,2021}, //6
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021}
};

int legajos[] ={20000,20006,20001,20005,20007,20002,20000,20004,20001,20003,20008,20001,20006,20003,20004,20008,20005,20000,20005,20003,20007,20008,20004};

int idComidas[]={1000,1003,1002,1000,1000,1004,1002,1001,1004,1003,1003,1004,1000,1002,1004,1004,1001,1001,1000,1001,1002,1002,1000};

int hardcodearAlmuerzos(eAlmuerzo lista[], int tam, int cant, int *pId)
{
    int cantidad = 0;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        for(int i=0; i<cant; i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            lista[i].idComida = idComidas[i];
            lista[i].legEmpleado = legajos[i];
            lista[i].fecha = fechas2[i];
            lista[i].isEmpty = 0;
            cantidad++;
        }

    }
    return cantidad;
}
