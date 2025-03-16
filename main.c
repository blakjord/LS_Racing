/***********************************************
*
* @Proposito: Almacena la funcion principal.
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#include "lectura.h"
#include "configuracion.h"
#include "carrera.h"
#include "clasificacion.h"

/***********************************************
*
* @Finalidad: Procedimiento principal, primero comprueba si los parametros que le has pasado son correctos, luego ejecuta la funcion de lectura de los archivos,
*             Y por ultimo te crea el menu que te dirigira a la funcion que el usuario diga, ya sea la de congifurar el coche, la de empezar la carrera escogiendole antes
*             el circuito que le toca, la de ver la clasificacion y la de guardar la temporada.
* @Parametros:  in: argc = numero de argumentos que se le pasan a la funcion.
*               in: veces = matriz que almacena todos los argumentos que se le pasan a la funcion.
* @Retorno: Retorna un entero 0 si tod0 el programa finaliza sin problemas.
*
************************************************/
int main(int argc, char *argv[]){
    if (argc != 5){
        printf("Parametros incorrectos");
        exit(-1);
    }
    //Leemos todos los ficheros
    General general = lecturaFicheros(argv);
    Coche coche;
    struct _node * current;
    //Creamos la lista bidireccional de clasificacion
    Clasificacion clasificacion = crearClasificacion();
    char opcion[50];
    int veces = 0;
    coche.corredor.dorsal = 0;
    printf("Bienvenidos a LS Racing !\n");
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
                    //Si el usuario aun no ha configurado su piloto entrara en esta condicion si no entrara en el else
                    if (coche.corredor.dorsal == 0){
                        configurarCoche(general,&coche);
                    } else {
                        PanelConfiguracion(general,&coche);
                    }
                    break;
                case 2:
                    //Nos guardamos la lis  ta de GP y la llevamos al ultimo nodo para comprobar en que momento de la temporada estamos
                    current = general.listaGP;
                    for (int i = 0; i < veces; ++i) {
                        current = current->next;
                    }
                    if (current == NULL){
                        printf("\nYa has finalizado la temporada.\n");
                    } else if (coche.corredor.dorsal == 0) {
                        printf("\nAun no has configurado el coche.\n");
                    } else {
                        carrera(general, coche, current, &clasificacion);
                        veces++;
                    }
                    break;
                case 3:
                    //Nos guardamos la lista de GP y la llevamos al ultimo nodo para comprobar en que momento de la temporada estamos
                    current = general.listaGP;
                    for (int i = 0; i < veces; ++i) {
                        current = current->next;
                    }
                    //Aqui entrara si la temporada ya a finalizado si no se ira a los else
                    if (current == NULL){
                        insertarNodoCarrera(coche.corredor, general.corredor, "Pepe", (float*)NULL, &clasificacion, 1);
                        clasificacionGeneral(clasificacion, 1);
                        eliminaNodoCarrera(&clasificacion);
                    } else if (veces == 0) {
                        printf("\nAun no ha comenzado la temporada.\n");
                    } else {
                        clasificacionGeneral(clasificacion, 0);
                    }
                    break;
                case 4:
                    generarLogs(clasificacion);
                    break;
                default:
                    printf("Error. Opcion no valida.\n\n");
                    break;
            }
        }
    } while (strcmp(opcion,"exit")!=0);
    //Liberamos tod0 tipo de memoria que hayamos utilizado
    destruyeClasi(&clasificacion);
    free(coche.pieza);
    free(general.listaGP);
    for (int j = 0; j < general.numCategorias; ++j) {
        free(general.categoria[j].pieza);
    }
    free(general.categoria);
    free(general.corredor);
    return 0;
}