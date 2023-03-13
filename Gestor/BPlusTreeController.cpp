//
// Created by tsegura on 3/11/2023.
//

#include "../ModelGestor/BPlusTreeController.h"

BPlusTreeController::BPlusTreeController(int degree) {
    tree = new BPlusTree(degree);
}

void BPlusTreeController::Insert(int data) {
    tree->Insert(data);
}

bool BPlusTreeController::Search(int data) {
    return tree->Search(data);
}

// Generates a new tree based on the previous one but without the key that is removed
bool BPlusTreeController::Remove(int data) {
    bool exists = this->tree->Search(data);

    BPlusTree* oldTree = this->tree;
    this->tree = oldTree->Remove(data);

    delete oldTree;

    return exists;
}

void BPlusTreeController::Print() {
    string* messageArray = new string[100];
    for (int i = 0; i < messageArray->size(); i++) {
        messageArray[i] = "";
    }

    tree->Print(tree->GetRoot(), messageArray, 0);

    for (int i = 0; i < messageArray->size(); i++) {
        if (messageArray[i] != "")
        {
            cout << messageArray[i] << endl;
        }
    }
}