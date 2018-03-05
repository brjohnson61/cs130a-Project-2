#include "BTreeNode.hpp"
#include <stdio.h>
#include <string>
#include<stdio.h>
#include"Node.hpp"

using namespace std;

BTreeNode::BTreeNode(){
    keys = new Node[3];
    children = new BTreeNode*[4];
    numKeys = 0;
    isLeaf = false;
}


int BTreeNode::search(Node node){
    if (numKeys == 0){
        return -1;
    }
    for (int i = 0; i< numKeys; i++){
        if (keys[i] == node){
            return i;
        }else if (keys[i] > node){
            return -1;
        }
    }
}

void BTreeNode::incrementNumKeys(){
    numKeys++;
}

BTreeNode::~BTreeNode(){
    delete [] keys;
    delete [] children;

}