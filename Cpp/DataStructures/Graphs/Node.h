#ifndef NODE_H
#define NODE_H

#include "Edge.h"

#include <string>
#include <iostream>
#include <vector>

class Edge;
class Node {
public:
    Node(std::string name, int data);
    
    void addEdge(Node * node, int weight);
    void addNeighbor(Node * node, int weight);
    
    void getNeighbors(std::vector<Edge*>& n);
    std::string getName();
    
private:
    static unsigned int count; 
    
    std::string name;
    int data;
    
    std::vector<Edge*> neighbors;
    
    // Assign an integet value to each Node to be able
    // to thell them apart, and separate by groups
    
    // If node A has a different groupID than node B, then
    // the nodes are not connected
    
    // DFS
    int groupID;
    
};


#endif // NODE_H
