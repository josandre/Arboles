//
// Created by tsegura on 3/11/2023.
//

#ifndef ARBOLES_BPLUSTREE_H
#define ARBOLES_BPLUSTREE_H

#include "BPlusTreeNode.h"
#include <iostream>

using namespace std;

class BPlusTree {
private:
    BPlusTreeNode* root;
    int degree;

    // Private functions
    BPlusTreeNode* Search(BPlusTreeNode* node, int key);

    BPlusTreeNode* RangeSearch(BPlusTreeNode* node, int key);

    int FindIndex(int* array, int data, int length);

    int* ItemInsert(int* array, int data, int length);

    BPlusTreeNode** ChildInsert(BPlusTreeNode** childArray, BPlusTreeNode* child, int length, int index);

    BPlusTreeNode* ChildItemInsert(BPlusTreeNode* node, int data, BPlusTreeNode* child);

    void InsertParent(BPlusTreeNode* parent, BPlusTreeNode* child, int data);

    // Used to generate a new tree without the value that is being deleted
    void MigrateToTree(BPlusTree* targetTree, BPlusTreeNode* currentNode, int dataToRemove);

public:
    // Constructor
    explicit BPlusTree(int);

    // Destructor
    ~BPlusTree();

    // Get & Set
    BPlusTreeNode* GetRoot();

    // Functions
    bool Search(int);

    void Insert(int);

    BPlusTree* Remove(int);

    void Clear(BPlusTreeNode*);

    void Print(BPlusTreeNode*, string*, int);
};

#endif //ARBOLES_BPLUSTREE_H
