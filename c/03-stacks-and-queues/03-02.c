#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define STACK_TERMINAL NULL

struct Stack {
    int min;
    LinkedListNode *head;
};

typedef struct Stack Stack;

Stack *StackNew() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->head = STACK_TERMINAL;
    stack->min = INT_MAX;
    
    return stack;
}

void StackDestroy(Stack **stackPtr) {
    
    Stack *stack = *stackPtr;
    
    if (stack->head != NULL) {
        LinkedListNode *prev = stack->head;
        LinkedListNode *curr = prev->next;
        stack->head = NULL;
        
        while (curr != NULL) {
            free(prev);
            prev = curr;
            curr = curr->next;
        }
        
        free(prev);
    }
    
    free(stack);
    
    *stackPtr = NULL;
}

void StackPush(Stack *stack, const int val) {
    // Create a new LinkedListNode to hold value
    LinkedListNode *newNode = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    newNode->val = val;
    newNode->next = stack->head;
    stack->head = newNode;
    if (val < stack->min) {
        stack->min = val;
    }
}

void StackPrint(Stack *stack) {
    LinkedListNode *head = stack->head;
    while (head != STACK_TERMINAL) {
        printf("%d <- ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv) {
    
    Stack *stack = StackNew();
    StackPrint(stack);
    printf("Current stack min is %d\n", stack->min);
    StackPush(stack, 12);
    printf("Current stack min is %d\n", stack->min);
    StackPush(stack, 4);
    printf("Current stack min is %d\n", stack->min);
    StackPrint(stack);
    StackDestroy(&stack);
}


