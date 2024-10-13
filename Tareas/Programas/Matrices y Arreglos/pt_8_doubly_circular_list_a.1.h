/*
    doubly_circular_list.h
*/
#ifndef DOUBLY_CIRCULAR_LIST_H
#define DOUBLY_CIRCULAR_LIST_H

#include <stdlib.h>

/*
    Node structure for doubly circular linked list
*/
typedef struct Node_ {
    void *data;
    struct Node_ *next;
    struct Node_ *prev;
} Node;

/*
    Structure for the doubly circular linked list
*/
typedef struct DoublyCircularList_ {
    int size;
    Node *head;
    Node *tail;
} DoublyCircularList;

/*
    Public Interfaces
*/
void list_init(DoublyCircularList *list);
void list_destroy(DoublyCircularList *list);
int list_insert(DoublyCircularList *list, const void *data);
int list_remove(DoublyCircularList *list, void **data);
void list_display(DoublyCircularList *list);

/*
    Macros
*/
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)

#endif // 
