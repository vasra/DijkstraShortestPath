#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>

class PriorityQueue
{
    private:
        typedef struct m_node
        {
            short priority;
            short vertex;
            m_node *next;
            m_node *previous;
        }node;
        node* m_head;
        short m_size;

    public:
        PriorityQueue();
        virtual ~PriorityQueue();

        void chgPriority(node* node, short priority);
        void insertNode(node* new_node);
        void setm_head(node* head);
        node* getm_head();
        node* top();
        bool contains(node*);
        short getm_sizeOfQueue();
};

#endif // PRIORITYQUEUE_H
