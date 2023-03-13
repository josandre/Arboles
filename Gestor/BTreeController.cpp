#include "../Model/BTree.h"
#include "../ModelGestor/BTreeController.h"

  BTreeController::BTreeController(int t)
  {
    bTree = new BTree(t);
  }

  void BTreeController::traverse()
  {
    bTree->traverse();
  }

  BTreeNode *BTreeController::search(int key)
  {
    return bTree->search(key);
  }

  void BTreeController::insert(int key)
  {
    bTree->insert(key);
  }


  void BTreeController::deletion(int key)
  {
    bTree->deletion(key);
  }

