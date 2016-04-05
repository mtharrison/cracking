#include "LinkedList.h"

void LinkedListPrint (LinkedListNode *node) {

    for (;;) {
        printf("%d --> ", node->val);
        node = node->next;

        if (!node) {
            break;
        }
    }
    printf("NULL\n");
}

LinkedListNode *LinkedListNew (int value, LinkedListNode *next) {

    LinkedListNode *node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    node->val = value;
    node->next = next;
    return node;
}
