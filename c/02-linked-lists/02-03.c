#include <stdio.h>
#include "BitVector.h"
#include "LinkedList.h"


void removeItemFromMiddleOfList(LinkedListNode *node) {

    if (!node || !node->next) {
        return;
    }

    *(node) = *(node->next);
}

int main(int argc, char **argv) {

    LinkedListNode D = { 4, NULL };
    LinkedListNode C = { 3, &D };
    LinkedListNode B = { 2, &C };
    LinkedListNode A = { 1, &B };

    LinkedListPrint(&A);
    removeItemFromMiddleOfList(&B);
    LinkedListPrint(&A);

    return 0;
}
