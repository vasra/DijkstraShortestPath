#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>

typedef struct m_node node;

class PriorityQueue
{

    private:

    const node& m_head;

    public:
        PriorityQueue();
        virtual ~PriorityQueue();

        typedef struct m_node
        {
            short priority;
            short vertex;
            m_node *next;
            m_node *previous;
        }node;

        void chgPriority(node* node, short priority);
        void insertNode(node*);
        node* minPriority();
        const node& top();
        bool contains(node*);
        short sizeOfQueue();


};

#endif // PRIORITYQUEUE_H
