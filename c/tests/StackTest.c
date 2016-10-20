#include <assert.h>
#include "Stack.h"

int main(int argc, char const **argv) {

    Stack *stack = StackNew();

    assert(stack->top->val == STACK_EMPTY_VAL);
    assert(stack->top->next == NULL);

    StackPush(stack, 5);
    assert(StackPeek(stack) == 5);
    StackPush(stack, 10);
    assert(StackPeek(stack) == 10);

    assert(StackPop(stack) == 10);
    assert(StackPop(stack) == 5);
    assert(stack->top->val == STACK_EMPTY_VAL);

    StackDestroy(&stack);
    assert(stack == NULL);

	return 0;
}
