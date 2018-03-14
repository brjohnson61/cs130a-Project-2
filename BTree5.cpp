#include "BTree4.hpp"
#include <stdio.h>
#include <string>
#include<stdio.h>

using namespace std;

BTree5::BTree5(){
    this->root = nullptr;
}

BTreeNode* BTree5::getRoot(){
    return this->root;
}

void BTree5::insertWord(string word, BTreeNode* root){
    Node temp = Node(word);
    if (this->root == nullptr){
        root = new BTreeNode();
        root->isLeaf = true;
        root->keys[0] = temp;
    }else{
        if (root->isLeaf != true){
            if (root->keys[0] > temp){
                insertWord(word, root->children[0]);               
            }else if (root->keys[0] == temp){
                root->keys[0].increaseCount();
            }else if (root->keys[1] > temp){
                insertWord(word, root->childern[1]);
            }else if (root->keys[1] == temp){
                root->keys[1].increaseCount();
            }else if (root->keys[2] > temp){
                insertWord(word, root->children[2]);
            }else if (root->keys[2] == temp){
                root->keys[2].increaseCount();
            }else if (root-> keys[3] > temp){
                insertWord(word, root->children[3]);
            }else if (root->keys[3] == temp){
                root->keys[3].increaseCount();
            }else {
                insertWord(word, root->children[4])
            }
        }else{
            if (root->numKeys == 4){
                cout << "Node is full";
                
            }else{
                root->insertNode(temp);
                
            }
        }

    }
}

void BTree5::deleteWord(string word, BTreeNode* root){
    
}

void BTree5::sortWords(BTreeNode* root){
    if (root != nullptr){
        sortWords(root->children[0]);
        if (root->key[0] != null){
            cout << root->key[0].getWord();
            sortWords(root->children[1]);
        }
        
        if (root->key[1] != null){
            cout << root->key[1].getWord();
            sortWords(root->children[2]);
        }
        
       if (root->key[2] != null){
            cout << root->key[2].getWord();
            sortWords(root->children[3]);
        }
        
        if (root->key[3] != null){
            cout << root->key[3].getWord();
            sortWords(root->childern[4])
        }
        
        
    }
}

BTreeNode* BTree5::searchWord(string word){
    return nullptr;
}

void BTree5::rangeSort(string word1, string word2){

}

BTree5::~BTree5(){
    delete root;
}