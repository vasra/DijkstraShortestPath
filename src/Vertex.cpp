#include "Vertex.h"

Vertex::Vertex(unsigned short name): name(name){}

Vertex::~Vertex(){}

std::forward_list<std::pair<short, int>>& Vertex::getAdjacencyList()
{
    return adjacencyList;
}

unsigned short Vertex::getName()
{
    return name;
}