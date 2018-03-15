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
        
        this-> root->insertNode(temp);
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
                cout << "Node is full" << endl;
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
            
            int index = rand() % 2 + 1;
            BTreeNode* temp0 = new BTreeNode();
            BTreeNode* temp1 = new BTreeNode();
            if (root->isLeaf){
                temp0->isLeaf = true;
                temp1->isLeaf = true;
                root->isLeaf = false;
            }


            temp0->insertNode(root->keys[0]);
            temp1->insertNode(root->keys[3]);
            
            if (index == 1){
                
                root->keys[0] = root->keys[1];
                temp1->insertNode(root->keys[2]);
                temp0->children[0] = root->children[0];
                temp0->children[1] = root->children[1];
                temp1->children[0] = root->children[2];
                temp1->children[1] = root->children[3];
                temp1->children[2] = root->children[4];
                
            }else {
                root->keys[0] = root->keys[2];
                temp0->insertNode(root->keys[1]);
                temp0->children[0] = root->children[0];
                temp0->children[1] = root->children[1];
                temp0->children[2] = root->children[2];
                temp1->children[0] = root->children[3];
                temp1->children[1] = root->children[4];
            }
            
            for (int i = 2; i <4; i++){
                root->children[i] = nullptr;
            }
            root->children[0] = temp0;
            root->children[1] = temp1;
            root->numKeys = 1;
            temp0 = nullptr;
            temp1 = nullptr;
            delete temp0;
            delete temp1;
        }
    }
    if (root != nullptr ){
        for (int i = 0; i < root->numKeys+1; i++){

            if (root->isLeaf != true){
                if ((root->children[i]->numKeys == 4) && (root->numKeys != 4) ){
                    int index =1;
                    int insert = root->insertNode(root->children[i]->keys[index]);
                    

                    BTreeNode* temp = new BTreeNode();
                    temp->insertNode(root->children[i]->keys[0]);
                    if( root->children[0]->isLeaf){
                        temp->isLeaf = true;
                    }
                    for(int k = root->numKeys; k > i; k--){
                        root->children[k] = root->children[k-1];
                    }
                    if (index == 1){
                        
                        root->children[i]->numKeys = 2;
                        root->children[i]->keys[0] = root->children[i]->keys[2]; 
                        root->children[i]->keys[1] = root->children[i]->keys[3];
                        root->children[i] = temp;
                        temp = nullptr;
                        delete temp;
                        
                        //need to get the case when children is not leaf

                        if (root->children[i]->isLeaf == false){
                            cout << "Children i : " << i << " is not leaf" << endl;
                            root->children[i]->children[0] = root->children[i+1]->children[0];
                            root->children[i]->children[1] = root->children[i+1]->children[1];
                            root->children[i+1]->children[0] = root->children[i+1]->children[2];
                            root->children[i+1]->children[1] = root->children[i+1]->children[3];
                            root->children[i+1]->children[2] = root->children[i+1]->children[4];
                        }

                    }else{
                        //need to do when index == 2

                    }
                    
                    


                } 
            }
        }
    }

    
}

void BTree5::getHeight(BTreeNode* root, int depth){
    if (root != nullptr){
        cout << "Number Of Keys: " << root->numKeys << " Depth" << depth << endl;
        for(int i = 0; i < root->numKeys+ 1; i ++){
            getHeight(root->children[i], depth+1) ;
        }
    }
}

BTree5::~BTree5(){
    delete root;
}

