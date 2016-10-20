#include "Queue.h"

Queue *QueueNew() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    return q;
}
