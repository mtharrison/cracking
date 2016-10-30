#include "DirectedGraph.h"

DirectedGraph *DirectedGraphCreate(int size) {
    DirectedGraph *graph = (DirectedGraph *) malloc(sizeof(DirectedGraph));
    graph->size = size;
    graph->vertexes = (DirectedGraphVertex *) malloc(sizeof(DirectedGraphVertex) * size);
    
    // Initialize each vertex
    
    for (int i = 0; i < size; i++) {
        DirectedGraphVertex *v = graph->vertexes + i;
        v->value = i;
        v->degree = 0;
        v->edges = NULL;
        v->visited = false;
    }
    
    return graph;
}

void DirectedGraphAddEdge(DirectedGraph *g, int src, int dst) {
    DirectedGraphVertex *srcV = g->vertexes + src;
    DirectedGraphVertex *dstV = g->vertexes + dst;
    
    srcV->degree++;
    
    if (srcV->edges == NULL) {
        srcV->edges = LinkedListGenericNew(dstV, NULL);
        return;
    }
    
    LinkedListGenericAddItem(srcV->edges, dstV);
    return;
}

DirectedGraphVertex *DirectedGraphVertexAt(DirectedGraph *g, int pos) {
    return g->vertexes + pos;
}
