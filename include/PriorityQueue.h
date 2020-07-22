#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>

typedef struct node node;

class PriorityQueue
{

    private:

    const node& head;

    public:
        PriorityQueue();
        virtual ~PriorityQueue();

        typedef struct node
        {
            short priority;
            short vertex;
            node *next;
            node *previous;
        }node;

        void chgPriority(node* node, short priority);
        void insertNode(node*);
        node* minPriority();
        const node& top();
        bool contains(node*);
        short sizeOfQueue();


};

#endif // PRIORITYQUEUE_H
