//
// Created by Alejandro on 05/03/2020.
//

#ifndef LS_RACING_GRAFICO_H
#define LS_RACING_GRAFICO_H

#include "tipos.h"
#define anchoPantalla 900
#define altoPantalla 550

void dibujaPanelConfiguracion(General general, Coche * coche);
void pinta(General general, Coche * coche, int x, int y, ALLEGRO_BITMAP * boxes, ALLEGRO_BITMAP * neumaticos, ALLEGRO_BITMAP * cotxe, ALLEGRO_BITMAP * gasolina, ALLEGRO_BITMAP * motor);

#endif //LS_RACING_GRAFICO_H
