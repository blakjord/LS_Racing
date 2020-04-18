/***********************************************
*
* @Proposito: Almacena las funciones sobre el apartado grafico de la configuracion de nuestro piloto.
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#include "grafico.h"

/***********************************************
*
* @Finalidad: Funcion que se encarga de pintar tod0 el apartado grafico de la libreria allegro para que se le pueda llamar en cualquier momento.
* @Parametros:  in: general = Struct con informacion de los ficheros.
*               in: coche = Struct con informacion del piloto del usuario.
*               in: x = numero que corresponde a la pieza de la categoria actual
*               in: y = numero que corresponde a la categoria de piezas actual.
*               in: boxes = imagen de los boxes
*               in: neumaticos = imagen de unos neumaticos.
*               in: coche = imagen del coche.
*               in: gasolina = imagen de la manguera de la gasolina.
*               in: motor = imagen del motor.
* @Retorno: No devuelve nada.
*
************************************************/
void pintaConfig(General general, Coche * coche, int x, int y, ALLEGRO_BITMAP * boxes, ALLEGRO_BITMAP * neumaticos, ALLEGRO_BITMAP * cotxe, ALLEGRO_BITMAP * gasolina, ALLEGRO_BITMAP * motor){
    float z = 0;
    al_draw_scaled_bitmap(boxes, 0,0,al_get_bitmap_width(boxes),al_get_bitmap_height(boxes),0,0,600,550,0);
    if (y == 0){
        al_draw_scaled_bitmap(neumaticos, 0,0,al_get_bitmap_width(neumaticos),al_get_bitmap_height(neumaticos),650,120,60,60,0);
    } else if (y > 0 && y < 4){
        al_draw_scaled_bitmap(cotxe, 0,0,al_get_bitmap_width(cotxe),al_get_bitmap_height(cotxe),650,120,60,60,0);
    } else if (y == 4){
        al_draw_scaled_bitmap(gasolina, 0,0,al_get_bitmap_width(gasolina),al_get_bitmap_height(gasolina),650,120,60,60,0);
    } else if (y == 5){
        al_draw_scaled_bitmap(motor, 0,0,al_get_bitmap_width(motor),al_get_bitmap_height(motor),650,120,60,60,0);
    }
    al_draw_filled_triangle(680,80,655,95,705,95,LS_allegro_get_color(WHITE));      //arriba
    al_draw_filled_rectangle(670,95,690,115,LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(680,220,655,205,705,205,LS_allegro_get_color(WHITE));   //abajo
    al_draw_filled_rectangle(670,185,690,205,LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(610,150,625,125,625,175,LS_allegro_get_color(WHITE));   //izquierda
    al_draw_filled_rectangle(625,140,645,160,LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(750,150,735,125,735,175,LS_allegro_get_color(WHITE));   //derecha
    al_draw_filled_rectangle(715,140,735,160,LS_allegro_get_color(WHITE));
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),670,20,0,"%s", general.categoria[y].nombreCategoria);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),770,100,0,"%s", general.categoria[y].pieza[x].nombrePieza);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),770,120,0,"VELOCIDAD: %d", general.categoria[y].pieza[x].velocidad);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),770,140,0,"ACELERACION: %d", general.categoria[y].pieza[x].aceleracion);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),770,160,0,"CONSUMO: %d", general.categoria[y].pieza[x].consumo);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),770,180,0,"FIABILIDAD: %d", general.categoria[y].pieza[x].fiabilidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),620,300,0,"CONFIGURACION ACTUAL");
    for (int i = 0; i < general.numCategorias; ++i) {
        al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),620, 320+z,0,"%s: %s", general.categoria[i].nombreCategoria, coche->pieza[i].nombrePieza);
        z += 15;
    }
    LS_allegro_clear_and_paint(BLACK);
}

/***********************************************
*
* @Finalidad:   Funcion del apartado grafico de configuracio del coche el cual te llenara el struct de piezas que tiene dependiendo de las que escoja el usuario
*               medienta las flechas de teclado gracias a la variable eje Y que guardara la categoria en la que estemos y el array de variables X que guardara
*               la pieza que el usuario se haya quedado en el la categoria que estuviera (x[y]), antes de eso se da el espacio al struct de piezas y se cargan
*               las imagenes las quales son variables ALLEGRO_BITMAP, cada cambio de ejes X e Y se ejecutara la funcion de pintar para actualizar los datos con
*               los ejes cmbiados, al final de tod0 se destruiran las variables de las imagenes para liberar la memoria.
* @Parametros:  in: general = Struct con informacion de los ficheros.
*               in: coche = Struct con informacion del piloto del usuario.
* @Retorno: No devuelve nada.
*
************************************************/
void dibujaPanelConfiguracion(General general, Coche * coche){
    int nSortir = 0, x[general.numCategorias], y = 0;
    for (int i = 0; i < general.numCategorias; ++i) {
        x[i] = 0;
    }
    coche->pieza = (Pieza*)malloc(sizeof(Pieza)*(general.numCategorias));
    //Inicializamos Allegro
    LS_allegro_init(anchoPantalla,altoPantalla,"Configuración Pantalla");
    ALLEGRO_BITMAP * boxes = NULL;
    boxes = al_load_bitmap("boxes.png");
    ALLEGRO_BITMAP * cotxe = NULL;
    cotxe = al_load_bitmap("cotxe.png");
    ALLEGRO_BITMAP * gasolina = NULL;
    gasolina = al_load_bitmap("gasolina.png");
    ALLEGRO_BITMAP * motor = NULL;
    motor = al_load_bitmap("motor.png");
    ALLEGRO_BITMAP * neumaticos = NULL;
    neumaticos = al_load_bitmap("neumaticos.png");
    pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
    while(!nSortir){
        if(LS_allegro_key_pressed(ALLEGRO_KEY_UP)){
            if(y > 0){
                y--;
            } else {
                y = y + general.numCategorias-1;
            }
            pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_DOWN)){
            if (y < general.numCategorias-1){
                y++;
            } else {
                y = y - general.numCategorias+1;
            }
            pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT)){
            if (x[y] < general.categoria[y].numPiezas-1){
                x[y]++;
            } else {
                x[y] = x[y] - general.categoria[y].numPiezas+1;
            }
            pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)){
            if (x[y] > 0){
                x[y]--;
            } else {
                x[y] = x[y] + general.categoria[y].numPiezas-1;
            }
            pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }
        coche->pieza[y] = general.categoria[y].pieza[x[y]];
    }
    for (int j = 0; j < general.numCategorias; ++j) {
        if (strlen(coche->pieza[j].nombrePieza) == 0){
            coche->pieza[j] = general.categoria[j].pieza[0];
        }
    }
    al_destroy_bitmap(boxes);
    al_destroy_bitmap(neumaticos);
    al_destroy_bitmap(cotxe);
    al_destroy_bitmap(gasolina);
    al_destroy_bitmap(motor);
    //Tanquem la finestra gràfica
    LS_allegro_exit();
}

