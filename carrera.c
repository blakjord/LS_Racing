/***********************************************
*
* @Proposito: Almacena las funciones de la carrera.
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#include "carrera.h"

/***********************************************
*
* @Finalidad: Funcion que te busca el circuito que tiene que hacer el usuario dependiendo de las veces que ya haya cursadoy te devuelve una copia.
* @Parametros:  in: head_ref = Lista de circuitos.
*               in: veces = numero de veces que el usuario ha cursado una carrera.
* @Retorno: Retorna un circuito.
*
************************************************/
struct _node * conseguirCircuito(struct _node** head_ref, int veces){
    struct _node * current;
    current = *head_ref;
    for (int i = 0; i < veces; ++i) {
        current = current->next;
    }
    return current;
}

/***********************************************
*
* @Finalidad: Funcion que simula un semaforo de carrera real, se dibuja repitiendo con bucles distintas figuras, las cuales a cada segundo vuelven a dibujarse,
*             pero con dos figuras rojas mas hasta que se acaban de iluminar todos los semaforos.
* @Parametros: No tiene parametros.
* @Retorno: No devuelve nada.
*
************************************************/
void semaforo(){
    int aux = 0;
    while (aux != 500) {
        for (int i = 0; i < 500; i += 100) {
            al_draw_filled_rectangle(200 + i, 130, 280 + i, 390, LS_allegro_get_color(BLACK));
        }
        for (int i = 0; i < 500; i += 100) {
            for (int j = 0; j < 240; j += 60) {
                al_draw_filled_circle(240 + i, 170 + j, 25, LS_allegro_get_color(GRAY));
            }
        }
        for (int i = 0; i < 100 + aux; i += 100) {
            al_draw_filled_circle(240 + i, 290, 25, LS_allegro_get_color(RED));
            al_draw_filled_circle(240 + i, 350, 25, LS_allegro_get_color(RED));
        }
        LS_allegro_clear_and_paint(WHITE);
        sleep(1);
        aux += 100;
    }
    sleep(1);
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de pintar toda la informacion de la carrera en la pantalla, lo unico que cambiara cada vez seran los segundos del timer
*             que haran que los coches se dibujen cada vez mas adelante y se pintaran por separado, y los stops que lleva hechos el usuario.
* @Parametros:  in: general = Struct con informacion de los ficheros
*               in: coche = Struct con informacion del piloto del usuario
*               in: numStops = maximo de paradas que tiene que hacer el usuario
*               in: stopsDone = numero de paradas que ha hecho el usuario
*               in: cotxe = imagen de nuesto vehiculo
*               in: tiempo = tiempo transcurrido durante la carrera
*               in: avance = pixeles que ha recorrido el piloto del usuario
*               in: tiempoTotal = array de los tiempos totales que recorrera el usuario
* @Retorno: No devuelve nada.
*
************************************************/
void pintarCarrera(General general, Coche coche, int numStops, int stopsDone, ALLEGRO_BITMAP * cotxe, int tiempo, float avance, const float * tiempoTotal){
    int plus = 0;
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(BLACK),30,25,0,"%d",coche.corredor.dorsal);
    al_draw_line(100,30,650,30,LS_allegro_get_color(BLACK),3);
    al_draw_scaled_bitmap(cotxe, 0,0,al_get_bitmap_width(cotxe),al_get_bitmap_height(cotxe),avance,0,60,60,0);
    for (int i = 0; i < 7; i++) {
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(BLACK),30,85+plus,0,"%d",general.corredor[i].dorsal);
        al_draw_line(100,90+plus,650,90+plus,LS_allegro_get_color(BLACK),3);
        al_draw_scaled_bitmap(cotxe, 0,0,al_get_bitmap_width(cotxe),al_get_bitmap_height(cotxe),90+((550/tiempoTotal[i+1])*(float)tiempo),60+plus,60,60,0);
        plus+=60;
    }
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
    al_draw_text(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,190,0,"VELOCIDAD");
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,210,0,"%d",general.base.velocidad);
    al_draw_text(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,230,0,"ACELERACION");
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,250,0,"%d",general.base.aceleracion);
    al_draw_text(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,270,0,"CONSUMO");
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,290,0,"%d",general.base.consumo);
    al_draw_text(LS_allegro_get_font(SMALL),LS_allegro_get_color(WHITE),720,310,0,"FIABILIDAD");
    al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),720,330,0,"%d",general.base.velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),715,410,0,"%d",tiempo);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),740,510,0,"STOPS: %d / %d", stopsDone, numStops);
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
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),270,150,0,"BIENVENIDO AL %s",circuito.nombreGP);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,220,0,"VELOCIDAD: %d",circuito.velocidadAdec);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,240,0,"ACELERACION: %d",circuito.aceleracionAdec);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,260,0,"CONSUMO: %d",circuito.consumoAdec);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,280,0,"FIABILIDAD: %d",circuito.fiabilidadAdec);
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),250,400,0,"PULSA R PARA COMENZAR LA CARRERA");
    LS_allegro_clear_and_paint(WHITE);
    while (!LS_allegro_key_pressed(ALLEGRO_KEY_R)){}
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de pintar la informacion que requiere la pantalla final de la carrera.
* @Parametros:  in: posicion = posicion en la que se ha quedado el piloto del usuario en la carrera
*               in: numbre = String con el nombre del piloto del usuario
* @Retorno: No devuelve nada.
*
************************************************/
void pintarPantallaFinal(int posicion , char * nombre){
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),270,150,0,"%s HA FINALIZADO ",nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),330,200,0,"EN LA POSICION %d",posicion);
    al_draw_text(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),250,400,0,"PULSA ENTER PARA VOLVER AL MENU");
    al_flip_display();
    while (!LS_allegro_key_pressed(ALLEGRO_KEY_ENTER)){}
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de calcular el tiempo total de cada jugador y el numero de pinStops que tiene que hacer.
* @Parametros:  in: general = Struct con informacion de los ficheros
*               in: coche = Struct con informacion del piloto del usuario
*               in: circuito = Struct con informacion del circuito.
*               in: numStops = maximo de paradas que tiene que hacer el usuario
*               in: tiempoTotal = array de los tiempos totales que recorrera el usuario
* @Retorno: No devuelve nada.
*
************************************************/
void calculosCarrera(General general, Coche coche, struct _node circuito, float * tiempoTotal, int * numStops){
    float aux, habilidad;
    //Calculo del piloto del usuario
    aux = (float)abs(circuito.velocidadAdec - general.base.velocidad);
    aux += (float)abs(circuito.aceleracionAdec - general.base.aceleracion);
    aux += (float)abs(circuito.consumoAdec - general.base.consumo);
    aux += (float)abs(circuito.fiabilidadAdec - general.base.fiabilidad);
    tiempoTotal[0] = circuito.tiempoBase + aux;
    numStops[0] = circuito.numeroPinStop;
    if (general.base.consumo < circuito.consumoAdec){
        numStops[0]++;
    } else if (general.base.consumo > circuito.consumoAdec){
        numStops[0]--;
    }
    habilidad = (((float)(coche.corredor.reflejos + coche.corredor.condicionFisica + coche.corredor.temperamento + coche.corredor.gestNeumaticos))/4)/2;
    tiempoTotal[0] -= habilidad;
    //Calculo de los pilotos bots
    for (int i = 0; i < 7; ++i) {
        aux = (float)abs(circuito.velocidadAdec - general.corredor[i].velocidad);
        aux += (float)abs(circuito.aceleracionAdec - general.corredor[i].aceleracion);
        aux += (float)abs(circuito.consumoAdec - general.corredor[i].consumo);
        aux += (float)abs(circuito.fiabilidadAdec - general.corredor[i].fiabilidad);
        tiempoTotal[i+1] = circuito.tiempoBase + aux;
        numStops[i+1] = circuito.numeroPinStop;
        if (general.corredor[i].consumo < circuito.consumoAdec){
            numStops[i+1]++;
        } else if (general.corredor[i].consumo > circuito.consumoAdec){
            numStops[i+1]--;
        }
        tiempoTotal[i+1] += (float)(numStops[i+1] * circuito.tiempoPinStop);
        habilidad = (((float)(general.corredor[i].reflejos + general.corredor[i].condicionFisica + general.corredor[i].temperamento + general.corredor[i].gestNeumaticos))/4)/2;
        tiempoTotal[i+1] -= habilidad;
    }
}

/***********************************************
*
* @Finalidad: Funcion que contiene toda la logica en la que sucede la carrera, la cual tiene un timer con el cual hacemos que a cada segundo que pase llame a
*             la funcion de pintar la carrera, y que si recibe la tecla R o P hagan su funcion tod0 gracias a distintos boleanos que crean la logica.
* @Parametros:  in: general = Struct con informacion de los ficheros.
*               in: coche = Struct con informacion del piloto del usuario.
*               in: circuito = Struct con informacion del circuito.
*               in: timer = temporizador de la carrera.
*               in: tiempoTotal = array de los tiempos totales que recorrera el usuario.
*               in: numStops = maximo de paradas que tiene que hacer el usuario.
* @Retorno: No devuelve nada.
*
************************************************/
void logicaCarrera(General general, Coche coche, struct _node circuito, ALLEGRO_BITMAP * cotxe, ALLEGRO_TIMER * timer, float * tiempoTotal, int numStops){
    bool running = true, pintar = true, radio = false, cuenta = true;
    int auxt = al_get_timer_count(timer), ganador, tiempoStop = -1, stopsDone = 0, miTimer= 0;
    float posicion = 0, longitudCarrera = 550, empezar = 90, tiempoTotalP = tiempoTotal[0];
    al_start_timer(timer);
    while (running){
        if (al_get_timer_count(timer) != auxt) {
            pintar = true;
            auxt = al_get_timer_count(timer);
            if (cuenta == true) {
                miTimer++;
            }
        } else if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            radio = true;
        } else if (LS_allegro_key_pressed(ALLEGRO_KEY_P)){
            if (stopsDone < numStops && cuenta == true){
                if(radio == true){
                    stopsDone++;
                }
                tiempoTotal[0] += (float)(numStops * circuito.tiempoPinStop);
                radio = false;
                cuenta = false;
                empezar = posicion;
                longitudCarrera = 550 - posicion;
                miTimer = 0;
                tiempoStop = (int)al_get_timer_count(timer)+circuito.tiempoPinStop;
            }
        }
        if (tiempoStop == (int)al_get_timer_count(timer)){
            cuenta = true;
        }
        if (pintar) {
            posicion = empezar+((longitudCarrera/tiempoTotalP)*(float)miTimer);
            pintarCarrera(general, coche,numStops, stopsDone, cotxe, al_get_timer_count(timer), posicion, tiempoTotal);
            pintar = false;
        }
        for (ganador = 0; ganador < 8; ++ganador) {
            if (al_get_timer_count(timer) == (int)tiempoTotal[ganador]){
                running = false;
            }
        }
    }
    if(stopsDone < numStops){
        tiempoTotal[0] += (float)(5*circuito.tiempoPinStop);
    }
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de ejecutar todos los procedimientos necesarios para la opcion 3 (carrera) del menu principal.
* @Parametros:  in: general = Struct con informacion de los ficheros.
*               in: coche = Struct con informacion del piloto del usuario.
*               in: veces = numero de veces que el usuario ha cursado una carrera.
* @Retorno: No devuelve nada.
*
************************************************/
void carrera(General general, Coche coche, int veces){
    struct _node * circuito;
    float tiempoTotal[8];
    int numStops[8], posicion = 1;
    circuito = conseguirCircuito(&general.listaGP,veces);
    LS_allegro_init(anchoPantalla,altoPantalla,"Carrera");
    ALLEGRO_BITMAP * cotxe = NULL;
    ALLEGRO_TIMER * timer = al_create_timer(1);
    cotxe = al_load_bitmap("cotxe.png");
    pintarPantallaInicio(*circuito);
    semaforo();
    calculosCarrera(general, coche, *circuito, tiempoTotal, numStops);
    logicaCarrera(general, coche, *circuito, cotxe, timer, tiempoTotal,numStops[0]);
    for (int i = 1; i < 8; ++i) {
        if (tiempoTotal[i]<tiempoTotal[0]){
            posicion++;
        }
    }
    pintarPantallaFinal(posicion,coche.corredor.nombreCorredor);
    al_destroy_bitmap(cotxe);
    LS_allegro_exit();
    free(circuito);
}