//
// Created by Alejandro on 05/03/2020.
//
#include "lista.h"

General GPLIST_create(General general) {
    //Dedicamos memoria al nodo fantasma "first" y "last"
    general.listaGp.first = (GP *) malloc(sizeof(GP));
    general.listaGp.last = (GP *) malloc(sizeof(GP));
    if (general.listaGp.first == NULL || general.listaGp.last == NULL) {
        printf("Error");
    } else {
        //Colocamos los nodos de forma ordenada
        general.listaGp.first->next = general.listaGp.last;
        general.listaGp.last->prev = general.listaGp.first;
        general.listaGp.first->prev = NULL;
        general.listaGp.last->next = NULL;
        general.listaGp.pdi = general.listaGp.first;
    }
    return general;
}

int GPLIST_insert(ListaGP *list, GP gp) {
    GP *n = (GP *) malloc(sizeof(GP));
    if (n == NULL){
        return 0;
    } else {
        //Enlazamos los nodos siguiente y anterior al nuevo nodo que queremos añadir
        n->posCalndario = gp.posCalndario;
        strcpy (n->nombreGP, gp.nombreGP);
        n->velocidadAdec = gp.velocidadAdec;
        n->aceleracionAdec = gp.aceleracionAdec;
        n->consumoAdec = gp.consumoAdec;
        n->fiabilidadAdec = gp.fiabilidadAdec;
        n->tiempoBase = gp.tiempoBase;
        n->tiempoPinStop = gp.tiempoPinStop;
        n->numeroPinStop = gp.numeroPinStop;
        n->next = list->pdi->next;
        n->prev = list->pdi;
        list->pdi->next = n;
        list->pdi = n;
        list->pdi->next->prev = list->pdi;
    }
    return 1;
}