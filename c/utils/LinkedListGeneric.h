#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListGenericNode_T {
    void *val;
    struct LinkedListGenericNode_T *next;
} LinkedListGenericNode;

LinkedListGenericNode *LinkedListGenericNew(void *val, LinkedListGenericNode *next);
void LinkedListGenericDestroy(LinkedListGenericNode **nodePtr);
void LinkedListGenericAddItem(LinkedListGenericNode *node, void *val);
