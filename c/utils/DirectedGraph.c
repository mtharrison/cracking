#include "DirectedGraph.h"

DirectedGraph *DirectedGraphNodeCreate(int val) {
    DirectedGraph *graph = malloc(sizeof(DirectedGraph));
    graph->val = val;
    graph->edges = NULL;

    return graph;
}
