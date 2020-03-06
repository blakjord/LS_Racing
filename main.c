#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lectura.h"

int main(int argc, char *argv[]){
    if (argc != 5){
        printf("Parametros incorrectos");
        exit(-1);
    }
    General general = lecturaFicheros(argv);
    printf("Bienvenidos a LS Racing !\n");
    char opcion[50];
    /*do{
        printf("   1. Configurar coche\n");
        printf("   2. Carrera\n");
        printf("   3. Ver clasificacion\n");
        printf("   4. Guardar temporada\n\n");
        printf("Que opcion quieres ejecutar? ");
        scanf("%s",opcion);
        if (strcmp(opcion,"exit")!=0){
            switch (atoi(opcion)) {
                case 1:
                    configurarCoche(general);
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
    free(general.categoria->pieza);
    free(general.categoria);
    free(general.corredor);*/
    configurarCoche(general);
    return 0;
}