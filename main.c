//
// Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
//
#include "lectura.h"
#include "configuracion.h"
#include "carrera.h"
#include "clasificacion.h"

int main(int argc, char *argv[]){
    //Procedimiento principal, primero comprueba si los parametros que le has pasado son correctos, luego ejecuta la funcion de lectura de los archivos,
    //Y por ultimo te crea el menu que te dirigira a la funcion que el usuario diga, ya sea la de congifurar el coche, la de empezar la carrera, la de
    //ver la clasificacion y la de guardar la temporada.
    if (argc != 5){
        printf("Parametros incorrectos");
        exit(-1);
    }
    General general = lecturaFicheros(argv);
    Coche coche;
    printf("Bienvenidos a LS Racing !\n");
    char opcion[50];
    do{
        printf("\n   1. Configurar coche\n");
        printf("   2. Carrera\n");
        printf("   3. Ver clasificacion\n");
        printf("   4. Guardar temporada\n\n");
        printf("Que opcion quieres ejecutar? ");
        scanf("%s",opcion);
        if (strcmp(opcion,"exit")!=0){
            switch (atoi(opcion)) {
                case 1:
                    configurarCoche(general,&coche);
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
    free(coche.pieza);
    free(general.listaGP);
    free(general.categoria->pieza);
    free(general.categoria);
    free(general.corredor);
    return 0;
}