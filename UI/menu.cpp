//
// Created by Elian Rocha on 12/3/23.
//

#include <iostream>
#include <limits>
#include "../ModelGestor/AVLTreeController.h"
#include "../ModelGestor/BPlusTreeController.h"
#include "../Model/RedBlackTree.h"
#include "../ModelGestor/BTreeController.h"
#include "../UI/menu.h"



// STATIC VARIABLES
static AVLTreeController *gestorAVL = new AVLTreeController();
static RedBlackTree *bst = new RedBlackTree();
static BTreeController *btree = new BTreeController(5);
static BPlusTreeController *bplus = new BPlusTreeController(4);


Menu::Menu() {

}



void Menu::insertar(int arbol)
{
    int input = -1;
    bool valid = false;

    switch (arbol)
    {
        case 1:
            do
            {
                cout << "Inserte un número (int): " << flush;
                cin >> input;
                if (cin.good())
                {
                    valid = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Inserte un número entero:" << endl;
                }
            } while (!valid);
            gestorAVL->AddBalanced(input);
            break;
        case 2:
            do
            {
                cout << "Inserte un número (int): " << flush;
                cin >> input;
                if (cin.good())
                {
                    valid = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Inserte un número entero:" << endl;
                }
            } while (!valid);
            bst->insert(input);
            break;
        case 3:
            do
            {
                cout << "Inserte un número (int): " << flush;
                cin >> input;
                if (cin.good())
                {
                    valid = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Inserte un número entero:" << endl;
                }
            } while (!valid);
            btree->insert(input);
            break;
        case 4:
            do
            {
                cout << "Inserte un número (int): " << flush;
                cin >> input;
                if (cin.good())
                {
                    valid = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Inserte un número entero:" << endl;
                }
            } while (!valid);
            bplus->Insert(input);
            break;
        case 0:
            cout << "Gracias!." << endl;
            break;
        default:
            cout << "Opción inválida. Ingrese otra opción" << endl;
    }
}



void Menu::remover(int arbol)
{
  int input = -1;
  bool valid = false;

  switch (arbol)
  {
  case 1:
    do
    {
      cout << "Inserte un número (int): " << flush;
      cin >> input;
      if (cin.good())
      {
        valid = true;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Inserte un número entero:" << endl;
      }
    } while (!valid);
      gestorAVL->Delete(input);
    break;
  case 2:
    do
    {
      cout << "Inserte un número (int): " << flush;
      cin >> input;
      if (cin.good())
      {
        valid = true;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Inserte un número entero:" << endl;
      }
    } while (!valid);
    bst->deleteNode(input);
    break;
  case 3:
    do
    {
      cout << "Inserte un número (int): " << flush;
      cin >> input;
      if (cin.good())
      {
        valid = true;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Inserte un número entero:" << endl;
      }
    } while (!valid);
      btree->deletion(input);
    break;
  case 4:
    do
    {
      cout << "Inserte un número (int): " << flush;
      cin >> input;
      if (cin.good())
      {
        valid = true;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Inserte un número entero:" << endl;
      }
    } while (!valid);
    bplus->Remove(input);
    break;
  case 0:
    cout << "Gracias!." << endl;
    break;
  default:
    cout << "Opción inválida. Ingrese otra opción" << endl;
  }
}

void Menu::buscar(int arbol)
{
  int input = -1;
  bool valid = false;

  switch (arbol)
  {
  case 1:
    do
    {
      cout << "Inserte un número (int): " << flush;
      cin >> input;
      if (cin.good())
      {
        valid = true;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Inserte un número entero:" << endl;
      }
    } while (!valid);
    if(gestorAVL->Search(input)){
        cout << input << endl;
    } else{
        cout << "this number does not exists" << endl;
    }

    break;
  case 2:
    do
    {
      cout << "Inserte un número (int): " << flush;
      cin >> input;
      if (cin.good())
      {
        valid = true;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Inserte un número entero:" << endl;
      }
    } while (!valid);
    bst->searchTree(input);
    break;
  case 3:
    do
    {
      cout << "Inserte un número (int): " << flush;
      cin >> input;
      if (cin.good())
      {
        valid = true;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Inserte un número entero:" << endl;
      }
    } while (!valid);
    btree->search(input);
    break;
  case 4:
    do
    {
      cout << "Inserte un número (int): " << flush;
      cin >> input;
      if (cin.good())
      {
        valid = true;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Inserte un número entero:" << endl;
      }
    } while (!valid);
    bplus->Search(input);
    break;
  case 0:
    cout << "Gracias!." << endl;
    break;
  default:
    cout << "Opción inválida. Ingrese otra opción" << endl;
  }
}



void Menu::imprimir(int arbol)
{
  int input = -1;
  bool valid = false;

  switch (arbol)
  {
  case 1:
    gestorAVL->Print();
    break;
  case 2:
    bst->printTree();
    break;
  case 3:
    btree->traverse();
    break;
  case 4:
    bplus->Print();
    break;
  case 0:
    cout << "Gracias!." << endl;
    break;
  default:
    cout << "Opción inválida. Ingrese otra opción" << endl;
  }
}

int Menu::menuOpcionesFun(int arbol, int answer)
{
    switch (answer)
    {
        case 1:

            insertar(arbol);
            break;
        case 2:
            remover(arbol);
            break;
        case 3:
            buscar(arbol);
            break;
        case 4:
            imprimir(arbol);
            break;
        case 0:
            cout << "Gracias!." << endl;
            break;
        default:
            cout << "Opción inválida. Ingrese otra opción" << endl;
    }
    return answer;
}

void Menu::menuPrincipal()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opción del menu:" << endl;
        cout << "1. Árbol AVL." << endl;
        cout << "2. Árbol Rojo Negro." << endl;
        cout << "3. Árbol B." << endl;
        cout << "4. Árbol B+." << endl;
        cout << "4. Mover datos entre estructuras." << endl;
        cout << "0. Exit." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        if(answer == 0){
            exit(0);
        }

        menuOpciones(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    }while (keepLooping);
}

void Menu::menuOpciones(int arbol)
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Insertar." << endl;
        cout << "2. Remover." << endl;
        cout << "3. Buscar." << endl;
        cout << "4. Imprimir." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuOpcionesFun(arbol, answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);

}
