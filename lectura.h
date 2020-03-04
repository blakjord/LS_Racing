//
// Created by Alejandro on 03/03/2020.
//

#ifndef LS_RACING_LECTURA_H
#define LS_RACING_LECTURA_H

typedef struct {
    char nombrePieza[50];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
} Pieza;

typedef struct {
    char nombreCategoria[50];
    Pieza * pieza;
    int numPiezas;
} Categoria;

typedef struct {
    Categoria * categoria;
    int numCategorias;
} General;


General lecturaFicheros(char *argv[]);
General lecturaPiezas(char *argv, General general);
General lecturaGPs(char *argv, General general);
General lecturaCorredores(char *argv, General general);
General lecturaBase(char *argv, General general);


#endif //LS_RACING_LECTURA_H
