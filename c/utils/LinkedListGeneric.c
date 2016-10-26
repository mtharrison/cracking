#include "LinkedListGeneric.h"

LinkedListGenericNode *LinkedListGenericNew (void *val, LinkedListGenericNode *next) {
    LinkedListGenericNode *node = (LinkedListGenericNode*) malloc(sizeof(LinkedListGenericNode));
    node->val = val;
    node->next = next;
    return node;
}

void LinkedListGenericDestroy(LinkedListGenericNode **nodePtr) {
    LinkedListGenericNode *node = *nodePtr;
    if (node->next == NULL) {
        free(node);
        return;
    }
    LinkedListGenericNode *curr = node;
    LinkedListGenericNode *next = node->next;
    while (next != NULL) {
        free(curr);
        curr = next;
        next = next->next;
    }
    free(curr);
    *nodePtr = NULL;
}

void LinkedListGenericAddItem(LinkedListGenericNode *node, void *val) {
    LinkedListGenericNode *ptr;
    ptr = node;

    // Advanced to the end of the list

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Create and insert the new element

    LinkedListGenericNode *newNode = LinkedListGenericNew(val, NULL);
    ptr->next = newNode;
}
