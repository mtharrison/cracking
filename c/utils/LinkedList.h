#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode_t {
    char val;
    struct LinkedListNode_t *next;
} LinkedListNode;

void LinkedListPrint (LinkedListNode *node);
LinkedListNode *LinkedListNew (int value, LinkedListNode *next);
LinkedListNode *LinkedListQuickCreate (int values[], int num);
