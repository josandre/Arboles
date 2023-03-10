//
// Created by Elian Rocha on 9/3/23.
//

#include "../Model/Node.h"

// Constructor
Node::Node(int data)
{
    SetValue(data);
    SetLeft(nullptr);
    SetRight(nullptr);
    SetParent(nullptr);
}

// Gets
Node *Node::GetRight() {
    return this->right;
}

Node *Node::GetLeft() {
    return this->left;
}

Node *Node::GetParent() {
    return this->parent;
}

int Node::GetValue() {
    return this->value;
}

int Node::GetBalanceFactor() {
    return this->balanceFactor;
}

// Sets
void Node::SetRight(Node* node) {
    this->right = node;
}

void Node::SetLeft(Node* node) {
    this->left = node;
}

void Node::SetParent(Node *node) {
    this->parent = node;
}

void Node::SetValue(int value) {
    this->value = value;
}

void Node::SetBalanceFactor(int value) {
    this->balanceFactor = value;
}