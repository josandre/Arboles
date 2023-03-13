cmake_minimum_required(VERSION 3.23)
project(Arboles)

set(CMAKE_CXX_STANDARD 14)

add_executable(Arboles main.cpp UI/menu.cpp UI/menu.h Controller/AVLTree.cpp Model/AVLTree.h Controller/BPlusTree.cpp Model/BPlusTree.h Controller/BPlusTreeNode.cpp Model/BPlusTreeNode.h Controller/BTree.cpp Model/BTree.h Controller/BtreeNode.cpp Model/BtreeNode.h Controller/Node.cpp Model/Node.h Controller/NodeRedBlackTree.cpp Model/NodeRedBlackTree.h Controller/RedBlackTree.cpp Model/RedBlackTree.h Gestor/AVLTreeController.cpp ModelGestor/AVLTreeController.h Gestor/BPlusTreeController.cpp ModelGestor/BPlusTreeController.h ModelGestor/BTreeController.h Gestor/BTreeController.cpp Gestor/RedBlackController.cpp ModelGestor/RedBlackController.h)