cmake_minimum_required(VERSION 3.23)
project(Arboles)

set(CMAKE_CXX_STANDARD 14)

add_executable(Arboles main.cpp Controller/AVLTree.cpp Controller/BPlusTree.cpp Controller/BPlusTreeNode.cpp Controller/BTree.cpp Controller/BtreeNode.cpp Controller/Node.cpp Controller/NodeRedBlackTree.cpp Controller/RedBlackTree.cpp Gestor/AVLTreeController.cpp Gestor/BPlusTreeController.cpp Gestor/BTreeController.cpp UI/menu.cpp)