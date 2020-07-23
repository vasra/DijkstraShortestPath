#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(Graph& g)
{
    for( auto& vertex : g.getVertices() )
        nodes.emplace_front(std::make_unique<node>(vertex));
}

PriorityQueue::~PriorityQueue()
{
    //dtor
}