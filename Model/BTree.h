//
// Created by Jocselyn Aguilar on 12/3/23.
//

#ifndef ARBOLES_BTREE_H
#define ARBOLES_BTREE_H


#include "BtreeNode.h"

class BTree {

public:
    BTree(int _t);
    void traverse();
    void insert(int k);
    void deletion(int k);
    BTreeNode *search(int k);



private:
    BTreeNode *root;
    int t;
};


#endif //ARBOLES_BTREE_H
