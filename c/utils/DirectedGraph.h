#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "LinkedListGeneric.h"

typedef struct DirectedGraph_T {
    int val;
    bool visited;
    LinkedListGenericNode *edges;
} DirectedGraph;

DirectedGraph *DirectedGraphNodeCreate(int val);
void DirectedGraphAddEdge(DirectedGraph *node1, DirectedGraph *node2);
bool DirectedGraphHasRoute(DirectedGraph *node1, DirectedGraph *node2);
