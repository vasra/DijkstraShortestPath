#ifndef VERTEX_H
#define VERTEX_H
#include <forward_list>
#include <map>
#include <memory>

class Vertex
{
    public:
        Vertex(unsigned short name);
        virtual ~Vertex();
        std::forward_list<std::pair<unsigned short, unsigned int>>& getAdjacencyList();
        unsigned short getName();
        void setPrevious(std::shared_ptr<Vertex>& prev);

    private:
        unsigned short name;                                                           // The name of the vertex.  It will be a number, e.g. 0, 1, 2, 3 etc.
        std::forward_list<std::pair<unsigned short, unsigned int>> adjacencyList;      // A linked list containing the neighbouring vertices
        std::shared_ptr<Vertex> previous = nullptr;                                    // A pointer to the previous vertex in Dijkstra's shortest path
};
#endif