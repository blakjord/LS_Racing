/***********************************************
*
* @Proposito: Almacena las funciones relacionadas con TADs
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#ifndef LS_RACING_LISTA_H
#define LS_RACING_LISTA_H
#include "tipos.h"

typedef struct {
    char nombre[MAXC];
    int posicion;
    int puntos;
    float tiempoTotal;
} Posicionamiento;

typedef struct {
    Posicionamiento pos[MAXPilotos];
    char nombre[MAXC];
} Carrera;

typedef struct N{
    Carrera carrera;
    struct N *sig;
    struct N *prev;
} NodoCarrera;

typedef struct {
    NodoCarrera *pri;
    NodoCarrera *pdi;
    NodoCarrera *ult;
} Clasificacion;

void sortedInsertGP(struct _node** head_ref, struct _node* new_node);
struct _node *nuevoNodoGP(GP gp);
Clasificacion crearClasificacion();
int calcularPosicion(float * tiempoTotal, int piloto);
int calcularPuntuacion(int posicion);
void insertarNodoCarrera(Corredor player, Corredor * bots, char * nombreGP, float * tiempoTotal, Clasificacion * clasificacion, int final);
void eliminaNodoCarrera(Clasificacion * c);
void avanzaClasi(Clasificacion * c);
void retrocedeClasi(Clasificacion * c);
void vesInicioClasi(Clasificacion * c);
int finalClasi(Clasificacion c);
void destruyeClasi(Clasificacion * c);
int compararNodo1(Clasificacion c);
int compararNodo2(Clasificacion c);
int compararNodo3(Clasificacion c);
void swap(Posicionamiento *A, Posicionamiento *B);
void selectionSort(Clasificacion * c, int acabada);
NodoCarrera consultaNodo(Clasificacion c);


#endif //LS_RACING_LISTA_H
