//
// Created by Alejandro on 05/03/2020.
//

#include "grafico.h"


void dibujaPanelConfiguracion(General general, Coche * coche){
    int nSortir = 0, x[general.numCategorias], y = 0;
    float z;
    ALLEGRO_BITMAP * boxes = NULL;
    coche->pieza = (Pieza*)malloc(sizeof(Pieza)*general.numCategorias+1);
    //Inicialitzem Allegro
    LS_allegro_init(800,600,"Tonto quien lo lea");
    boxes = al_load_bitmap("boxes.png");
    //al_draw_bitmap(boxes,0,0,0);
    al_draw_scaled_bitmap(boxes, 0, 0, 400, 600, 0, 0 , 400, 600, 0);
    //al_flip_display();
    //Bucle infinit del joc
    char cadena[50];
    while(!nSortir){
        z = 0;
        coche->pieza[y] = general.categoria[y].pieza[x[y]];
        //Escoltem el teclat esperant la tecla ESC
        if(LS_allegro_key_pressed(ALLEGRO_KEY_UP)){
            if(y > 0){
                y--;
            } else {
                y = y + general.numCategorias-1;
            }
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_DOWN)){
            if (y < general.numCategorias-1){
                y++;
            } else {
                y = y - general.numCategorias+1;
            }
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT)){
            if (x[y] < general.categoria[y].numPiezas-1){
                x[y]++;
            } else {
                x[y] = x[y] - general.categoria[y].numPiezas+1;
            }
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)){
            if (x[y] > 0){
                x[y]--;
            } else {
                x[y] = x[y] + general.categoria[y].numPiezas-1;
            }
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }
        //Donem l'ordre d'escriure el text de benvinguda
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),520,20,0,"%s", general.categoria[y].nombreCategoria);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,100,0,"%s", general.categoria[y].pieza[x[y]].nombrePieza);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,120,0,"VELOCIDAD: %d", general.categoria[y].pieza[x[y]].velocidad);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,140,0,"ACELERACION: %d", general.categoria[y].pieza[x[y]].aceleracion);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,160,0,"CONSUM: %d", general.categoria[y].pieza[x[y]].consumo);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,180,0,"FIABILIDAD: %d", general.categoria[y].pieza[x[y]].fiabilidad);
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),540,300,0,"CONFIGURACION ACTUAL");

        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,320,0,"%s: %s", general.categoria[0].nombreCategoria, coche->pieza[0].nombrePieza);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,340,0,"%s: %s", general.categoria[1].nombreCategoria, coche->pieza[1].nombrePieza);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,360,0,"%s: %s", general.categoria[2].nombreCategoria, coche->pieza[2].nombrePieza);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,380,0,"%s: %s", general.categoria[3].nombreCategoria, coche->pieza[3].nombrePieza);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,400,0,"%s: %s", general.categoria[4].nombreCategoria, coche->pieza[4].nombrePieza);
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540,420,0,"%s: %s", general.categoria[5].nombreCategoria, coche->pieza[5].nombrePieza);
        /*printf("%f",z);
        scanf("%s",cadena);*/
        /*for (int i = 0; i < general.numCategorias; ++i) {
            //al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),540, 320+z,0,"%s: %s", general.categoria[i].nombreCategoria, coche->pieza[i].nombrePieza);
            z += 20;
        }*/
        //Pintem la pantalla de la finestra gràfica
        LS_allegro_clear_and_paint(BLACK);
    }
    al_destroy_bitmap(boxes);
    //Tanquem la finestra gràfica
    LS_allegro_exit();
}