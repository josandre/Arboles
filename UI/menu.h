#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include "../ModelGestor/AVLTreeController.h"
#include "../ModelGestor/BPlusTreeController.h"
#include "../Model/RedBlackTree.h"
#include "../ModelGestor/BTreeController.h"

class Menu{
public:
    Menu();
    void menuPrincipal();
    void menuOpciones(int arbol);
    int menuOpcionesFun(int arbol, int answer);
    void insertar(int arbol);
    void remover(int arbol);
    void buscar(int arbol);
    void imprimir(int arbol);
};



#endif
