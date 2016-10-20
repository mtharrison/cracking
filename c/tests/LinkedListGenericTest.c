#include <assert.h>
#include "LinkedListGeneric.h"

int main(int argc, char const **argv) {

    int num1 = 5;
    LinkedListGenericNode *node = LinkedListGenericNew(&num1, NULL);
    int num2 = 10;
    LinkedListGenericNode *node2 = LinkedListGenericNew(&num2, node);

    assert(*((int *)node2->val) == 10);
    assert(node2->next == node);
    assert(*((int *)node2->next->val) == 5);
    assert(node2->next->next == NULL);

	return 0;
}
