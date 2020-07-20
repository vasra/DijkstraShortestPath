#include "Graph.h"

using namespace std;

int main()
{
    Graph *g = new Graph(10, 0.4f, 1.0f, 10.0f);
    g->generate();
    g->printConnectivityMatrix();
    return 0;
}
