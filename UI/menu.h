#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include "ModelGestor/AVLTreeController.h"
#include "ModelGestor/BPlusTreeController.h"
#include "Model/RedBlackTree.h"
#include "ModelGestor/BTreeController.h"

void menuPrincipal();
int menuOpciones(int arbol);
int menuOpcionesFun(int arbol, int answer);
void insertar(int arbol, AVLTreeController *gestorAVL, RedBlackTree *bst, BTreeController *btree, BPlusTreeController *bplus);
void remover(int arbol, AVLTreeController *gestorAVL, RedBlackTree *bst, BTreeController *btree, BPlusTreeController *bplus);
void buscar(int arbol, AVLTreeController *gestorAVL, RedBlackTree *bst, BTreeController *btree, BPlusTreeController *bplus);
void imprimir(int arbol, AVLTreeController *gestorAVL, RedBlackTree *bst, BTreeController *btree, BPlusTreeController *bplus);

void InsertBPlus(BPlusTreeController *tree, int value);

#endif
