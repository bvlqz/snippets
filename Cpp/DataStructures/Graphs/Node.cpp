#include "Node.h"

unsigned int Node::count = 0;

Node::Node(std::string s, int d)
{
    name = s;
    data = d;
    
    count++;
    
    std::cout
        << "Created node "
        << this->name
        << " with data "
        << this->data
        << "\ttotal node count is: "
        << count
        << std::endl;
}


void Node::addNeighbor(Node * node, int weight) { addEdge(node, weight); }
void Node::addEdge(Node * node, int weight)
{
    Edge* e = new Edge(this, node, weight);
    
    std::cout
        << "Node "
        << this->name
        << " now has neighbor "
        << e->getEndNode()->name
        << " with weight "
        << e->getWeight()
        << std::endl;
    
    neighbors.push_back(e);
}

std::string Node::getName() { return name; }
void Node::getNeighbors(std::vector<Edge*>& n) { n = neighbors; }
