#include <assert.h>
#include "Queue.h"

int main(int argc, char const **argv) {

    Queue *q = QueueNew();

    assert(QueueDequeue(q) == NULL);

    int value = 42;
    QueueEnqueue(q, &value);

    void *item = QueueDequeue(q);
    assert((*(int*)item) == 42);
    assert(QueueDequeue(q) == NULL);

    int value2 = 43;
    QueueEnqueue(q, &value2);
    int value3 = 44;
    QueueEnqueue(q, &value3);

    item = QueueDequeue(q);
    assert((*(int*)item) == 43);
    item = QueueDequeue(q);
    assert((*(int*)item) == 44);

    assert(QueueDequeue(q) == NULL);
    assert(QueueDequeue(q) == NULL);

    QueueDestroy(&q);
    assert(q == NULL);

	return 0;
}
