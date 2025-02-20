#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <string>
#include <vector>
#include <limits>

#include "Graph.h"
#include "Node.h"

struct NodeInfo
{
    bool visited;
    
    // Shortest known distance
    int distance;
    
    // Previous node
    Node* previous;
    NodeInfo()
    {
        distance = std::numeric_limits<int>::max();
        previous = nullptr;
        visited = false;
    }
};

class Dijkstra
{
public:
    Dijkstra(Graph* g, Node* n);
    ~Dijkstra();
    
    void solve();
    
    void printTable();
    void printShortestPath(Node* n);
    
private:
    void solve(Node* n);
    
    Node* startingNode;
    std::map<std::string, NodeInfo*> info;
};


#endif // DIJKSTRA_H
