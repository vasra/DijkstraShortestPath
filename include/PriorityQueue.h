#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <list>
#include "Vertex.h"
#include "Graph.h"

class PriorityQueue
{
    private:
        struct node {
            node(std::shared_ptr<Vertex>& vertex) {
                std::shared_ptr<Vertex> v = vertex;
                unsigned int weight = INT_MAX;
            }
        };
        std::list<std::unique_ptr<node>> nodes;
    public:
        PriorityQueue(Graph& g);
        virtual ~PriorityQueue();

};

#endif // PRIORITYQUEUE_H
