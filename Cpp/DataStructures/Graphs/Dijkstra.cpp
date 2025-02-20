#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph* g, Node* n)
{
    startingNode = n;
    std::vector<Node*> nodes;
    g->getNodes(nodes);
    
    for (auto & node : nodes)
    {
        NodeInfo* ni = new NodeInfo();
        std::pair<std::string, NodeInfo*> i (node->getName(), ni);
        info.insert(i);
    }

    info.find(n->getName())->second->distance = 0;
}


Dijkstra::~Dijkstra()
{}

void Dijkstra::solve()
{
    info.find(this->startingNode->getName())->second->distance = 0;
    solve(this->startingNode);    
}

void Dijkstra::solve(Node* n)
{
    NodeInfo* node = info.find(n->getName())->second;
    
    std::vector<Edge*> neighbors;
    n->getNeighbors(neighbors);
    
    // Holds the lowest distance to a neighbor of the current node
    int neighborBestDist = std::numeric_limits<int>::max();
    Node* nextNode = nullptr;
    
    for (auto const& neighbor : neighbors)
    {
        NodeInfo* neighborNode = info.find(neighbor->getEndNode()->getName())->second;
        if (neighborNode->visited) continue;
        int distToNeighbor = node->distance + neighbor->getWeight();
        if (distToNeighbor < neighborNode->distance)
        {
            neighborNode->distance = distToNeighbor;
            neighborNode->previous = n;
            
            if (distToNeighbor < neighborBestDist)
                nextNode = neighbor->getEndNode();
        }
    }
    printTable();
    node->visited = true;
    if (nextNode != nullptr) solve(nextNode);
}

void Dijkstra::printShortestPath(Node* n)
{
    NodeInfo* node = info.find(n->getName())->second;
    
    if (node->previous == nullptr && n != startingNode){
        std::cout
            << "Node "
            << n->getName()
            << " is not connected"
            << std::endl;
        return;
    }
    
    if (n != startingNode)
    {
        printShortestPath(node->previous);
        std::cout << n->getName() << " (" << node->distance << ")" << " ";
        
        return;
    }
    std::cout << n->getName() << " -> ";
}

void Dijkstra::printTable()
{
    std::cout << std::endl << "\t\t\tShortest" << std::endl;
    std::cout << "\t\t\tDistance\tPrevious" << std::endl;
    std::cout << "Vertex\t\tfrom " << startingNode->getName() << "\t\tNode" << std::endl << std::endl;
    for (auto const& node : info)
    {
        bool inf = node.second->distance == std::numeric_limits<int>::max();
        bool null = node.second->previous == nullptr;
        
        std::cout << node.first << "\t\t\t";
        
        if (inf) { std::cout << "INF"; }
        else { std::cout << node.second->distance; }
        
        std::cout << "\t\t\t";
        
        if (null) { std::cout << "NULL"; }
        else { std::cout << node.second->previous->getName(); }
        
        std::cout << "\t" << std::endl;
    }
    std::cout << std::endl;
}
