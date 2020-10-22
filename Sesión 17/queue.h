#include <stdlib.h>

struct strNode {
    char data;
    struct strNode* next;
};

typedef struct strNode* nodeRef;

struct strQueue {
    struct strNode *first, *last;
    int size;
};

typedef struct strQueue* queueRef;

queueRef queueCreate();

int queueSize(queueRef);

int queue_isEmpty(queueRef);

char queuePeek(queueRef);

void queueOffer(queueRef, char);

char queuePoll(queueRef);

void queueDestroy(queueRef);

void printQueue(queueRef);
