//
// Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
//
#include "lista.h"

void sortedInsert(struct _node** head_ref, struct _node* new_node){
    struct _node * current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->posCalndario >= new_node->posCalndario){
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL && current->next->posCalndario < new_node->posCalndario) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

struct _node *newNode(GP gp){
    /* allocate node */
    struct _node* new_node = (struct _node*) malloc(sizeof(struct _node));
    /* put in the data  */
    new_node->posCalndario  = gp.posCalndario;
    strcpy(new_node->nombreGP,gp.nombreGP);
    new_node->velocidadAdec  = gp.velocidadAdec;
    new_node->aceleracionAdec  = gp.aceleracionAdec;
    new_node->consumoAdec  = gp.consumoAdec;
    new_node->fiabilidadAdec  = gp.fiabilidadAdec;
    new_node->tiempoBase  = gp.tiempoBase;
    new_node->tiempoPinStop  = gp.tiempoPinStop;
    new_node->numeroPinStop  = gp.numeroPinStop;
    new_node->next =  NULL;
    return new_node;
}