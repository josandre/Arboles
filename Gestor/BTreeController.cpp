#include "../Model/BTree.h"

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

  void print()
  {
    string *lines = new string[100];
    for (int i = 0; i < 100; i++)
    {
      lines[i] = "";
    }
    bTree->print(bTree->getRoot(), lines, 0);
    for (int i = 0; i < 100; i++)
    {
      if (lines[i] != "")
      {
        cout << lines[i] << endl;
      }
    }
    delete[] lines;
  }
  void deletion(int key)
  {
    bTree->deletion(key);
  }
};
