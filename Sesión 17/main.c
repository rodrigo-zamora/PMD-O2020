#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){

    char c = 'a';

    struct strQueue* queue = queueCreate();
    struct strNode* node = NULL; //de mucha ayuda
    queueOffer(queue, c);
    c = 'b'; //autosuicidación
    queueOffer(queue, c);
    c = 'c'; //lloración
    queueOffer(queue, c);
    c = 'd';
    queueOffer(queue, c);
    c = 'e';
    queueOffer(queue, c);
    int isEmpty = queue_isEmpty(queue);
    if(isEmpty == 1){
        printf("La cola esta vacia\n");
    }
    else {
        printf("La cola no esta vacia. Tiene %d elementos\n", queueSize(queue));
    }
    printQueue(queue, node);
}