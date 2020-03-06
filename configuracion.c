//
// Created by Alejandro on 03/03/2020.
//

#include "configuracion.h"


int configurarCoche(General general){
    Coche coche;
    /*printf("Nombre del piloto? ");
    scanf("%s",coche.corredor.nombreCorredor);
    printf("Nombre de la escuderia? ");
    scanf("%s",coche.corredor.escuderia);
    do{
        printf("Dorsal? ");
        scanf("%d",&coche.corredor.dorsal);
        if (coche.corredor.dorsal < 1 || coche.corredor.dorsal > 99){
            printf("\nError, el dorsal tiene que ser un entero entre 1 y 99\n\n");
        }
    } while (coche.corredor.dorsal < 1 || coche.corredor.dorsal > 99);
    do{
        printf("Reflejos? ");
        scanf("%d",&coche.corredor.reflejos);
        if (coche.corredor.reflejos < 0 || coche.corredor.reflejos > 10){
            printf("\nError, los reflejos tienen que ser un entero entre 0 y 10\n\n");
        }
    } while (coche.corredor.reflejos < 0 || coche.corredor.reflejos > 10);
    do{
        printf("Condicion fisica? ");
        scanf("%d",&coche.corredor.condicionFisica);
        if (coche.corredor.condicionFisica < 0 || coche.corredor.condicionFisica > 10){
            printf("\nError, la condicion fisica tiene que ser un entero entre 0 y 10\n\n");
        }
    } while (coche.corredor.condicionFisica < 0 || coche.corredor.condicionFisica > 10);
    do{
        printf("Temperamento? ");
        scanf("%d",&coche.corredor.temperamento);
        if (coche.corredor.temperamento < 0 || coche.corredor.temperamento > 10){
            printf("\nError, el temperamento tiene que ser un entero entre 0 y 10\n\n");
        }
    } while (coche.corredor.temperamento < 0 || coche.corredor.temperamento > 10);
    do{
        printf("Gestion de neumaticos? ");
        scanf("%d",&coche.corredor.gestNeumaticos);
        if (coche.corredor.gestNeumaticos < 0 || coche.corredor.gestNeumaticos > 10){
            printf("\nError, la gestio nde neumaticos tiene que ser un entero entre 0 y 10\n\n");
        }
    } while (coche.corredor.gestNeumaticos < 0 || coche.corredor.gestNeumaticos > 10);
    printf("\n\nCargando configurador ...");*/
    dibujaPanelConfiguracion(general,&coche);
    return 1;
}