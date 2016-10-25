#include "Queue.h"

Queue *QueueNew() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void *QueueDequeue(Queue *q) {

    // queue empty

    if (q->tail == NULL &&
        q->head == NULL) {
        return NULL;
    }

    void *val = q->head->val;

    if (q->tail == q->head) {
        q->tail = q->head->next;
    }

    q->head = q->head->next;

    return val;
}

void QueueEnqueue(Queue *q, void *val) {

    // Build a queue item

    LinkedListGenericNode *item = LinkedListGenericNew(val, NULL);

    // Check if queue is empty

    if (q->tail == NULL &&
        q->head == NULL) {
        q->tail = item;
        q->head = item;
        return;
    }

    q->tail->next = item;
    q->tail = item;
    return;
}

void QueueDestroy(Queue **qPtr) {
    Queue *q = *qPtr;
    LinkedListGenericNode *item = q->head;
    while (item != NULL) {
        LinkedListGenericDestroy(&item);
        item = item->next;
    }
    free(q);
    *qPtr = NULL;
}
