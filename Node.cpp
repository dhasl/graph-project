#include "Node.h"

void Node::addEdge(Node* dest, int weight) {
    neighbors[dest] = weight;
}

std::vector<Node*> Node::getNeighborNodes() {
    std::vector<Node*> list;
    for (auto& n : neighbors) {
        list.push_back(n.first);
    }
    return list;
}
int Node::getID() const {
    return id;
}

void Node::printNeighbors() {
    std::cout << "Neighbors of Node " << id << "\n";
    for (auto& n : neighbors) {
        std::cout << "  Node " << n.first->getID() << " with weight " << n.second << "\n";
    }
}
