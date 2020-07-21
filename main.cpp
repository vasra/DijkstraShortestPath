#include "Graph.h"

using namespace std;

int main()
{
    Graph g{ 10, 0.8f, 1, 10 };
    g.printConnectivityMatrix();
    return 0;
}
