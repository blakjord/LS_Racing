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
* @Finalidad: Funcion que se encarga de calcular el tiempo total de cada jugador y el numero de pinStops que tiene que hacer.
* @Parametros:  in: general = struct con informacion de los ficheros.
*               in: coche = struct con informacion del piloto del usuario.
*               in: circuito = struct con informacion del circuito.
*               in: tiempoTotal = array de floats que almacena todos los tiempos de todos los pilotos en la carrera.
*               in: numStops = maximo de paradas que tiene que hacer el usuario.
* @Retorno: No devuelve nada.
*
************************************************/
void calculosCarrera(General general, Coche coche, struct _node circuito, float * tiempoTotal, int * numStops){
    float aux;
    //Calculo del piloto del usuario
    aux = (float)abs(circuito.velocidadAdec - general.base.velocidad);
    aux += (float)abs(circuito.aceleracionAdec - general.base.aceleracion);
    aux += (float)abs(circuito.consumoAdec - general.base.consumo);
    aux += (float)abs(circuito.fiabilidadAdec - general.base.fiabilidad);
    tiempoTotal[0] = circuito.tiempoBase + aux;
    numStops[0] = circuito.numeroPinStop;
    if (general.base.consumo < circuito.consumoAdec){
        numStops[0]--;
    } else if (general.base.consumo > circuito.consumoAdec){
        numStops[0]++;
    }
    tiempoTotal[0] -= (((float)(coche.corredor.reflejos + coche.corredor.condicionFisica + coche.corredor.temperamento + coche.corredor.gestNeumaticos))/4)/2;
    //Calculo de los pilotos bots
    for (int i = 0; i < MAXPilotos-1; ++i) {
        aux = (float)abs(circuito.velocidadAdec - general.corredor[i].velocidad);
        aux += (float)abs(circuito.aceleracionAdec - general.corredor[i].aceleracion);
        aux += (float)abs(circuito.consumoAdec - general.corredor[i].consumo);
        aux += (float)abs(circuito.fiabilidadAdec - general.corredor[i].fiabilidad);
        tiempoTotal[i+1] = circuito.tiempoBase + aux;
        numStops[i+1] = circuito.numeroPinStop;
        if (general.corredor[i].consumo < circuito.consumoAdec){
            numStops[i+1]--;
        } else if (general.corredor[i].consumo > circuito.consumoAdec){
            numStops[i+1]++;
        }
        tiempoTotal[i+1] += (float)(numStops[i+1] * circuito.tiempoPinStop);
        tiempoTotal[i+1] -= (((float)(general.corredor[i].reflejos + general.corredor[i].condicionFisica + general.corredor[i].temperamento + general.corredor[i].gestNeumaticos))/4)/2;
    }
}

/***********************************************
*
* @Finalidad: Funcion que contiene toda la logica en la que sucede la carrera en bucle, la cual tiene dos timers, uno que controla el tiempo en general
*             y el otro el tiempo del jugador, si recibe la tecla R o P haran su funcion tod0 gracias a distintos boleanos que crean la logica.
* @Parametros:  in: general = struct con informacion de los ficheros.
*               in: coche = struct con informacion del piloto del usuario.
*               in: circuito = struct con informacion del circuito.
*               in: cotxe = foto de nuestro vehiculo que correra la carrera.
*               in: logo = foto de nuestro logo para la carrera.
*               in: timer = temporizador de la carrera.
 *               in: timerP = temporizador del piloto.
*               in: tiempoTotal = array de floats que almacena todos los tiempos de todos los pilotos en la carrera.
*               in: numStops = maximo de paradas que tiene que hacer el usuario.
* @Retorno: Devuelve el numero de pinStops que ha efectuado el usuario durante la carrera.
*
************************************************/
int logicaCarrera(General general, Coche coche, struct _node circuito, ALLEGRO_BITMAP * cotxe, ALLEGRO_BITMAP * logo, ALLEGRO_TIMER * timer, ALLEGRO_TIMER * timerP, float * tiempoTotal, int numStops){
    bool running = true, radio = false, cuenta = true;
    int stopsRadioDone = 0, stopsAllDone = 0;
    float tiempoStop = -1;
    //Iniciamos los timers.
    al_start_timer(timerP);
    al_start_timer(timer);
    while (running){
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            radio = true;
        } else if (LS_allegro_key_pressed(ALLEGRO_KEY_P)){
            if (stopsRadioDone < numStops && cuenta == true){
                //Si se ha llamado a radio contara como stop hecho si no simplemente hara el stop sin contar.
                if(radio == true){
                    stopsRadioDone++;
                    radio = false;
                }
                stopsAllDone++;
                cuenta = false;
                tiempoStop = ((float)al_get_timer_count(timer)/10)+(float)circuito.tiempoPinStop;
                al_stop_timer(timerP);
            }
        }
        //Cuando el tiempo del pin stop haya finalizado el usuario puede volver a moverse.
        if ((int)tiempoStop == al_get_timer_count(timer)/10 && cuenta == false){
            cuenta = true;
            al_start_timer(timerP);
        }
        //Pintamos toda la carrera.
        pintarCarrera(general, coche, numStops, stopsRadioDone, cotxe, logo, al_get_timer_count(timer), al_get_timer_count(timerP), tiempoTotal);
        //Cuando el timer llegue al tiempo total del usuario que tiene que tardar acaba la carrera.
        if ((al_get_timer_count(timerP)/10) == (int)tiempoTotal[0]){
            running = false;
            pintarCarrera(general, coche, numStops, stopsRadioDone, cotxe, logo, al_get_timer_count(timer), al_get_timer_count(timerP), tiempoTotal);
            tiempoTotal[0] += (float)(stopsAllDone * circuito.tiempoPinStop);
        }
    }
    return stopsRadioDone;
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de ejecutar todos los procedimientos necesarios para la opcion 3 (carrera) del menu principal, usando las herramientas
*             de allegro para generar la pantalla, la musica y el temporizador que usara.
* @Parametros:  in: general = struct con informacion de los ficheros.
*               in: coche = struct con informacion del piloto del usuario.
*               in: circuito = nodo de circuito de la lista de GP's el cual tendra la informacion del circuito a correr.
*               in: clasificacion = lista bidireccional que almacena la informacion de anteriores circuitos recorridos.
* @Retorno: No devuelve nada.
*
************************************************/
void carrera(General general, Coche coche, struct _node* circuito, Clasificacion * clasificacion){
    float tiempoTotal[MAXPilotos];
    int numStops[MAXPilotos], posicion, stopsDone, penalizacion = 0;
    LS_allegro_init(anchoPantalla,altoPantalla,"Carrera");
    //Imagenes, temporizadores y musica de allegro
    ALLEGRO_BITMAP * cotxe = al_load_bitmap("cotxe.png");
    ALLEGRO_BITMAP * logo = al_load_bitmap("logo.png");
    ALLEGRO_TIMER * timer = al_create_timer(0.1);
    ALLEGRO_TIMER * timerP = al_create_timer(0.1);
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
    ALLEGRO_SAMPLE * sample = al_load_sample("Naruto_Soundtrack.ogg");
    pintarPantallaInicio(*circuito);
    semaforo();
    al_play_sample(sample, 0.2, 0, 1, ALLEGRO_PLAYMODE_LOOP,NULL);
    calculosCarrera(general, coche, *circuito, tiempoTotal, numStops);
    stopsDone = logicaCarrera(general, coche, *circuito, cotxe, logo, timer, timerP, tiempoTotal, numStops[0]);
    //Si no has hecho suficientes pin stops se te penaliza
    if (stopsDone < numStops[0]){
        tiempoTotal[0] += (float)circuito->tiempoPinStop*5;
        penalizacion = 1;
    }
    posicion = calcularPosicion(tiempoTotal, 0);
    pintarPantallaFinal(posicion, coche.corredor.nombreCorredor, penalizacion);
    al_destroy_sample(sample);
    al_destroy_bitmap(cotxe);
    al_destroy_bitmap(logo);
    al_uninstall_audio();
    LS_allegro_exit();
    //Insertaremos los resultados de la carrera en la clasificacion
    insertarNodoCarrera(coche.corredor, general.corredor, circuito->nombreGP, tiempoTotal, clasificacion, 0);
}