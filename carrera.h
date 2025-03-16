/***********************************************
*
* @Proposito: Almacena las funciones de la carrera
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#ifndef LS_RACING_CARRERA_H
#define LS_RACING_CARRERA_H

#include "grafico.h"

void semaforo();
void calculosCarrera(General general, Coche coche, struct _node circuito, float * tiempoTotal, int * numStops);
int logicaCarrera(General general, Coche coche, struct _node circuito, ALLEGRO_BITMAP * cotxe, ALLEGRO_BITMAP * logo,
        ALLEGRO_TIMER * timer, ALLEGRO_TIMER * timerP, float * tiempoTotal, int numStops);
void carrera(General general, Coche coche, struct _node* circuito, Clasificacion * clasificacion);


#endif //LS_RACING_CARRERA_H
