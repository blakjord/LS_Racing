/***********************************************
*
* @Proposito: Almacena las funciones sobre la configuracion de nuestro piloto y su coche.
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#include "configuracion.h"

/***********************************************
*
* @Finalidad: Funcion de la opcion 1 del menu principal llamada configurar coche, la cual se encarga de llenarte el struct coche que se le pasa por referencia,
*             al usuario le iran preguntando por las variables que ha de rellenar, despues llamara a la funcion que llenara las piezas del coche.
* @Parametros:  in: general = Struct con informacion de los ficheros.
*               in: coche = Struct con informacion del piloto del usuario.
* @Retorno: No devuelve nada.
*
************************************************/
void configurarCoche(General general, Coche * coche){
    char cadena[MAXC], aux;
    //Pedimos nombre del piloto
    do{
        printf("Nombre del piloto? ");
        scanf("%s",coche->corredor.nombreCorredor);
        scanf("%c", &aux);
        while (aux != '\n'){
            scanf("%s",cadena);
            scanf("%c", &aux);
            strcat(coche->corredor.nombreCorredor," ");
            strcat(coche->corredor.nombreCorredor,cadena);
        }
        if (strlen(coche->corredor.nombreCorredor) > 25){
            printf("\nError, nombre de usuario no puede ser de mas de 25 caracteres\n\n");
        }
    } while (strlen(coche->corredor.nombreCorredor) > 25);
    //Pedimos escuderia
    do{
        printf("Nombre de la escuderia? ");
        scanf("%s",coche->corredor.escuderia);
        scanf("%c", &aux);
        while (aux != '\n'){
            scanf("%s",cadena);
            scanf("%c", &aux);
            strcat(coche->corredor.escuderia," ");
            strcat(coche->corredor.escuderia,cadena);
        }
        if (strlen(coche->corredor.escuderia) > 25){
            printf("\nError, nombre de la escuderia no puede ser de mas de 25 caracteres\n\n");
        }
    } while (strlen(coche->corredor.escuderia) > 25);
    //Pedimos los demas enteros: Dorsal, Reflejos, Condicion Fisica, Temperamento y Gestion de neumaticos.
    do{
        printf("Dorsal? ");
        fflush(stdin);
        scanf("%d",&coche->corredor.dorsal);
        if (coche->corredor.dorsal < 1 || coche->corredor.dorsal > 99){
            printf("\nError, el dorsal tiene que ser un entero entre 1 y 99\n\n");
        }
    } while (coche->corredor.dorsal < 1 || coche->corredor.dorsal > 99);
    do{
        printf("Reflejos? ");
        fflush(stdin);
        scanf("%d",&coche->corredor.reflejos);
        if (coche->corredor.reflejos < 0 || coche->corredor.reflejos > 10){
            printf("\nError, los reflejos tienen que ser un entero entre 0 y 10\n\n");
        }
    } while (coche->corredor.reflejos < 0 || coche->corredor.reflejos > 10);
    do{
        printf("Condicion fisica? ");
        fflush(stdin);
        scanf("%d",&coche->corredor.condicionFisica);
        if (coche->corredor.condicionFisica < 0 || coche->corredor.condicionFisica > 10){
            printf("\nError, la condicion fisica tiene que ser un entero entre 0 y 10\n\n");
        }
    } while (coche->corredor.condicionFisica < 0 || coche->corredor.condicionFisica > 10);
    do{
        printf("Temperamento?");
        fflush(stdin);
        scanf("%d",&coche->corredor.temperamento);
        if (coche->corredor.temperamento < 0 || coche->corredor.temperamento > 10){
            printf("\nError, el temperamento tiene que ser un entero entre 0 y 10\n\n");
        }
    } while (coche->corredor.temperamento < 0 || coche->corredor.temperamento > 10);
    do{
        printf("Gestion de neumaticos? ");
        fflush(stdin);
        scanf("%d",&coche->corredor.gestNeumaticos);
        if (coche->corredor.gestNeumaticos < 0 || coche->corredor.gestNeumaticos > 10){
            printf("\nError, la gestion de neumaticos tiene que ser un entero entre 0 y 10\n\n");
        }
    } while (coche->corredor.gestNeumaticos < 0 || coche->corredor.gestNeumaticos > 10);
    printf("\n\nCargando configurador ...\n");
    PanelConfiguracion(general,coche);
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
void PanelConfiguracion(General general, Coche * coche){
    int nSortir = 0, x[general.numCategorias], y = 0;
    //Inicializamos todos los enteros del array x porque si no se buguea basto
    for (int i = 0; i < general.numCategorias; ++i) {
        x[i] = 0;
    }
    coche->pieza = (Pieza*)malloc(sizeof(Pieza)*(general.numCategorias));
    LS_allegro_init(anchoPantalla, altoPantalla,"Configuración Pantalla");
    //Fotos allegro
    ALLEGRO_BITMAP * boxes = al_load_bitmap("boxes.png");
    ALLEGRO_BITMAP * cotxe = al_load_bitmap("cotxe.png");
    ALLEGRO_BITMAP * gasolina = al_load_bitmap("gasolina.png");
    ALLEGRO_BITMAP * motor = al_load_bitmap("motor.png");
    ALLEGRO_BITMAP * neumaticos = al_load_bitmap("neumaticos.png");
    coche->pieza[y] = general.categoria[y].pieza[x[y]];
    pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
    while(!nSortir){
        if(LS_allegro_key_pressed(ALLEGRO_KEY_UP)){
            if(y > 0){
                y--;
            } else {
                y = y + general.numCategorias-1;
            }
            coche->pieza[y] = general.categoria[y].pieza[x[y]];
            pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_DOWN)){
            if (y < general.numCategorias-1){
                y++;
            } else {
                y = y - general.numCategorias+1;
            }
            coche->pieza[y] = general.categoria[y].pieza[x[y]];
            pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT)){
            if (x[y] < general.categoria[y].numPiezas-1){
                x[y]++;
            } else {
                x[y] = x[y] - general.categoria[y].numPiezas+1;
            }
            coche->pieza[y] = general.categoria[y].pieza[x[y]];
            pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)){
            if (x[y] > 0){
                x[y]--;
            } else {
                x[y] = x[y] + general.categoria[y].numPiezas-1;
            }
            coche->pieza[y] = general.categoria[y].pieza[x[y]];
            pintaConfig(general,coche,x[y],y,boxes,neumaticos,cotxe,gasolina,motor);
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }
    }
    //Ponemos piezas por defecto si el usuario no las ha seleccionado
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
    LS_allegro_exit();
}
