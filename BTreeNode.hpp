#ifndef BTreeNode_hpp
#define BTreeNode_hpp

#include <stdio.h>
#include <string>
#include<stdio.h>
#include"Node.hpp"

using namespace std;

class BTreeNode {
    public:
        BTreeNode();
        int searchNode(Node node);
        void incrementNumKeys();
        ~BTreeNode();

    private:
        Node* keys;
        BTree4Node** children;
        bool isLeaf;
        int numKeys;

friend class BTree4; 
};

#endif /* BTreeNode_hpp */