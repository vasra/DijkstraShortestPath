#include "Graph.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Graph *g = new Graph(50, 0.4, 1.0f, 10.0f);
    g->generate();
    g->printGraph();
    return 0;
}
