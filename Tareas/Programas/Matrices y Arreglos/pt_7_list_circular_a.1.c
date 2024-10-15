/*
    clist.c
*/

#include <stdlib.h>
#include <string.h>
#include "clist.h"

//Creamos la lista:
void clist_init(CList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
}

//Para destruir nuestra lista:
void clist_destroy(CList *list) {
    void *data;

    while (clist_size(list) > 0) {
        if (clist_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(CList));
    return;
}

//Para insertar nodos:
int clist_ins_next(CList *list, CListNode *node, const void *data) {//se arreglo el error en 975
    CListNode *new_node;

    if ((new_node = (CListNode *)malloc(sizeof(CListNode))) == NULL)
        return -1;

    new_node->data = (void *)data;

    if (clist_size(list) == 0) {
        // Insertar en una lista vacia
        new_node->next = new_node;
        list->head = new_node;
    } else {
        if (node == NULL) {
            // Si la lista no es vacia, esto pasa
            new_node->next = list->head;
            CListNode *last_node = list->head;
            while (last_node->next != list->head)
                last_node = last_node->next;
            last_node->next = new_node;
            list->head = new_node;
        } else {
            // Insertar en algun lado
            new_node->next = node->next;
            node->next = new_node;
        }
    }

    list->size++;
    return 0;
}

//Para remover de la lista
int clist_rem_next(CList *list, CListNode *node, void **data) {
    CListNode *old_node;

    if (clist_size(list) == 0)
        return -1;

    if (node == NULL) {
        // Caso para eliminar en head
        *data = list->head->data;
        if (list->head == list->head->next) {
            old_node = list->head;
            list->head = NULL;
        } else {
            old_node = list->head;
            node = list->head;
            while (node->next != list->head)
                node = node->next;

            node->next = list->head->next;
            list->head = list->head->next;
        }
    } else {
        // Caso para eliminar donde sea menos en head
        if (node->next == NULL)
            return -1;

        old_node = node->next;
        *data = old_node->data;
        node->next = old_node->next;
    }
    
    free(old_node);
    list->size--;
    return 0;
}
