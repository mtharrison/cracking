#include <assert.h>
#include <stdbool.h>
#include "DirectedGraph.h"

void test1() {
    DirectedGraph *node = DirectedGraphNodeCreate(42);
    assert(node->val == 42);
    assert(node->edges == NULL);
}

void test2() {
    DirectedGraph *node1 = DirectedGraphNodeCreate(42);
    DirectedGraph *node1 = DirectedGraphNodeCreate(43);

    DirectedGraphCreateEdge(node1, node2);
}

void test3() {}

void test4() {}


int main(int argc, char const **argv) {

    test1();
    test2();
    test3();
    test4();

    return 0;
}
