#include "LinkedList.h"

void LinkedListPrint (LinkedListNode *node) {

    for (;;) {
        printf("%d", node->val);
        node = node->next;

        if (!node) {
            break;
        }

        printf(" --> ");
    }
    printf("\n");
}

LinkedListNode *LinkedListNew (int value, LinkedListNode *next) {

    LinkedListNode *node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    node->val = value;
    node->next = next;
    return node;
}

LinkedListNode *LinkedListQuickCreate (int values[], int num) {

    LinkedListNode *next = NULL;
    LinkedListNode *node;

    for (int i = num - 1; i >= 0; i--) {
        node = LinkedListNew(values[i], next);
        next = node;
    }

    return node;
}
