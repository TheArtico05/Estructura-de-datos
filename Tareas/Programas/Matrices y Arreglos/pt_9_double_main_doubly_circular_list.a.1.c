#include <stdio.h>
#include <stdlib.h>

#include "doubly_circular_list.h"

static void print_list(const DoublyCircularList *list) {
    Node *node;
    double *data;
    int i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    do {
        data = (double *)node->data;
        fprintf(stdout, "list.node[%03d]=%.2f, %p -> %p \n", i, *data, node, node->next);
        i++;
        node = node->next;
    } while (node != list_head(list));

    fprintf(stdout, "\n");
}

int main(int argc, char **argv) {
    DoublyCircularList list;
    Node *node;
    double *data;
    int i;

    list_init(&list);

    double nums[] = {3.14, 2.71, 1.41, 1.73, 0.57, 4.67, 5.89, 2.23, 6.28, 0.1};
    for (i = 0; i < 10; i++) {
        if ((data = (double *)malloc(sizeof(double))) == NULL)
            return 1;

        *data = nums[i];

        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }

    print_list(&list);

    node = list_head(&list);

    for (i = 0; i < 3; ++i)
        node = node->next;

    data = (double *)node->data;
    fprintf(stdout, "\nRemoving a node after the one containing %.2f\n", *data);

    if (list_rem_next(&list, node, (void**)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting 9.99 at the tail of the list\n");
    *data = 9.99;
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

    fprintf(stdout, "\nInsert 8.88 at the head of the list\n");
    *data = 8.88;
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

    fprintf(stdout, "\nInserting 7.77 after the first node\n");
    *data = 7.77;
    if (list_ins_next(&list, list_head(&list), data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);
    
    return 0;
}
