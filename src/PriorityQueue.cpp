#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
    //ctor
}

PriorityQueue::~PriorityQueue()
{
    //dtor
}

void PriorityQueue::chgPriority(node* Node, short priority)
{
    Node->priority = priority;
    (Node->previous)->next = Node->next;
    (Node->next)->previous = Node->previous;
    Node->next = Node->previous = nullptr;


    for( node* iterator_node = top(); iterator_node->next != nullptr; iterator_node->next = (iterator_node->next)->next)
    {

    }
}

const node& PriorityQueue::top()
{
    return m_head;
}
