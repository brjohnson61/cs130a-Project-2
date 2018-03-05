#ifndef AVL_hpp
#define AVL_hpp

#include "Node.hpp"


class AVL{
public:
    //Constructors, Destructors, and Operators
    AVL();
    AVL(AVL& original);
    AVL(Node& original);
    ~AVL();
    bool operator=(AVL& rhs);

    //Getters, Setters
    AVL* getRight();
    void setRight(AVL* right);
    AVL* getLeft();
    void setLeft(AVL* left);
    Node* getRoot();
    void setRoot(Node* root);
    unsigned int getHeight();
    int getBalance();
    

    //Assignment functions
    bool searchTree(string word);
    AVL insertNode(Node& newNode);
    AVL insertNode(string word);
    AVL deleteNode(string word);
    void rangeSearch(string upperBound, string lowerBound);

private:
    //Private members
    int balance;
    unsigned int height;
    AVL* right;
    AVL* left;
    Node* root;
};


#endif