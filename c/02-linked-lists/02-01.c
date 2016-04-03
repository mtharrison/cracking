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

void removeListDuplicates (Node *node) {

    BitVector *bv = BitVectorNew(255);

    for (;;) {

        if (!node->next) {
            break;
        }

        BitVectorSet(bv, node->val);

        // Check if the next item in the list is a duplicate

        if (BitVectorGet(bv, node->next->val)) {

            // Find the next element that isn't a duplicate OR the end

            Node *temp = node->next;

            for (;;) {

                if (temp == NULL) {
                    node->next = NULL;
                    return;
                }

                if (!BitVectorGet(bv, temp->val)) {
                    node->next = temp;
                    break;
                }

                temp = temp->next;
            }
        }

        node = node->next;
    }
}

int main(int argc, char **argv) {

    Node D = { 12, NULL };
    Node C = { 6, &D };
    Node B = { 8, &C };
    Node A = { 12, &B };

    printList(&A);
    removeListDuplicates(&A);
    printList(&A);

    return 0;
}
