#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    struct strQueue* queue = queueCreate();
    char c = 'a';
    queueOffer(queue, c);
    c = 'b'; //autosuicidación
    //queueOffer(queue, c);
    c = 'c'; //lloración
    /*queueOffer(queue, c);
    c = 'd';
    queueOffer(queue, c);
    c = 'e';
    queueOffer(queue, c);*/
    int isEmpty = queue_isEmpty(queue);
    if(isEmpty == 1){
        printf("La cola esta vacia\n");
    }
    else {
        printf("La cola no esta vacia. Tiene %d elementos\n", queueSize(queue));
    }
    printQueue(queue);
    printf("\nPrimer caracter: %c\n", queuePoll(queue));
    printQueue(queue);
    /*printf("\nPrimer caracter: %c\n", queuePoll(queue));
    printQueue(queue);*/
    queueDestroy(queue);
    printf("\n");
    printQueue(queue);
}
