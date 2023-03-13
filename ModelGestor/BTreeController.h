#ifndef BTREECONTROLLER_H
#define BTREECONTROLLER_H

#include <iostream>
#include "../Model/BTree.h"

using namespace std;

class BTreeController
{
private:
  BTree *bTree;

public:
  BTreeController(int t);

  void traverse();
  BTreeNode *search(int key);
  void insert(int key);
  void print();
};

#endif // BTREECONTROLLER_H
