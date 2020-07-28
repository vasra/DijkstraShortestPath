#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <queue>
#include "Vertex.h"
#include "Graph.h"

class PriorityQueue
{
    private:
        struct node
        {
            std::shared_ptr<Vertex> vertex;
            unsigned int distance = 0;

            node(std::shared_ptr<Vertex>& v, unsigned int d = INT_MAX)
            {
                vertex = std::make_shared<Vertex>(*v);
                distance = d;
            }
            bool operator<(std::shared_ptr<const node>& n)
            {
                return this->distance < n->distance;
            }
            bool operator>(std::shared_ptr<node> n)
            {
                return this->distance > n->distance;
            }
            bool operator>=(std::shared_ptr<node> n)
            {
                return this->distance >= n->distance;
            }
            bool operator<=(std::shared_ptr<node> n)
            {
                return this->distance <= n->distance;
            }
            bool operator==(std::shared_ptr<node> n)
            {
                return this->distance == n->distance;
            }
        };
  
        struct compare
        {
            bool operator()(std::shared_ptr<const node>& a, std::shared_ptr<const node>& b)
            {
                return a->distance > b->distance;
            }
        };
        std::priority_queue < std::shared_ptr<const node>, std::vector<std::shared_ptr<const node>>, compare > nodes;

    public:
        PriorityQueue(/*Graph& g*/);
        virtual ~PriorityQueue();

        void printQueue();
        void addToQueue(std::shared_ptr<Vertex>& v, unsigned int d);
        std::shared_ptr<const node> pop();
};
#endif