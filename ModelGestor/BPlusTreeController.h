//
// Created by tsegura on 3/11/2023.
//

#ifndef ARBOLES_BPLUSTREECONTROLLER_H
#define ARBOLES_BPLUSTREECONTROLLER_H

#include "../Model/BPlusTree.h"
#include<iostream>

using namespace std;

class BPlusTreeController {
private:
    BPlusTree* tree;

public:
    explicit BPlusTreeController(int);

    // Inserts a new value into the tree
    void Insert(int);

    // Returns true if the value is in the tree
    bool Search(int);

    // Generates a new tree based on the previous one but without the key that is removed
    bool Remove(int);

    // Prints the tree structure in the console
    void Print();
};


#endif //ARBOLES_BPLUSTREECONTROLLER_H
