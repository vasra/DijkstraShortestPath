#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
    //ctor
}

PriorityQueue::~PriorityQueue()
{
    //dtor
}

void PriorityQueue::chgPriority( node* chgNode, short priority )
{
    chgNode->priority = priority;
    ( chgNode->previous )->next = chgNode->next;
    ( chgNode->next )->previous = chgNode->previous;
    chgNode->next = chgNode->previous = nullptr;

    insertNode(chgNode);
}

void PriorityQueue::insertNode( node* new_node )
{
    if( !contains( new_node ) )
        m_size++;

    if( m_head == nullptr )
    {
        setm_head(new_node);
        return;
    }

    for( node* iterator_node = top(); iterator_node->next != nullptr; iterator_node = iterator_node->next )
    {
        if( new_node->priority < iterator_node->priority )
        {
            if( iterator_node == top() )
            {
                setm_head( iterator_node );
            }
            else
            {
                new_node->next = iterator_node;
                new_node->previous = iterator_node->previous;
                ( new_node->next )->previous = new_node;
                ( new_node->previous )->next = new_node;
            }
            break;
        }
    }
}

void PriorityQueue::setm_head( node* head )
{
    if( !contains( head ) )
        m_size++;

    head->next = top();
    top()->previous = head;
    head->previous = nullptr;
    m_head = head;
}

PriorityQueue::node* PriorityQueue::Getm_head()
{
    node* old_head = top();
    (top()->next)->previous = nullptr;
    m_head = ( top()->next );
    m_size--;
    return old_head;
}

PriorityQueue::node* PriorityQueue::top()
{
    return m_head;
}

bool PriorityQueue::contains( node* search_node )
{
    for( node* iterator_node = top(); iterator_node->next != nullptr; iterator_node = iterator_node->next )
    {
        if( iterator_node->vertex == search_node->vertex )
            return true;
    }
    return false;
}

short PriorityQueue::Getm_sizeOfQueue()
{
    return m_size;
}
