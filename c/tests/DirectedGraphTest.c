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
    DirectedGraph *node2 = DirectedGraphNodeCreate(43);
    DirectedGraph *node3 = DirectedGraphNodeCreate(44);
    DirectedGraph *node4 = DirectedGraphNodeCreate(45);

    DirectedGraphAddEdge(node1, node2);
    DirectedGraphAddEdge(node2, node3);
    DirectedGraphAddEdge(node1, node4);
    DirectedGraphAddEdge(node3, node1);     // creates a cycle

    assert(node1->edges->val == node2);
    assert(node1->edges->next->val == node4);
    assert(node2->edges->val == node3);
    assert(node3->edges->val == node1);
    assert(node4->edges == NULL);

    assert(DirectedGraphHasRoute(node1, node3) == true);
    assert(DirectedGraphHasRoute(node2, node4) == false);
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
