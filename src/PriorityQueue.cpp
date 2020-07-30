#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {}

PriorityQueue::~PriorityQueue() {
    while (!nodes.empty())
        nodes.pop();
}

void PriorityQueue::printQueue() {
    std::cout << "Priority queue" << std::endl << "Vertex | distance" << std::endl;
    while(!nodes.empty()) {
        std::cout << nodes.top()->vertex->getName() << " | " << nodes.top()->distance << std::endl;
        nodes.pop();
    }
}

void PriorityQueue::addToQueue(std::shared_ptr<Vertex> v, unsigned int d) {
    nodes.emplace(std::make_shared<node>(v, d));
}

const std::shared_ptr<Vertex> PriorityQueue::pop() {
    const std::shared_ptr<Vertex> v = nodes.top()->vertex;
    nodes.pop();
    return v;
}