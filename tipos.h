/***********************************************
*
* @Proposito: Almacena todos los tipos y constantes
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#ifndef LS_RACING_TIPOS_H
#define LS_RACING_TIPOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LS_allegro.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define anchoPantalla 900
#define altoPantalla 550
#define MAXC 26
#define MAXPilotos 8
#define vel "VELOCIDAD"
#define acel "ACELERACION"
#define cons "CONSUMO"
#define fiab "FIABILIDAD"

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
    struct _node *next;
} GP;

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
    struct _node * listaGP;
    int numGPs;
    Corredor * corredor;
    int numCorredores;
    Base base;
} General;

typedef struct {
    Corredor corredor;
    Pieza * pieza;
} Coche;

#endif //LS_RACING_TIPOS_H
