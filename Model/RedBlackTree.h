//
// Created by Jocselyn Aguilar on 2/3/23.
//

#ifndef ARBOLES_REDBLACKTREE_H
#define ARBOLES_REDBLACKTREE_H


#include "NodeRedBlackTree.h"
#include "iostream"

using namespace std;

class RedBlackTree {

public:
    RedBlackTree();
    void leftRotate(NodeRedBlackTree *);
    void rightRotate(NodeRedBlackTree *);
    NodeRedBlackTree *minimum(NodeRedBlackTree *);
    NodeRedBlackTree *maximum(NodeRedBlackTree *);
    NodeRedBlackTree *sucesor(NodeRedBlackTree *);
    NodeRedBlackTree *predecesor(NodeRedBlackTree *);
    void insert(int);
    void preOrder();
    void inOrder();
    void postOrden();
    NodeRedBlackTree *searchTree(int);
    NodeRedBlackTree *getRoot();
    void deleteNode(int);
    void printTree();


private:
    NodeRedBlackTree *root;
    NodeRedBlackTree  *tnull;
    void setRoot(NodeRedBlackTree *);
    NodeRedBlackTree *getTnull();
    void setTNull(NodeRedBlackTree *);
    void initializeNullNode(NodeRedBlackTree * , NodeRedBlackTree *);
    void preOrderHelper(NodeRedBlackTree *);
    void inOrderHelper(NodeRedBlackTree *);
    void postOrdenHelper(NodeRedBlackTree *);
    NodeRedBlackTree *searchTreeHelper(NodeRedBlackTree *, int);
    void deleteFiX(NodeRedBlackTree *);
    void rbTransplant(NodeRedBlackTree *, NodeRedBlackTree *);
    void deleteNodeHelper(NodeRedBlackTree *, int);
    void insertFix(NodeRedBlackTree *);
    void printHelper(NodeRedBlackTree *, string ,bool);

};


#endif //ARBOLES_REDBLACKTREE_H
