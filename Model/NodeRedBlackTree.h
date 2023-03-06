//
// Created by Jocselyn Aguilar on 2/3/23.
//

#ifndef ARBOLES_NODEREDBLACKTREE_H
#define ARBOLES_NODEREDBLACKTREE_H


class NodeRedBlackTree {
public:
    NodeRedBlackTree(int, NodeRedBlackTree*, NodeRedBlackTree*,NodeRedBlackTree*, int);
    NodeRedBlackTree();
    int getData();
    void setData(int);
    NodeRedBlackTree *getParent();
    void setParent(NodeRedBlackTree *);
    NodeRedBlackTree *getLeft();
    void setLeft(NodeRedBlackTree *);
    NodeRedBlackTree *getRight();
    void setRight(NodeRedBlackTree *);
    int getColor();
    void setColor(int);

private:
    int data;
    NodeRedBlackTree *parent;
    NodeRedBlackTree *left;
    NodeRedBlackTree *right;
    int color;
};


#endif //ARBOLES_NODEREDBLACKTREE_H
