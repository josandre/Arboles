//
// Created by Jocselyn Aguilar on 12/3/23.
//

#include "../ModelGestor/RedBlackController.h"

RedBlackController::RedBlackController() {
    redBlackTree = new RedBlackTree();
}

void RedBlackController::insert(int key) {
    redBlackTree->insert(key);
}

bool RedBlackController::deleteNode(int key) {
    bool exists = redBlackTree->searchTree(key);
    redBlackTree->deleteNode(key);

    return exists;
}

bool RedBlackController::searchTree(int key) {
    return redBlackTree->searchTree(key);
}

void RedBlackController::printTree() {
    redBlackTree->printTree();
}