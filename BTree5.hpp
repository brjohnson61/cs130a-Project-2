#ifndef BTree5_hpp
#define BTree5_hpp

#include <stdio.h>
#include <string>

using namespace std;

class BTree5 {
    public: 
        BTree5();
        BTreeNode* getRoot();
        void insertWord(string word, BTreeNode* root);S
        void deleteWord(string word, BTreeNode* root);
        BTreeNode* searchWord(string word);
        void sortWords();
        void rangeSort(string word1, string word2);
        ~BTree5();


    private:
        BTreeNode * root;


};

#endif /* BTree4_hpp */