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

int AVL::getHeight(){
    if(this == NULL){
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

AVL* AVL::rotateRight(){
    if(this->left == NULL){
        return this;
    }

    AVL* nextRoot = this->left;
    AVL* childSwitch = NULL;
    if(this->left->getRight() != NULL){
        childSwitch = this->left->getRight();
        cout << "assigned child root in rotation" << endl;
    }

    this->left = childSwitch;
    this->setBalanceAndHeight();
    cout << "assigned child to old root" << endl;
    
    nextRoot->setRight(this);
    nextRoot->setBalanceAndHeight();

    cout << "New root: " << nextRoot->getRoot()->getWord() << endl;
    if(nextRoot->getLeft() == NULL){
        cout << "New left: NULL" << endl;
    }
    else{
        cout << "New left: " << nextRoot->getLeft()->getRoot()->getWord() << endl;
    }
    if(nextRoot->getRight() == NULL){
        cout << "New right: NULL" << endl;
    }
    else{
        cout << "New right: " << nextRoot->getRight()->getRoot()->getWord() << endl;
    }

    return nextRoot;
}

AVL* AVL::rotateLeft(){
    if(this->right == NULL){
        return this;
    }

    AVL* nextRoot = this->right;
    AVL* childSwitch = NULL;

    if(this->right->getLeft() != NULL){
        childSwitch = this->right->getLeft();
        cout << "assigned child root in rotation" << endl;
    }

    this->right = childSwitch;
    this->setBalanceAndHeight();
    cout << "assigned child to old root" << endl;

    nextRoot->setLeft(this);
    nextRoot->setBalanceAndHeight();

    cout << "New root: " << nextRoot->getRoot()->getWord() << endl;
    if(nextRoot->getLeft() == NULL){
        cout << "New left: NULL" << endl;
    }
    else{
        cout << "New left: " << nextRoot->getLeft()->getRoot()->getWord() << endl;
    }
    if(nextRoot->getRight() == NULL){
        cout << "New right: NULL" << endl;
    }
    else{
        cout << "New right: " << nextRoot->getRight()->getRoot()->getWord() << endl;
    }

    return nextRoot;
}

void AVL::setBalanceAndHeight(){
    if(this->right->getHeight() > this->left->getHeight()){
        this->height = this->right->getHeight() + 1;
    }
    else{
        this->height = this->left->getHeight() + 1;
    }

    this->balance = this->right->getHeight() - this->left->getHeight();
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

AVL* AVL::insertNode(string word){
    cout << "inserting word: " << word << endl;
    if(this == NULL){
        cout << "this is NULL" << endl;
    }
    if(this->root == NULL){
        cout << "This->root is NULL" << endl;
        this->root = new Node(word);
    }
    else{
        cout << "Root not NULL, trying to place word" << endl;
        if(this->root->getWord() < word){
           cout << "Placing word in right tree." << endl;
            if(this->right == NULL){
                this->right = new AVL();
                cout << "adding new empty right tree" << endl;
            }
            this->right = this->right->insertNode(word);
            cout << "calling insert on right tree and setting equal to right tree" << endl;
        }
        else if(this->root->getWord() == word){
            this->root->increaseCount();
            cout << "incremented count" << endl;
            return this;
        }
        else{
            cout << "Placing word in left tree." << endl;
            if(this->left == NULL){
                this->left = new AVL();
                cout << "added new empty left tree" << endl;
            }
            this->left = this->left->insertNode(word);
            cout << "called insert on left tree and set equal to left tree" << endl;
        }
    }


    cout << "Right height: " << this->right->getHeight() << endl;
    cout << "Left height: " << this->left->getHeight() << endl;
    if(this->right->getHeight() > this->left->getHeight()){
        this->height = this->right->getHeight() + 1;
    }
    else{
        this->height = this->left->getHeight() + 1;
    }

    cout << "Height: " << this->height << endl;

    this->balance = this->right->getHeight() - this->left->getHeight();

    cout << "Balance: " << this->balance << endl;

    if(this->balance < -1){
        cout << "Left ";
        if(this->left->getRoot()->getWord() < word){
            cout << "Right" << endl;
            this->left = this->left->rotateLeft();
        }
        else{
            cout << "Left" << endl;
        }
        return this->rotateRight();
    }
    else if(this->balance > 1){
         cout << "Right ";
        if(this->right->getRoot()->getWord() > word){
            cout << "Left" << endl;
            this->right = this->right->rotateRight();//right rotate when right left
        }
        else{
            cout << "Right" << endl;
        }
        return this->rotateLeft();
    }
    return this;
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

