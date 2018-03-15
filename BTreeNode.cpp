#include "BTreeNode.hpp"
#include <stdio.h>
#include <string>
#include<stdio.h>
#include"Node.hpp"
#include <vector>


BTreeNode::BTreeNode(){
    keys = new Node[4];
    children = new BTreeNode*[5];
    for (int i = 0; i< 5; i++){
        this->children[i] = nullptr;
    }
    this-> isLeaf = false;
    this-> numKeys = 0;
}

void BTreeNode::incrementNumKeys(){
    this-> numKeys++;
}

int BTreeNode::searchNode(Node node){
    for(int i= 0;i< this->numKeys;i++){
        if (this->keys[i] == node){
            return i;
        }
        if (this->keys[i] > node){
            return  -10 - i;
        }
    }
    return -10 - this-> numKeys;
}

int BTreeNode::insertNode(Node node){
     if (this->numKeys == 4){
        return -1;
    }

    if (this->numKeys == 0){

        this->keys[0] = node;
        this->incrementNumKeys();
        return 0;
    }

    int search = searchNode(node);
    if (search >= 0){
        this->keys[search].increaseCount();
        return -2;
    }
   
    search = search*-1 - 10;
    if (search == numKeys){
        this->keys[search] = node;
        this->incrementNumKeys();
        return search;
    }else{
        for (int i = numKeys; i > search; i--){
            this->keys[i] = this->keys[i-1];
        }
        this->keys[search] = node;
        this->incrementNumKeys();
        return search;
    }
    
}

bool BTreeNode::isFull(){
    if (this->numKeys == 4)
        return true;
    return false;
    
}


