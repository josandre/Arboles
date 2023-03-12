//
// Created by msaenz on 3/12/2023.
//
#ifndef NODE_H
#define NODE_H

class Node
{
public:
  int key;
  Node *left;
  Node *right;
  Node(int key);
};

void insert(Node *&root, int key);
Node *findMin(Node *root);
void deleteNode(Node *&root, int key);
void inorder(Node *root);
void print(Node *node);

#endif
