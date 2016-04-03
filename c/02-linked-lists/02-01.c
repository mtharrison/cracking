#include <stdio.h>
#include "BitVector.h"

typedef struct node_t {
    char val;
    struct node_t *next;
} Node;

void printList (Node *node) {

    for (;;) {
        printf("%d --> ", node->val);
        node = node->next;

        if (!node) {
            break;
        }
    }
    printf("NULL\n");
}

// This uses a BitVector to store lookups against each value
// It only requires a single pass over the list
// so it's O(n) time and O(1) space

void removeListDuplicates(Node *node) {

    BitVector *bv = BitVectorNew(255);
    Node *previous = node;

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

void removeListDuplicatesNoBuffer(Node *node) {

    while (node) {
        Node *runner = node->next;
        Node *prev = node;

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

    Node D = { 16, NULL };
    Node C = { 2, &D };
    Node B = { 2, &C };
    Node A = { 16, &B };

    printList(&A);
    removeListDuplicates(&A);
    printList(&A);

    Node H = { 16, NULL };
    Node G = { 2, &H };
    Node F = { 2, &G };
    Node E = { 16, &F };

    printList(&E);
    removeListDuplicatesNoBuffer(&E);
    printList(&E);

    return 0;
}
