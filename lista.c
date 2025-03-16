/***********************************************
*
* @Proposito: Almacena las funciones relacionadas con TADs.
* @Autor/s: Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
* @Fecha creacion: 3/3/20
* @Fecha ultima modificacion: 26/04/2020
*
************************************************/

#include "lista.h"

/***********************************************
*
* @Finalidad: Funcion que inserta un nuevo nodo en la lista ordenada, se comprueba si el nodo es el primero de la lista o es menor o igual al primer nodo que
*             pueda haber, y se inserta como primer nodo de la lista, si no lo es entonces va nodo a nodo hasta encontrar el nodo el cual sea mas pequeño que
*             el nuevo o el final de la lista y entonces se inserta ahi.
* @Parametros:  in: head_ref = Lista de nodos de los grandes premios.
*               in: _node = Nodo nuevo generado que insertaremos.
* @Retorno: No devuelve nada.
*
************************************************/
void sortedInsertGP(struct _node** head_ref, struct _node* new_node){
    struct _node * current;
    //Si el primer nodo esta vacio o tiene una fecha mas grande de la que quieres insertar lo pones al inicio.
    if (*head_ref == NULL || (*head_ref)->posCalndario >= new_node->posCalndario){
        new_node->next = *head_ref;
        *head_ref = new_node;
    //Si el primer contiene algo y tiene una fecha mas pequeña de la que quieres insertar vas buscando mas nodos siguientes hasta insertarse.
    } else {
        current = *head_ref;
        while (current->next!=NULL && current->next->posCalndario < new_node->posCalndario) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

/***********************************************
*
* @Finalidad: Funcion de creacion de un nuevo nodo, se le pasa por parametro un nodo estatico normal y te lo devuelve como un nodo dinamico preparado para ser
*             insertado en una lista.
* @Parametros:  in: gp = Struct donde esta la informacion que cargara el nuevo nodo.
* @Retorno: Devuelve el nuevo nodo creado.
*
************************************************/
struct _node *nuevoNodoGP(GP gp){
    struct _node* new_node = (struct _node*) malloc(sizeof(struct _node));
    new_node->posCalndario  = gp.posCalndario;
    strcpy(new_node->nombreGP, gp.nombreGP);
    new_node->velocidadAdec  = gp.velocidadAdec;
    new_node->aceleracionAdec  = gp.aceleracionAdec;
    new_node->consumoAdec  = gp.consumoAdec;
    new_node->fiabilidadAdec  = gp.fiabilidadAdec;
    new_node->tiempoBase  = gp.tiempoBase;
    new_node->tiempoPinStop  = gp.tiempoPinStop;
    new_node->numeroPinStop  = gp.numeroPinStop;
    new_node->next = NULL;
    return new_node;
}

/***********************************************
*
* @Finalidad: Funcion de creacion de la lista bidireccional Clasificacion, te crea los nodos fantasma del inicio y del final y los inserta en su sitio.
* @Parametros:  No tiene parametros de entrada.
* @Retorno: Devuelve el nuevo nodo la nueva lista.
*
************************************************/
Clasificacion crearClasificacion() {
    Clasificacion c;
    NodoCarrera *fantasmaStart;
    NodoCarrera *fantasmaEnd;
    fantasmaStart = (NodoCarrera*)malloc(sizeof(NodoCarrera));
    fantasmaEnd = (NodoCarrera*)malloc(sizeof(NodoCarrera));
    if (fantasmaStart == NULL || fantasmaEnd==NULL) {
        printf("\nError al crear la lista...\n");
        if (fantasmaStart!=NULL) free(fantasmaStart);
        if (fantasmaEnd!=NULL) free(fantasmaEnd);
        exit(-1);
    } else {
        fantasmaStart->sig = fantasmaEnd;
        fantasmaStart->prev = NULL;
        fantasmaEnd->sig = NULL;
        fantasmaEnd->prev = fantasmaStart;
        c.pri = fantasmaStart;
        c.ult = fantasmaEnd;
        c.pdi = fantasmaStart;
    }
    return c;
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de calcula la posicion en la que se ha quedado un piloto.
* @Parametros:  in: tiempoTotal = array de floats que almacena todos los tiempos de todos los pilotos en la carrera.
*               in: piloto = numero entero que identifica al piloto.
* @Retorno: Devuelve el entero que define la posicion del piloto en la carrera.
*
************************************************/
int calcularPosicion(float * tiempoTotal, int piloto){
    int posicion = 1;
    for (int i = 0; i < MAXPilotos; ++i) {
        if (tiempoTotal[i] < tiempoTotal[piloto]){
            posicion++;
        }
    }
    return posicion;
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de calcula la puntuacion que tendra el piloto al acabar la carrera.
* @Parametros:  in: posicion = entero que define la posicion del piloto en la carrera.
* @Retorno: Devuelve el entero que define la puntuacion del piloto en la carrera.
*
************************************************/
int calcularPuntuacion(int posicion){
    switch (posicion) {
        case 1:
            return 25;
        case 2:
            return 18;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 8;
        case 6:
            return 6;
        case 7:
            return 5;
        case 8:
            return 3;
        default:
            return 0;
    }
}

/***********************************************
*
* @Finalidad: Funcion que intercambia el contenido de una posicion del struct Posicionamiento por otra.
* @Parametros:  in: A = primera posicion a intercambiar.
*               in: B = segunda posicion a intercambiar.
* @Retorno: No devuelve nada.
*
************************************************/
void swap(Posicionamiento *A, Posicionamiento *B){
    Posicionamiento temp = *A;
    *A = *B;
    *B = temp;
}

/***********************************************
*
* @Finalidad: Funcion que te ordena un struct carrera sus posicionamientos dependiendo si es el nodo final (por puntos) o no (por tiempo total),
*             La funcion usa el metodo de ordenacion llamado selection sort ya que funciona muy bien con nodos structs ya que simplemente hace swap sus contenidos.
* @Parametros:  in: carrera = struct que se ordenara.
*               in: acabada = entero que sirve de boleano para saber si se ha de ordenar un nodo normal de carrera (0) o el final (1).
* @Retorno: No devuelve nada.
*
************************************************/
void selectionSort(Clasificacion * c, int acabada){
    int m;
    for (int i = 0; i < 7; i++){
        m = i;
        for (int j = i+1; j < MAXPilotos; j++)
            if (acabada == 0){
                if (c->pdi->carrera.pos[j].tiempoTotal < c->pdi->carrera.pos[m].tiempoTotal)
                    m = j;
            } else {
                if (c->pdi->carrera.pos[j].puntos > c->pdi->carrera.pos[m].puntos)
                    m = j;
            }

        swap(&c->pdi->carrera.pos[i], &c->pdi->carrera.pos[m]);
    }
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de insertar un nodo delante del pdi a la lista bidireccional de la clasificacion, insertandolo como nodo normal
*             o como nodo final dependiendo si ha acabado la temporada o no.
* @Parametros:  in: player = struct con informacion del jugador del usuario.
*               in: bots = struct con informacion de los pilotos bots que han competido.
*               in: nombreGP = cadena de caracteres que tiene el nombre de la carrera finalizada.
*               in: tiempoTotal = array de floats que almacenan los tiempos totales que han tadado en recorrerse la carrera todos los pilotos.
*               in: clasificacion = lista bidireccional a la que se le quiere insertar el nuevo nodo.
*               in: final = entero que funciona de boleano para indicar si es el nodo final (1) o no (0).
* @Retorno: No devuelve nada.
*
************************************************/
void insertarNodoCarrera(Corredor player, Corredor * bots, char * nombreGP, float * tiempoTotal, Clasificacion * clasificacion, int final){
    NodoCarrera * aux = (NodoCarrera*)malloc(sizeof(NodoCarrera));
    if (aux == NULL) {
        printf("\nError al generar un nodo de Carrera...\n");
    } else {
        strcpy(aux->carrera.nombre, nombreGP);
        for (int i = 0; i < MAXPilotos; ++i) {
            if (i == 0){
                strcpy(aux->carrera.pos[i].nombre, player.nombreCorredor);
            } else {
                strcpy(aux->carrera.pos[i].nombre, bots[i-1].nombreCorredor);
            }
            //Si es un nodo normal se insertara normalmente
            if (final == 0) {
                aux->carrera.pos[i].tiempoTotal = tiempoTotal[i];
                aux->carrera.pos[i].posicion = calcularPosicion(tiempoTotal, i);
                aux->carrera.pos[i].puntos = clasificacion->pdi->carrera.pos[i].puntos + calcularPuntuacion(aux->carrera.pos[i].posicion);
            //Si es un nodo final se insertara pero poniendo dorsales en la variable de tiempo para reutilizarla
            } else {
                if (i == 0){
                    aux->carrera.pos[i].tiempoTotal = (float)player.dorsal;
                } else {
                    aux->carrera.pos[i].tiempoTotal = (float)bots[i-1].dorsal;
                }
                aux->carrera.pos[i].posicion = (int) NULL;
                aux->carrera.pos[i].puntos = clasificacion->ult->prev->carrera.pos[i].puntos;
            }
        }
        //Se inserta el nodo
        aux->sig = clasificacion->pdi->sig;
        aux->prev = clasificacion->pdi;
        aux->sig->prev = aux;
        clasificacion->pdi->sig = aux;
        clasificacion->pdi = aux;
    }
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de eliminar el nodo pdi de la lista bidireccional de la clasificacion.
* @Parametros:  in: c = lista bidireccional a la que se le quiere borrar el nodo.
* @Retorno: No devuelve nada.
*
************************************************/
void eliminaNodoCarrera(Clasificacion * c){
    NodoCarrera *aux;
    if (c->pdi == c->pri || c->pdi == c->ult) {
        printf("\nError al eliminar, PDI situado al principio o final...");
    } else {
        aux = c->pdi;
        aux->sig->prev = aux->prev;
        aux->prev->sig = aux->sig;
        c->pdi = aux->sig;
        free(aux);
    }
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de eliminar el nodo pdi de la lista bidireccional de la clasificacion para que sea el siguiente a este.
* @Parametros:  in: c = lista bidireccional a la que se le quiere avanzar el nodo pdi.
* @Retorno: No devuelve nada.
*
************************************************/
void avanzaClasi(Clasificacion * c) {
    if (c->pdi == c->ult) {
        printf("\nError al avanzar...\n");
    } else {
        c->pdi = c->pdi->sig;
    }
}

/***********************************************
*
* @Finalidad: Funcion que se encarga de retroceder el nodo pdi de la lista bidireccional de la clasificacion para que sea el previo a este.
* @Parametros:  in: c = lista bidireccional a la que se le quiere retroceder el nodo pdi.
* @Retorno: No devuelve nada.
*
************************************************/
void retrocedeClasi(Clasificacion * c) {
    if (c->pdi == c->pri) {
        printf("\nError al retroceder...\n");
    } else {
        c->pdi = c->pdi->prev;
    }
}

/***********************************************
*
* @Finalidad: Funcion que te mueve el nodo pdi al primer nodo de una lista.
* @Parametros:  in: c = lista a la que se le cambiara el nodo pdi por el siguiente nodo al primer nodo fantasma.
* @Retorno: No devuelve nada.
*
************************************************/
void vesInicioClasi(Clasificacion * c) {
    c->pdi = c->pri->sig;
}

/***********************************************
*
* @Finalidad: Funcion que te comprueba si en una lista bidireccional su nodo pdi esta al final.
* @Parametros:  in: c = lista bidireccional a la que se le hara la comprobacion.
* @Retorno: Retorna un 1 si el siguiente nodo en el pdi es igual al ultimo nodo fantasma o dicho de otra manera es en el nodo final.
*
************************************************/
int finalClasi(Clasificacion c) {
    return c.pdi == c.ult;
}

/***********************************************
*
* @Finalidad: Funcion que te elimina tod0 el contenido de una lista bidireccional, eliminando nodo por nodo hasta que este vacia y liberando la memoria
*             correspondiente.
* @Parametros:  in: c = lista bidireccional que quiere destruirse.
* @Retorno: No devuelve nada.
*
************************************************/
void destruyeClasi(Clasificacion * c) {
    NodoCarrera *aux;
    while (c->pri != NULL) {
        aux = c->pri;
        c->pri = aux->sig;
        free(aux);
    }
    c->ult = c->pdi = NULL;
}

/***********************************************
*
* @Finalidad: Funcion creada para respetar la encapsulacion, comprueva si el nodo anterior al pdi es diferente al primer nodo.
* @Parametros:  in: c = lista bidireccional a la que se le hara la comprobacion.
* @Retorno: Retorna un entero dependiendo si son o no los mismos nodos.
*
************************************************/
int compararNodo1(Clasificacion c){
    return c.pdi->prev != c.pri;
}

/***********************************************
*
* @Finalidad: Funcion creada para respetar la encapsulacion, comprueva si el nodo siguiente del nodo siguiente del nodo pdi es igual a el ultimo nodo.
* @Parametros:  in: c = lista bidireccional a la que se le hara la comprobacion.
* @Retorno: Retorna un entero dependiendo si son o no los mismos nodos.
*
************************************************/
int compararNodo2(Clasificacion c){
    return c.pdi->sig->sig == c.ult;
}

/***********************************************
*
* @Finalidad: Funcion creada para respetar la encapsulacion, comprueva si el nodo siguiente al pdi es diferente al ultimo nodo.
* @Parametros:  in: c = lista bidireccional a la que se le hara la comprobacion.
* @Retorno: Retorna un entero dependiendo si son o no los mismos nodos.
*
************************************************/
int compararNodo3(Clasificacion c){
    return c.pdi->sig != c.ult;
}

/***********************************************
*
* @Finalidad: Funcion creada para respetar la encapsulacion, te devuelve el nodo actual pdi de la lista.
* @Parametros:  in: c = lista bidireccional que tendra el pdi.
* @Retorno: Retorna un NodoCarrera.
*
************************************************/
NodoCarrera consultaNodo(Clasificacion c){
    return *c.pdi;
}