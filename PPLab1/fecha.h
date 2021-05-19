#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

int validarFecha(eFecha fecha, eFecha fechaHoy, eFecha fechaMin);

/** \brief valida el anio ingresado y actualiza (en el puntero) la cantidad de dias del anio ingresado
 *
 * \param anio int anio a validar
 * \param anioHoy int anio actual o maximo anio valido
 * \param anioMin int minimo anio valido
 * \param pCantDiasAnio int* cantidad de dias del anio, si es 0 el anio es invalido
 * \return int retorna 1 si esta todo ok, 0 si hubo un problema con los prametros preseteados(anioHoy, anioMin, *dias), 2 si esta mal el anio, 3 si esta mal el mes, 4 si esta mal el dia
 *
 */
int validarAnio(int anio, int anioHoy, int anioMin, int *pCantDiasAnio);

/** \brief valida el mes ingresado y guarda (en el puntero) la cantidad de dias del mes ingresado
 *
 * \param mes int mes a validar
 * \param mesHoy int mes actual o maximo mes valido
 * \param mesMin int minimo mes valido
 * \param anio int anio ya validado
 * \param anioHoy int anio actual o maximo anio valido
 * \param anioMin int minimo anio valido
 * \param cantDiasAnio int cantidad de dias del anio
 * \param pCantDiasMes int* cantidad de dias del mes ingresado, si es 0 el mes es invalido
 * \return int retorna 1 si esta todo ok, 0 si hubo un problema con los prametros preseteados(mesHoy, mesMin, *dias)
 *
 */
int validarMes(int mes, int mesHoy, int mesMin, int anio, int anioHoy, int anioMin, int cantDiasAnio, int *pCantDiasMes);

/** \brief valida el dia ingresado
 *
 * \param fecha eFecha fecha ingresada
 * \param fechaHoy eFecha fecha actual o maxima fecha valida
 * \param fechaMin eFecha minima fecha valida
 * \param dias int cantidad de dias del mes
 * \return int retorna 1 si esta todo ok, -1 si hubo un problema con los prametros preseteados(mesHoy, mesMin, *dias)
 *             o 0 si el dia ingresado es invalido
 */
int validarDia(eFecha fecha, eFecha fechaHoy, eFecha fechaMin, int dias);
