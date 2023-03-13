//
// Created by msaenz on 3/12/2023.
//
#ifndef NODE_H
#define NODE_H
#include "iostream"
using namespace std;

class BTreeNode
{
public:
    BTreeNode(int, bool);
    void insertNonFull(int );
    void splitChild(int, BTreeNode *);
    void traverse();
    BTreeNode *search(int k);
    int *getKeys();
    int getN();
    bool getLeaf();
    void setN(int);
    BTreeNode **getC();

private:
    int *keys;
    int t;
    BTreeNode **c;
    int n;
    bool leaf;
};



#endif
