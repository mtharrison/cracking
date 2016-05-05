#include <assert.h>
#include <stdio.h>
#include "LinkedList.h"


LinkedListNode *DetectLoopStartNode(LinkedListNode *start) {

    LinkedListNode *slow = start->next;
    LinkedListNode *fast = start->next->next;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
    }

    while (start != slow) {
        start = start->next;
        slow = slow->next;
    }

    return start;
}


int main(int argc, char **argv) {

    LinkedListNode *H = LinkedListNew( 8, NULL );
    LinkedListNode *G = LinkedListNew( 7, H );
    LinkedListNode *F = LinkedListNew( 6, G );
    LinkedListNode *E = LinkedListNew( 5, F );
    LinkedListNode *D = LinkedListNew( 4, E );
    LinkedListNode *C = LinkedListNew( 3, D );
    LinkedListNode *B = LinkedListNew( 2, C );
    LinkedListNode *A = LinkedListNew( 1, B );

    H->next = D;

    LinkedListNode *loopNode = DetectLoopStartNode(A);

    assert(loopNode->val == 4);

    return 0;
}
