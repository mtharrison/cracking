#include <assert.h>
#include <stdbool.h>
#include "DirectedGraph.h"

void test1() {
    DirectedGraph *g = DirectedGraphCreate(3);
    assert(g->size == 3);
    
    DirectedGraphVertex *v1 = DirectedGraphVertexAt(g, 0);
    assert(v1->value == 0);
    assert(v1->degree == 0);
    assert(v1->edges == NULL);
    
    DirectedGraphVertex *v2 = DirectedGraphVertexAt(g, 1);
    assert(v2->value == 1);
    assert(v2->degree == 0);
    assert(v2->edges == NULL);
    
    DirectedGraphVertex *v3 = DirectedGraphVertexAt(g, 2);
    assert(v3->value == 2);
    assert(v3->degree == 0);
    assert(v3->edges == NULL);
}

void test2() {
    DirectedGraph *g = DirectedGraphCreate(3);
    DirectedGraphAddEdge(g, 0, 1);
    DirectedGraphAddEdge(g, 0, 2);
    
    DirectedGraphVertex *v0 = DirectedGraphVertexAt(g, 0);
    
    assert(v0->degree == 2);
    assert(v0->edges->val == DirectedGraphVertexAt(g, 1));
    assert(v0->edges->next->val == DirectedGraphVertexAt(g, 2));
}

void test3() {}

void test4() {}


int main(int argc, char const **argv) {

    test1();
    test2();
    // test3();
    // test4();

    return 0;
}
