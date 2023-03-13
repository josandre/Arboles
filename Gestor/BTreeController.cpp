#include "../ModelGestor/BTreeController.h"

class BTreeController
{
private:
  BTree *bTree;

public:
  BTreeController(int t)
  {
    bTree = new BTree(t);
  }

  void traverse()
  {
    bTree->traverse();
  }

  BTreeNode *search(int key)
  {
    return bTree->search(key);
  }

  void insert(int key)
  {
    bTree->insert(key);
  }
};
