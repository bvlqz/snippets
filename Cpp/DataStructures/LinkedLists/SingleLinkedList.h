#include <iostream>

/*
A single linked list example

Becerra, Jorge Alberto <jorge@koruke.com>
Code
2021-07-10
*/

class Node {
    Node* nextNodePtr;
    int nodeData;

public:
    Node(int data)
    {
        nodeData = data;
        nextNodePtr = nullptr;
    }
    ~Node(){
        if (this->nextNodePtr != nullptr) delete this->nextNodePtr;
    }
    void printAllNodes()
    {
        Node* currentWorkingNode = this;
        
        while (currentWorkingNode->nextNodePtr != nullptr)
        {
            std::cout << currentWorkingNode->nodeData << std::endl;
            currentWorkingNode = currentWorkingNode->nextNodePtr;
        }
        std::cout << currentWorkingNode->nodeData << std::endl;
    }
    void AppendToTail(int data)
    {
        Node* newEndNode = new Node(data);
        Node* currentWorkingNode = this;
        
        while (currentWorkingNode->nextNodePtr != nullptr)
        {
            currentWorkingNode = currentWorkingNode->nextNodePtr;
        }
        currentWorkingNode->nextNodePtr = newEndNode;
    }
};
