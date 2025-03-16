/***********************************************
*
* @Proposito: Almacena las funciones sobre la clasificacion y la generacion de logs.
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#include "clasificacion.h"

/***********************************************
*
* @Finalidad: Funcion que te muestra las clasificaciones de los pilotos en carreras ya cursadas, se queda en un bucle infinito mostrando la siguiente
*             clasificacion o la anterior dependiendo el boton al que le de el usuario.
* @Parametros:  in: clasificacion = lista bidireccional donde esta toda la informacion a mostrar.
*               in: acabada = entero que funciona de boleano para indicar si ha terminado la temporada ya (1) o no (0).
* @Retorno: No devuelve nada.
*
************************************************/
void clasificacionGeneral(Clasificacion clasificacion, int acabada){
    ALLEGRO_BITMAP * logo = NULL;
    LS_allegro_init(anchoPantalla,altoPantalla,"Clasificacion");
    logo = al_load_bitmap("logo.png");
    vesInicioClasi(&clasificacion);
    selectionSort(&clasificacion, 0);
    pintarClasificacion(clasificacion, logo);
    while (!LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
        if(LS_allegro_key_pressed(ALLEGRO_KEY_A)){
            //Si el nodo pdi esta al principio no entrara en esta condicion
            if (compararNodo1(clasificacion)){
                retrocedeClasi(&clasificacion);
                pintarClasificacion(clasificacion, logo);
            }
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_D)){
            //Si el nodo pdi esta al final (sin contar la clasificacion final) y esta acabada la temporada no entrara en esta condicion
            if (compararNodo2(clasificacion) && acabada == 1){
                avanzaClasi(&clasificacion);
                selectionSort(&clasificacion, 1);
                pintarClasificacionFinal(clasificacion, logo);
            //Si el nodo pdi esta al final no entrara en esta condicion
            } else if (compararNodo3(clasificacion)) {
                avanzaClasi(&clasificacion);
                selectionSort(&clasificacion, 0);
                pintarClasificacion(clasificacion, logo);
            }
        }
    }
    al_destroy_bitmap(logo);
    LS_allegro_exit();
}

/***********************************************
*
* @Finalidad: Funcion que te tiene que generar un fichero txt con toda la informacion de la lista de clasificacion.
* @Parametros:  in: clasificacion = lista bidireccional donde esta toda la informacion a mostrar en el log que generar.
* @Retorno: No devuelve nada.
*
************************************************/
void generarLogs(Clasificacion clasificacion){
    NodoCarrera aux;
    FILE * fp = fopen(NOMBRE_FICHERO, "w");
    if (fp == NULL) {
        printf("Error: Fichero inexistente.\n\n");
        exit(-1);
    }
    vesInicioClasi(&clasificacion);
    while (finalClasi(clasificacion) != 1){
        aux = consultaNodo(clasificacion);
        fprintf(fp, "Clasificacion del %s\n",aux.carrera.nombre);
        for (int i = 0; i < MAXPilotos; ++i) {
            fprintf(fp, "%d. %s amb %.0f segons. Punts: %d\n", i+1, aux.carrera.pos[i].nombre,
                    aux.carrera.pos[i].tiempoTotal, aux.carrera.pos[i].puntos);

        }
        avanzaClasi(&clasificacion);
    }
    fclose(fp);
}
