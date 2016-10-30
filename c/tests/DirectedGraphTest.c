#include <assert.h>
#include <stdbool.h>
#include "DirectedGraph.h"

void test1() {
    DirectedGraph *graph = DirectedGraphCreate(3);
    assert(graph->size == 3);
}

void test2() {}

void test3() {}

void test4() {}


int main(int argc, char const **argv) {

    test1();
    // test2();
    // test3();
    // test4();

    return 0;
}
