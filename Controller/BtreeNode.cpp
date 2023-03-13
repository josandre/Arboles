


#include "../Model/BtreeNode.h"

BTreeNode::BTreeNode(int t1, bool leaf1)
{
    this->t = t1;
    this->leaf = leaf1;
    this->keys = new int[2*t-1];
    this->c = new BTreeNode *[2*t];
    this->n = 0;
}

void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < n; i++)
    {

        if (leaf == false){
            this->c[i]->traverse();
        }

        cout << " " << keys[i];

    }


    if (leaf == false){
        this->c[i]->traverse();
    }

}

BTreeNode *BTreeNode::search(int key)
{

    int i = 0;
    while (i < n && key > keys[i]){
        i++;
    }


    if (keys[i] == key){
        return this;
    }

    if (leaf == true){
        return nullptr;
    }

    return this->c[i]->search(key);
}

int *BTreeNode::getKeys() {
    return this->keys;
}

int BTreeNode::getN() {
    return this->n;
}

bool BTreeNode::getLeaf() {
    return this->leaf;
}

void BTreeNode::setN(int n) {
    this->n = n;
}

BTreeNode **BTreeNode::getC() {
    return this->c;
}

void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;


    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++){
            z->getC()[j] = y->getC()[j+t];
        }


    }

    y->n = t - 1;

    for (int j = n; j >= i+1; j--){
        this->getC()[j+1] = this->getC()[j];
    }


    this->getC()[i+1] = z;


    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];


    keys[i] = y->keys[t-1];


    n = n + 1;
}

void BTreeNode::insertNonFull(int key) {

    int i = n-1;
    if (leaf == true)
    {

        while (i >= 0 && keys[i] > key)
        {
            keys[i+1] = keys[i];
            i--;
        }


        keys[i+1] = key;
        n = n+1;
    }
    else
    {

        while (i >= 0 && keys[i] > key)
            i--;


        if (this->c[i+1]->n == 2*t-1)
        {
            splitChild(i+1, c[i+1]);
            if (keys[i+1] < key)
                i++;
        }
        c[i+1]->insertNonFull(key);
    }
}
