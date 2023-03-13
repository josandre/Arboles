//
// Created by Jocselyn Aguilar on 12/3/23.
//
#include "../Model/BTree.h"

BTree::BTree(int t) {
    this->root = nullptr;
    this->t = t;
}

void BTree::traverse() {
    if(this->root != nullptr) this->root->traverse();
}

BTreeNode *BTree::search(int key) {
    return this->root == nullptr ? nullptr : this->root->search(key);
}

void BTree::insert(int key) {

    if (root == nullptr)
    {

        root = new BTreeNode(t, true);
        root->getKeys()[0] = key;
        root->setN(1);
    }
    else
    {

        if (root->getN() == 2*t-1)
        {

            BTreeNode *s = new BTreeNode(t, false);
            s->getC()[0] = this->root;
            s->splitChild(0, this->root);

            int i = 0;
            if (s->getKeys()[0] < key){
                i++;
            }
            s->getC()[i]->insertNonFull(key);

            root = s;
        }
        else  {
            root->insertNonFull(key);
        }

    }
}
