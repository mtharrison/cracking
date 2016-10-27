#include "DirectedGraph.h"

DirectedGraph *DirectedGraphNodeCreate(int val) {
    DirectedGraph *graph = malloc(sizeof(DirectedGraph));
    graph->val = val;
    graph->edges = NULL;
    graph->visited = false;

    return graph;
}

void DirectedGraphAddEdge(DirectedGraph *node1, DirectedGraph *node2) {

    // Start a list if the node has no edges

    if (node1->edges == NULL) {
        node1->edges = LinkedListGenericNew(node2, NULL);
        return;
    }

    // Otherwise just append to current list

    LinkedListGenericAddItem(node1->edges, node2);
}

bool DirectedGraphHasRoute(DirectedGraph *node1, DirectedGraph *node2) {

    if (node1->visited == true) {
        return false;
    }

    if (node1 == node2) {
        return true;
    }

    LinkedListGenericNode *tmp = node1->edges;

    while(tmp != NULL) {
        if (DirectedGraphHasRoute(tmp->val, node2)) {
            return true;
        }
        tmp = tmp->next;
    }

    node1->visited = true;

    return false;
}
