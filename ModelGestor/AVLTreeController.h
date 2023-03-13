//
// Created by Elian Rocha on 9/3/23.
//

#ifndef ARBOLES_AVLTREECONTROLLER_H
#define ARBOLES_AVLTREECONTROLLER_H

#include "../Model/AVLTree.h"

class AVLTreeController {
private:
    AVLTree* avlTree;

public:
    // Constructor
    explicit AVLTreeController();

    // Methods
    void Add(int);
    void AddBalanced(int);
    void Delete(int);
    bool Search(int);

    void BalanceTree();
    int Height();
    int Weight();

    string PrintPreOrder();
    string PrintInOrder();
    string PrintPostOrder();

    void Print();
};

#endif //ARBOLES_AVLTREECONTROLLER_H
