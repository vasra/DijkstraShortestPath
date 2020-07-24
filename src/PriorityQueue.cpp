#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(Graph& g)
{
    for( auto& vertex : g.getVertices() )
        nodes.emplace_back(std::make_shared<node>(vertex));
}

PriorityQueue::~PriorityQueue()
{
    //dtor
}

std::shared_ptr<PriorityQueue::node>& PriorityQueue::top()
{
    return nodes.front();
}

int PriorityQueue::left(int i)
{
    return (2 * i + 1);
}

int PriorityQueue::right(int i)
{
    return (2 * i + 2);
}

int PriorityQueue::parent(int i)
{
    return (i - 1) / 2;
}

int PriorityQueue::min_child(int i)
{
    if (left(i) < nodes.size() && nodes[left(i)] < nodes[i])
        return left(i);

    if (right(i) < nodes.size() && nodes[right(i)] < nodes[i])
        return i * 2;

    return i * 2 + 1;
}

void PriorityQueue::insert(std::shared_ptr<node>& ptr)
{
    nodes.push_back(ptr);
    percolate_up(nodes.size() - 1);
}

void PriorityQueue::delete_min()
{
    
}

void PriorityQueue::percolate_up(int i)
{
    if (i > 0 && nodes[i] < nodes[parent(i)])
    {
        swap(i, parent(i));
        i = parent(i);
        percolate_up(i);
    }
}

void PriorityQueue::swap(int a, int b)
{
    std::shared_ptr<node> temp = nodes[a];
    nodes[a] = nodes[b];
    nodes[b] = temp;
}