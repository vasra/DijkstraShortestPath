#include "Graph.h"

using namespace std;

int main()
{
    Graph *g = new Graph(50, 0.4, 1.0f, 10.0f);
    g->generate();
    g->printGraph();
    cout << "NOE: " << g->getNumOfEdges();
    return 0;
}
