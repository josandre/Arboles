//
// Created by Jocselyn Aguilar on 12/3/23.
//

#ifndef ARBOLES_BTREE_H
#define ARBOLES_BTREE_H


#include "BtreeNode.h"

class BTree {
public:
    BTree(int);
    void traverse();
   BTreeNode *search(int);
   void insert(int);
    void print(BTreeNode*, string*, int);
    BTreeNode* getRoot();

private:
    BTreeNode *root;
    int t;
};


#endif //ARBOLES_BTREE_H
