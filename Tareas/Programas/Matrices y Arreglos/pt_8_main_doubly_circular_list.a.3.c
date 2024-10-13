#include <stdio.h>
#include <stdlib.h>

#include "doubly_circular_list.h"

static void print_list(const DoublyCircularList *list) {
    Node *node;
    char *data;
    int i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    do {
        data = (char *)node->data;
        fprintf(stdout, "list.node[%03d]=%c, %p -> %p \n", i, *data, node, node->next);
        i++;
        node = node->next;
    } while (node != list_head(list));

    fprintf(stdout, "\n");
}

int main(int argc, char **argv) {
    DoublyCircularList list;
    Node *node;
    char *data;
    int i;

    list_init(&list);

    char chars[] = {'E', 'I', 'O', 'U', 'Q', 'Z', 'Y', 'X', 'R', 'L'};
    for (i = 0; i < 10; i++) {
        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = chars[i];

        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }

    print_list(&list);

    node = list_head(&list);

    for (i = 0; i < 3; ++i)
        node = node->next;

    data = (char *)node->data;
    fprintf(stdout, "\nRemoving a node after the one containing %c\n", *data);

    if (list_rem_next(&list, node, (void**)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting 'X' at the tail of the list\n");
    *data = 'X';
    if (list_ins_next(&list, list_tail(&list), data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nRemoving a node after the first node\n");
    if (list_rem_next(&list, list_head(&list), (void**)&data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nRemoving a node at the head of the list\n");
    if (list_rem_next(&list, NULL, (void**)&data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nInsert 'Z' at the head of the list\n");
    *data = 'Z';
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nIterating and removing the fourth node\n");

    node = list_head(&list);
    node = node->next;
    node = node->next;

    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting 'W' after the first node\n");
    *data = 'W';
    if (list_ins_next(&list, list_head(&list), data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);
    
    return 0;
}
