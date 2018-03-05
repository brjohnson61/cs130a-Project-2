#include "AVL.hpp"
#include <string>


AVL::AVL(){
    this->balance = 0;
    this->height = 0;
    this->right = NULL;
    this->left = NULL;
    this->root = NULL;
}


AVL::AVL(AVL* original){
    this->balance = original->getBalance();
    this->height = original->getHeight();
    this->root = new Node(original->getRoot());
    if(original->getRight() == NULL){
        this->right = NULL;
    }
    else{
        this->right = new AVL(original->getRight());
    }
    if(original->getLeft() == NULL){
        this->left = NULL;
    }
    else{
        this->left = new AVL(original->getLeft());
    }
}

AVL::AVL(Node* original){
    this->balance = 0;
    this->height = 0;
    this->right = NULL;
    this->left = NULL;
    this->root = new Node(original);
}

AVL::~AVL(){
    delete this->root;
    if(this->right != NULL){
        delete this->right;
        this->right = NULL;
    }
    if(this->left != NULL){
        delete this->left;
        this->left = NULL;
    }
    this->balance = 0;
    this->height = 0;
    delete this;
}

bool AVL::operator=(AVL& rhs){
    this->right = new AVL(*(rhs.getRight()));
    this->left = new AVL(*(rhs.getLeft()));
    this->root = new Node(rhs.getRoot());
    this->balance = rhs.getBalance();
    this->height = rhs.getHeight();
}

AVL* AVL::getRight(){
    return this->right;
}

//TODO: make height and balance work as well
void AVL::setRight(AVL* right){
    this->right = right;
}

AVL* AVL::getLeft(){
    return this->left;
}

//TODO: make height and balance work as well
void AVL::setLeft(AVL* left){
    this->left = left;
}

Node* AVL::getRoot(){
    return this->root;
}

void AVL::setRoot(Node* root){
    this->root = root;
}

unsigned int AVL::getHeight(){
    return this->height;
}

int AVL::getBalance(){
    return this->balance;
}

bool AVL::searchTree(string word){
    return false;
}

AVL* AVL::insertNode(Node* newNode){
    return this;
}

AVL* AVL::insertNode(string word){
    return this;
}

AVL* AVL::deleteNode(string word){
    return this;
}

void rangeSearch(string upperBound, string lowerBound){

}

