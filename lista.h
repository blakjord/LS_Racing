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
#define MAXC 25
#include "tipos.h"

void sortedInsert(struct _node** head_ref, struct _node* new_node);
struct _node *newNode(GP gp);

#endif //LS_RACING_LISTA_H
