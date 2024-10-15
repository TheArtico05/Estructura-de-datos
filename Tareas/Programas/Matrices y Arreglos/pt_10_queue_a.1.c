#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "list.h"
//Imprimimos la cola
static void print_queue (const Queue *queue) {
    ListNode *node;
    int *data, Aztlan;

    fprintf(stdout, "La cola mide %d\n", queue_size(queue));

    Aztlan = 0;
    node = list_head(queue);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "queue.node[%03d]=%03d, %p -> %p \n", Aztlan, *data, node, node->next);

        Aztlan++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

   return;
}

int main (int argc, char **argv) {
    Queue queue;
    ListNode *node;

    int *data, Aztlan;

    //Iniciamos la cola con unos cuantos elementos
    queue_init(&queue, free);
    
    for (Aztlan=5;Aztlan>0;Aztlan--) {

        if ((data=(int *)malloc(sizeof(int))) == NULL)
            return 1;
        *data = Aztlan;

        if (queue_enqueue(&queue, data) != 0)
            return 1;
    }

    print_queue(&queue);
    //Desencolar
    if (queue_dequeue(&queue, (void**)&data) != 0)
        return 1;

    fprintf(stdout, "Se desencolo: %d\n", *data);
    free(data);

print_queue(&queue);
	
	    //Encolar una palabra
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;

    *data = "Ajolote";
    if (queue_enqueue(&queue, data) != 0)
        return 1;
        
	fprintf(stdout, "Se agrego el elemento: %d\n", *data);
    print_queue(&queue);

	
    //Encolar un número
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;

    *data = 7;
    if (queue_enqueue(&queue, data) != 0)
        return 1;
        
	fprintf(stdout, "Se agrego el elemento: %d\n", *data);
    print_queue(&queue);

    // Para ojear elementos (o bueno, hacer peek) de la head
    data = queue_peek(&queue);
    fprintf(stdout, "Se ojea (o hace peek) de head: %d\n", *data);

    // Eliminamos la queue para acabar
    fprintf(stdout, "\nFinalmente, destruimos la queue\n");
    queue_destroy(&queue);

    return 0;
}
