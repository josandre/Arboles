//
// Created by Elian Rocha on 9/3/23.
//

#include "../Model/AVLTreeController.h"

// Constructor
AVLTreeController::AVLTreeController() {
    this->avlTree = new AVLTree();
}

// Methods
void AVLTreeController::Add(int value) {
    this->avlTree->Add(this->avlTree->GetRoot(), value);
}


void AVLTreeController::AddBalanced(int value) {
    this->avlTree->AddBalanced(this->avlTree->GetRoot(), value);
}

void AVLTreeController::Delete(int value) {
    this->avlTree->Delete(this->avlTree->GetRoot(), value);
}

void AVLTreeController::BalanceTree() {
    this->avlTree->CheckForBalance(this->avlTree->GetRoot());
    this->avlTree->BalanceTree(this->avlTree->GetRoot());
}

int AVLTreeController::Height() {
    return this->avlTree->Height(this->avlTree->GetRoot(), 0);
}

int AVLTreeController::Weight() {
    return this->avlTree->Weight(this->avlTree->GetRoot());
}

string AVLTreeController::PrintPreOrder() {
    string elements = this->avlTree->PrintPreOrder(this->avlTree->GetRoot());
    return elements;
}

string AVLTreeController::PrintInOrder() {
    string elements = this->avlTree->PrintInOrder(this->avlTree->GetRoot());
    return elements;
}

string AVLTreeController::PrintPostOrder() {
    string elements = this->avlTree->PrintPostOrder(this->avlTree->GetRoot());
    return elements;
}

void AVLTreeController::Print() {
    string elements = this->avlTree->Print(this->avlTree->GetRoot(), 0, "");
    return;
}