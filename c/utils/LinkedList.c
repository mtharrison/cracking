#include "LinkedList.h"

void LinkedListPrint (LinkedListNode *node) {
	if (node == NULL) {
		printf("Can't print NULL list");
		return;
	}
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

LinkedListNode *LinkedListNew (const int value, LinkedListNode *next) {
    LinkedListNode *node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    node->val = value;
    node->next = next;
    return node;
}

LinkedListNode *LinkedListQuickCreate (const int values[], const int num) {
    LinkedListNode *next = NULL;
    LinkedListNode *node;
    for (int i = num - 1; i >= 0; i--) {
        node = LinkedListNew(values[i], next);
        next = node;
    }

    return node;
}

void LinkedListDestroy(LinkedListNode **nodePtr) {
	LinkedListNode *node = *nodePtr;
	if (node->next == NULL) {
		free(node);
		return;
	}
	LinkedListNode *curr = node;
	LinkedListNode *next = node->next;
	while (next != NULL) {
		free(curr);
		curr = next;
		next = next->next;
	}
	free(curr);
	*nodePtr = NULL;
}
