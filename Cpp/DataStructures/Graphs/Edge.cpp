#include "Edge.h"

Edge::Edge(Node* a, Node* b, int w)
{
    startNode = a;
    endNode = b;
    weight = w; 
}

int Edge::getWeight()      { return weight;   }
Node* Edge::getEndNode()   { return endNode;   }
Node* Edge::getStartNode() { return startNode; }
