/***********************************************
*
* @Proposito: Almacena las funciones sobre la clasificacion y la generacion de logs.
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#ifndef LS_RACING_CLASIFICACION_H
#define LS_RACING_CLASIFICACION_H

#include "grafico.h"

#define NOMBRE_FICHERO "log_temporada.txt"

void clasificacionGeneral(Clasificacion clasificacion, int acabada);
void generarLogs(Clasificacion clasificacion);

#endif //LS_RACING_CLASIFICACION_H
