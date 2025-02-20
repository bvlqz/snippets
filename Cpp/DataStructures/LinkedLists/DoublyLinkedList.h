#include <iostream>

/*
A doubly linked list example

Becerra, Jorge Alberto <jorge@koruke.com>
Code
2021-07-10
*/

class Node {
    Node* prevNodePtr;
    int nodeData;
    Node* nextNodePtr;

public:
    Node(int data)
    {
        prevNodePtr = nullptr;
        nodeData = data;
        nextNodePtr = nullptr;
    }
    ~Node(){
        if (this->nextNodePtr != nullptr) delete this->nextNodePtr;
        if (this->prevNodePtr != nullptr) delete this->prevNodePtr;
    }
    void printAllNodes()
    {
        Node* currentWorkingNode = this;
        
        while (currentWorkingNode->prevNodePtr != nullptr)
        {
            std::cout << currentWorkingNode ->nodeData << std::endl;
            currentWorkingNode = currentWorkingNode->prevNodePtr;
            
        }
        
        std::cout << this->nodeData << "<-"  << std::endl;
        
        currentWorkingNode = this;
        
        while (currentWorkingNode->nextNodePtr != nullptr)
        {
            currentWorkingNode = currentWorkingNode->nextNodePtr;
            std::cout << currentWorkingNode ->nodeData << std::endl;
        }
    }
    Node* AppendToTail(int data)
    {
        Node* newEndNode = new Node(data);
        Node* currentWorkingNode = this;
        
        while (currentWorkingNode->nextNodePtr != nullptr)
        {
            currentWorkingNode = currentWorkingNode->nextNodePtr;
        }
        currentWorkingNode->nextNodePtr = newEndNode;
        newEndNode->prevNodePtr = this;
        return newEndNode;
    }
    Node* AddToFront(int data)
    {
        Node* newFrontNode = new Node(data);
        Node* currentWorkingNode = this;
        
        while (currentWorkingNode->prevNodePtr != nullptr)
        {
            currentWorkingNode = currentWorkingNode->prevNodePtr;
        }
        currentWorkingNode->prevNodePtr = newFrontNode;
        newFrontNode->nextNodePtr = this;
        return newFrontNode;
    }
};

