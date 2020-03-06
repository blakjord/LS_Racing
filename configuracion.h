//
// Created by Alejandro on 03/03/2020.
//

#ifndef LS_RACING_CONFIGURACION_H
#define LS_RACING_CONFIGURACION_H

#include "lectura.h"
#include "grafico.h"

typedef struct {
    Corredor corredor;
    Pieza * pieza;
} Coche;

int configurarCoche(General general);

#endif //LS_RACING_CONFIGURACION_H
