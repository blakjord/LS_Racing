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

#include "tipos.h"

void dibujaPanelConfiguracion(General general, Coche * coche);
void pintaConfig(General general, Coche * coche, int x, int y, ALLEGRO_BITMAP * boxes, ALLEGRO_BITMAP * neumaticos, ALLEGRO_BITMAP * cotxe, ALLEGRO_BITMAP * gasolina, ALLEGRO_BITMAP * motor);

#endif //LS_RACING_GRAFICO_H
