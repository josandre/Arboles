//
// Created by Jocselyn Aguilar on 2/3/23.
//

#include "../Model/RedBlackTree.h"


RedBlackTree::RedBlackTree() {
    this->tnull = new NodeRedBlackTree();
    this->tnull->setColor(0);
    this->tnull->setLeft(nullptr);
    this->tnull->setRight(nullptr);
    this->root = this->tnull;
}

void RedBlackTree::initializeNullNode(NodeRedBlackTree *node, NodeRedBlackTree *parent) {
    node->setData(0);
    node->setParent(parent);
    node->setLeft(nullptr);
    node->setRight(nullptr);
    node->setColor(0);
}


void RedBlackTree::preOrderHelper(NodeRedBlackTree *node) {
    if(node != this->tnull){
        cout << node->getData() << " ";
        preOrderHelper(node->getLeft());
        preOrderHelper(node->getRight());
    }
}

void RedBlackTree::inOrderHelper(NodeRedBlackTree *node) {
    if(node != this->tnull){
        inOrderHelper(node->getLeft());
        cout << node->getData() << " ";
        inOrderHelper(node->getRight());
    }
}

void RedBlackTree::postOrdenHelper(NodeRedBlackTree *node) {
    if(node != this->tnull){
        postOrdenHelper(node->getLeft());
        postOrdenHelper(node->getRight());
        cout << node->getData() << " ";
    }
}

NodeRedBlackTree *RedBlackTree::searchTreeHelper(NodeRedBlackTree *node, int data) {
    if(node == this->tnull || data == node->getData()){
        return node;
    }

    if(data < node->getData()){
        return searchTreeHelper(node->getLeft(), data);
    }

    return searchTreeHelper(node->getRight(), data);
}


void RedBlackTree::leftRotate(NodeRedBlackTree *x) {
    NodeRedBlackTree *y = x->getRight();
    x->setRight(y->getLeft());

    if(y->getLeft() != this->tnull){
        y->getLeft()->setParent(x);
    }

    y->setParent(x->getParent());

    if(x->getParent() == nullptr){
        this->root = y;
    }else if(x == x->getParent()->getLeft()){
        x->getParent()->setLeft(y);
    } else{
        x->getParent()->setRight(y);
    }
    y->setLeft(x);
    x->setParent(y);
}

void RedBlackTree::rightRotate(NodeRedBlackTree *x) {
    NodeRedBlackTree *y = x->getLeft();
    x->setLeft(y->getRight());

    if(y->getRight() != this->tnull){
        y->getRight()->setParent(x);
    }
    y->setParent(x->getParent());

    if(x->getParent() == nullptr){
        this->root = y;
    }else if(x == x->getParent()->getRight()){
        x->getParent()->setRight(y);
    }else{
        x->getParent()->setLeft(y);
    }

    y->setRight(x);
    x->setParent(y);
}

void RedBlackTree::deleteFiX(NodeRedBlackTree *x) {
    NodeRedBlackTree *s;
    while(x != this->root && x->getColor() == 0){
        if(x == x->getParent()->getLeft()){
            s = x->getParent()->getRight();;

            if(s->getColor() == 1){
                s->setColor(0);
                x->getParent()->setColor(1);
                leftRotate(x->getParent());
                s = x->getParent()->getRight();
            }

            if(s->getLeft()->getColor() == 0 && s->getRight()->getColor() == 0){
                s->setColor(1);
                x = x->getParent();
            }else{
                if(s->getRight()->getColor() == 0){
                    s->getLeft()->setColor(0);
                    s->setColor(1);
                    rightRotate(s);
                    s = x->getParent()->getRight();
                }

                s->setColor(x->getParent()->getColor());
                x->getParent()->setColor(0);
                s->getRight()->setColor(0);
                leftRotate(x->getParent());
                x = this->root;
            }
        } else{
            s = x->getParent()->getLeft();
            if(s->getColor() == 1){
                s->setColor(0);
                x->getParent()->setColor(1);
                rightRotate(x->getParent());
                s = x->getParent()->getLeft();
            }

            if(s->getRight()->getColor() == 0 && s->getRight()->getColor() == 0){
                s->setColor(1);
                x = x->getParent();
            }else{
                if(s->getLeft()->getColor() == 0){
                    s->getRight()->setColor(0);
                    s->setColor(1);
                    leftRotate(s);
                    s = x->getParent()->getLeft();
                }

                s->setColor(x->getParent()->getColor());
                x->getParent()->setColor(0);
                s->getLeft()->setColor(0);
                rightRotate(x->getParent());
                x = this->root;
            }
        }
    }

    x->setColor(0);
}

void RedBlackTree::rbTransplant(NodeRedBlackTree *u, NodeRedBlackTree *v) {
    if(u->getParent() == nullptr){
        this->root = v;
    }else if(u == u->getParent()->getLeft()){
        u->getParent()->setLeft(v);
    }else{
        u->getParent()->setRight(v);
    }

    v->setParent(u->getParent());
}

NodeRedBlackTree *RedBlackTree::minimum(NodeRedBlackTree *node) {
    while (node->getLeft() != this->tnull){
        node = node->getLeft();
    }

    return node;
}


void RedBlackTree::deleteNodeHelper(NodeRedBlackTree *node, int data) {
    NodeRedBlackTree *z = this->tnull;
    NodeRedBlackTree *x, *y;

    while(node != this->tnull){
        if(node->getData() == data){
            z = node;
        }

        if(node->getData() <= data){
            node = node->getRight();
        } else{
            node = node->getLeft();
        }
    }

    if(z == this->tnull){
        cout << "The keys was not found in the tree" << endl;
        return;
    }

    y = z;
    int yOriginalColor = y->getColor();
    if(z->getLeft() == this->tnull){
        x = z->getRight();
        rbTransplant(z, z->getRight());
    }else if(z->getRight() == this->tnull){
        x = z->getLeft();
        rbTransplant(z, z->getLeft());
    }else{
        y = minimum(z->getRight());
        yOriginalColor = y->getColor();
        x = y->getRight();

        if(y->getParent() == z){
            x->setParent(y);
        }else{
            rbTransplant(y, y->getRight());
            y->setRight(z->getRight());
            y->getRight()->setParent(y);
        }

        rbTransplant(z,y);
        y->setLeft(z->getLeft());
        y->getLeft()->setParent(y);
        y->setColor(z->getColor());
    }
    delete z;
    if(yOriginalColor == 0){
        deleteFiX(x);
    }

}

void RedBlackTree::insertFix(NodeRedBlackTree *k) {
    NodeRedBlackTree *u;


    while (k->getParent() != nullptr && k->getParent()->getColor() == 1){
        if(k->getParent() == k->getParent()->getParent()->getRight()){
            u = k->getParent()->getParent()->getLeft();

            if(u->getColor() == 1){
                u->setColor(0);
                k->getParent()->setColor(0);
                k->getParent()->getParent()->setColor(1);
                k = k->getParent()->getParent();
            }else{
                if(k == k->getParent()->getLeft()){
                    k = k->getParent();
                    rightRotate(k);
                }

                k->getParent()->setColor(0);
                k->getParent()->getParent()->setColor(1);
                leftRotate(k->getParent()->getParent());
            }
        } else{
            u = k->getParent()->getParent()->getRight();

            if(u->getColor() == 1){
                u->setColor(0);
                k->getParent()->setColor(0);
                k->getParent()->getParent()->setColor(1);
                k = k->getParent()->getParent();
            }else {
                if(k == k->getParent()->getRight()){
                    k = k->getParent();
                    leftRotate(k);


                    k->getParent()->setColor(0);
                    k->getParent()->getParent()->setColor(1);
                    rightRotate(k->getParent()->getParent());
                }
            }

            if(k == this->root){
                break;
            }
        }
    }

    root->setColor(0);
}


void RedBlackTree::printHelper(NodeRedBlackTree *root, string indent, bool last) {
    if(root != this->tnull){
        cout << indent;

        if(last){
            cout << "R-----";
            indent += "    ";
        }else{
            cout << "L------";
            indent += "|  ";
        }

        string sColor = root->getColor() ? "RED" : "BLACK";
        cout << root->getData() << "(" << sColor << ")" << endl;
        printHelper(root->getLeft(), indent, false);
        printHelper(root->getRight(), indent, true);
    }
}

void RedBlackTree::preOrder() {
    preOrderHelper(this->root);
}

void RedBlackTree::inOrder() {
    inOrderHelper(this->root);
}

void RedBlackTree::postOrden() {
    postOrdenHelper(this->root);
}

NodeRedBlackTree *RedBlackTree::searchTree(int data) {
    return searchTreeHelper(this->root, data);
}

NodeRedBlackTree *RedBlackTree::maximum(NodeRedBlackTree *node) {
    while (node->getRight() != this->tnull){
        node = node->getRight();
    }
    return node;
}

NodeRedBlackTree *RedBlackTree::sucesor(NodeRedBlackTree *node) {
    if(node->getRight() != this->tnull){
        return minimum(node->getRight());
    }

    NodeRedBlackTree *aux = node->getParent();
    while (aux != this->tnull && node == aux->getRight()){
        node = aux;
        aux = aux->getParent();
    }

    return aux;
}


NodeRedBlackTree *RedBlackTree::predecesor(NodeRedBlackTree *node) {
    if(node->getLeft() != this->tnull){
        return maximum(node->getLeft());
    }

    NodeRedBlackTree *aux = node->getParent();
    while (aux != this->tnull && node == aux->getLeft()){
        node = aux;
        aux = aux->getParent();
    }

    return aux;
}

void RedBlackTree::insert(int data) {
    NodeRedBlackTree *node = new NodeRedBlackTree();
    node->setParent(nullptr);
    node->setData(data);
    node->setLeft(this->tnull);
    node->setRight(this->tnull);
    node->setColor(1);

    NodeRedBlackTree *y = nullptr;
    NodeRedBlackTree *x = this->root;

    while (x != this->tnull){
        y = x;

        if(node->getData() < x->getData()){
            x = x->getLeft();
        }else{
            x = x->getRight();
        }
    }

    node->setParent(y);

    if(y == nullptr){
        this->root = node;
    }else if(node->getData() < y->getData()){
        y->setLeft(node);
    }else{
        y->setRight(node);
    }

    if(node->getParent() == nullptr){
        node->setColor(0);
        return;
    }

    if(node->getParent()->getParent() == nullptr){
        return;
    }

    insertFix(node);
}

NodeRedBlackTree *RedBlackTree::getRoot() {
    return this->root;
}

void RedBlackTree::deleteNode(int data) {
    deleteNodeHelper(this->root, data);
}

void RedBlackTree::printTree() {
    if(this->root){
        printHelper(this->root, "", true);
    }
}
