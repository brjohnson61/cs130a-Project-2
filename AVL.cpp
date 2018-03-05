#include "AVL.hpp"
#include <string>


AVL::AVL(){
    this->balance = 0;
    this->height = 0;
    this->right = NULL;
    this->left = NULL;
    this->root = NULL;
}


AVL::AVL(AVL& original){
    this->balance = original.getBalance();
    this->height = original.getHeight();
    this->root = new Node(original.getRoot());
    if(original.getRight() == NULL){
        this->right = NULL;
    }
    else{
        this->right = new AVL(*(original.getRight()));
    }
    if(original.getLeft() == NULL){
        this->left = NULL;
    }
    else{
        this->left = new AVL(*(original.getLeft()));
    }
}


