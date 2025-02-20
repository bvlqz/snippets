#include <iostream>
#include <string>

class HashNode {
    HashNode* nextNodePtr;
    std::string nodeKey;
    std::string nodeValue;

public:
    HashNode(std::string key, std::string value)
    {
        nodeKey = key;
        nodeValue = value;
        nextNodePtr = nullptr;
    }
    ~HashNode()
    {
        if (this->nextNodePtr != nullptr) delete this->nextNodePtr;
    }
    std::string getNodeValue()
    {
        return nodeValue;
    }
    std::string getNodeValueWithKey(std::string key)
    {
        if (this->nodeKey == key) {
            return this->nodeValue;
        }
        else {
            this->nextNodePtr->getNodeValueWithKey(key);
        }
    }
    void AppendToTail(std::string key, std::string value)
    {
        HashNode* newEndNode = new HashNode(key, value);
        HashNode* currentWorkingNode = this;
        while (currentWorkingNode->nextNodePtr != nullptr)
        {
            currentWorkingNode = currentWorkingNode->nextNodePtr;
        }
        currentWorkingNode->nextNodePtr = newEndNode;
    }
};

class HashTable {
public:
    HashTable(int size)
    {
        tableSize = size;
        list = new HashNode*[size];
    }
    
    void add(std::string k, std::string v)
    {
        if (list[hash(k)] != nullptr) {
            std::cout << "Key " << k << " exists" << std::endl;
            list[hash(k)] = new HashNode(k, v);
        } else {
            list[hash(k)]->AppendToTail(k, v);
        }
        
    }
    
    std::string get(std::string k)
    {
        return list[hash(k)]->getNodeValueWithKey(k);
    }
    
private:
    int hash(std::string key)
    {
        int keyASCIISum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            keyASCIISum += key[i] + 1;
        }
        return keyASCIISum % tableSize;
    }
    
    HashNode** list;
    int tableSize;
    int itemCount;
};

