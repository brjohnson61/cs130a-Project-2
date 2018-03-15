#ifndef BTreeNode_hpp
#define BTreeNode_hpp

#include <stdio.h>
#include <string>
#include <stdio.h>
#include "Node.hpp"
#include <vector>

using namespace std;

class BTreeNode {
    public:
        BTreeNode();
        int searchNode(Node node);
        int insertNode(Node node);
        void incrementNumKeys();
        bool isFull();

    private:
        Node* keys;
        BTreeNode** children;
        bool isLeaf;
        int numKeys;

friend class BTree5; 
};

#endif /* BTreeNode_hpp */