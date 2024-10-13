/*
    doubly_circular_list.c
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "doubly_circular_list.h"

/*
    Initialize the doubly circular linked list
*/
void list_init(DoublyCircularList *list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return;    
}

/*
    Destroy the list
*/
void list_destroy(DoublyCircularList *list) {
    void *data;

    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, (void **)&data) == 0) {
            free(data); // Asumimos que `data` debe ser liberado
        }
    }    
    memset(list, 0, sizeof(DoublyCircularList));
    return;
}

/*
    Insert next node at the end of the list
*/
int list_ins_next(DoublyCircularList *list, Node *node, const void *data) {
    Node *new_node;

    if ((new_node = (Node *)malloc(sizeof(Node))) == NULL)
        return -1;

    new_node->data = (void *)data;

    // Handle insertion at head of the list
    if (node == NULL) {
        if (list_size(list) == 0) {
            new_node->next = new_node;
            new_node->prev = new_node;
            list->head = new_node;
            list->tail = new_node;
        } else {
            new_node->next = list->head;
            new_node->prev = list->tail;
            list->tail->next = new_node;
            list->head->prev = new_node;
            list->tail = new_node;
        }
    } else {
        // Handle insertion after the given node
        new_node->next = node->next;
        new_node->prev = node;

        node->next = new_node;

        if (new_node->next == list->head) {
            list->tail = new_node;
            new_node->next->prev = new_node;
        } else {
            new_node->next->prev = new_node;
        }
    }

    list->size++;
    return 0;
}

/*
    Remove next node from the list
*/
int list_rem_next(DoublyCircularList *list, Node *node, void **data) {
    Node *old_node;

    // Check if the list is not empty
    if (list_size(list) == 0)
        return -1;

    // Handle removal from head of the list
    if (node == NULL) {
        *data = list->head->data;
        old_node = list->head;

        if (list_size(list) == 1) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            list->head = list->head->next;
            list->head->prev = list->tail;
            list->tail->next = list->head;
        }
    } else {
        // Handle removal from somewhere other than head
        if (node->next == NULL)
            return -1;

        *data = node->next->data;
        old_node = node->next;
        node->next = old_node->next;

        if (old_node->next == list->head) {
            list->tail = node;
            node->next->prev = node;
        } else {
            node->next->prev = node;
        }
    }

    free(old_node);
    list->size--;
    return 0;
}

/*
    Display the list elements
*/
void list_display(DoublyCircularList *list) {
    if (list_size(list) == 0) {
        printf("List is empty\n");
        return;
    }

    Node *current = list->head;
    do {
        printf("%d ", *(int *)current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}
