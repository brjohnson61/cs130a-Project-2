#include "BTreeNode.hpp"
#include <stdio.h>
#include <string>
#include<stdio.h>
#include"Node.hpp"


void BTreeNode::incrementNumKeys(){
    numKeys++;
}

BTreeNode::~BTreeNode(){
    delete [] keys;
    delete [] children;

}