#include "DirectedGraph.h"

DirectedGraph *DirectedGraphCreate(int size) {
    
    DirectedGraph *graph = (DirectedGraph *) malloc(sizeof(DirectedGraph));
    graph->size = size;
    graph->vertexes = (DirectedGraphVertex *) malloc(sizeof(DirectedGraphVertex) * size);
    
    // Initialize each vertex
    
    for (int i = 0; i < size; i++) {
        DirectedGraphVertex *v = graph->vertexes + i;
        v->value = 0;
        v->degree = 0;
        v->edges = NULL;
    }
    
    return graph;
}
