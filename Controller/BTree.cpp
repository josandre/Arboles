//
// Created by Jocselyn Aguilar on 12/3/23.
//
#include "../Model/BTree.h"

BTree::BTree(int _t) {
    root = nullptr;
    t = _t;
}

void BTree::traverse() {
    if (root != nullptr)
        root->traverse();
}



void BTree::insert(int k) {
    if (root == nullptr) {
        this->root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(t, false);

            s->C[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        } else
            root->insertNonFull(k);
    }
}


void BTree::deletion(int k) {
    if (!root) {
        cout << "The tree is empty\n";
        return;
    }

    root->deletion(k);

    if (root->n == 0) {
        BTreeNode *tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];

        delete tmp;
    }
    return;
}