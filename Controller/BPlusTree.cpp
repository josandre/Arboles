//
// Created by tsegura on 3/11/2023.
//

#include "../Model/BPlusTree.h"

// Private functions
BPlusTreeNode* BPlusTree::Search(BPlusTreeNode* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    // Search leaf page
    BPlusTreeNode* cursor = node;
    while (cursor->IsLeaf() == false) {
        for (int i = 0; i < cursor->GetSize(); i++) {
            // Search child at the left
            if (key < cursor->GetItem()[i]) {
                cursor = cursor->GetChildren()[i];
                break;
            }

            // Search child at the right
            if (i == cursor->GetSize() - 1) {
                cursor = cursor->GetChildren()[i + 1];
            }
        }
    }

    // Search for the key if it exists in leaf node
    for (int i = 0; i < cursor->GetSize(); i++) {
        if (cursor->GetItem()[i] == key) {
            return cursor;
        }
    }

    return nullptr;
}

BPlusTreeNode* BPlusTree::RangeSearch(BPlusTreeNode* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    BPlusTreeNode* cursor = node;

    while (cursor->IsLeaf() == false) {
        for (int i = 0; i < cursor->GetSize(); i++) {
            if (key < cursor->GetItem()[i]) {
                cursor = cursor->GetChildren()[i];
                break;
            }
            if (i == cursor->GetSize() - 1) {
                cursor = cursor->GetChildren()[i + 1];
                break;
            }
        }
    }

    return cursor;
}

int BPlusTree::FindIndex(int* array, int data, int length) {
    int index = 0;

    for (int i = 0; i < length; i++) {
        // Internal pointers
        if (data < array[i]) {
            index = i;
            break;
        }

        // Last pointer
        if (i == length - 1) {
            index = length;
            break;
        }
    }

    return index;
}

int* BPlusTree::ItemInsert(int* array, int data, int length) {
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (data < array[i]) {
            index = i;
            break;
        }

        if (i == length - 1) {
            index = length;
            break;
        }
    }

    // Sort items in page
    for (int i = length; i > index; i--) {
        array[i] = array[i - 1];
    }

    array[index] = data;

    return array;
}

BPlusTreeNode** BPlusTree::ChildInsert(BPlusTreeNode** childArray, BPlusTreeNode* child, int length, int index) {
    for (int i = length; i > index; i--) {
        childArray[i] = childArray[i - 1];
    }

    childArray[index] = child;
    return childArray;
}

BPlusTreeNode* BPlusTree::ChildItemInsert(BPlusTreeNode* node, int data, BPlusTreeNode* child) {
    int itemIndex = 0;
    int childIndex = 0;

    for (int i = 0; i < node->GetSize(); i++) {
        if (data < node->GetItem()[i]) {
            itemIndex = i;
            childIndex = i + 1;
            break;
        }

        if (i == node->GetSize() - 1) {
            itemIndex = node->GetSize();
            childIndex = node->GetSize() + 1;
            break;
        }
    }

    // Move values
    for (int i = node->GetSize(); i > itemIndex; i--) {
        node->GetItem()[i] = node->GetItem()[i - 1];
    }
    // Move pointers
    for (int i = node->GetSize() + 1; i > childIndex; i--) {
        node->GetChildren()[i] = node->GetChildren()[i - 1];
    }

    // Insert value and pointer
    node->GetItem()[itemIndex] = data;
    node->GetChildren()[childIndex] = child;

    return node;
}

void BPlusTree::InsertParent(BPlusTreeNode* parent, BPlusTreeNode* child, int data) {
    BPlusTreeNode* cursor = parent;

    // Overflow check
    if (cursor->GetSize() < this->degree - 1) {  // There is no overflow, simply insert in correct position
        cursor = ChildItemInsert(cursor, data, child);
        cursor->SetSize(cursor->GetSize() + 1);
    }
    else {   // Handle overflow
        // New node
        BPlusTreeNode* newNode = new BPlusTreeNode(this->degree);
        newNode->SetParent(cursor->GetParent());

        // Copy items
        int* itemCopy = new int[cursor->GetSize() + 1];
        for (int i = 0; i < cursor->GetSize(); i++) {
            itemCopy[i] = cursor->GetItem()[i];
        }
        itemCopy = ItemInsert(itemCopy, data, cursor->GetSize());

        // Copy children nodes
        BPlusTreeNode** childCopy = new BPlusTreeNode*[cursor->GetSize() + 2];
        for (int i = 0; i < cursor->GetSize() + 1; i++) {
            childCopy[i] = cursor->GetChildren()[i];
        }
        childCopy[cursor->GetSize() + 1] = nullptr;
        childCopy = ChildInsert(childCopy, child, cursor->GetSize() + 1, FindIndex(itemCopy, data, cursor->GetSize() + 1));

        // Split nodes
        cursor->SetSize(this->degree / 2);
        if (this->degree % 2 == 0) {
            newNode->SetSize((this->degree / 2) - 1);
        } else {
            newNode->SetSize(this->degree / 2);
        }

        //
        for (int i = 0; i < cursor->GetSize(); i++) {
            cursor->GetItem()[i] = itemCopy[i];
            cursor->GetChildren()[i] = childCopy[i];
        }
        cursor->GetChildren()[cursor->GetSize()] = childCopy[cursor->GetSize()];

        //
        for (int i = 0; i < newNode->GetSize(); i++) {
            newNode->GetItem()[i] = itemCopy[cursor->GetSize() + i + 1];
            newNode->GetChildren()[i] = childCopy[cursor->GetSize() + i + 1];
            newNode->GetChildren()[i]->SetParent((newNode));
        }
        newNode->GetChildren()[newNode->GetSize()] = childCopy[cursor->GetSize() + newNode->GetSize() + 1];
        newNode->GetChildren()[newNode->GetSize()]->SetParent(newNode);

        int parentItem = itemCopy[this->degree / 2];

        delete[] itemCopy;
        delete[] childCopy;

        // Parent check (Insert middle value
        if (cursor->GetParent() == nullptr) { // Root
            BPlusTreeNode* newParent = new BPlusTreeNode(this->degree);
            cursor->SetParent(newParent);
            newNode->SetParent(newParent);

            newParent->GetItem()[0] = parentItem;
            newParent->SetSize(newParent->GetSize() + 1);

            newParent->GetChildren()[0] = cursor;
            newParent->GetChildren()[1] = newNode;

            this->root = newParent;

        } else { // The node already has a parent node
            InsertParent(cursor->GetParent(), newNode, parentItem);
        }
    }
}

// Used to generate a new tree without the value that is being deleted
void BPlusTree::MigrateToTree(BPlusTree* targetTree, BPlusTreeNode* currentNode, int dataToRemove) {
    if (currentNode == nullptr) {
        return;
    }

    if (currentNode->IsLeaf() == false) {
        for (int i = 0; i < currentNode->GetSize() + 1; i++) {
            MigrateToTree(targetTree, currentNode->GetChildren()[i], dataToRemove);
        }
    } else {
        for (int i = 0; i < currentNode->GetSize(); i++) {
            if (currentNode->GetItem()[i] != dataToRemove) {
                targetTree->Insert(currentNode->GetItem()[i]);
            }
        }
    }
}


// Public functions

// Constructor
BPlusTree::BPlusTree(int _degree) {
    this->root = nullptr;
    this->degree = _degree;
}

// Destructor
BPlusTree::~BPlusTree() {
    Clear(this->root);
}

// Get & Set
BPlusTreeNode* BPlusTree::GetRoot() {
    return this->root;
}

// Functions
bool BPlusTree::Search(int data) {
    return (Search(this->root, data)) != nullptr;
}

void BPlusTree::Insert(int data) {
    if (this->root == nullptr) {    // The tree is empty
        this->root = new BPlusTreeNode(this->degree);
        this->root->SetIsLeaf(true);
        this->root->GetItem()[0] = data;
        this->root->SetSize(1);

    } else { // There is at least one node
        BPlusTreeNode* cursor = this->root;

        // Move to leaf node
        cursor = RangeSearch(cursor, data);

        // Overflow check
        if (cursor->GetSize() < (this->degree - 1)) {   // No overflow, simply insert and sort
            // Insert item and rearrange
            cursor->SetItem(ItemInsert(cursor->GetItem(), data, cursor->GetSize()));
            cursor->SetSize(cursor->GetSize() + 1);

            // Pointers
            cursor->GetChildren()[cursor->GetSize()] = cursor->GetChildren()[cursor->GetSize() - 1];
            cursor->GetChildren()[cursor->GetSize() - 1] = nullptr;
        } else {    //Detected overflow
            BPlusTreeNode* newNode = new BPlusTreeNode(this->degree);
            newNode->SetIsLeaf(true);
            newNode->SetParent(cursor->GetParent());

            // Copy item
            int* itemCopy = new int[cursor->GetSize() + 1];
            for (int i = 0; i < cursor->GetSize(); i++) {
                itemCopy[i] = cursor->GetItem()[i];
            }

            // Insert and rearrange
            itemCopy = ItemInsert(itemCopy, data, cursor->GetSize());

            // Split nodes
            cursor->SetSize(this->degree / 2);
            if (this->degree % 2 == 0) {
                newNode->SetSize(this->degree / 2);
            } else {
                newNode->SetSize((this->degree / 2) + 1);
            }

            for (int i = 0; i < cursor->GetSize(); i++) {
                cursor->GetItem()[i] = itemCopy[i];
            }
            for (int i = 0; i < newNode->GetSize(); i++) {
                newNode->GetItem()[i] = itemCopy[cursor->GetSize() + i];
            }

            cursor->GetChildren()[cursor->GetSize()] = newNode;
            newNode->GetChildren()[newNode->GetSize()] = cursor->GetChildren()[this->degree - 1];
            cursor->GetChildren()[this->degree - 1] = nullptr;

            delete[] itemCopy;

            // Parent check, the value in the middle of the split must go to the parent node
            int parentItem = newNode->GetItem()[0];

            if (cursor->GetParent() == nullptr) {   // Root case
                BPlusTreeNode* newParent = new BPlusTreeNode(this->degree);
                cursor->SetParent(newParent);
                newNode->SetParent(newParent);

                newParent->GetItem()[0] = parentItem;
                newParent->SetSize(newParent->GetSize() + 1);

                newParent->GetChildren()[0] = cursor;
                newParent->GetChildren()[1] = newNode;

                this->root = newParent;
            } else { // There is already a parent defined
                InsertParent(cursor->GetParent(), newNode, parentItem);
            }
        }
    }
}

BPlusTree* BPlusTree::Remove(int data) {
    BPlusTree* newTree = new BPlusTree(this->degree);
    MigrateToTree(newTree, this->root, data);
    return newTree;
}

void BPlusTree::Clear(BPlusTreeNode* cursor) {
    if (cursor == nullptr) {
        return;
    }

    for (int i = 0; i < cursor->GetSize(); ++i) {
        Clear(cursor->GetChildren()[i]);
    }

    delete[] cursor->GetItem();
    delete[] cursor->GetChildren();
    delete cursor;
}

void BPlusTree::Print(BPlusTreeNode* cursor, string* messageArray, int level) {
    if (cursor == nullptr) {
        return;
    }

    string myNodes = "";
    // Print current node
    for (int i = 0; i < cursor->GetSize(); i++) {
        myNodes += "|" + to_string(cursor->GetItem()[i]);
    }
    myNodes += "|    ";
    messageArray[level] += myNodes;

    // Print children
    if (cursor->IsLeaf() == false) {

        for (int i = 0; i < cursor->GetSize() + 1; i++) {
            Print(cursor->GetChildren()[i], messageArray, level + 1);
        }
    }
}