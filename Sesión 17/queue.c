#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queueRef queueCreate()
{
    queueRef queue = malloc(sizeof(struct strQueue));
    queue->size = 0;
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

int queueSize(queueRef queue)
{
    return queue->size;
}

int queue_isEmpty(queueRef queue)
{
    if(queue->size == 0){
        return 1;
    }
    else return 0;
}

char queuePeekqueueRef(queueRef queue)
{

}

void printQueue(queueRef queue, nodeRef node){
    int contador = 0;
    while(queue->first != NULL && contador != queue->size){
        printf("[%c] ", queue->first->data);
        queue->first = queue->last->next;
        contador++;
    }
}

void queueOffer(queueRef queue, char data){
    struct strNode* new = malloc(sizeof(struct strNode));
    new->data = data;
    new->next = NULL;
    if(queue->size == 0){
        queue->first = new;
        queue->last = new;
    }else{
        queue->last->next = new;
    }
    queue->size++;
}

char queuePoll(queueRef queue)
{

}

void queueDestroy(queueRef queue)
{

}