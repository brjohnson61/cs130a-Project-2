#ifndef AVL_hpp
#define AVL_hpp

#include "Node.hpp"


class AVL{
public:
    //Constructors, Destructors, and Operators
    AVL();
    AVL(AVL* original);
    AVL(Node* original);
    AVL(string& word);
    ~AVL();
    bool operator=(AVL& rhs);

    //Getters, Setters, Helper Functions
    AVL* getRight();
    void setRight(AVL* right);
    AVL* getLeft();
    void setLeft(AVL* left);
    Node* getRoot();
    void setRoot(Node* root);
    int getHeight();
    int getBalance();
    AVL* rotateRight();
    AVL* rotateLeft();
    void setBalanceAndHeight();
    AVL* minimumRoot();
    

    //Assignment functions
    bool searchTree(string word);
    AVL* insertNode(string word);
    AVL* deleteNode(string word);
    void sortTree();
    void rangeSearchTree(string upperBound, string lowerBound);

private:
    //Private members
    int balance;
    int height;
    AVL* right;
    AVL* left;
    Node* root;
};


#endif