#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "LinkedListGeneric.h"

typedef struct DirectedGraphVertex_T {
    int value;
    int degree;
    bool visited;
    LinkedListGenericNode *edges;
} DirectedGraphVertex;

typedef struct DirectedGraph_T {
    int size;
    DirectedGraphVertex *vertexes;
} DirectedGraph;

DirectedGraph *DirectedGraphCreate(int size);
DirectedGraphVertex *DirectedGraphVertexAt(DirectedGraph *g, int pos);
void DirectedGraphAddEdge(DirectedGraph *g, int src, int dst);
bool DirectedGraphRouteExists(DirectedGraph *g, int src, int dst);
