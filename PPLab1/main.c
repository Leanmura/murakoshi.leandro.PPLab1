#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "inputs_lean.h"

#define INTENTOS 3

#define TAMT 5
#define TAMA 5
#define TAMC 5
#define TAMM 5
#define TAMS 4

typedef struct
{
    int id;
    char descripcion[20];
} eMarca;

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
} eServicio;

typedef struct
{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

void menu();
int inicializarAutos(eAuto lista[], int tam);
int buscarLibre(eAuto lista[], int tam);
int altaAuto(eAuto lista[], int tam, int *pNextId, eMarca listaM[], int tamM, eColor listaC[], int tamC);
int cargarDescripcionColor(int idColor, eColor listaC[], int tamC, char desc[]);
int cargarMarca(int idMarca, eMarca listaM[], int tamM, char marca[]);
int mostrarAuto(eAuto Auto, eMarca listaM[], int tamM, eColor listaC[], int tamC);
int mostrarAutos(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC);
int buscarAuto(eAuto lista[], int tam, char patente[]);
int modificarAuto(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC);
void menuModificar();
int bajaAuto(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC);

void mostrarMarca(eMarca marca);
void mostrarMarcas(eMarca marcas[], int tam);

void mostrarColores(eColor colores[], int tam);
void mostrarColor(eColor color);

void mostrarServicios(eServicio servicios[], int tam);
void mostrarServicio(eServicio servicio);

int altaTrabajo(eTrabajo lista[], int tam, int *pNextId, eServicio listaS[], int tamS, eAuto listaA[], int tamA, eMarca listaM[], int tamM, eColor listaC[], int tamC);
int buscarLibreTrabajo(eTrabajo lista[], int tam);

int cargarDescripcionServicio(int idServicio, eServicio listaS[], int tamS, char desc[]);
int mostrarTrabajos(eTrabajo lista[], int tam, eServicio listaS[], int tamS);
int mostrarTrabajo(eTrabajo Trabajo, eServicio listaS[], int tamS);

int main()
{

    int opcion;
    char salir = 'n';
    int nextIdAuto = 2000;
    int flag = 0;
    int nextIdTrabajo = 3000;
    int flagTrabajo = 0;

    eMarca marcas[TAMM] =
        {
            {1000, "Renault"},
            {1001, "Fiat"},
            {1002, "Ford"},
            {1003, "Chevrolet"},
            {1004, "Peugeot"}};

    eColor colores[TAMC] =
        {
            {5000, "Negro"},
            {5001, "Blanco"},
            {5002, "Gris"},
            {5003, "Rojo"},
            {5004, "Azul"}};

    eServicio servicios[TAMS] =
        {
            {20000, "Lavado", 250},
            {20001, "Pulido", 300},
            {20002, "Encerado", 400},
            {20003, "Completo", 600}};

    eAuto autos[TAMA];

    eTrabajo trabajos[TAMT];

    inicializarAutos(autos, TAMA);
    do
    {
        menu();
        if (!getInt(&opcion, 1, 10, INTENTOS, "Ingrese lo que desea hacer: ", "Error. "))
        {
            printf("Ha excedido el limite de intentos. Se finalizara el programa.\n\n");
            salir = 's';
        }

        switch (opcion)
        {
        case 1:
            system("cls");
            printf(" Alta auto\n");
            printf("Id: #%d\n", nextIdAuto);

            if (altaAuto(autos, TAMA, &nextIdAuto, marcas, TAMM, colores, TAMC))
            {
                printf("Alta exitosa!!!\n\n");
                flag = 1;
            }
            else
            {
                printf("Hubo un error en el alta.\n\n");
            }

            system("PAUSE");
            break;

        case 2:
            system("cls");
            if (flag)
            {
                printf(" Modificar auto\n");
                if (modificarAuto(autos, TAMC, marcas, TAMM, colores, TAMC))
                {
                    printf("modificacion exitosa!!!\n\n");
                }
                else
                {
                    printf("Hubo un error en la modificacion.\n\n");
                }
            }
            else
            {
                printf("No puede modificar un auto si no hay autos.\n\n");
            }
            system("PAUSE");
            break;

        case 3:
            system("cls");
            if (flag)
            {
                printf(" Baja auto\n");
                if (bajaAuto(autos, TAMC, marcas, TAMM, colores, TAMC))
                {
                    printf("Baja exitosa!!!\n\n");
                }
                else
                {
                    printf("Hubo un error en la baja.\n\n");
                }
            }
            else
            {
                printf("No puede dar de baja un auto si no hay autos.\n\n");
            }
            system("PAUSE");
            break;

        case 4:
            system("cls");
            if (flag)
            {
                mostrarAutos(autos, TAMA, marcas, TAMM, colores, TAMC);
            }
            else
            {
                printf("No puede listar los autos si no hay autos.\n\n");
            }
            system("PAUSE");
            break;

        case 5:
            system("cls");
            if (flag)
            {
                mostrarMarcas(marcas, TAMM);
            }
            else
            {
                printf("No puede listar las marcas si no hay marcas.\n\n");
            }
            system("PAUSE");
            break;

        case 6:
            system("cls");
            if (flag)
            {
                mostrarColores(colores, TAMC);
            }
            else
            {
                printf("No puede listar los Colores si no hay Colores.\n\n");
            }
            system("PAUSE");
            break;
        case 7:
            system("cls");
            if (flag)
            {
                mostrarServicios(servicios, TAMS);
            }
            else
            {
                printf("No puede listar los Servicios si no hay Servicios.\n\n");
            }
            system("PAUSE");
            break;

        case 8:
            system("cls");
            if (flag)
            {
                printf(" Alta trabajo\n");
                printf("Id: #%d\n", nextIdTrabajo);

                if (altaTrabajo(trabajos, TAMA, &nextIdTrabajo, servicios, TAMS, autos, TAMA, marcas, TAMM, colores, TAMC))
                {
                    printf("Alta exitosa!!!\n\n");
                    flagTrabajo = 1;
                }
                else
                {
                    printf("Hubo un error en el alta.\n\n");
                }
            }
            else
            {
                printf("No puede dar de alta trabajos si no hay Autos.\n\n");
            }

            system("PAUSE");
            break;

        case 9:
            system("cls");
            if(flagTrabajo)
            {
                mostrarTrabajos(trabajos, TAMT, servicios, TAMS);
            }
                        else
            {
                printf("No puede listar los trabajos si no hay trabajos.\n\n");
            }
            system("PAUSE");

            break;


        case 10:
            system("cls");
            printf("--------- Salir ---------\n");

            if (!getLetra(&salir, 3, "Confirmar salida? [s/n] ", "Error. "))
            {
                printf("Ha excedido el limite de intentos se cerrara el programa.\n\n");
            }
            break;
        }
    } while (salir == 'n');
    return 0;
}

void menu()
{
    system("cls");
    printf("------- autos -------\n");
    printf("1. Alta auto\n");
    printf("2. Modificar auto\n");
    printf("3. Baja auto\n");
    printf("4. Listar autos\n");
    printf("5. Listar marcas\n");
    printf("6. Listar colores\n");
    printf("7. Listar servicios\n");
    printf("8. Alta trabajo\n");
    printf("9. Listar trabajos\n");
    printf("10. Salir\n\n");
}

int inicializarAutos(eAuto lista[], int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eAuto lista[], int tam)
{
    int indice = -1;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaAuto(eAuto lista[], int tam, int *pNextId, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    int todoOk = 0;
    int indice;
    eAuto auxAuto;
    if (lista != NULL && tam >= 0 && pNextId != NULL)
    {
        indice = buscarLibre(lista, tam);
        if (indice != -1)
        {
            if (getString(auxAuto.patente, 20, INTENTOS, "Ingrese patente: ", "Error. "))
            {
                mostrarMarcas(listaM, tamM);
                if (getInt(&auxAuto.idMarca, 1000, 1004, INTENTOS, "Ingrese id de la Marca: ", "Error. "))
                {
                    mostrarColores(listaC, TAMC);
                    if (getInt(&auxAuto.idColor, 5000, 5004, INTENTOS, "Ingrese idColor: ", "Error. "))
                    {
                        if (getInt(&auxAuto.modelo, 1500, 2021, INTENTOS, "Ingrese modelo: ", "Error. "))
                        {
                            auxAuto.isEmpty = 0;
                            auxAuto.id = *pNextId;
                            (*pNextId)++;

                            lista[indice] = auxAuto;
                            todoOk = 1;
                        }
                    }
                }
            }
        }
        else
        {
            printf("No hay lugar disponible\n");
        }
    }
    return todoOk;
}

int cargarDescripcionColor(int idColor, eColor listaC[], int tamC, char desc[])
{
    int todoOk = 0;

    if (listaC != NULL && tamC > 0 && desc != NULL && idColor >= 5000 && idColor <= 5004)
    {
        for (int i = 0; i < tamC; i++)
        {
            if (idColor == listaC[i].id)
            {
                strcpy(desc, listaC[i].nombreColor);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

int cargarMarca(int idMarca, eMarca listaM[], int tamM, char marca[])
{
    int todoOk = 0;
    if (listaM != NULL && tamM > 0 && marca != NULL && idMarca >= 1000 && idMarca <= 1004)
    {
        for (int i = 0; i < tamM; i++)
        {
            if (idMarca == listaM[i].id)
            {
                strcpy(marca, listaM[i].descripcion);
                todoOk = 1;
            }
        }
        return todoOk;
    }
    return todoOk;
}

int mostrarAuto(eAuto Auto, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    char descripcionC[20];
    char marca[20];
    int todoOk = 0;
    if (listaM != NULL && listaC != NULL && tamC > 0 && tamM > 0)
    {
        if (cargarMarca(Auto.idMarca, listaM, tamM, marca))
        {
            if (cargarDescripcionColor(Auto.idColor, listaC, tamC, descripcionC))
            {
                printf(" %-8s   %-10s   %-10s  %d  \n", Auto.patente, marca, descripcionC, Auto.modelo);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int mostrarAutos(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    int todoOk = 0;
    int flagIsEmpty = 1;
    if (listaC != NULL && tamC > 0 && listaM != NULL && tamM > 0 && lista != NULL && tam > 0)
    {
        printf("Patente     Marca       Color      Modelo \n");
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty)
            {
                mostrarAuto(lista[i], listaM, tamM, listaC, tamC);
                flagIsEmpty = 0;
            }
        }
        if (flagIsEmpty)
        {
            printf("No hay autos.\n");
        }
        printf("\n");
        todoOk = 1;
    }

    return todoOk;
}

int buscarAuto(eAuto lista[], int tam, char patente[])
{
    int indice = -1;

    if (lista != NULL && tam > 0 && patente != NULL)
    {
        for (int i = 0; i < tam; i++)
        {
            if (strcmp(lista[i].patente, patente) == 0 && !lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int modificarAuto(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    char patente[20];
    int indice;
    int todoOk = 0;
    char confirmacion;
    int opcion;
    eAuto auxAuto;

    if (lista != NULL && tam >= 0)
    {
        if (getString(patente, 20, 3, "Ingrese la patente del Auto: ", "Error. "))
        {
            indice = buscarAuto(lista, tam, patente);
            if (indice != -1)
            {
                printf("  patente   Marca   Color Modelo \n");
                mostrarAuto(lista[indice], listaM, tamM, listaC, tamC);
                printf("\nEsta seguro que quiere modificar esta patente? ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                if (confirmacion == 's')
                {
                    menuModificar();
                    printf("Patente    Marca   Color Modelo\n");
                    mostrarAuto(lista[indice], listaM, tamM, listaC, tamC);
                    printf("\nIngrese lo que desea modificar: ");
                    fflush(stdin);
                    while (!scanf("%d", &opcion) || opcion < 1 || opcion > 3)
                    {
                        printf("Error. Ingrese lo que desea modificar: ");
                        fflush(stdin);
                    }

                    switch (opcion)
                    {
                    case 1:
                        printf("ID de la marca a modificar: %d\n", lista[indice].idMarca);
                        mostrarMarcas(listaM, tamM);
                        if (getInt(&auxAuto.idMarca, 1000, 1004, INTENTOS, "Ingrese id de la Marca: ", "Error. "))
                        {
                            printf("Esta seguro que quiere cambiar '%d' por '%d'? ", lista[indice].idMarca, auxAuto.idMarca);
                            fflush(stdin);
                            scanf("%c", &confirmacion);
                            if (confirmacion == 's')
                            {
                                lista[indice].idMarca = auxAuto.idMarca;
                                printf("Marca modificado con exito!\n\n");
                                todoOk = 1;
                            }
                        }
                        break;

                    case 2:
                        printf("Modelo a modificar: %d\n", lista[indice].modelo);

                        if (getInt(&auxAuto.modelo, 1500, 2021, INTENTOS, "Ingrese modelo: ", "Error. "))
                        {
                            printf("Esta seguro que quiere cambiar '%d' por '%d'? ", lista[indice].modelo, auxAuto.modelo);
                            fflush(stdin);
                            scanf("%c", &confirmacion);
                            if (confirmacion == 's')
                            {
                                lista[indice].modelo = auxAuto.modelo;
                                printf("Modelo modificado con exito!\n\n");
                                todoOk = 1;
                            }
                        }
                        break;
                    }
                    if (confirmacion != 's')
                    {
                        printf("Modificacion abortada.\n");
                    }
                }
                else
                {
                    printf("Operacion abortada.\n");
                }
            }
        }
        else
        {
            printf("No se encontro el id.\n");
        }
    }

    return todoOk;
}

void menuModificar()
{
    system("cls");
    printf("------- Menu Modificar -------\n");
    printf("1. Marca\n");
    printf("2. Modelo\n");
    printf("3. Salir\n\n");
}

void mostrarMarca(eMarca marca)
{
    printf("#%03d  %-10s \n", marca.id, marca.descripcion);
}

void mostrarMarcas(eMarca marcas[], int tam)
{
    if (marcas != NULL && tam > 0)
    {
        printf("\n***** Listado de marcas *****\n");
        printf(" ID   Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            mostrarMarca(marcas[i]);
        }
        printf("\n");
    }
}

void mostrarColor(eColor color)
{
    printf("#%03d  %-10s \n", color.id, color.nombreColor);
}

void mostrarColores(eColor colores[], int tam)
{
    if (colores != NULL && tam > 0)
    {
        printf("\n***** Listado de colores *****\n");
        printf(" ID   Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            mostrarColor(colores[i]);
        }
        printf("\n");
    }
}

void mostrarServicio(eServicio servicio)
{
    printf("#%03d  %-10s %.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

void mostrarServicios(eServicio servicios[], int tam)
{
    if (servicios != NULL && tam > 0)
    {
        printf("\n***** Listado de servicios *****\n");
        printf(" ID   Descripcion   Precio\n");
        for (int i = 0; i < tam; i++)
        {
            mostrarServicio(servicios[i]);
        }
        printf("\n");
    }
}

int bajaAuto(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    char patente[20];
    int indice;
    int todoOk = 0;
    char confirmacion;

    if (lista != NULL && tam >= 0)
    {
        mostrarAutos(lista, tam, listaM, TAMM, listaC, TAMC);
        if (getString(patente, 20, 3, "Ingrese la patente del Auto: ", "Error. "))
        {
            indice = buscarAuto(lista, tam, patente);
            if (indice != -1)
            {
                printf("Patente    Marca   Color Modelo\n");
                mostrarAuto(lista[indice], listaM, tamM, listaC, tamC);
                printf("\nEsta seguro que quiere eliminar este auto? (s/n)");
                fflush(stdin);
                scanf("%c", &confirmacion);
                if (confirmacion == 's')
                {
                    lista[indice].isEmpty = 1;
                    todoOk = 1;
                }
                else
                {
                    printf("Operacion abortada.\n\n");
                }
            }
            else
            {
                printf("No se encontro la patente.\n\n");
            }
        }
    }

    return todoOk;
}

int buscarLibreTrabajo(eTrabajo lista[], int tam)
{
    int indice = -1;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaTrabajo(eTrabajo lista[], int tam, int *pNextId, eServicio listaS[], int tamS, eAuto listaA[], int tamA, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;
    if (lista != NULL && tam >= 0 && pNextId != NULL)
    {
        indice = buscarLibreTrabajo(lista, tam);
        if (indice != -1)
        {
            mostrarAutos(listaA, tamA, listaM, tamM, listaC, tamC);
            printf("Ingrese Patente del auto: ");
            scanf("%s", auxTrabajo.patente);
            while (buscarAuto(listaA, tamA, auxTrabajo.patente) == -1)
            {
                printf("Error. ");
                scanf("%s", auxTrabajo.patente);
                fflush(stdin);
            }
            mostrarServicios(listaS, tamS);
            if (getInt(&auxTrabajo.idServicio, 20000, 20003, INTENTOS, "Ingrese id de la Marca: ", "Error. "))
            {
                eFecha fechaHoy = {19, 05, 2021};
                eFecha fechaMin = {01, 01, 2000};
                if (getFecha(&auxTrabajo.fecha, fechaHoy, fechaMin, 3, "Ingresar la fecha de hoy(DD/MM/AAAA): ", "Error. ") == 1)
                {
                    auxTrabajo.isEmpty = 0;
                    auxTrabajo.id = *pNextId;
                    (*pNextId)++;

                    lista[indice] = auxTrabajo;
                    todoOk = 1;
                }
            }
        }
    }
    else
    {
        printf("No hay lugar disponible\n");
    }
    return todoOk;
}

int mostrarTrabajo(eTrabajo Trabajo, eServicio listaS[], int tamS)
{
    char descripcionS[20];
    int todoOk = 0;
    if (listaS != NULL && tamS > 0)
    {

        if (cargarDescripcionServicio(Trabajo.idServicio, listaS, tamS, descripcionS))
        {
            printf(" %-8s %-10s %02d/%02d/%04d \n", Trabajo.patente, descripcionS, Trabajo.fecha.dia, Trabajo.fecha.mes, Trabajo.fecha.anio);
            todoOk = 1;
        }
    }
    return todoOk;
}

int mostrarTrabajos(eTrabajo lista[], int tam, eServicio listaS[], int tamS)
{
    int todoOk = 0;
    int flagIsEmpty = 1;
    if (listaS != NULL && tamS > 0 && lista != NULL && tam > 0)
    {
        printf("Patente   Servicio   Fecha \n");
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty)
            {
                mostrarTrabajo(lista[i], listaS, tamS);
                flagIsEmpty = 0;
            }
        }
        if (flagIsEmpty)
        {
            printf("No hay Trabajos.\n");
        }
        printf("\n");
        todoOk = 1;
    }

    return todoOk;
}

int cargarDescripcionServicio(int idServicio, eServicio listaS[], int tamS, char desc[])
{
    int todoOk = 0;

    if (listaS != NULL && tamS > 0 && desc != NULL && idServicio >= 20000 && idServicio <= 20003)
    {
        for (int i = 0; i < tamS; i++)
        {
            if (idServicio == listaS[i].id)
            {
                strcpy(desc, listaS[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}
