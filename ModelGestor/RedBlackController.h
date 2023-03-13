//
// Created by Jocselyn Aguilar on 12/3/23.
//

#ifndef ARBOLES_REDBLACKCONTROLLER_H
#define ARBOLES_REDBLACKCONTROLLER_H
#include "../Model/RedBlackTree.h"
#include "../Model/NodeRedBlackTree.h"


class RedBlackController {
public:
    RedBlackController();
    void insert(int);
    bool searchTree(int);
    void deleteNode(int);
    void printTree();

private:
    RedBlackTree *redBlackTree;


};


#endif //ARBOLES_REDBLACKCONTROLLER_H
