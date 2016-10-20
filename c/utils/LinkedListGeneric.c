#include "LinkedListGeneric.h"

LinkedListGenericNode *LinkedListGenericNew (void *val, LinkedListGenericNode *next) {
    LinkedListGenericNode *node = (LinkedListGenericNode*) malloc(sizeof(LinkedListGenericNode));
    node->val = val;
    node->next = next;
    return node;
}
