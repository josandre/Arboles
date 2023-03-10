//
// Created by Elian Rocha on 9/3/23.
//

#ifndef ARBOLES_NODE_H
#define ARBOLES_NODE_H

class Node {

private:
    Node* left;
    Node* right;
    Node* parent;
    int value;
    int balanceFactor;

public:
    // Constructor
    explicit Node(int);

    // Gets
    Node* GetRight();
    Node* GetLeft();
    Node* GetParent();
    int GetValue();
    int GetBalanceFactor();

    // Sets
    void SetLeft(Node*);
    void SetRight(Node*);
    void SetParent(Node*);
    void SetValue(int);
    void SetBalanceFactor(int);
};

#endif //ARBOLES_NODE_H
