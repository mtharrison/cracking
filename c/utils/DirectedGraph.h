#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "LinkedListGeneric.h"

typedef struct DirectedGraph_T {
    int val;
    LinkedListGenericNode *edges;
} DirectedGraph;

DirectedGraph *DirectedGraphNodeCreate(int val);
