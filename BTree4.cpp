#include "BTree4.hpp"
#include <stdio.h>
#include <string>
#include<stdio.h>

using namespace std;

BTree4::BTree4(){
    this->root = nullptr;
}

BTreeNode* BTree4::getRoot(){
    return this->root;
}

void BTree4::insertWord(string word, BTreeNode* root){
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
            }else {
                insertWord(word, root->children[3]);
            }
        }

    }
}

void BTree4::deleteWord(string word, BTreeNode* root){
    
}

void BTree4::sortWords(BTreeNode* root){
    if (root != nullptr){
        sortWords(root->children[0]);
        if (root->key[0] != nullptr){
            cout << root->key[0].getWord();
        }
        sortWords(root->children[1]);
        if (root->key[1] != nullptr){
            cout << root->key[1].getWord();
        }
        sortWords(root->children[2]);
       if (root->key[2] != nullptr){
            cout << root->key[2].getWord();
        }
        sortWords(root->children[3]);
        
    }
}

BTreeNode* BTree4::searchWord(string word){
    return nullptr;
}

void BTree4::rangeSort(string word1, string word2){

}

BTree4::~BTree4(){
    delete root;
}