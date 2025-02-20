#include "Graph.h"
#include "Dijkstra.h"
#include <iostream>

int main()
{
    std::cout << "Graph Example" << std::endl;
    
    Graph* G1 = new Graph();
    
    G1->addNode("A", 0);
    G1->addNode("B", 1);
    G1->addNode("C", 2);
    G1->addNode("D", 3);
    G1->addNode("E", 4);
    G1->addNode("F", 4);

    G1->addEgde("A", "B", 6, true);
    G1->addEgde("A", "D", 1, true);
    G1->addEgde("B", "D", 2, true);
    G1->addEgde("B", "E", 2, true);
    G1->addEgde("B", "C", 5, true);
    G1->addEgde("C", "E", 5, true);
    G1->addEgde("D", "E", 1, true);

    Dijkstra* D1 = new Dijkstra(G1, G1->getNode("A"));
    D1->solve();
    
    D1->printShortestPath(G1->getNode("A"));
    D1->printShortestPath(G1->getNode("F"));
    
    D1->printShortestPath(G1->getNode("C"));
    
    std::cout << std::endl;
    D1->printShortestPath(G1->getNode("E"));
    std::cout << std::endl;
    
    delete G1;
    delete D1;
}
