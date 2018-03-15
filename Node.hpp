
//
//  Node.hpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>



using namespace std;


class Node {
public:
    Node();
    Node(string word);
    Node(Node* copy);
    void operator=(Node& rhs);
    bool operator==( Node& rhs);
    bool operator<( Node& rhs);
    bool operator>( Node& rhs); 
    string getWord(void);
    int getCount(void);
    void setWord(string word);
    void setCount(int count);
    void decreaseCount(void);
    void increaseCount(void);
private:
    string word;
    int count;
};

void outputToFile(string word, string pathName);

#endif /* Node_hpp */