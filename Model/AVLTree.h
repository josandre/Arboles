//
// Created by Elian Rocha on 9/3/23.
//

#ifndef ARBOLES_AVLTREE_H
#define ARBOLES_AVLTREE_H


#include <string>
#include "Node.h"

using namespace std;

class AVLTree {
private:
    Node* root;

    Node* MinValueNode(Node*);

public:
    // Constructor
    explicit AVLTree();

    // Gets
    Node* GetRoot();

    // Sets
    void SetRoot(Node *node);

    // Methods
    void Add(Node*, int);
    void AddBalanced(Node*, int);
    Node* Delete(Node*, int);
    bool Search(Node*, int);

    void CheckForBalance(Node*);
    bool BalanceTree(Node*);
    void SimpleRight(Node *currentNode);
    void SimpleLeft(Node*);
    bool ApplyRotation(Node*);

    // Longest path from the root to a node + 1
    int Height(Node*, int);
    // Number of elements
    int Weight(Node*);

    string PrintPreOrder(Node*);
    string PrintInOrder(Node*);
    string PrintPostOrder(Node*);

    string Print(Node*, int, string);
};

#endif //ARBOLES_AVLTREE_H
