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
    balanceInsertNode(root);
    
    Node temp = Node(word);
    if ((this->root == nullptr) && (this->root == root)){
        
        this-> root = new BTreeNode();
        this-> root->isLeaf = true;
        this-> root->insertNode(temp);
    }else{
    
        if (root->isLeaf != true ){
            for (int i = 0; i < root->numKeys;i++){
                if(temp < root->keys[i]){
                    insertWord(word,root->children[i]);
                    return;
                }else if (root->keys[i] == temp){
                    root->keys[i].increaseCount();
                    return;
                }
                
            }
            if (temp > root->keys[root->numKeys-1]){
                insertWord(word, root->children[root->numKeys]);
                return;
            }
            
            
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
    Node temp = Node(word);
    for (int i = 0; i < root->numKeys; i++){
        if (temp < root->keys[i]){
            cout << "This executes" << endl;
            if (root->children[i]->isLeaf == true){
                cout << "Children of i: " << i << " is leaf: " << root->children[i]->isLeaf <<endl;
                int search = root->children[i]->searchNode(temp);
                if (search >= 0){
                    cout << "Search was sucessfull: "<< search << endl;
                    balanceLeafWithParent(i, root);
                }
            }
            deleteWord(word, root->children[i]);
            return;
        }else if (temp == root->keys[i]){
            if (root->isLeaf){
                if (root->numKeys <= 1){
                    cout << "Shouldnt happen only if root->numkeys = 1"<< endl;
                    if ((root == this->root) && (root->numKeys == 1)){
                        root->~BTreeNode();
                        root = nullptr;
                    }
                    return;
                }else{
                    root->deleteNode(temp);
                    cout << "Done deleting " << temp.getWord() << endl;
                    return;
                }
            }else{
                if (root->numKeys <= 1 ){
                    //shouldnt happen
                    cout << "Shouldnt happen" << endl;
                }else{
                    cout << "Trying to delete " << word << endl; 
                    if ((root->children[i]->numKeys > 2) || (root->children[i+1]->numKeys > 2)){
                        if (root->children[i]->numKeys > root->children[i+1]->numKeys ){
                            if (root->children[i]->numKeys == 3){
                                int index = 2;
                                root->insertNode(root->children[i]->keys[index]);
                                this->deleteWord(root->children[i]->keys[index].getWord(), root->children[i]);
                                root->deleteNode(temp);
                                return;
                            }
                            if (root->children[i]->numKeys==4){
                                int index = 3;
                                root->insertNode(root->children[i]->keys[index]);
                                this->deleteWord(root->children[i]->keys[index].getWord(), root->children[i]);
                                root->deleteNode(temp);
                                return;
                            }
                        }else{
                            cout <<"Children i + 1 " << i+1 << " has more children" << endl; 
                            if (root->children[i+1]->numKeys == 3){
                                int index = 0;
                                root->insertNode(root->children[i+1]->keys[index]);
                                this->deleteWord(root->children[i+1]->keys[index].getWord(), root->children[i+1]);
                                root->deleteNode(temp);
                                return;
                            }
                            if (root->children[i+1]->numKeys==4){
                                cout << "Has four children" << endl;
                                int index = 0;
                                root->insertNode(root->children[i+1]->keys[index]);
                                this->deleteWord(root->children[i+1]->keys[index].getWord(), root->children[i+1]);
                                root->deleteNode(temp);
                                return;
                            }
                        }  
                        
                    }else{
                        root->deleteNode(temp);
                        BTreeNode* temp0 = root->children[i];
                        cout << "One children has atleast one one child or both child hace two"<< endl;
                        for (int k = 0; k< root->children[i]->numKeys; k++){
                            root->children[i+1]->children[root->children[i+1]->numKeys+1] = root->children[i]->children[k];
                            root->children[i+1]->insertNode(root->children[i]->keys[k]);
                            if (i == root->children[i+1]->numKeys-1){
                                     root->children[i+1]->children[root->children[i+1]->numKeys+1] = root->children[i]->children[k+1];
                            }
                        }

                        for (int j = i; j < root->numKeys+1; j++){
                            root->children[j] =  root->children[j+1];
                        }
                        for (int d = 0; d < temp0->numKeys; d ++){
                            temp0->children[d] = nullptr;
                            if (d == temp0->numKeys+1){
                                temp0->children[d+1] = nullptr;
                            }
                        }
                        temp0->~BTreeNode();

                     }

                }
            }
        } 
    }
    if (temp > root->keys[root->numKeys]){
         if (root->children[root->numKeys]->isLeaf == true){
                int search = root->children[root->numKeys]->searchNode(temp);
                if (search >= 0){
                    balanceLeafWithParent(root->numKeys, root);
                }
            }
        deleteWord(word,root->children[root->numKeys]);
        return;
    }
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

void BTree5::balanceInsertNode(BTreeNode* root){

    if ((this->root == root) && (root != nullptr)){
        if (root->numKeys == 4){
            
            int index = 1;
            BTreeNode* temp0 = new BTreeNode();
            BTreeNode* temp1 = new BTreeNode();
            if (root->isLeaf){
                temp0->isLeaf = true;
                temp1->isLeaf = true;
                root->isLeaf = false;
            }


            temp0->insertNode(root->keys[0]);
            temp1->insertNode(root->keys[3]);
            root->numKeys = 0;
            root->insertNode(root->keys[index]);
            
            
            if (index == 1){
                
                temp1->insertNode(root->keys[2]);
                temp0->children[0] = root->children[0];
                temp0->children[1] = root->children[1];
                temp1->children[0] = root->children[2];
                temp1->children[1] = root->children[3];
                temp1->children[2] = root->children[4];
                
                
            }else if (index == 2) {

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
                    int index = 2; 

                    BTreeNode* temp = new BTreeNode();

                    if( root->children[0]->isLeaf){
                        temp->isLeaf = true;
                    }
                    
                    root->insertNode(root->children[i]->keys[index]);
                    temp->insertNode(root->children[i]->keys[0]);
                    

                    for(int k = root->numKeys; k > i; k--){
                        root->children[k] = root->children[k-1];
                    }
                    root->children[i] = temp;

                    if (index == 1){
                        root->children[i+1]->numKeys = 0;
                        root->children[i+1]->insertNode(root->children[i+1]->keys[2]);
                        root->children[i+1]->insertNode(root->children[i+1]->keys[3]);
                        
                        //need to get the case when children is not leaf
                        if (root->children[i]->isLeaf == false){
                           
                            temp->children[0] = root->children[i+1]->children[0];
                            temp->children[1]=  root->children[i+1]->children[1];
                            root->children[i+1]->children[0] = root->children[i+1]->children[2];
                            root->children[i+1]->children[1] = root->children[i+1]->children[3];
                            root->children[i+1]->children[2] = root->children[i+1]->children[4];
                        }

                    }else{
                        temp->insertNode(root->children[i+1]->keys[1]);
                        root->children[i+1]->numKeys = 0;
                        root->children[i+1]->insertNode(root->children[i+1]->keys[3]);
                        
                        if(root->children[i]->isLeaf == false){
                            temp->children[0] = root->children[i+1]->children[0];
                            temp->children[1] = root->children[i+1]->children[1];
                            temp->children[2] = root->children[i+1]->children[2];
                            root->children[i+1]->children[0] = root->children[i+1]->children[3];
                            root->children[i+1]->children[1] = root->children[i+1]->children[4];
                        }

                    }
                    temp = nullptr;
                    delete temp;
                
                } 
            }
        }
    }
}

void BTree5::borrowFromRight(int keyIndex, BTreeNode* parent){
    cout << "Borrow from right getting called" << endl;
    if (parent->children[keyIndex]->isLeaf == true){
        parent->children[keyIndex]->insertNode(parent->keys[keyIndex]);
        parent->deleteNode(parent->keys[keyIndex]);
        parent->insertNode(parent->children[keyIndex+1]->keys[0]);
        parent->children[keyIndex+1]->deleteNode(parent->keys[keyIndex]);
    }
}

void BTree5::borrowFromLeft(int keyIndex, BTreeNode* parent){
    if (parent->children[keyIndex]->isLeaf == true){
        parent->children[keyIndex+1]->insertNode(parent->keys[keyIndex]);
        parent->deleteNode(parent->keys[keyIndex]);
        parent->insertNode(parent->children[keyIndex]->keys[parent->children[keyIndex]->numKeys-1]);
        parent->children[keyIndex]->deleteNode(parent->keys[keyIndex]);
    }
}

void BTree5::mergeChildrenFromKey(int keyIndex, BTreeNode* parent){
    
}
void BTree5::balanceLeafWithParent(int child, BTreeNode* parent){
   if (parent->children[child]->numKeys < 2){
       if (child == 0){
           cout << "Child == 0" << endl;
           if (parent->children[1]->numKeys > 1){
               borrowFromRight(0, parent);
           }else {
               mergeChildrenFromKey(0, parent);
           }
       }else if (child == parent->numKeys){
           if (parent->children[child-1]->numKeys > 1){
               borrowFromLeft(child-1, parent);
           }else {
               mergeChildrenFromKey(child-1, parent);
           }
       }else{
           if (parent->children[child+1]->numKeys > 1){
               borrowFromRight(child, parent);
           }else if(parent->children[child-1]->numKeys > 1){
               borrowFromLeft(child-1, parent);
           }else {
               mergeChildrenFromKey(child-1, parent);
           }

       }
   }
}



void BTree5::getHeight(BTreeNode* root, int depth){
    if (root != nullptr){
        cout << "Number Of Keys: " << root->numKeys << " Depth " << depth << endl;
        cout << "Is Leaf = " << root->isLeaf << endl;
        for(int i= 0; i <root->numKeys; i++){
            cout << "Key [" << i << "] : " << root->keys[i].getWord() << " Depth: "<< depth << endl;
        }
        for(int i = 0; i < root->numKeys ; i ++){
            getHeight(root->children[i], depth+1);
           
        }
        getHeight(root->children[root->numKeys], depth+1);
    }
}

BTree5::~BTree5(){
    delete root;
}

