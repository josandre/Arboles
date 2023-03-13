//
// Created by msaenz on 3/12/2023.
//
#ifndef NODE_H
#define NODE_H
#include "iostream"
using namespace std;

class BTreeNode {
    int *keys;
    int t;
    BTreeNode **C;
    int n;
    bool leaf;

public:
    BTreeNode(int _t, bool _leaf);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void traverse();
    int findKey(int k);
    void deletion(int k);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPredecessor(int idx);
    int getSuccessor(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
    friend class BTree;
    BTreeNode *search(int k);
};



#endif
