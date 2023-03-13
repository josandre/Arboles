#include <iostream>
#include "Model/RedBlackTree.h"
#include "ModelGestor/BPlusTreeController.h"
#include "Model/BTree.h"
#include "ModelGestor/AVLTreeController.h"


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
void AVLTest() {
    AVLTreeController* avlTree = new AVLTreeController();

    avlTree->AddBalanced(1);
    avlTree->AddBalanced(2);
    avlTree->AddBalanced(3);
    avlTree->AddBalanced(4);
    avlTree->AddBalanced(5);
    avlTree->AddBalanced(6);
    avlTree->AddBalanced(7);
    avlTree->AddBalanced(8);
    avlTree->AddBalanced(9);
    avlTree->AddBalanced(10);

    avlTree->Print();

    cout << "REMOVE 4" << endl;
    avlTree->Delete(4);
    cout << "" << endl << endl;
    avlTree->Print();

    cout << "REMOVE 2" << endl;
    avlTree->Delete(2);
    cout << "" << endl << endl;
    avlTree->Print();

    cout << "REMOVE 9" << endl;
    avlTree->Delete(9);
    cout << "" << endl << endl;
    avlTree->Print();
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

void BTreeTest(){
   BTree *b = new BTree(3);
   b->insert(10);
   b->insert(20);
   b->insert(5);
   b->insert(6);
   b->insert(12);
   b->insert(30);
   b->insert(7);
   b->insert(17);
   /*
    cout << "Traversal of the constructed tree is ";
    b->traverse();

    int k = 6;
    (b->search(k) != nullptr)? cout << "\nPresent" : cout << "\nNot Present";

    k = 15;
    (b->search(k) != nullptr)? cout << "\nPresent" : cout << "\nNot Present";
    */
    string* messageArray = new string[100];
    for (int i = 0; i < messageArray->size(); i++) {
        messageArray[i] = "";
    }

    b->print(b->getRoot(), messageArray, 0);

    for (int i = 0; i < messageArray->size(); i++) {
        if (messageArray[i] != "")
        {
            cout << messageArray[i] << endl;
        }
    }
}

int main() {
    //RedBlackTest();
    //BPlusTest();
    BTreeTest();
    return 0;
}
