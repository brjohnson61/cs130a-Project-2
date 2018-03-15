#include <stdio.h>
#include <string>
#include <iostream>
#include "Node.hpp"
#include "AVL.hpp"
#include "BTree5.hpp"
#include <iomanip>
#include <fstream>
#include <experimental/filesystem>
#include <vector>
#include <cstring>
#include <chrono>
#include <algorithm>


namespace fs = std::experimental::filesystem;
using namespace std;

//All credit for find_and_replace function goes to: http://bits.mdminhazulhaque.io/cpp/find-and-replace-all-occurrences-in-cpp-string.html
void find_and_replace(string& source, string const& find, string const& replace);
void readFilesToVec(vector<string>& fileNames, string path);
void cleanParse(string& s);
void BTreeTesting();

int main(){
    BTreeTesting();

    AVL* tree = new AVL();
    BTree5* bTree = new BTree5();
    string func;
    string inp1;
    string inp2;
    int wordCount = 0;
    string word;
    unsigned int count = 0;
    vector<string> fileList;
    readFilesToVec(fileList, "hotels-small");
    
    for(int i=0; i< fileList.size(); i++){
        ifstream inFile(fileList[i].c_str());
        string load = "";
        while(inFile >> load){
            cleanParse(load);
            if(load != ""){
                tree->insertNode(load);
                bTree->insertWord(load, bTree->getRoot());
                wordCount++;
            }
        }
        inFile.close();
    }

 

    // for (int i = 0; i<fileList.size();i++){
    //     ifstream inFile(fileList[i].c_str());
    //     string load = "";
    //     while(inFile >> load){
    //         cleanParse(load);
    //         if (load != ""){
    //             table->insertNode(load);
    //         }
    //     }
    //     inFile.close();
    // }

    cout << "Begin Final Turnin Select Menu" << endl;

    while(1){

        cout << "Option 1: Search" << endl;
        cout << "Option 2: Insert" << endl;
        cout << "Option 3: Delete" << endl;
        cout << "Option 4: Sort" << endl;
        cout << "Option 5: Range Search" << endl;

        cin >> func; 
        if(func == "1"){
                bool bt4bool, bbool;
                cout << "Enter word to search for: " << endl;
                cin >> inp1;
                
                auto start0 = chrono::high_resolution_clock::now();
                bbool = (tree->searchTree(inp1)) ? true : false;
                auto finish0 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed0 = finish0 - start0;
                
 
                auto start1 = chrono::high_resolution_clock::now();  
                bt4bool = (bTree->searchWord(inp1) != nullptr)? true : false;
                auto finish1 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed1 = finish1 - start1;
                
                (bbool || bt4bool) ? cout<< "true" : cout << "false";
                cout << endl;

                cout << "BST: " << elapsed0.count() << " s" << endl;
                cout << "HashTable: " << elapsed1.count() << " s" << endl;  
        }
        else if(func == "2"){
                cout << "Enter word to insert: " << endl;
                cin >> inp1;

                auto start0 = chrono::high_resolution_clock::now();
                tree->insertNode(inp1);
                auto finish0 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed0 = finish0 - start0;

                auto start1 = chrono::high_resolution_clock::now();
                bTree->insertWord(inp1, bTree->getRoot());
                auto finish1 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed1 = finish1 - start1;

                cout << "BST: " << elapsed0.count() << endl;
                cout << "Hash: " << elapsed1.count() << endl;
        }
        else if(func == "3"){
            cout << "Enter word to delete: " << endl;
            cin >> inp1;
                
            auto start0 = chrono::high_resolution_clock::now();
            tree->deleteNode(inp1);
            auto finish0 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed0 = finish0 - start0;

            auto start1 = chrono::high_resolution_clock::now();
            bTree->deleteWord(inp1, bTree->getRoot());
            auto finish1 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed1 = finish1 - start1;

            cout << "BST: " << elapsed0.count() << "s" << endl;
            cout << "Hash: " << elapsed1.count() << "s" << endl;
            }
            else if(func == "4"){
            outputToFile("reported", "output.txt");
            system("rm output.txt");

            auto start0 = chrono::high_resolution_clock::now();
            tree->sortTree();
            auto finish0 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed0 = finish0 - start0;

            outputToFile("", "output.txt");

            auto start1 = chrono::high_resolution_clock::now();
            bTree->sortWords(bTree->getRoot());
            auto finish1 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed1 = finish1 - start1;

            cout << "BST: " << elapsed0.count() << "s" << endl;
            cout << "Hash: " << elapsed1.count() << "s" << endl;
        }
        else if(func == "5"){
            cout << "Enter two words for ranged search." << endl;
            cout << "First word (lower bound): " << endl;
            cin >> inp1;
            cout << "Second word (upper bound): " << endl;
            cin >> inp2;
                
            auto start0 = chrono::high_resolution_clock::now();
            tree->rangeSearchTree(inp1, inp2);
            auto finish0 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed0 = finish0 - start0;

            cout << endl << endl;

            auto start1 = chrono::high_resolution_clock::now();
            bTree->rangeSearch(inp1, inp2);
            auto finish1 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed1 = finish1 - start1;

            cout << "BST: " << elapsed0.count() << endl;
            cout << "Hash: " << elapsed1.count() << endl;
        }
    }
    return 0;
}

void cleanParse(string& s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    find_and_replace(s, ",", "");
    find_and_replace(s, ".", "");
    find_and_replace(s, "!", "");
    find_and_replace(s, "?", "");
    find_and_replace(s, "(", "");
    find_and_replace(s, ")", "");
    find_and_replace(s, "*", "");
    find_and_replace(s, "&", "");
    find_and_replace(s, ":", "");
    find_and_replace(s, ";", "");
    find_and_replace(s, "�", "");
}

void readFilesToVec(vector<string>& fileNames, string path){
     for(auto& p: fs::recursive_directory_iterator(path)){
        string newPath = p.path().string();
        if(!is_directory(p.path())){
            int index = newPath.find("._");
            if( index < 0){
                find_and_replace(newPath, "/", "//");
                fileNames.push_back(newPath);
            }
        }
    }
}

//All credit for find_and_replace function goes to: http://bits.mdminhazulhaque.io/cpp/find-and-replace-all-occurrences-in-cpp-string.html
void find_and_replace(string& source, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}


void BTreeTesting(){

}