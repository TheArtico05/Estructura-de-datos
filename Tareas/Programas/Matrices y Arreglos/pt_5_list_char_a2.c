#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void print_list(const List *list) {
    ListNode *node;
    char *data;
    int i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (node != NULL) {  
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]=%c, %p -> %p \n", i, *data, node, node->next);
        i++;
        node = list_next(node);  
    }
}

int main(int argc, char **argv) {
    List list;
    ListNode *node;
    char *data;
    char nuevocarac;
    int Contar;
    int i;

    list_init(&list, free);

    for (Contar = 0; Contar < 14; Contar++) {
        printf("Ingresa el caracter que quieres meter: ");
        scanf(" %c", &nuevocarac);

        if ((data = (char *)malloc(sizeof(char))) == NULL) {
            fprintf(stderr, "No se ha asignado bien la memoria, que habra pasado?\n");
            return 1;
        }

        *data = nuevocarac;  

        if (i == 0) {
            if (list_ins_next(&list, NULL, data) != 0) {
                fprintf(stderr, "No se pudo ingresar el eemento\n");
                return 1;
            }
        } else {
            if (list_ins_next(&list, list_tail(&list), data) != 0) {
                fprintf(stderr, "No se pudo igual ingresar, que habra pasado?");
                return 1;
            }
        }
    }

    print_list(&list);

    node = list_head(&list);

    for (i = 0; i < 3 && node != NULL; ++i)
        node = list_next(node);

    data = list_data(node);
    fprintf(stdout, "\nRemoving a node after the one containing %c\n", *data);

    if (list_rem_next(&list, node, (void**)&data) != 0)
        return 1;
    free(data);
    print_list(&list);

    fprintf(stdout, "\nInserting 'D' at the tail of the list\n");
    *data = 'D';
    if (list_ins_next(&list, list_tail(&list), data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nRemoving a node at the head of the list\n");
    if (list_rem_next(&list, NULL, (void**)&data) != 0)
        return 1;
    print_list(&list);
    
    fprintf(stdout, "\nIterating and removing the fourth node\n");

    node = list_head(&list);
    node = list_next(node);
    node = list_next(node);

    fprintf(stdout, "\nInserting '9' at the tail of the list\n");

    *data = '9';
    if (list_ins_next(&list, list_tail(&list), data) != 0)
        return 1;
    print_list(&list);

        fprintf(stdout, "\nRemoving a node after the first node\n");
    if (list_rem_next(&list, list_head(&list), (void**)&data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nInsert 'R' at the head of the list\n");
    *data = 'R';
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);
    
    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;
    free(data);

    print_list(&list);

    fprintf(stdout, "\nInserting 'o' after the first node\n");
    *data = 'o';
    if (list_ins_next(&list, list_head(&list), data) != 0)
        return 1;
    print_list(&list);

    i = list_is_head(&list, list_head(&list));
    fprintf(stdout, "\nTesting list_is_head... value=%d (1=OK)\n", i);
    i = list_is_head(&list, list_tail(&list));
    fprintf(stdout, "Testing list_is_head... value=%d (1=OK)\n", i);
    i = list_is_tail(list_tail(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    i = list_is_tail(list_head(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);

    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);
    return 0;
}
