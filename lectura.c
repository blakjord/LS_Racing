//
// Created by Alejandro on 03/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lectura.h"

General lecturaFicheros(char * argv[]){
    General general;
    general = lecturaPiezas(argv[1], general);
    general = lecturaGPs(argv[2], general);
    general = lecturaCorredores(argv[3], general);
    general = lecturaBase(argv[4], general);
    return general;
}

General lecturaPiezas(char * argv, General general) {
    char cadena[50], aux = ' ';
    FILE * fp = fopen(argv, "r");
    if (fp == NULL) {
        printf("Error: Fichero inexistente.\n\n");
        exit(0);
    }
    fscanf(fp,"%d",&general.numCategorias);
    printf("%d",general.numCategorias);
    general.categoria = malloc(sizeof(Categoria));
    for (int i = 0; i < general.numCategorias; ++i) {
        printf("%d",i);
        general.categoria = realloc(general.categoria, sizeof(Categoria)*i+1);
        fscanf(fp,"%s",general.categoria[i].nombreCategoria);
        fscanf(fp,"%c", &aux);
        while (aux != '\n'){
            fscanf(fp,"%s",cadena);
            fscanf(fp,"%c", &aux);
            strcat(general.categoria[i].nombreCategoria,cadena);
        }
        printf("%s", general.categoria[i].nombreCategoria);
        fscanf(fp,"%d", &general.categoria[i].numPiezas);
        printf("%d", general.categoria[i].numPiezas);
        general.categoria[i].pieza = malloc(sizeof(Pieza));
        for (int j = 0; j < general.categoria[i].numPiezas; ++j) {
            printf("%d",j);
            general.categoria[i].pieza = realloc(general.categoria[i].pieza, sizeof(Pieza)*j+1);
            /*fscanf(fp,"%s",general.categoria[i].pieza[j].nombrePieza);
            fscanf(fp,"%c", &aux);
            while (aux != '\n'){
                fscanf(fp,"%s",cadena);
                fscanf(fp,"%c", &aux);
                strcat(general.categoria[i].pieza[j].nombrePieza,cadena);
            }*/
            printf("%s", general.categoria[i].pieza[j].nombrePieza);
            fscanf(fp, "%d", &general.categoria[i].pieza[j].velocidad);
            fscanf(fp, "%d", &general.categoria[i].pieza[j].aceleracion);
            fscanf(fp, "%d", &general.categoria[i].pieza[j].consumo);
            fscanf(fp, "%d", &general.categoria[i].pieza[j].fiabilidad);
        }
    }
    printf("WHAT THE FUCK");
    fclose(fp);
    return general;
}

General lecturaGPs(char *argv, General general){
    return general;
}

General lecturaCorredores(char *argv, General general){
    return general;
}

General lecturaBase(char *argv, General general){
    return general;
}