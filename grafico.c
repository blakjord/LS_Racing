/***********************************************
*
* @Proposito: Almacena las funciones sobre el apartado grafico de tod0 el proyecto.
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
    //Fotos
    al_draw_scaled_bitmap(boxes, 0,0,(float)al_get_bitmap_width(boxes), (float)al_get_bitmap_height(boxes),0,0,600,550,0);
    if (y == 0){
        al_draw_scaled_bitmap(neumaticos, 0,0,(float)al_get_bitmap_width(neumaticos), (float)al_get_bitmap_height(neumaticos),650,120,60,60,0);
    } else if (y > 0 && y < 4){
        al_draw_scaled_bitmap(cotxe, 0,0,(float)al_get_bitmap_width(cotxe), (float)al_get_bitmap_height(cotxe),650,120,60,60,0);
    } else if (y == 4){
        al_draw_scaled_bitmap(gasolina, 0,0,(float)al_get_bitmap_width(gasolina), (float)al_get_bitmap_height(gasolina),650,120,60,60,0);
    } else if (y == 5){
        al_draw_scaled_bitmap(motor, 0,0,(float)al_get_bitmap_width(motor), (float)al_get_bitmap_height(motor),650,120,60,60,0);
    }
    al_draw_filled_triangle(680,80,655,95,705,95,LS_allegro_get_color(WHITE));      //arriba
    al_draw_filled_rectangle(670,95,690,115,LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(680,220,655,205,705,205,LS_allegro_get_color(WHITE));   //abajo
    al_draw_filled_rectangle(670,185,690,205,LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(610,150,625,125,625,175,LS_allegro_get_color(WHITE));   //izquierda
    al_draw_filled_rectangle(625,140,645,160,LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(750,150,735,125,735,175,LS_allegro_get_color(WHITE));   //derecha
    al_draw_filled_rectangle(715,140,735,160,LS_allegro_get_color(WHITE));
    //Texto
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
* @Finalidad: Funcion que se encarga de pintar toda la informacion de la carrera en la pantalla, lo unico que cambiara cada vez seran los segundos del timer
*             que haran que los coches se dibujen cada vez mas adelante y se pintaran por separado, y los stops que lleva hechos el usuario.
* @Parametros:  in: general = Struct con informacion de los ficheros.
*               in: coche = Struct con informacion del piloto del usuario.
*               in: numStops = maximo de paradas que tiene que hacer el usuario.
*               in: stopsDone = numero de paradas que ha hecho el usuario.
*               in: cotxe = imagen de nuesto vehiculo.
*               in: logo = foto de nuestro logo para la carrera.
*               in: tiempo = tiempo transcurrido durante la carrera.
*               in: avance = pixeles que ha recorrido el piloto del usuario.
*               in: tiempoTotal = Array de floats que almacena todos los tiempos de todos los pilotos en la carrera.
* @Retorno: No devuelve nada.
*
************************************************/
void pintarCarrera(General general, Coche coche, int numStops, int stopsDone, ALLEGRO_BITMAP * cotxe, ALLEGRO_BITMAP * logo, float tiempo, float tiempoP, const float * tiempoTotal){
    int plus = 0;
    //Carrera
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(BLACK),30,25,0,"%d", coche.corredor.dorsal);
    al_draw_line(100,30,650,30,LS_allegro_get_color(BLACK),3);
    al_draw_scaled_bitmap(cotxe, 0,0, (float)al_get_bitmap_width(cotxe), (float)al_get_bitmap_height(cotxe), 90+((550/tiempoTotal[0])*(tiempoP/10)),0,60,60,0);
    for (int i = 0; i < 7; i++) {
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(BLACK),30,85+plus,0,"%d", general.corredor[i].dorsal);
        al_draw_line(100,90+plus,650,90+plus,LS_allegro_get_color(BLACK),3);
        if (90+((550/tiempoTotal[i+1])*(tiempo/10)) < 640){
            al_draw_scaled_bitmap(cotxe, 0,0, (float)al_get_bitmap_width(cotxe), (float)al_get_bitmap_height(cotxe),90+((550/tiempoTotal[i+1])*(tiempo/10)),60+plus,60,60,0);
        } else {
            al_draw_scaled_bitmap(cotxe, 0,0, (float)al_get_bitmap_width(cotxe), (float)al_get_bitmap_height(cotxe),640,60+plus,60,60,0);
        }
        plus+=60;
    }
    //Texto
    al_draw_filled_rectangle(0,500,700,555,LS_allegro_get_color(BLACK));
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),35,520,0,"RADIO (R)");
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),540,520,0,"PIT STOP (P)");
    al_draw_filled_rectangle(700,0,900,555,LS_allegro_get_color(BLACK));
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),710,15,0,"PILOTO");
    al_draw_text(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,40,0,"NOMBRE");
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,60,0,"%s",coche.corredor.nombreCorredor);
    al_draw_text(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,80,0,"ESCUDERIA");
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,100,0,"%s",coche.corredor.escuderia);
    al_draw_text(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,120,0,"DORSAL");
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,140,0,"%d",coche.corredor.dorsal);
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),710,170,0,"COCHE");
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,190,0,"%s", vel);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,210,0,"%d", general.base.velocidad);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,230,0,"%s", acel);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,250,0,"%d", general.base.aceleracion);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,270,0,"%s", cons);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,290,0,"%d", general.base.consumo);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,310,0,"%s", fiab);
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,330,0,"%d", general.base.fiabilidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),715,410,0,"%.0f", tiempo/10);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),740,510,0,"STOPS: %d / %d", stopsDone, numStops);
    al_draw_scaled_bitmap(logo, 0,0,(float)al_get_bitmap_width(logo), (float)al_get_bitmap_height(logo),745,360,140,110,0);
    LS_allegro_clear_and_paint(WHITE);
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de pintar la informacion que requiere la pantalla de inicio de la carrera.
* @Parametros:  in: circuito = Struct con informacion del circuito.
* @Retorno: No devuelve nada.
*
************************************************/
void pintarPantallaInicio(struct _node circuito){
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),270,150,0,"BIENVENIDO AL %s", circuito.nombreGP);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,220,0,"%s: %d", vel, circuito.velocidadAdec);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,240,0,"%s: %d", acel, circuito.aceleracionAdec);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,260,0,"%s: %d", cons, circuito.consumoAdec);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,280,0,"%s: %d", fiab, circuito.fiabilidadAdec);
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),250,400,0,"PULSA R PARA COMENZAR LA CARRERA");
    LS_allegro_clear_and_paint(WHITE);
    while (!LS_allegro_key_pressed(ALLEGRO_KEY_R)){}
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de pintar la informacion que requiere la pantalla final de la carrera, si ha habido una penalizacion lo avisa para que el usuario entienda
*             porque no ha podido ganar aunque se viera visualmente a el llegando el primero.
* @Parametros:  in: posicion = posicion en la que se ha quedado el piloto del usuario en la carrera
*               in: numbre = String con el nombre del piloto del usuario
* @Retorno: No devuelve nada.
*
************************************************/
void pintarPantallaFinal(int posicion , char * nombre, int penalizacion){
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),270,150,0,"%s HA FINALIZADO ",nombre);
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,200,0,"EN LA POSICION");
    al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),505,195,0,"%d",posicion);
    if (penalizacion == 1){
        al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),170,250,0,"(Tiempo penalizado por no hacer todas las paradas)");
    }
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),250,400,0,"PULSA ENTER PARA VOLVER AL MENU");
    al_flip_display();
    while (!LS_allegro_key_pressed(ALLEGRO_KEY_ENTER)){}
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de pintar la informacion que requiere la pantalla de clasificacion, imprimiendo promero el podio de colores distintos
*             y luego el resto de pilotos.
* @Parametros:  in: clasificacion = lista bidireccional que tiene la informacion del resultado de la carrera a pintar.
*               in: logo = imagen de nuestro logo.
* @Retorno: No devuelve nada.
*
************************************************/
void pintarClasificacion(Clasificacion clasificacion, ALLEGRO_BITMAP * logo){
    float aux = 0;
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),240,10,0,"Clasificacion de %s",clasificacion.pdi->carrera.nombre);
    //Podio
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),220,50,0,"1. %s (%.0f s) - %d punts",
                  clasificacion.pdi->carrera.pos[0].nombre, clasificacion.pdi->carrera.pos[0].tiempoTotal, clasificacion.pdi->carrera.pos[0].puntos);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(GRAY),220,70,0,"2. %s (%.0f s) - %d punts",
                  clasificacion.pdi->carrera.pos[1].nombre, clasificacion.pdi->carrera.pos[1].tiempoTotal, clasificacion.pdi->carrera.pos[1].puntos);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(RED),220,90,0,"3. %s (%.0f s) - %d punts",
                  clasificacion.pdi->carrera.pos[2].nombre, clasificacion.pdi->carrera.pos[2].tiempoTotal, clasificacion.pdi->carrera.pos[2].puntos);
    //Otras posiciones
    for (int i = 3; i < MAXPilotos; ++i) {
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),220,130+aux,0,"%d. %s (%.0f s) - %d punts",
                      i+1, clasificacion.pdi->carrera.pos[i].nombre, clasificacion.pdi->carrera.pos[i].tiempoTotal, clasificacion.pdi->carrera.pos[i].puntos);
        aux+=20;
    }
    al_draw_scaled_bitmap(logo, 0,0,(float)al_get_bitmap_width(logo), (float)al_get_bitmap_height(logo),250,240,400,300,0);
    LS_allegro_clear_and_paint(BLACK);
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de pintar la informacion que requiere la pantalla de clasificacion final (ya que es distinta a la normal),
*             imprimiendo promero el podio de colores distintos y luego el resto de pilotos.
* @Parametros:  in: clasificacion = lista bidireccional que tiene la informacion del resultado de la carrera a pintar.
* @Retorno: No devuelve nada.
*
************************************************/
void pintarClasificacionFinal(Clasificacion clasificacion, ALLEGRO_BITMAP * logo){
    float aux = 0;
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),240,10,0,"Clasificacion final de la temporada");
    //Podio
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),220,50,0,"1. %s (#%.0f) - %d punts",
                  clasificacion.pdi->carrera.pos[0].nombre, clasificacion.pdi->carrera.pos[0].tiempoTotal, clasificacion.pdi->carrera.pos[0].puntos);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(GRAY),220,70,0,"2. %s (#%.0f) - %d punts",
                  clasificacion.pdi->carrera.pos[1].nombre, clasificacion.pdi->carrera.pos[1].tiempoTotal, clasificacion.pdi->carrera.pos[1].puntos);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(RED),220,90,0,"3. %s (#%.0f) - %d punts",
                  clasificacion.pdi->carrera.pos[2].nombre, clasificacion.pdi->carrera.pos[2].tiempoTotal, clasificacion.pdi->carrera.pos[2].puntos);
    //Otras posiciones
    for (int i = 3; i < MAXPilotos; ++i) {
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),220,130+aux,0,"%d. %s (#%.0f) - %d punts",
                      i+1, clasificacion.pdi->carrera.pos[i].nombre, clasificacion.pdi->carrera.pos[i].tiempoTotal, clasificacion.pdi->carrera.pos[i].puntos);
        aux+=20;
    }
    al_draw_scaled_bitmap(logo, 0,0,(float)al_get_bitmap_width(logo), (float)al_get_bitmap_height(logo),250,240,400,300,0);
    LS_allegro_clear_and_paint(BLACK);
}