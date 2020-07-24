#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Vertex.h"
#include "Graph.h"

class PriorityQueue
{
    private:
        struct node
        {
            std::shared_ptr<Vertex> vertex;
            unsigned int weight;

            node(std::shared_ptr<Vertex>& v, int w = INT_MAX)
            {
                std::shared_ptr<Vertex> vertex = v;
                unsigned int weight = w;
            }
            bool operator<(node& n)
            {
                return weight < n.weight;
            }
         
        };
        std::vector<std::shared_ptr<node>> nodes;

    public:
        PriorityQueue(Graph& g);
        virtual ~PriorityQueue();

        std::shared_ptr<node>& top();
        int left(int i);
        int right(int i);
        int parent(int i);
        int min_child(int i);
        void insert(std::shared_ptr<node>& ptr);
        void delete_min();
        void percolate_up(int i);
        void percolate_down(int i);
        void swap(int a, int b);
};

#endif // PRIORITYQUEUE_H
