#ifndef BTree5_hpp
#define BTree5_hpp

#include <stdio.h>
#include <string>
#include "BTreeNode.hpp"

using namespace std;

class BTree5 {
    public: 
        BTree5();
        BTreeNode* getRoot();
        void insertWord(string word, BTreeNode* root);
        void deleteWord(string word, BTreeNode* root);
        BTreeNode* searchWord(string word, BTreeNode*root);
        void sortWords(BTreeNode* root);
        void rangeSearch(string word1, string word2, BTreeNode*);
        void getHeight(BTreeNode* root, int depth);
        void balanceInsertNode(BTreeNode* root);
        void balanceLeafWithParent(int child, BTreeNode* parent);
        void borrowFromRight(int keyIndex, BTreeNode* parent);
        void borrowFromLeft(int keyIndex, BTreeNode* parent);
        void mergeChildrenFromKey(int keyIndex, BTreeNode* parent);
        
        ~BTree5();


    private:
        BTreeNode * root;
        

};

#endif /* BTree4_hpp */