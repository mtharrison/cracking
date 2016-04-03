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

void removeItemFromMiddleOfList(Node *node) {

    if (!node || !node->next) {
        return;
    }

    *(node) = *(node->next);
}

int main(int argc, char **argv) {

    Node D = { 4, NULL };
    Node C = { 3, &D };
    Node B = { 2, &C };
    Node A = { 1, &B };

    printList(&A);
    removeItemFromMiddleOfList(&B);
    printList(&A);

    return 0;
}
