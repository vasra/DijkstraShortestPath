#ifndef VERTEX_H
#define VERTEX_H
#include <forward_list>
#include <map>

class Vertex
{
    public:
        Vertex(unsigned short name);
        virtual ~Vertex();
        std::forward_list<std::pair<Vertex&, int>>& getAdjacencyList();

    private:
        unsigned short m_name;                                        // The name of the vertex.  It will be a number, e.g. 0, 1, 2, 3 etc.
        std::forward_list<std::pair<Vertex&, int>> m_adjacencyList;    // A linked list containing the neighbouring vertices
};

#endif // VERTEX_H
