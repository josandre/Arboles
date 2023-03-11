//
// Created by tsegura on 3/11/2023.
//

#include "../Model/BPlusTreeNode.h"

// Constructor
BPlusTreeNode::BPlusTreeNode(int _degree) {
        this->isLeaf = false;
        this->degree = _degree;
        this->size = 0;

        // Init items array
        int* _item = new int[_degree - 1];
        for (int i = 0; i < _degree - 1; i++) {
            _item[i] = 0;
        }
        this->item = _item;

        // Init pointers array
        BPlusTreeNode** _children = new BPlusTreeNode*[degree];
        for (int i = 0; i < degree; i++) {
            _children[i] = nullptr;
        }
        this->children = _children;

        this->parent = nullptr;
}

// Gets
bool BPlusTreeNode::IsLeaf() {
    return this->isLeaf;
}

int BPlusTreeNode::GetSize() {
    return this->size;
}

int* BPlusTreeNode::GetItem() {
    return this->item;
}

BPlusTreeNode** BPlusTreeNode::GetChildren() {
    return this->children;
}

BPlusTreeNode* BPlusTreeNode::GetParent() {
    return this->parent;
}

// Sets
void BPlusTreeNode::SetIsLeaf(bool value) {
    this->isLeaf = value;
}

void BPlusTreeNode::SetSize(int value) {
    this->size = value;
}

void BPlusTreeNode::SetItem(int* value) {
    this->item = value;
}

void BPlusTreeNode::SetParent(BPlusTreeNode* value) {
    this->parent = value;
}