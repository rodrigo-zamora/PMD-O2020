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

void printQueue(queueRef queue){
    int contador = 0;
    nodeRef focusNode = queue->last;
    while(focusNode != NULL && contador <= queue->size){
        printf("[%c] ", focusNode->data);
        focusNode = focusNode->next;
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
    } else {
        new->next = queue->last;
        queue->last = new;
    }
    queue->size++;
}

char queuePoll(queueRef queue)
{
    int contador = 1;   
    nodeRef focusNode = queue->last;
    nodeRef toRemove = queue->first;

    if(queue->size == 1){
        queue->size = 0;
        queue->first = NULL;
        queue->last = NULL;
    } else{
        while(focusNode != NULL && contador <= queue->size){
            if(contador == (queue->size)-1){
                queue->first = focusNode;
                focusNode->next = focusNode->next->next;
            } else {
                focusNode = focusNode->next;
            }
            contador++;
        }
        queue->size--;
        free(focusNode);
        return toRemove->data;
    }
}
void queueDestroy(queueRef queue)
{
    if(queue->size > 1){
        nodeRef focusNode = queue->last;
        while(focusNode != NULL){
            queuePoll(queue);
            focusNode = focusNode->next;
        }
    }
    free(queue->first);
    queue->size = -1;
}
