#include <assert.h>
#include "LinkedList.h"

int main(int argc, char const **argv) {

    LinkedListNode *node = LinkedListNew(5, NULL);
    LinkedListNode *node2 = LinkedListNew(10, node);

    assert(node2->val == 10);
    assert(node2->next == node);
    assert(node2->next->val == 5);
    assert(node2->next->next == NULL);

    const int values[] = {1,2,3};
    LinkedListNode *node3 = LinkedListQuickCreate(values, 3);
    assert(node3->val == 1);
    assert(node3->next->val == 2);
    assert(node3->next->next->val == 3);

    LinkedListDestroy(&node3);
    assert(node3 == NULL);

	return 0;
}
