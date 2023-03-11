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
    explicit BPlusTreeNode(int);

    // Gets
    bool IsLeaf();
    int GetSize();
    int* GetItem();
    BPlusTreeNode** GetChildren();
    BPlusTreeNode* GetParent();

    // Sets
    void SetIsLeaf(bool value);
    void SetSize(int value);
    void SetItem(int* value);
    void SetParent(BPlusTreeNode* value);
};

#endif //ARBOLES_BPLUSTREENODE_H
