#include "LinkedListGeneric.h"

typedef LinkedListGenericNode QueueItem;

typedef struct Queue_T {
    QueueItem *head;
    QueueItem *tail;
} Queue;

Queue *QueueNew();
void *QueueDequeue(Queue *q);
void QueueEnqueue(Queue *q, void *val);
void QueueDestroy(Queue **qPtr);
