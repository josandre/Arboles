//
// Created by Elian Rocha on 9/3/23.
//


#include <iostream>
#include "../Model/Node.h"
#include "../Model/AVLTree.h"


// Constructor
AVLTree::AVLTree() {
    this->root = nullptr;
}

// Gets
Node* AVLTree::GetRoot() {
    return this->root;
}

// Sets
void AVLTree::SetRoot(Node* node) {
    this->root = node;
}

Node* AVLTree::MinValueNode(Node* currentNode) {
    Node* current = currentNode;

    // Search the smallest leaf
    while (current->GetLeft() != nullptr) {
        current = current->GetLeft();
    }

    return current;
}

// Methods
void AVLTree::Add(Node* currentNode, int value) {
    if (currentNode == nullptr) {
        //Assign root
        if (GetRoot() == nullptr) {
            Node *newNode = new Node(value);
            SetRoot(newNode);
        }
        return;
    }

    // Less than current node
    if (value < currentNode->GetValue()) {
        // If there is a node at the left then compare recursively
        if (currentNode->GetLeft() != nullptr) {
            Add(currentNode->GetLeft(), value);
            return;
            // Add the new node as the left child of this node
        } else {
            Node *newNode = new Node(value);
            newNode->SetParent(currentNode);
            currentNode->SetLeft(newNode);
            return;
        }
    }

    // Greater than current node
    if (value > currentNode->GetValue()) {
        // If there is a node at the right then compare recursively
        if (currentNode->GetRight() != nullptr) {
            Add(currentNode->GetRight(), value);
            return;
            // Add the new node as the left child of this node
        } else {
            Node *newNode = new Node(value);
            newNode->SetParent(currentNode);
            currentNode->SetRight(newNode);
            return;
        }
    }
}

void AVLTree::AddBalanced(Node* currentNode, int value) {
    Add(currentNode, value);
    CheckForBalance(currentNode);
    BalanceTree(currentNode);
}

Node* AVLTree::Delete(Node* currentNode, int value) {

    if (currentNode == nullptr) {
        return nullptr;
    }

    // Search node to delete based value
    if (value < currentNode->GetValue()) {  // Less than current node value
        currentNode->SetLeft(Delete(currentNode->GetLeft(), value));

    } else if (value > currentNode->GetValue()) {   // Greater than current node value
        currentNode->SetRight(Delete(currentNode->GetRight(), value));

    } else { // We found the node to be deleted
        // Node with one child or none
        if (currentNode->GetLeft() == nullptr ||
            currentNode->GetRight() == nullptr) {
            Node *temp = currentNode->GetLeft();
            if (temp == nullptr) {
                temp = currentNode->GetRight();
            }

            // No child case
            if (temp == nullptr) {
                temp = currentNode;
                currentNode = nullptr;
                // One child case
            } else {
                // Copy content
                *currentNode = *temp;
            }

            // Clear node
            delete temp;
            // Node with two children
        } else {
            // Get the inorder successor (Smallest node in the right subtree)
            Node *temp = MinValueNode(currentNode->GetRight());

            // Get smallest data to current node
            currentNode->SetValue(temp->GetValue());

            // Delete the inorder successor
            currentNode->SetRight(Delete(currentNode->GetRight(), temp->GetValue()));
        }
    }

    // If the tree only had one node then return
    if (currentNode == nullptr) {
        return nullptr;
    }

    // Balance tree
    CheckForBalance(root);
    BalanceTree(root);

    return currentNode;
}

bool AVLTree::Search(Node* currentNode, int value) {
    if (currentNode == nullptr) {
        return false;
    }

    // Just found it
    if (currentNode->GetValue() == value) {
        return true;
    }

    // Search in children
    if (value < currentNode->GetValue()) {
        return Search(currentNode->GetLeft(), value);
    }
    if (value > currentNode->GetValue()) {
        return Search(currentNode->GetRight(), value);
    }

    return false;
}

void AVLTree::CheckForBalance(Node* currentNode) {
    if (currentNode == nullptr)
    {
        return;
    }

    int balance = Height(currentNode->GetRight(), -1) - Height(currentNode->GetLeft(), -1);
    currentNode->SetBalanceFactor(balance);
    CheckForBalance(currentNode->GetLeft());
    CheckForBalance(currentNode->GetRight());

    //cout << "(" << currentNode->GetValue() << ") FE: " << balance << endl;
    return;
}

bool AVLTree::BalanceTree(Node* currentNode) {
    if (currentNode == nullptr)
    {
        return false;
    }

    // Modify the tree to make sure is balanced
    if (abs(currentNode->GetBalanceFactor()) > 1)
    {
        if (ApplyRotation(currentNode))
        {
            return true;
        }
    }

    if (BalanceTree(currentNode->GetLeft()))
    {
        return true;
    }
    if (BalanceTree(currentNode->GetRight()))
    {
        return true;
    }

    return false;
}

bool AVLTree::ApplyRotation(Node* currentNode) {

    if (currentNode->GetBalanceFactor() == -2)
    {
        // Simple Right
        if (currentNode->GetLeft()->GetBalanceFactor() == -1)
        {
            cout << "Simple Right" << endl;
            SimpleRight(currentNode);
            return true;
        }
        // Double Right
        if (currentNode->GetLeft()->GetBalanceFactor() == 1)
        {
            cout << "Double Right" << endl;
            SimpleLeft(currentNode->GetLeft());
            SimpleRight(currentNode);
            return true;
        }
    }
    else if (currentNode->GetBalanceFactor() == 2)
    {
        // Simple Left
        if (currentNode->GetRight()->GetBalanceFactor() == 1)
        {
            cout << "Simple Left" << endl;
            SimpleLeft(currentNode);
            return true;
        }
        // Double Left
        if (currentNode->GetRight()->GetBalanceFactor() == -1)
        {
            cout << "Double Left" << endl;
            SimpleRight(currentNode->GetRight());
            SimpleLeft(currentNode);
            return true;
        }
    }

    return false;
}

void AVLTree::SimpleRight(Node* currentNode) {
    if (currentNode == nullptr)
    {
        return;
    }

    Node* P = currentNode;
    Node* Q = (P != nullptr) ? P->GetLeft() : nullptr;
    Node* A = (Q != nullptr) ? Q->GetLeft() : nullptr;
    Node* B = (Q != nullptr) ? Q->GetRight() : nullptr;
    Node* C = (P != nullptr) ? P->GetRight() : nullptr;

    Node* pParent = P->GetParent();

    // B as left for P
    P->SetLeft(B);
    if (B != nullptr)
    {
        B->SetParent(P);
    }

    // P as right for Q
    Q->SetRight(P);
    P->SetParent(Q);

    // Q takes P position
    Q->SetParent(pParent);
    if (pParent == nullptr)
    {
        SetRoot(Q);
    }
    else
    {
        if (P == pParent->GetLeft())
        {
            pParent->SetLeft(Q);
        }
        if (P == pParent->GetRight())
        {
            pParent->SetRight(Q);
        }
    }
}

void AVLTree::SimpleLeft(Node* currentNode) {
    if (currentNode == nullptr)
    {
        return;
    }

    Node* P = currentNode;
    Node* Q = (P != nullptr) ? P->GetRight() : nullptr;
    Node* A = (P != nullptr) ? P->GetLeft() : nullptr;
    Node* B = (Q != nullptr) ? Q->GetLeft() : nullptr;
    Node* C = (Q != nullptr) ? Q->GetRight() : nullptr;

    Node* pParent = P->GetParent();

    // B as right of P
    P->SetRight(B);
    if (B != nullptr)
    {
        B->SetParent(P);
    }

    // P as left of Q
    Q->SetLeft(P);
    P->SetParent(Q);

    // Q takes P position
    Q->SetParent(pParent);
    if (pParent == nullptr)
    {
        SetRoot(Q);
    }
    else
    {
        if (P == pParent->GetLeft())
        {
            pParent->SetLeft(Q);
        }
        if (P == pParent->GetRight())
        {
            pParent->SetRight(Q);
        }
    }
}

int AVLTree::Height(Node* currentNode, int currentHeight) {
    if (currentNode == nullptr)
    {
        return currentHeight;
    }

    currentHeight++;
    // Search left and right heights
    int leftHeight = Height(currentNode->GetLeft(), currentHeight);
    int rightHeight = Height(currentNode->GetRight(), currentHeight);

    return max(leftHeight, rightHeight);
}

int AVLTree::Weight(Node* currentNode) {
    if (currentNode == nullptr)
    {
        return 0;
    }

    int count = 1;  // Count self
    count += Weight(currentNode->GetLeft());    // Left child
    count += Weight(currentNode->GetRight());   // Right child
    return count;
}

// Pre Order: Root, Left, Right
string AVLTree::PrintPreOrder(Node* currentNode) {
    if (currentNode == nullptr)
    {
        return "";
    }

    string elements = "";
    elements += to_string(currentNode->GetValue()) + ", ";
    elements += PrintPreOrder(currentNode->GetLeft());
    elements += PrintPreOrder(currentNode->GetRight());

    return elements;
}

// In Order: Left, Root, Right
string AVLTree::PrintInOrder(Node* currentNode) {
    if (currentNode == nullptr)
    {
        return "";
    }

    string elements = "";
    elements += PrintInOrder(currentNode->GetLeft());
    elements += to_string(currentNode->GetValue()) + ", ";
    elements += PrintInOrder(currentNode->GetRight());

    return elements;
}

// Post Order: Left, Right, Root
string AVLTree::PrintPostOrder(Node* currentNode) {
    if (currentNode == nullptr)
    {
        return "";
    }

    string elements = "";
    elements += PrintPostOrder(currentNode->GetLeft());
    elements += PrintPostOrder(currentNode->GetRight());
    elements += to_string(currentNode->GetValue()) + ", ";

    return elements;
}

// Print the tree with format
string AVLTree::Print(Node* currentNode, int level, string prefix) {
    if (currentNode == nullptr)
    {
        return "\n";
    }

    string number = "(" + to_string(currentNode->GetValue()) + ")";
    for (int i = number.length(); i < 7; i++)
    {
        number = "-" + number;
    }
    number = "-" + number;
    if (currentNode->GetLeft() != nullptr || currentNode->GetRight() != nullptr)
    {
        number += "|";
    }

    prefix += "|       ";
    Print(currentNode->GetRight(), level + 1, prefix);
    cout << prefix << number << endl;
    Print(currentNode->GetLeft(), level + 1, prefix);
    return "";
}