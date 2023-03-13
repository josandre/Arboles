//
// Created by Elian Rocha on 12/3/23.
//

#include <iostream>
#include <limits>
#include "../ModelGestor/AVLTreeController.h"
#include "../ModelGestor/BPlusTreeController.h"
#include "../Model/RedBlackTree.h"
#include "../ModelGestor/BTreeController.h"
#include "../ModelGestor/RedBlackController.h"
#include "../UI/menu.h"



// STATIC VARIABLES
static AVLTreeController *gestorAVL = new AVLTreeController();
static RedBlackController *bst = new RedBlackController();
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

    if (gestorAVL->Delete(input) == true) {
        cout << input << " fue eliminado correctamente" << endl;
    } else {
        cout << input << " no se puede eliminar porque no existe en la estructura" << endl;
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
      if (bst->deleteNode(input) == true) {
          cout << input << " fue eliminado correctamente" << endl;
      } else {
          cout << input << " no se puede eliminar porque no existe en la estructura" << endl;
      }
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

      if (btree->deletion(input) == true) {
          cout << input << " fue eliminado correctamente" << endl;
      } else {
          cout << input << " no se puede eliminar porque no existe en la estructura" << endl;
      }
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

      if (bplus->Remove(input) == true) {
          cout << input << " fue eliminado correctamente" << endl;
      } else {
          cout << input << " no se puede eliminar porque no existe en la estructura" << endl;
      }
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
        cout << "El número " << input << " si se encuentra en la estructura" << endl;
    } else{
        cout << "El número no existe en la estructura" << endl;
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

    if(bst->searchTree(input)){
        cout << "El número " << input << " si se encuentra en la estructura" << endl;
    } else{
        cout << "El número no existe en la estructura" << endl;
    }

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

      if(btree->search(input)){
          cout << "El número " << input << " si se encuentra en la estructura" << endl;
      } else{
          cout << "El número no existe en la estructura" << endl;
      }
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

      if(bplus->Search(input)){
          cout << "El número " << input << " si se encuentra en la estructura" << endl;
      } else{
          cout << "El número no existe en la estructura" << endl;
      }
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

void Menu::insertarDatosDePrueba() {
    gestorAVL->AddBalanced(1);
    gestorAVL->AddBalanced(2);
    gestorAVL->AddBalanced(3);
    gestorAVL->AddBalanced(4);
    gestorAVL->AddBalanced(5);

    bst->insert(6);
    bst->insert(7);
    bst->insert(8);
    bst->insert(9);
    bst->insert(10);

    btree->insert(11);
    btree->insert(12);
    btree->insert(13);
    btree->insert(14);
    btree->insert(15);

    bplus->Insert(16);
    bplus->Insert(17);
    bplus->Insert(18);
    bplus->Insert(19);
    bplus->Insert(20);
}

void Menu::datosEntreEstructuras() {

    int estructura1;
    int estructura2;
    int dato;

    cout << "-------------------------------------" << endl;
    cout << "Seleccione la estructura de la que desea obtener el dato:" << endl;
    cout << "1. Árbol AVL." << endl;
    cout << "2. Árbol Rojo Negro." << endl;
    cout << "3. Árbol B." << endl;
    cout << "4. Árbol B+." << endl;
    cout << "0. Exit." << endl;
    cout << "-------------------------------------" << endl;
    cin >> estructura1;

    cout << "-------------------------------------" << endl;
    cout << "Ingrese el dato que desea mover:" << endl;
    cin >> dato;

    bool exists = false;

    switch (estructura1) {
        case 1:
            exists = gestorAVL->Search(dato);
            break;
        case 2:
            exists = bst->searchTree(dato);
            break;
        case 3:
            exists = btree->search(dato);
            break;
        case 4:
            exists = bplus->Search(dato);
            break;
    }

    if (exists == false) {
        cout << "No se puede pasar el dato porque no existe en la estructura seleccionada" << endl;
        return;
    }

    cout << "-------------------------------------" << endl;
    cout << "Seleccione la estructura a la que desea transferir el dato:" << endl;
    cout << "1. Árbol AVL." << endl;
    cout << "2. Árbol Rojo Negro." << endl;
    cout << "3. Árbol B." << endl;
    cout << "4. Árbol B+." << endl;
    cout << "-------------------------------------" << endl;
    cin >> estructura2;

    if (estructura1 < 0 || estructura2 > 4) {
        cout << "Opción inválida" << endl;
        return;
    }

    switch (estructura1) {
        case 1:
            if (exists) {
                gestorAVL->Delete(dato);
            }
            break;
        case 2:
            if (exists) {
                bst->deleteNode(dato);
            }
            break;
        case 3:
            if (exists) {
                btree->deletion(dato);
            }
            break;
        case 4:
            if (exists == true) {
                bplus->Remove(dato);
            }
            break;
    }

    switch (estructura2) {
        case 1:
            gestorAVL->AddBalanced(dato);
            break;
        case 2:
            bst->insert(dato);
            break;
        case 3:
            btree->insert(dato);
            break;
        case 4:
            bplus->Insert(dato);
            break;
    }

    cout << "Operación realizada correctamente" << endl;
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
        cout << "5. Mover datos entre estructuras." << endl;
        cout << "6. Insertar datos de prueba" << endl;
        cout << "0. Exit." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        if (answer == 5) {
            datosEntreEstructuras();
        } else if (answer == 6) {
            insertarDatosDePrueba();
        } else if(answer == 0){
            exit(0);
        } else {
            menuOpciones(answer);
        }

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
