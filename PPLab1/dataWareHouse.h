#include "fecha.h"
#include "../abmEmpleados/empleado.h"
#include "../abmEmpleados/almuerzo.h"
#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

int hardcodearEmpleados(eEmpleado lista[], int tam, int cant, int *pLegajo);

int hardcodearAlmuerzos(eAlmuerzo lista[], int tam, int cant, int *pId);

#endif // DATAWAREHOUSE_H_INCLUDED
