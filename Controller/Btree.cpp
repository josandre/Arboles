//
// Created by msaenz on 3/12/2023.
//
#include <iostream>
#include "node.h"
using namespace std;

Node::Node(int key)
{
  this->key = key;
  left = right = nullptr;
}

/*
 * insert: inserta un nuevo nodo en el árbol.
 * root: puntero a la raíz del árbol.
 * key: valor a insertar.
 */
void insert(Node *&root, int key)
{
  if (root == nullptr)
  { // Si la raíz es nula, crea un nuevo nodo con el valor a insertar.
    root = new Node(key);
    return;
  }
  if (key < root->key)
  { // Si el valor a insertar es menor que el valor de la raíz, llama a la función recursivamente para insertarlo en el subárbol izquierdo.
    insert(root->left, key);
  }
  else if (key > root->key)
  { // Si el valor a insertar es mayor que el valor de la raíz, llama a la función recursivamente para insertarlo en el subárbol derecho.
    insert(root->right, key);
  }
}

/*
 * findMin: encuentra el nodo con el valor mínimo en el subárbol especificado.
 * root: puntero a la raíz del subárbol.
 */
Node *findMin(Node *root)
{
  while (root->left != nullptr)
  { // Recorre el subárbol hacia la izquierda hasta encontrar un nodo sin hijo izquierdo.
    root = root->left;
  }
  return root; // Retorna el nodo con el valor mínimo.
}

/*
 * deleteNode: elimina un nodo del árbol binario de búsqueda.
 * root: puntero a la raíz del árbol.
 * key: valor del nodo a eliminar.
 */
void deleteNode(Node *&root, int key)
{
  if (root == nullptr)
  { // Si la raíz es nula, el nodo no existe en el árbol.
    return;
  }
  if (key < root->key)
  { // Si el valor a eliminar es menor que el valor de la raíz, llama a la función recursivamente para buscarlo en el subárbol izquierdo.
    deleteNode(root->left, key);
  }
  else if (key > root->key)
  { // Si el valor a eliminar es mayor que el valor de la raíz, llama a la función recursivamente para buscarlo en el subárbol derecho.
    deleteNode(root->right, key);
  }
  else
  { // Si el valor es igual al valor de la raíz, se encontró el nodo a eliminar.
    if (root->left == nullptr)
    { // Si el nodo no tiene hijo izquierdo, se enlaza el nodo derecho como hijo de la raíz y se elimina el nodo actual.
      Node *temp = root->right;
      delete root;
      root = temp;
      cout << "deleted successfully\n";
    }
    else if (root->right == nullptr)
    { // Si el nodo no tiene hijo derecho, se enlaza el nodo izquierdo como hijo de la raíz y se elimina el nodo actual.
      Node *temp = root->left;
      delete root;
      root = temp;
      cout << "deleted successfully\n";
    }
    else
    { // Si el nodo tiene dos hijos, se encuentra el nodo con el valor mínimo en su subárbol derecho y se reemplaza el valor del nodo actual por el valor mínimo.

      // Luego, se elimina el nodo con el valor mínimo en el subárbol derecho recursivamente.
      Node *temp = findMin(root->right);  // Encuentra el nodo con el valor mínimo en el subárbol derecho
      root->key = temp->key;              // Reemplaza el valor del nodo actual con el valor mínimo encontrado
      deleteNode(root->right, temp->key); // Elimina el nodo con el valor mínimo en el subárbol derecho recursivamente
    }
  }

  // Función para recorrer el árbol en orden (izquierda, raíz, derecha)
  void inorder(Node * root)
  {
    if (root == nullptr)
    {
      return;
    }
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
  }

  // Función para imprimir un mensaje cuando se elimina un nodo
  void print(Node * node)
  {
    cout << node->key << " deleted successfully\n";
  }