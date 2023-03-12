#include <iostream>
#include "Model/RedBlackTree.h"
#include "Model/BPlusTreeController.h"

void InsertBPlus(BPlusTreeController* tree, int value) {
    cout << "INSERT " << value << endl;
    tree->Insert(value);
    tree->Print();
    cout << endl << endl;
}
void BPlusTest() {
    BPlusTreeController* tree = new BPlusTreeController(4);

    InsertBPlus(tree, 15);
    InsertBPlus(tree, 16);
    InsertBPlus(tree, 17);
    InsertBPlus(tree, 18);
    InsertBPlus(tree, 19);
    InsertBPlus(tree, 20);
    InsertBPlus(tree, 30);
    InsertBPlus(tree, 40);
    InsertBPlus(tree, 50);
    InsertBPlus(tree, 60);
    InsertBPlus(tree, 70);
    InsertBPlus(tree, 80);
    InsertBPlus(tree, 90);
    InsertBPlus(tree, 100);

    cout << endl << "Remove 30" << endl << endl;
    tree->Remove(30);
    tree->Print();

    cout << endl << "Remove 15" << endl << endl;
    tree->Remove(15);
    tree->Print();

    cout << endl << "Remove 20" << endl << endl;
    tree->Remove(20);
    tree->Print();

}

void RedBlackTest() {
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
}

void BTree(){
    Node *root = nullptr;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);
    deleteNode(root, 40);
    inorder(root);
    return 0;
}

int main() {
    RedBlackTest();
    //BPlusTest();
    cout << "Btree resultados";
    BTree();

    return 0;
}
