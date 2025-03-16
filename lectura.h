/***********************************************
*
* @Proposito: Almacena las funciones de la lectura de ficheros
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#ifndef LS_RACING_LECTURA_H
#define LS_RACING_LECTURA_H
#include "lista.h"

General lecturaFicheros(char *argv[]);
void comprobarFicharo(FILE * fp);
General lecturaPiezas(char *argv, General general);
General lecturaGPs(char *argv, General general);
General lecturaCorredores(char *argv, General general);
General lecturaBase(char *argv, General general);


#endif //LS_RACING_LECTURA_H
