#include "BTreeNode.hpp"
#include <stdio.h>
#include <string>
#include<stdio.h>
#include"Node.hpp"


BTreeNode::BTreeNode(){
    this-> keys = new Node[4];
    this-> children = new BTreeNode*[5];
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

bool BTreeNode::insertNode(Node node){
     if (this->numKeys == 4){
        return false;
    }

    if (this->numKeys == 0){
        this->keys[0] = node;
        this->incrementNumKeys();
        return true;
    }

    int search = searchNode(node);
    if (search >= 0){
        this->keys[search].increaseCount();
        return true;
    }
   
    search = search*-1 - 10;
    if (search == numKeys){
        this->keys[search] = node;
        this->incrementNumKeys();
        return true;
    }else{
        for (int i = numKeys; i > search; i--){
            this->keys[i] = this->keys[i-1];
        }
        this->keys[search] = node;
        this->incrementNumKeys();
        return true;
    }
    
}

BTreeNode::~BTreeNode(){
    delete [] keys;
    delete [] children;

}