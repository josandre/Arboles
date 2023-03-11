//
// Created by tsegura on 3/11/2023.
//

#ifndef ARBOLES_BPLUSTREECONTROLLER_H
#define ARBOLES_BPLUSTREECONTROLLER_H

#include<iostream>

#include<list>
#include "BPlusTree.h"

using namespace std;

class BPlusTreeController {
private:
    BPlusTree* tree;

public:
    BPlusTreeController(int degree) {
        tree = new BPlusTree(degree);
    }

    void Insert(int data) {
        tree->Insert(data);
    }

    bool Search(int data) {
        return tree->Search(data);
    }

    // Generates a new tree based on the previous one but without the key that is removed
    void Remove(int data) {
        BPlusTree* oldTree = this->tree;
        this->tree = oldTree->Remove(data);

        delete oldTree;
    }

    void Print() {
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
};


#endif //ARBOLES_BPLUSTREECONTROLLER_H
