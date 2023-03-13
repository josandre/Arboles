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

void RedBlackController::deleteNode(int key) {
    redBlackTree->deleteNode(key);
}

bool RedBlackController::searchTree(int key) {
    return redBlackTree->searchTree(key);
}

void RedBlackController::printTree() {
    redBlackTree->printTree();
}