#include <assert.h>
#include <stdio.h>

typedef struct node_t {
    char val;
    struct node_t *next;
} Node;

Node *kthToLast(Node *list, int k) {

    // Keep an equisitant set of pointer on the list and advance to the end
    //
    // e.g. k = 2, n = 4; return 1
    //     a-------b
    // 0-->1-->2-->3-->
    //
    // e.g. k = 4, n = 4; return NULL
    // ------------b
    // 0-->1-->2-->3-->

    int a = -k;
    int b = 0;

    while (((list + b))->next) {
        a++;
        b++;
    }

    if (a < 0) {
        return NULL;
    }

    return list + a;
}

int main(int argc, char **argv) {

    Node D = { 4, NULL };
    Node C = { 3, &D };
    Node B = { 2, &C };
    Node A = { 1, &B };

    assert(kthToLast(&A, 0)->val == 4);
    assert(kthToLast(&A, 1)->val == 3);
    assert(kthToLast(&A, 2)->val == 2);
    assert(kthToLast(&A, 3)->val == 1);
    assert(kthToLast(&A, 4) == NULL);

    return 0;
}
