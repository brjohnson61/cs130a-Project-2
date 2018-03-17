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
    //BTreeTesting();

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
        int btree= 0;
        while(inFile >> load){
            cleanParse(load);
            if(load != ""){
                tree = tree->insertNode(load);
                bTree->insertWord(load, bTree->getRoot());
                //wordCount++;
            }
        }
        inFile.close();
    }
    
    
    // bTree->sortWords(bTree->getRoot());
    
    // cout << "Option 1: Test complexity and timing" << endl;
    // cout << "Option 2: Regular output" << endl;

    // string navigation = "";
    // cin >> navigation;

    // if(navigation == "1"){
    //     ifstream inFile("testWords.txt");
    //     string load = "";
    //     wordCount = 0;
    //     auto startTimeTest = chrono::high_resolution_clock::now();
    //     while(inFile >> load){
    //         cleanParse(load);
    //         if(load != ""){
    //             if(wordCount == 1000){
    //                 break;
    //             }
    //             tree = tree->insertNode(load);
    //             //bTree->insertWord(load, bTree->getRoot());
    //             wordCount++;
    //         }
    //     }
    //     auto finishTimeTest = chrono::high_resolution_clock::now();
    //     inFile.close();
    //     chrono::duration<double> elapsedTimeTest = finishTimeTest - startTimeTest;
    //     cout << "Timing Test: " << elapsedTimeTest.count() << " s" << endl;
    // }


    // cout << "Begin Final Turnin Select Menu" << endl;

    while(1){

        // cout << "Option 1: Search" << endl;
        // cout << "Option 2: Insert" << endl;
        // cout << "Option 3: Delete" << endl;
        // cout << "Option 4: Sort" << endl;
        // cout << "Option 5: Range Search" << endl;

        cin >> func; 
        if(func == "1"){
                bool bt4bool, bbool;
                //cout << "Enter word to search for: " << endl;
                cin >> inp1;
                
                auto start0 = chrono::high_resolution_clock::now();
                bbool = (tree->searchTree(inp1)) ? true : false;
                auto finish0 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed0 = finish0 - start0;
                
 
                auto start1 = chrono::high_resolution_clock::now();  
                bt4bool = (bTree->searchWord(inp1, bTree->getRoot()) != nullptr)? true : false;
                auto finish1 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed1 = finish1 - start1;
                
                (bbool) ? cout<< "true" : cout << "false";
                cout << endl;

                cout << "AVL: " << elapsed0.count() << " s" << endl;
                cout << "2-5: " << elapsed1.count() << " s" << endl;  
        }
        else if(func == "2"){
                // cout << "Enter word to insert: " << endl;
                cin >> inp1;

                auto start0 = chrono::high_resolution_clock::now();
                tree = tree->insertNode(inp1);
                auto finish0 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed0 = finish0 - start0;

                auto start1 = chrono::high_resolution_clock::now();
                //bTree->insertWord(inp1, bTree->getRoot());
                auto finish1 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed1 = finish1 - start1;

                cout << "AVL: " << elapsed0.count() << endl;
                cout << "2-5: " << elapsed1.count() << endl;
        }
        else if(func == "3"){
            // cout << "Enter word to delete: " << endl;
            cin >> inp1;
                
            auto start0 = chrono::high_resolution_clock::now();
            tree = tree->deleteNode(inp1);
            auto finish0 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed0 = finish0 - start0;

            auto start1 = chrono::high_resolution_clock::now();
            bTree->deleteWord(inp1, bTree->getRoot());
            auto finish1 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed1 = finish1 - start1;

            cout << "AVL: " << elapsed0.count() << "s" << endl;
            cout << "2-5: " << elapsed1.count() << "s" << endl;
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

            cout << "AVL: " << elapsed0.count() << "s" << endl;
            cout << "2-5: " << elapsed1.count() << "s" << endl;
        }
        else if(func == "5"){
            // cout << "Enter two words for ranged search." << endl;
            // cout << "First word (lower bound): " << endl;
            cin >> inp1;
            // cout << "Second word (upper bound): " << endl;
            cin >> inp2;
                
            auto start0 = chrono::high_resolution_clock::now();
            tree->rangeSearchTree(inp1, inp2);
            auto finish0 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed0 = finish0 - start0;

            cout << endl << endl;

            auto start1 = chrono::high_resolution_clock::now();
            bTree->rangeSearch(inp1, inp2, bTree->getRoot());
            auto finish1 = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed1 = finish1 - start1;

            cout << "AVL: " << elapsed0.count() << endl;
            cout << "2-5: " << elapsed1.count() << endl;
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
    BTree5* tree = new BTree5();

    tree->insertWord("animal",tree->getRoot());
    tree->insertWord("welch",tree->getRoot());
    tree->insertWord("hungry",tree->getRoot());
    tree->insertWord("happy",tree->getRoot());
    tree->insertWord("hello", tree->getRoot());
    tree->insertWord("name", tree->getRoot());
    tree->insertWord("translate", tree->getRoot());
    tree->insertWord("tradition", tree->getRoot());
    tree->insertWord("terrain", tree->getRoot());
    tree->insertWord("answer", tree->getRoot());
    tree->insertWord("angel", tree->getRoot());
    tree->insertWord("trash", tree->getRoot());
    tree->insertWord("winner", tree->getRoot());
    tree->insertWord("won", tree->getRoot());
    tree->insertWord("wonderful", tree->getRoot());
    tree->insertWord("zit", tree->getRoot());
    tree->insertWord("zzz", tree->getRoot());
    tree->insertWord("vault", tree->getRoot());
    tree->insertWord("trunk", tree->getRoot());
    tree->insertWord("quart", tree->getRoot());
    tree->insertWord("van", tree->getRoot());
    tree->insertWord("vast", tree->getRoot());
    tree->insertWord("xanax", tree->getRoot());
    tree->insertWord("zorro", tree->getRoot());
    tree->insertWord("zombie", tree->getRoot());
    tree->insertWord("xaxaphone", tree->getRoot());
    tree->insertWord("zone", tree->getRoot());
    tree->insertWord("zam", tree->getRoot());
    tree->insertWord("basement", tree->getRoot());
    tree->insertWord("montreal", tree->getRoot());
    tree->insertWord("numbers", tree->getRoot());
    tree->insertWord("sort", tree->getRoot());
    tree->insertWord("text", tree->getRoot());
    tree->insertWord("sext", tree->getRoot());
    tree->insertWord("you", tree->getRoot());
    tree->insertWord("yoursel", tree->getRoot());
    tree->insertWord("yam", tree->getRoot());
    tree->insertWord("yesterday", tree->getRoot());
    tree->insertWord("yard", tree->getRoot());
    tree->insertWord("yeeeeee", tree->getRoot());
    tree->insertWord("yesterday", tree->getRoot());
    tree->insertWord("yard", tree->getRoot());
    tree->insertWord("yeeeeee", tree->getRoot());
    tree->insertWord("wow", tree->getRoot());
    tree->insertWord("what", tree->getRoot());
    tree->insertWord("wart", tree->getRoot());
    tree->insertWord("wash", tree->getRoot());
    tree->insertWord("winier", tree->getRoot());
    tree->insertWord("wet", tree->getRoot());
    tree->insertWord("pussy", tree->getRoot());
    tree->insertWord("waterdrop", tree->getRoot());
    tree->insertWord("eskit", tree->getRoot());
    tree->insertWord("bones", tree->getRoot());


    tree->deleteWord("zzz", tree->getRoot());
    tree->deleteWord("bones", tree->getRoot());
    tree->deleteWord("zorro", tree->getRoot());
    
    cout << endl<< endl;
    
    
    // cout << "After deleting" << endl << endl;

    tree->sortWords(tree->getRoot()); 
    tree->getHeight(tree->getRoot(), 0);
    
    BTreeNode* temp = tree->searchWord("wet", tree->getRoot());
    cout << "Search pointer " << temp << endl;


     //tree->deleteWord("zorro", tree->getRoot());
    
    
    
}