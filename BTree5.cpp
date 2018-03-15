#include "BTree5.hpp"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

BTree5::BTree5(){
    this->root = nullptr;
}

BTreeNode* BTree5::getRoot(){
    return this->root;
}

void BTree5::insertWord(string word, BTreeNode* root){
    balanceNode(root);
    
    Node temp = Node(word);
    if (this->root == nullptr){
        
        this-> root = new BTreeNode();
        this-> root->isLeaf = true;
        this-> root->keys[0] = temp;
    }else{
    
        if (root->isLeaf != true ){
            
           
            for (int i = 0; i < root->numKeys;i++){
                
                if(root->keys[i] > temp){
                    insertWord(word,root->children[i]);
                }else if (root->keys[i] == temp){
                    root->keys[i].increaseCount();
                }
                
            }
            
            insertWord(word, root->children[root->numKeys]);
            
            
        }else{
            if (root->numKeys == 4){
                
            }else{
                int index = root->insertNode(temp);
                
            }
        }

    }
   
}

void BTree5::deleteWord(string word, BTreeNode* root){
    
}

void BTree5::sortWords(BTreeNode* root){
    
    if (root != nullptr){
    
        if (root->numKeys != 0){
            for (int i= 0; i < root->numKeys; i++){
                this->sortWords(root->children[i]);
                cout << root->keys[i].getWord() << endl;
            }
            sortWords(root->children[root->numKeys]);
        }
    }
}

BTreeNode* BTree5::searchWord(string word){
    return nullptr;
}

void BTree5::rangeSearch(string word1, string word2){

}

void BTree5::balanceNode(BTreeNode* root){
    
    if ((this->root == root) && (root != nullptr)){
        if (root->numKeys == 4){
            root->isLeaf = false;
            int index = 2;
            cout << "Index " << index << endl;
            BTreeNode* temp0 = new BTreeNode();
            BTreeNode* temp1 = new BTreeNode();
             
            temp0->insertNode(root->keys[0]);
            temp1->insertNode(root->keys[3]);
            
            temp0->isLeaf = true;
            temp1->isLeaf = true;
            
            if (index == 1){

                temp1->insertNode(root->keys[2]);
                temp0->children[0] = root->children[0];
                temp0->children[1] = root->children[1];
                temp1->children[0] = root->children[2];
                temp1->children[1] = root->children[3];
                temp1->children[2] = root->children[4];
                
            }else {
                temp0->insertNode(root->keys[1]);
                temp0->children[0] = root->children[0];
                temp0->children[1] = root->children[1];
                temp0->children[2] = root->children[2];
                temp1->children[0] = root->children[3];
                temp1->children[1] = root->children[4];
            }
            
            for (int i = 1; i <4; i++){
                root->children[i] = nullptr;
            }

            
            root->children[0] = temp0;
            root->children[1] = temp1;
            root->numKeys = 1;
            temp0 = nullptr;
            temp1 = nullptr;
            
            
        }
    }else{

    }
}

BTree5::~BTree5(){
    delete root;
}

