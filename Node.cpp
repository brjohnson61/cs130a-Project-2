//
//  Node.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#include "Node.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>


using namespace std;

Node::Node(){
    word = "";
    count = 0;
}

Node::Node(string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    this->word = word;
    count = 1;
}

Node::Node(Node* copy){
    word = copy->getWord();
    count = copy->getCount();
}

bool Node::operator==(Node& rhs){
    if (this->word == rhs.getWord()){
        return true;
    }
    else{
        return false;
    }
}

bool Node::operator>( Node& rhs){
    if (this->word > rhs.getWord()){
        return true;
    }
    else{
        return false;
    }
}

bool Node::operator<(Node& rhs){
    if(this->word < rhs.getWord()){
        return true;
    }
    else{
        return false;
    }
}

void Node::operator=(Node& rhs){
    this->count = rhs.getCount();
    this->word = rhs.getWord();
}

string Node::getWord(){
    return this->word;
}

int Node::getCount(){
    return this->count;
}

void Node::setWord(string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    this->word = word;
}

void Node::setCount(int count){
    this->count = count;
}

void Node::increaseCount(){
    this->count++;
}

void Node::decreaseCount(){
    this->count--;
}

void outputToFile(string word, string pathName){
    ofstream outputFile; 
    outputFile.open(pathName, ios::app);
    outputFile << word << endl;
    outputFile.close();
}

