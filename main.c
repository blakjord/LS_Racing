#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "LS_allegro.h"
#include "lectura.h"

int main(int argc, char *argv[]){
    if (argc != 5){
        printf("Parametros incorrectos");
        exit(-1);
    }
    General general = lecturaFicheros(argv);
    printf("Bienvenidos a LS Racing !\n");
    char opcion[50];
    do{
        printf("   1. Configurar coche\n");
        printf("   2. Carrera\n");
        printf("   3. Ver clasificacion\n");
        printf("   4. Guardar temporada\n\n");
        printf("Que opcion quieres ejecutar? ");
        scanf("%s",opcion);
        if (strcmp(opcion,"exit")!=0){
            switch (atoi(opcion)) {
                case 1:
                    printf("Se ejecuta la opcion 1");
                    break;
                case 2:
                    printf("Se ejecuta la opcion 2");
                    break;
                case 3:
                    printf("Se ejecuta la opcion 3");
                    break;
                case 4:
                    printf("Se ejecuta la opcion 4");
                    break;
                default:
                    printf("Error. Opcion no valida.\n\n");
                    break;
            }
        }
    } while (strcmp(opcion,"exit")!=0);

    /*int nSortir = 0;
    //Inicialitzem Allegro
    LS_allegro_init(800,600,"Projecte 2");
    //Bucle infinit del joc
    while(!nSortir){
        //Escoltem el teclat esperant la tecla ESC
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }
        //Donem l'ordre d'escriure el text de benvinguda
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,100,0,"%s","Benvingut a Allegro! Prem ESC per sortir...");
        //Pintem la pantalla de la finestra gràfica
        LS_allegro_clear_and_paint(BLACK);
    }
    //Tanquem la finestra gràfica
    LS_allegro_exit();*/

    return 0;
}