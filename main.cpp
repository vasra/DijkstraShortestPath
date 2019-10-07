#include "Graph.h"
#include "PriorityQueue.h"

int main()
{
    Graph *g = new Graph(10, 0.4f, 1.0f, 10.0f);
    g->generateGraph();
    g->printAdjacencyMatrix();

    return 0;
}
