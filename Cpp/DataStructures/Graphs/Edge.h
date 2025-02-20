#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Node;
class Edge {
public:
    Edge(Node* a, Node* b, int w);
    
    int getWeight();
    Node* getEndNode();
    Node* getStartNode();
    
private:
    Node* startNode;
    Node* endNode;
    int weight;
};

#endif // EDGE_H
