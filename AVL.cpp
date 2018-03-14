#include "AVL.hpp"
#include <string>
#include <stdio.h>
#include <iostream>


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

AVL::AVL(string& word){
    this->balance = 0;
    this->height = 0;
    this->right = NULL;
    this->left = NULL;
    this->root = new Node(word);
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
    unsigned int lheight = 0;
    unsigned int rheight = 0;
    this->right = right;
    if(right->getHeight() != NULL){
        rheight = right->getHeight();
    }
    if(this->left != NULL){
        lheight = this->left->getHeight();
    }
    if(rheight > lheight){
        this->height = rheight + 1;
    }
    else{
        this->height = lheight + 1;
    }
    this->balance = rheight - lheight;
}

AVL* AVL::getLeft(){
    return this->left;
}

//TODO: make height and balance work as well
// void AVL::setLeft(AVL* left){
//     int lheight = 0;
//     int rheight = 0;
//     this->left = left;
//     if(left->getHeight() != NULL){
//         lheight = left->getHeight();
//     }
//     else{
//         lheight = -1;
//     }
//     if(this->right != NULL){
//         rheight = this->right->getHeight();
//     }
//     else{
//         rheight = -1;
//     }
//     if(rheight > lheight){
//         this->height = rheight + 1;
//     }
//     else{
//         this->height = lheight + 1;
//     }
//     this->balance = rheight - lheight;
// }

Node* AVL::getRoot(){
    return this->root;
}

void AVL::setRoot(Node* root){
    this->root = root;
}

int AVL::getHeight(){
    if(this->root == NULL){
        return -1;
    }
    return this->height;
}

int AVL::getBalance(){
    if(this->root == NULL){
        return 0;
    }
    return this->balance;
}

bool AVL::searchTree(string word){
    if(this->root == NULL){
        return false;
    }
    else{
        if(this->root->getWord() == word){
            return true;
        }
        else if(this->root->getWord() < word){
            if(this->right == NULL){
                return false;
            }
            else{
                return this->right->searchTree(word);
            }
        }
        else{
            if(this->left == NULL){
                return false;
            }
            else{
                return this->left->searchTree(word);
            }
        }
    }
    
}

void AVL::insertNode(string word){
    if(this->root == NULL){
        this->root = new Node(word);
    }
    else{
        if(this->root->getWord() > word){
            if(this->right == NULL){
                this->right = new AVL();
            }
            this->right->insertNode(word);
        }
        if(this->root->getWord() == word){
            this->root->increaseCount();
        }
        else{
            if(this->left == NULL){
                this->left = new AVL();
            }
            this->left->insertNode(word);
        }
    }

    if(this->right->getHeight() > this->left->getHeight()){
        this->height = this->right->getHeight() + 1;
    }
    else{
        this->height = this->left->getHeight() + 1;
    }

    this->balance = this->right->getHeight() - this->left->getHeight();

    if(this->balance < -1){
        if
    }
    else{

    }

}

AVL* AVL::deleteNode(string word){
    return this;
}

void AVL::sortTree(){
    if(this->left != NULL){
        this->left->sortTree();
    }
    outputToFile(this->root->getWord(), "output.txt");
    if(this->right != NULL){
        this->right->sortTree();
    }
}

void AVL::rangeSearchTree(string upperBound, string lowerBound){
    if(this->root->getWord() >= upperBound && this->root->getWord() <= lowerBound){
        this->left->rangeSearchTree(upperBound, lowerBound);
        cout << this->root->getWord() << endl;
        this->right->rangeSearchTree(upperBound, lowerBound);
    }
    else if(this->root->getWord() >= lowerBound){
        this->left->rangeSearchTree(upperBound, lowerBound);
    }
    else{
        this->right->rangeSearchTree(upperBound, lowerBound);
    }
}

