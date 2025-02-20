#include "HashTable.h"

int main()
{
    std::cout << "Hash Table Example" << std::endl;
    
    HashTable hashTable(2);
    hashTable.add("one", 1);
    hashTable.add("two", 2);
    hashTable.add("yes", 3);
    
    std::cout << "Get Values" <<std::endl;
    std::cout << hashTable.get("yes") << std::endl;
}
