#include <assert.h>
#include "LinkedListGeneric.h"

void test1() {
    int num1 = 5;
    LinkedListGenericNode *node = LinkedListGenericNew(&num1, NULL);
    int num2 = 10;
    LinkedListGenericNode *node2 = LinkedListGenericNew(&num2, node);

    assert(*((int *)node2->val) == 10);
    assert(node2->next == node);
    assert(*((int *)node2->next->val) == 5);
    assert(node2->next->next == NULL);
}

void test2() {
    int num1 = 5;
    LinkedListGenericNode *node = LinkedListGenericNew(&num1, NULL);
    int num2 = 10;
    LinkedListGenericAddItem(node, &num2);

    assert(*((int *)node->val) == 5);
    assert(*((int *)node->next->val) == 10);
    assert(node->next->next == NULL);
}

int main(int argc, char const **argv) {

    test1();
    test2();

	return 0;
}
