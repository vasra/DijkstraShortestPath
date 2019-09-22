#include "Graph.h"
#include <vector>

using namespace std;

Graph::Graph(short numOfVertices, float density, short range): m_numOfVertices(numOfVertices), m_density(density), m_range(range){}
Graph::~Graph(){}

vector<Vertex> Graph::getVertices()
{
    return this->m_vertices;
}
