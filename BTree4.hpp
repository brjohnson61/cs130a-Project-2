#ifndef BTree4_hpp
#define BTree4_hpp

#include <stdio.h>
#include <string>

using namespace std;

class BTree4 {
    public: 
        BTree4();
        BTreeNode* getRoot();
        void insertWord(string word, BTreeNode* root);
        void deleteWord(string word, BTreeNode* root);
        BTreeNode* searchWord(string word);
        void sortWords();
        void rangeSort(string word1, string word2);
        ~BTree4();


    private:
        BTreeNode * root;


};

#endif /* BTree4_hpp */