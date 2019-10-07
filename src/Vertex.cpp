#include "Vertex.h"

Vertex::Vertex(short name, short value): m_name(name), m_value(value)
{
    //ctor
}

Vertex::~Vertex()
{
    m_adjacencyList.clear();
    m_adjacencyList.resize(0);
}

unsigned short Vertex::getName()
{
    return m_name;
}

unsigned short Vertex::getValue()
{
    return m_value;
}

std::vector<Vertex*> Vertex::getAdjacencyList()
{
    return m_adjacencyList;
}

void Vertex::setName(unsigned short val)
{
    m_name = val;
}

void Vertex::setValue(unsigned short val)
{
    m_value = val;
}

void Vertex::setAdjacencyList(Vertex* v)
{
    m_adjacencyList.push_back(v);
}
