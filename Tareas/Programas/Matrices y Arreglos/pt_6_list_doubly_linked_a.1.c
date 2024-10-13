#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Función para imprimir la lista
static void print_list(const List *list) {
    ListNode *node = list_head(list);
    int i = 0;

    fprintf(stdout, "List size is %d\n", list_size(list));

    while (node != NULL) {
        int *data = list_data(node);
        fprintf(stdout, "list.node[%03d] = %03d, %p -> %p\n", i, *data, node, node->next);
        node = list_next(node);
        i++;
    }
}

int main() {
    List list;
    ListNode *node;
    int *data;
    int i;

    // Inicializar la lista
    list_init(&list, free);

    // Rellenar la lista
    for (i = 20; i > 10; i--) {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

        *data = i;

        if (list_ins_next(&list, NULL, data) != 0) {
            free(data); // Liberar memoria si falla la inserción
            return 1;
        }
    }

    print_list(&list);

    // Eliminar un nodo después del primero
    node = list_head(&list);
    if (list_rem_next(&list, node, (void **)&data) != 0) {
        free(data);
        return 1;
    }
    free(data); // Liberar memoria del nodo eliminado
    print_list(&list);

    // Insertar un nuevo nodo al final
    fprintf(stdout, "\nInserting 187 at the tail of the list\n");
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 187;
    if (list_ins_next(&list, list_tail(&list), data) != 0) {
        free(data);
        return 1;
    }
    print_list(&list);

    // Eliminar el primer nodo
    if (list_rem_next(&list, NULL, (void **)&data) != 0) {
        free(data);
        return 1;
    }
    free(data);
    print_list(&list);

    // Insertar al principio de la lista
    fprintf(stdout, "\nInsert 975 at the head of the list\n");
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 975;
    if (list_ins_next(&list, NULL, data) != 0) {
        free(data);
        return 1;
    }
    print_list(&list);

    // Destruir la lista
    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);

    return 0;
}
