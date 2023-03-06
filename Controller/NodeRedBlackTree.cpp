//
// Created by Jocselyn Aguilar on 2/3/23.
//

#include "../Model/NodeRedBlackTree.h"


NodeRedBlackTree::NodeRedBlackTree() {}

NodeRedBlackTree::NodeRedBlackTree(int data, NodeRedBlackTree *parent, NodeRedBlackTree *right, NodeRedBlackTree *left, int color) {
    this->data = data;
    this->parent = nullptr;
    this->right = nullptr;
    this->left = nullptr;
    this->color = 0;
}


int NodeRedBlackTree::getData() {
    return this->data;
}

void NodeRedBlackTree::setData(int newData) {
    this->data = newData;
}

NodeRedBlackTree *NodeRedBlackTree::getParent() {
    return this->parent;
}

void NodeRedBlackTree::setParent(NodeRedBlackTree *newParent) {
    this->parent = newParent;
}

NodeRedBlackTree * NodeRedBlackTree::getLeft() {
    return this->left;
}

void NodeRedBlackTree::setLeft(NodeRedBlackTree *newLeft) {
    this->left = newLeft;
}

NodeRedBlackTree * NodeRedBlackTree::getRight() {
    return this->right;
}

void NodeRedBlackTree::setRight(NodeRedBlackTree *newRight) {
    this->right = newRight;
}

int NodeRedBlackTree::getColor() {
    return this->color;
}

void NodeRedBlackTree::setColor(int newColor) {
    this->color = newColor;
}