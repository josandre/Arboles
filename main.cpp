#include <iostream>
#include "Model/RedBlackTree.h"

int main() {
    RedBlackTree *bst = new RedBlackTree();
    bst->insert(55);
    bst->insert(40);
    bst->insert(65);
    bst->insert(60);
    bst->insert(75);
    bst->insert(57);
    bst->printTree();
    bst->deleteNode(60);
    bst->printTree();
    return 0;
}
