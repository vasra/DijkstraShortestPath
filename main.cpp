#include "Graph.h"
#include "PriorityQueue.h"

unsigned int main()
{
    Graph g{ 10, 0.8f, 1, 10 };
    PriorityQueue q{ g };
    g.printGraph();
    q.printQueue();
    return 0;
}
