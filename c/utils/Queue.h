#include "LinkedListGeneric.h"

typedef struct Queue_T {
    LinkedListGenericNode *head;
    LinkedListGenericNode *tail;
} Queue;

Queue *QueueNew();
