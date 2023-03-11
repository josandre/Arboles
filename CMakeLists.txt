cmake_minimum_required(VERSION 3.23)
project(Arboles)

set(CMAKE_CXX_STANDARD 14)

add_executable(Arboles main.cpp Controller/RedBlackTree.cpp Model/RedBlackTree.h Controller/NodeRedBlackTree.cpp Model/NodeRedBlackTree.h Controller/BPlusTreeNode.cpp Model/BPlusTreeNode.h Controller/BPlusTree.cpp Model/BPlusTree.h Controller/BPlusTreeController.cpp Model/BPlusTreeController.h)
