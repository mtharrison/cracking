#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode_T {
    char val;
    struct LinkedListNode_T *next;
} LinkedListNode;

void LinkedListPrint (LinkedListNode *node);
LinkedListNode *LinkedListNew (const int value, LinkedListNode *next);
LinkedListNode *LinkedListQuickCreate (const int values[], const int num);
void LinkedListDestroy(LinkedListNode **nodePtr);
