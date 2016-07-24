#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack *StackNew() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    LinkedListNode *node = LinkedListNew(STACK_EMPTY_VAL, NULL);
    stack->top = node;
    return stack;
}

void StackPrint (Stack *stack) {
    LinkedListPrint(stack->top);
}

void StackPush (Stack *stack, int val) {
    LinkedListNode *node = LinkedListNew(val, stack->top);
    stack->top = node;
}

int StackPeek (Stack *stack) {
    return stack->top->val;
}

int StackPop (Stack *stack) {
    int val = stack->top->val;
    if (val != STACK_EMPTY_VAL) {
        stack->top = stack->top->next;     // If not at bottom proceed pointer
    }
    return val;
}
