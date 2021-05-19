#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"

int validarFecha(eFecha fecha, eFecha fechaHoy, eFecha fechaMin)
{
    int valido = 0;
    int cantDiasAnio = 365;
    int cantDiasMes;
    if(validarAnio(fecha.anio, fechaHoy.anio, fechaMin.anio, &cantDiasAnio) && validarMes(fecha.mes, fechaHoy.mes, fechaMin.mes, fecha.anio, fechaHoy.anio, fechaMin.anio, cantDiasAnio, &cantDiasMes) && validarDia(fecha, fechaHoy, fechaMin, cantDiasMes) != -1)
    {
        if ( cantDiasAnio == 0)
        {
            valido = 2;
            printf("ERROR Anio.\n");
        }
        else
        {
            if (cantDiasMes == 0)
            {
                valido = 3;
                printf("ERROR Mes.\n");
            }
            else
            {
                if (validarDia(fecha, fechaHoy, fechaMin, cantDiasMes) == 0)
                {
                    valido = 4;
                    printf("ERROR Dia.\n");
                }
                else
                {
                    valido = 1;
                    //printf("Fecha valida.\n");
                }
            }
        }
    }


    return valido;
}

int validarAnio(int anio, int anioHoy, int anioMin, int *pCantDiasAnio)
{
    int todoOk = 0;
    if (pCantDiasAnio != NULL && anioMin > 0 && anioMin <= anioHoy && anioHoy < 10001)
    {
        if (anio > anioHoy || anio < anioMin)
        {
            *pCantDiasAnio = 0;
        }
        else
        {
            if (anio % 4 == 0)
            {
                if (anio % 100 != 0)
                {
                    *pCantDiasAnio = 366;
                }
                else
                {
                    if (anio % 400 == 0)
                    {
                        *pCantDiasAnio = 366;
                    }
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarMes(int mes, int mesHoy, int mesMin, int anio, int anioHoy, int anioMin, int cantDiasAnio, int *pCantDiasMes)
{
    int todoOk = 0;
    if ((pCantDiasMes != NULL) &&(mesMin <= 12 && mesMin >= 1 && mesHoy <= 12 && mesHoy >= 1) && !(anioHoy == anioMin && mesHoy < mesMin))
    {
        if ((mes > 12 && mes < 1) || (anio == anioHoy && mes > mesHoy) || (anio == anioMin && mes < mesMin))
        {
            *pCantDiasMes = 0;
        }
        else
        {
            switch (mes)
            {
            case 1:  // Enero
            case 3:  // Marzo
            case 5:  // Mayo
            case 7:  // Julio
            case 8:  // Agosto
            case 10: // Octubre
            case 12: // Diciembre
                *pCantDiasMes = 31;
                break;

            case 4:  // Abril
            case 6:  // Junio
            case 9:  // Septiembre
            case 11: // Noviembre
                *pCantDiasMes = 30;
                break;

            case 2: // Febrero
                if (cantDiasAnio == 366)
                {
                    *pCantDiasMes = 29;
                }
                else
                {
                    *pCantDiasMes = 28;
                }
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarDia(eFecha fecha, eFecha fechaHoy, eFecha fechaMin, int cantDiasMes)
{
    int todoOk = 0;
    int cantDiasAnioHoy = 365;
    int cantDiasAnioMin = 365;
    int cantDiasMesHoy;
    int cantDiasMesMin;

    validarAnio(fechaHoy.anio, 10000, 1, &cantDiasAnioHoy);
    validarMes(fechaHoy.mes, 12, 1, fechaHoy.anio, 10000, 1, cantDiasAnioHoy, &cantDiasMesHoy);

    validarAnio(fechaMin.anio, 10000, 1, &cantDiasAnioMin);
    validarMes(fechaMin.mes, 12, 1, fechaMin.anio, 10000, 1, cantDiasAnioMin, &cantDiasMesMin);

    if (fechaHoy.dia > cantDiasMesHoy || fechaHoy.dia < 1 || fechaMin.dia > cantDiasMesMin || fechaMin.dia < 1 || ((fechaHoy.anio == fechaMin.anio) && (fechaHoy.mes == fechaMin.mes) && (fechaHoy.dia < fechaMin.dia)))
    {
        todoOk = -1;
    }
    else
    {
        if (fecha.dia <= cantDiasMes && fecha.dia > 0)
        {
            todoOk = 1;
            if (fecha.anio == fechaHoy.anio && fecha.mes == fechaHoy.mes && fecha.dia > fechaHoy.dia)
            {
                todoOk = 0;
            }
            if (fecha.anio == fechaMin.anio && fecha.mes == fechaMin.mes && fecha.dia < fechaMin.dia)
            {
                todoOk = 0;
            }
        }
    }

    return todoOk;
}
