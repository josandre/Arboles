#ifndef BTREE_CONTROLLER_H
#define BTREE_CONTROLLER_H

#include "../Model/BTree.h"

class BTreeController
{
private:
  BTree *bTree;

public:
  BTreeController(int t);
  void traverse();
  BTreeNode *search(int key);
  void insert(int key);
};

#endif /* BTREE_CONTROLLER_H */
