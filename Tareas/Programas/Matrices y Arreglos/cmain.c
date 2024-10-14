#include <stdio.h>
#include <stdlib.h>
#include "clist.h"
//lista circular
static void print_clist(const CList *list) {
    CListNode *node;
    int *data, i;

    fprintf(stdout, "Nuestra lista circular mide %d\n", clist_size(list));

    i = 0;
    node = clist_head(list);

    if (node == NULL) return;

    do {
        data = clist_data(node);
        fprintf(stdout, "clist.node[%03d]=%03d, %p -> %p \n", i, *data, node, node->next);
        node = clist_next(node);
        i++;
    } while (node != clist_head(list));

    return;
}

int main(int argc, char **argv) {
    CList list;
    CListNode *node;

    int *data, i;

//Iniciamos la lista
    clist_init(&list, free);

    
    node = clist_head(&list);
    for (i = 20; i > 10; i--) {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

        *data = i;

        if (clist_ins_next(&list, node == NULL ? NULL : clist_head(&list), data) != 0)
            return 1;

        node = clist_head(&list);
    }

    print_clist(&list);

    node = clist_head(&list);

    for (i = 0; i < 7; ++i)
        node = clist_next(node);

    data = clist_data(node);
    fprintf(stdout, "\nRemoving a node after the one containing %03d\n", *data);

    if (clist_rem_next(&list, node, (void**)&data) != 0)
        return 1;

    print_clist(&list);

    fprintf(stdout, "\nInsertaremos un 50 al final de la lista\n");
    *data = 53;
    if (clist_ins_next(&list, clist_head(&list), data) != 0)
        return 1;

    print_clist(&list);

    fprintf(stdout, "\nQuitamos a head ahora\n");
    if (clist_rem_next(&list, NULL, (void**)&data) != 0)
        return 1;
    print_clist(&list);

    fprintf(stdout, "\nQuitamos un nodo depues de head\n");
    if (clist_rem_next(&list, clist_head(&list), (void**)&data) != 0)
        return 1;
    print_clist(&list);

    fprintf(stdout, "\nInsertamos 42 en head\n");//se para en este nodo??
    *data = 42;
    if (clist_ins_next(&list, clist_head(&list), data) != 0)
        return 1;
    print_clist(&list);


    fprintf(stdout, "\nAhora insertamos un nodo con 99 despues de el primer nodo\n");
    *data = 12;
    if (clist_ins_next(&list, clist_head(&list), data) != 0)
        return 1;
    print_clist(&list);

    // Destruimos la lista
    fprintf(stdout, "\nDestruimos la lista para acabar el ejercicio\n");
    clist_destroy(&list);

    return 0;
}

