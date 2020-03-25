//
// Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
//

#include "configuracion.h"

int configurarCoche(General general, Coche * coche){
    //Funcion de la opcion 1 del menu principal llamada configurar coche, la cual se encarga de llenarte el struct coche que se le pasa por referencia,
    //al usuario le iran preguntando por las variables que ha de rellenar, despues llamara a la funcion que llenara las piezas del coche.
    printf("Nombre del piloto? ");
    fflush(stdin);
    fgets(coche->corredor.nombreCorredor, 25, stdin);
    printf("Nombre de la escuderia? ");
    fgets(coche->corredor.escuderia, 25, stdin);
    do{
        printf("Dorsal? ");
        scanf("%d",&coche->corredor.dorsal);
        if (coche->corredor.dorsal < 1 || coche->corredor.dorsal > 99){
            printf("\nError, el dorsal tiene que ser un entero entre 1 y 99\n\n");
        }
    } while (coche->corredor.dorsal < 1 || coche->corredor.dorsal > 99);
    do{
        printf("Reflejos? ");
        scanf("%d",&coche->corredor.reflejos);
        if (coche->corredor.reflejos < 0 || coche->corredor.reflejos > 10){
            printf("\nError, los reflejos tienen que ser un entero entre 0 y 10\n\n");
        }
    } while (coche->corredor.reflejos < 0 || coche->corredor.reflejos > 10);
    do{
        printf("Condicion fisica? ");
        scanf("%d",&coche->corredor.condicionFisica);
        if (coche->corredor.condicionFisica < 0 || coche->corredor.condicionFisica > 10){
            printf("\nError, la condicion fisica tiene que ser un entero entre 0 y 10\n\n");
        }
    } while (coche->corredor.condicionFisica < 0 || coche->corredor.condicionFisica > 10);
    do{
        printf("Temperamento? ");
        scanf("%d",&coche->corredor.temperamento);
        if (coche->corredor.temperamento < 0 || coche->corredor.temperamento > 10){
            printf("\nError, el temperamento tiene que ser un entero entre 0 y 10\n\n");
        }
    } while (coche->corredor.temperamento < 0 || coche->corredor.temperamento > 10);
    do{
        printf("Gestion de neumaticos? ");
        scanf("%d",&coche->corredor.gestNeumaticos);
        if (coche->corredor.gestNeumaticos < 0 || coche->corredor.gestNeumaticos > 10){
            printf("\nError, la gestio nde neumaticos tiene que ser un entero entre 0 y 10\n\n");
        }
    } while (coche->corredor.gestNeumaticos < 0 || coche->corredor.gestNeumaticos > 10);
    printf("\n\nCargando configurador ...\n");
    dibujaPanelConfiguracion(general,coche);
    return 1;
}