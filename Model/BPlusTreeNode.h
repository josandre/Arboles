//
// Created by tsegura on 3/11/2023.
//

#ifndef ARBOLES_BPLUSTREENODE_H
#define ARBOLES_BPLUSTREENODE_H

class BPlusTreeNode {
private:
    bool isLeaf;
    int degree;     // Max number of children
    int size;       // Current number of item

    int* item;
    BPlusTreeNode** children;
    BPlusTreeNode* parent;

public:
    // Constructor
    explicit BPlusTreeNode(int _degree) {
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
    bool IsLeaf() {
        return this->isLeaf;
    }

    int GetSize() {
        return this->size;
    }

    int* GetItem() {
        return this->item;
    }

    BPlusTreeNode** GetChildren() {
        return this->children;
    }

    BPlusTreeNode* GetParent() {
        return this->parent;
    }

    // Sets
    void SetIsLeaf(bool value) {
        this->isLeaf = value;
    }

    void SetSize(int value) {
        this->size = value;
    }

    void SetItem(int* value) {
        this->item = value;
    }

    void SetParent(BPlusTreeNode* value) {
        this->parent = value;
    }
};

#endif //ARBOLES_BPLUSTREENODE_H
