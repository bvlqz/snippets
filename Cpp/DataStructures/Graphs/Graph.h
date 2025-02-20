#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "Edge.h"
#include "Node.h"

/*
A graph

(a)-(b)
 |
(c)
 
(x) -> Vertex / Node
 -  -> Edge

Becerra, Jorge Alberto <jorge@koruke.com>
Code
2021-07-10
*/

class Graph {

public:
    Graph();
    ~Graph();

    // Does there exist a path between node A and node B
    void checkConnectivity(std::string a, std::string b); // Union find data structure, BFS, DFS

    // Does the weighted diagraph have any negative cicles? 
    void checkNegativeCicles(); // Bellman-Ford, Floyd-Warshall

    // Self contained cicles within a directed graph, SCCs 
    void checkStronglyConnectedComponents(); // Tarjan's, Kosaraju's

    // Given a list of cicties and the distances between each pair of cities
    // What is the shortest possible route that visits each city exactly once
    // and returns to the origin city? 
    void travelingSalesman(); // Held-Karp, branch and bound, etc.
    
    // Edges in a graph whose removal increases the number of connected components
    // Hints weak points, bottlenecks or vulnerabilities
    // AKA Bridges
    void findCutEdges();

    // Node in a graph whose removal increases the number of connected components
    // AKA Articulation Points
    void findCutVertices();

    // Is a subset of the edges of a connected, edge-weighted graph that connects
    // al the vertices together, without any cicles and with the minimun possible 
    // total edge weight
    void minimunSpanningTree(); // (MST) Kruskal's, Prim's, Borůvka's

    // With an infinite input source how much "flow" can we push through the network
    void maxFlow(); // (Flow networks) Ford-Fulkerson, Edmonds-Karp, Dinic's algoritm

    // Find the shortest path of edges from node A to node B
    void shortestPath(); // BFS (unweighted graph), Dijkstra's, Bellman-Ford, Floyd-Warshall, A*, etc.
    
    
    
    void breadthFirstSearch(std::string at); // BFS
    void dephtFirstSearch(std::string at); // DFS

    void addNode(std::string name, int data);
    Node* getNode(std::string name);
    void getNodes(std::vector<Node*>& n);
    
    void printAdjacencyMatrix();
    void printAdjacencyList();
    
    
    
    void addEgde(std::string a, std::string b, int weight, bool undirected=true);

private:
    std::vector<Node*> nodes;
    std::map<std::string, Node*> nodeLocator;
    
    
    int nodeCount;
    
    static std::vector<bool> tempDFSVisited;
    
    // Good for dense graphs (space efficient)
    // Not so good for sparse graphs
    std::vector< std::vector< int > > adjacencyMatrix;
    
    
    // Great for sparse graps
    // Efficient when iterating all the edges
    // std::map<std::string, int> adjacencyList;
    
    
    
    // Used by Depht First Search
    std::map< std::string, bool > visitedMap;
    int groupCount;
    
    // Queue for Breadth First Search
    
    
};

#endif // GRAPH_H
