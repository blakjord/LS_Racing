/***********************************************
*
* @Proposito: Almacena las funciones sobre el apartado grafico de la configuracion de nuestro piloto
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#ifndef LS_RACING_GRAFICO_H
#define LS_RACING_GRAFICO_H

#include "lista.h"

void pintaConfig(General general, Coche * coche, int x, int y, ALLEGRO_BITMAP * boxes, ALLEGRO_BITMAP * neumaticos, ALLEGRO_BITMAP * cotxe, ALLEGRO_BITMAP * gasolina, ALLEGRO_BITMAP * motor);
void pintarCarrera(General general, Coche coche, int numStops, int stopsDone, ALLEGRO_BITMAP * cotxe, ALLEGRO_BITMAP * logo, float tiempo, float tiempoP, const float * tiempoTotal);
void pintarPantallaInicio(struct _node circuito);
void pintarPantallaFinal(int posicion , char * nombre, int penalizacion);
void pintarClasificacion(Clasificacion clasificacion, ALLEGRO_BITMAP * logo);
void pintarClasificacionFinal(Clasificacion clasificacion, ALLEGRO_BITMAP * logo);

#endif //LS_RACING_GRAFICO_H
