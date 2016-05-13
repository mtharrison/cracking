#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define STACK_EMPTY_VAL -1

typedef struct Stack_t {
    LinkedListNode *top;
} Stack;

Stack *StackNew();
int StackPeek (Stack *stack);
int StackPop (Stack *stack);
void StackPrint (Stack *top);
void StackPush (Stack *top, int val);
