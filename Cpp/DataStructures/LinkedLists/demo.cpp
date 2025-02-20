#include <iostream>
#include "SingleLinkedList.h"

int main()
{
    std::cout << "Linked List Example" << std::endl;
    
    Node* InitialNode = new Node(0);
    
    InitialNode->AppendToTail(1);
    InitialNode->AppendToTail(2);
    InitialNode->AppendToTail(3);
    InitialNode->AppendToTail(4);
    InitialNode->AppendToTail(5);
    
    InitialNode->printAllNodes();
    delete InitialNode;
}


/*
int main()
{
    std::cout << "Doubly Linked List Example" << std::endl;
    
    Node* InitialNode = new Node(0);
    
    InitialNode->AppendToTail(1);
    InitialNode->AppendToTail(2);
    Node* MiddleNode = InitialNode->AppendToTail(3);
    InitialNode->AppendToTail(4);
    InitialNode->AppendToTail(5);
    InitialNode->AppendToTail(6);
    
    // InitialNode->printAllNodes();
    
    MiddleNode->printAllNodes();
    delete InitialNode;
}
*/