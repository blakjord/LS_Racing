//
// Created by Alejandro on 11/03/2020.
//

#ifndef LS_RACING_TIPOS_H
#define LS_RACING_TIPOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LS_allegro.h"
#define MAXC 25

typedef struct {
    char nombrePieza[MAXC];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
} Pieza;

typedef struct {
    char nombreCategoria[MAXC];
    Pieza * pieza;
    int numPiezas;
} Categoria;

typedef struct _node{
    int posCalndario;
    char nombreGP[MAXC];
    int velocidadAdec;
    int aceleracionAdec;
    int consumoAdec;
    int fiabilidadAdec;
    float tiempoBase;
    int tiempoPinStop;
    int numeroPinStop;
    struct _node *prev;
    struct _node *next;
} GP;

typedef struct {
    GP * first;
    GP * pdi;
    GP * last;
    int numGPs;
} ListaGP;

typedef struct {
    char nombreCorredor[MAXC];
    int dorsal;
    char escuderia[MAXC];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
    int reflejos;
    int condicionFisica;
    int temperamento;
    int gestNeumaticos;
} Corredor;

typedef struct {
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
} Base;

typedef struct {
    Categoria * categoria;
    int numCategorias;
    ListaGP listaGp;
    Corredor * corredor;
    int numCorredores;
    Base base;
} General;

typedef struct {
    Corredor corredor;
    Pieza * pieza;
} Coche;

#endif //LS_RACING_TIPOS_H
