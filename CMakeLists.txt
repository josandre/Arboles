cmake_minimum_required(VERSION 3.23)
project(Arboles)

set(CMAKE_CXX_STANDARD 14)

add_executable(Arboles main.cpp Controller/RedBlackTree.cpp Model/RedBlackTree.h Controller/NodeRedBlackTree.cpp Model/NodeRedBlackTree.h Controller/BPlusTreeNode.cpp Model/BPlusTreeNode.h Controller/BPlusTree.cpp Model/BPlusTree.h Gestor/BPlusTreeController.cpp ModelGestor/BPlusTreeController.h Controller/AVLTree.cpp Gestor/AVLTreeController.cpp Controller/Node.cpp Controller/BTree.cpp Controller/BtreeNode.cpp Gestor/BTreeController ModelGestor/BTreeController.h UI/menu.cpp)