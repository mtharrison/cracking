#include <assert.h>
#include <stdio.h>
#include "Stack.h"

#define CHECK_EMPTY(ret)                                                                \
    if (stack->numElements[stackNum] == 0) {                                            \
        printf("Stack %d empty dude!", stackNum);                                       \
        return ret;                                                                     \
    }

#define CHECK_EXIST(ret)                                                                \
    if (stackNum < 0 || stackNum >= stack->numStacks) {                                 \
        printf("Stack %d doesn\'t exist!\n", stackNum);                                 \
        return ret;                                                                     \
    }

#define CHECK_FULL()                                                                    \
    if (stack->numElements[stackNum] >= (stack->totalLength / stack->numStacks)) {      \
        printf("Stack %d already full dude! Can\'t push %d.\n", stackNum, val);         \
        return;                                                                         \
    }                                                                                   \

// Take an array of size N and make K stacks.
// for every queue K, the Ith item goes at position (I * K)

// Value |   0 |   0 |   0 |   0 |   0 |   0 |   0 |   0 |   0 |
// Stack |   0 |   1 |   2 |   0 |   1 |   2 |   0 |   1 |   2 |

struct NStack {
    int *arr;
    int *numElements;
    int numStacks;
    int totalLength;
};

typedef struct NStack NStack;

NStack *NStackCreate(int numStacks, int numElementsPerStack) {

    NStack *stack = malloc(sizeof(NStack));
    stack->numStacks = numStacks;
    stack->totalLength = numStacks * numElementsPerStack;
    stack->arr = (int*) malloc(stack->totalLength * sizeof(int));
    stack->numElements = (int*) malloc(numStacks * sizeof(int));

    for (int i = 0; i < numStacks; i++) {
        stack->numElements[i] = 0;
    }

    for (int i = 0; i < stack->totalLength; i++) {
        stack->arr[i] = 0;
    }

    return stack;
}

void NStackFree(NStack *stack) {

    free(stack->numElements);
    free(stack->arr);
    free(stack);
}

void NStackPush(NStack *stack, int stackNum, int val) {

    CHECK_EXIST();
    CHECK_FULL();

    stack->arr[stackNum + (stack->numElements[stackNum]) * stack->numStacks] = val;
    stack->numElements[stackNum]++;
}

void NStackPrint(NStack *stack) {

    for (int i = 0; i < stack->totalLength; i++) {
        printf("| %3d ", stack->arr[i]);
    }
    printf("|\n");
    for (int i = 0; i < stack->totalLength; i++) {
        printf("| %3d ", i % stack->numStacks);
    }
    printf("|\n");
}

int NStackPop(NStack *stack, int stackNum) {

    CHECK_EXIST(-1);
    CHECK_EMPTY(-1);

    int val = stack->arr[stackNum + ((stack->numElements[stackNum] - 1) * stack->numStacks)];
    stack->numElements[stackNum]--;

    return val;
}

int NStackPeek(NStack *stack, int stackNum) {

    CHECK_EXIST(-1);
    CHECK_EMPTY(-1);

    return stack->arr[stackNum + ((stack->numElements[stackNum] - 1) * stack->numStacks)];
}

int main(int argc, char **argv) {

    NStack *stack = NStackCreate(3, 3);

    NStackPrint(stack);

    NStackPush(stack, 0, 1);
    NStackPush(stack, 0, 4);
    NStackPush(stack, 0, 7);

    NStackPrint(stack);

    NStackPush(stack, 1, 2);
    NStackPush(stack, 1, 5);
    NStackPush(stack, 1, 8);

    NStackPrint(stack);

    NStackPush(stack, 2, 3);
    NStackPush(stack, 2, 6);
    NStackPush(stack, 2, 9);

    NStackPrint(stack);

    printf("%d\n", NStackPeek(stack, 0));
    printf("%d\n", NStackPeek(stack, 1));
    printf("%d\n", NStackPeek(stack, 2));

    NStackPrint(stack);

    printf("%d\n", NStackPop(stack, 0));
    printf("%d\n", NStackPop(stack, 1));
    printf("%d\n", NStackPop(stack, 2));

    NStackPrint(stack);

    printf("%d\n", NStackPeek(stack, 0));
    printf("%d\n", NStackPeek(stack, 1));
    printf("%d\n", NStackPeek(stack, 2));

    NStackFree(stack);

    return 0;
}
