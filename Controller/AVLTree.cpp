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
    // Find left and right heights
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