#include "Graph.h"
#include "PriorityQueue.h"

unsigned int main()
{
    Graph g{ 10, 0.8f, 1, 10 };
    g.printGraph();
    
    std::cout << "Choose the starting and ending vertex to run Dijkstra's shortest path." << std::endl;
    unsigned short start, destination;
    do {
        std::cout << "Choose a value for the starting vertex from 0 to " << g.GetNumOfVertices() - 1 << std::endl;
        std::cout << "Start: ";
        std::cin  >> start;
    } while (start < 0 || start > g.GetNumOfVertices() - 1);

    do {
        std::cout << "Choose a value for the destination vertex from 0 to " << g.GetNumOfVertices() - 1 << std::endl;
        std::cout << "Destination: ";
        std::cin  >> destination;
    } while (destination < 0 || destination > g.GetNumOfVertices() - 1 || destination == start);

    return 0;
}
