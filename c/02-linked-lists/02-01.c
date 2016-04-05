#include <stdio.h>
#include "BitVector.h"
#include "LinkedList.h"


// This uses a BitVector to store lookups against each value
// It only requires a single pass over the list
// so it's O(n) time and O(1) space

void removeListDuplicates(LinkedListNode *node) {

    BitVector *bv = BitVectorNew(255);
    LinkedListNode *previous = node;

    while (node != NULL) {
        if (BitVectorGet(bv, node->val)) {
            previous->next = node->next;
        } else {
            BitVectorSet(bv, node->val);
            previous = node;
        }
        node = node->next;
    }
}

// This has to check N - 1 - i elements for every ith element
// in the list meaning it has O(n^2) time and O(1) space
// it doesn't however need to allocate any additional memory (aside from 2 pointers)

void removeListDuplicatesNoBuffer(LinkedListNode *node) {

    while (node) {
        LinkedListNode *runner = node->next;
        LinkedListNode *prev = node;

        while (runner) {
            if (runner->val == node->val) {
                prev->next = runner->next;
            }
            else {
                prev = runner;
            }
            runner = runner->next;
        }

        node = node->next;
    }
}

int main(int argc, char **argv) {

    LinkedListNode D = { 16, NULL };
    LinkedListNode C = { 2, &D };
    LinkedListNode B = { 2, &C };
    LinkedListNode A = { 16, &B };

    LinkedListPrint(&A);
    removeListDuplicates(&A);
    LinkedListPrint(&A);

    LinkedListNode H = { 16, NULL };
    LinkedListNode G = { 2, &H };
    LinkedListNode F = { 2, &G };
    LinkedListNode E = { 16, &F };

    LinkedListPrint(&E);
    removeListDuplicatesNoBuffer(&E);
    LinkedListPrint(&E);

    return 0;
}
