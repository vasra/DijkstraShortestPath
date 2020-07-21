#include "Vertex.h"

Vertex::Vertex(unsigned short name): m_name(name){}

Vertex::~Vertex(){}

std::forward_list<std::pair<Vertex&, int>>& Vertex::getAdjacencyList()
{
    return m_adjacencyList;
}