#ifndef VERTEX_H
#define VERTEX_H
#include <vector>

class Vertex
{
    public:
        Vertex(short name);
        virtual ~Vertex();

    private:
        short m_name;                           // The name of the vertex.  It will be a number, e.g. 1, 2, 3 etc.
        std::vector<Vertex> m_adjacencyList;    // A vector containing the neighbouring vertices
};

#endif // VERTEX_H
