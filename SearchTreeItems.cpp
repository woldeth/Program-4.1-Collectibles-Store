// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: SearchTreeItems.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// SearchTreeItems class:
//   Implements the search tree specifcally for Items using the following
//   methods: insert(), find(), display()
//
//  The search tree is use to keep all the items stored in order by type
//  The search tree will perform various actions to assist transactions methods
//---------------------------------------------------------------------------

#include "SearchTreeItems.h"

///--------------------------------- ~SearchTreeItems ------------------------------------
// Constructor
// Preconditions: None
// Postconditions: Clears all dynamicaly allocated nodes
SearchTreeItems::~SearchTreeItems()
{
    clear(root);
}

void SearchTreeItems::clear(Node *&node)
{
    if (node == nullptr)
    {
        return;
    }

    clear(node->left);
    clear(node->right);

    delete node->item;
    node->item = nullptr;

    delete node;
    node = nullptr;
}

///--------------------------------- Insert ------------------------------------
// Takse ptr to customer and creates node to put in BST
// Preconditions: unique customer in bst
// Postconditions: Nodes is inserted in bst of unqiue type 
bool SearchTreeItems::insert(Item *ptr, int qty)
{
    bool flag = false;
    insertPrivate(ptr, root, flag, qty);
    return flag;
}

///--------------------------------- insertPrivate ------------------------------------
// Private helper method take ptr to customer and creates node to put in BST
// Preconditions: The tree has been created 
// Postconditions: Nodes is inseerted in bst as long as it does not exist
void SearchTreeItems::insertPrivate(Item *ptr, Node *&node, bool &flag, int qty)
{

    // Tree is empty
    if (node == nullptr)
    {
        Node *newNode = new Node(ptr);
        newNode->qty = qty;
        node = newNode;
        flag = true;
        return;
    }
    else if (*ptr == *(node->item)) // char is already in tree
    {
        cout << "Item already exist" << endl;
        return;
    }
    else if (*ptr < *(node->item))
    {
        insertPrivate(ptr, node->left, flag, qty); // traverse left
    }
    else if (*(node->item) < *ptr)
    {
        insertPrivate(ptr, node->right, flag, qty); // traverse right
    }
}

///--------------------------------- find ------------------------------------
// Traverse the item tree to find the specfic item for buy or sell
// Preconditions: The item must be in the tree
// Postconditions: The count will be increment or decremened
void SearchTreeItems::find(Item *i, bool buy)
{
    findPrivate(root, i, buy);
}

///--------------------------------- findPrivate ------------------------------------
// Private helper Traverse the item tree to find node to buy or sell
// Preconditions: The item must be in the tree to buy or sell
// Postconditions: The count will decrement for sale or incrementfor buy
void SearchTreeItems::findPrivate(Node *&node, Item *i, bool buy)
{
    if (node == nullptr)
    {
        return;
    }
    else if (*i == *(node->item)) // item is already in tree
    {
        if (buy == true)
        {
            node->qty = node->qty + 1;
            cout << "BOUGHT:\t";
            node->item->toString();
        }
        else if (buy == false && node->qty > 0)
        {
            node->qty = node->qty - 1;
            cout << "SOLD:\t";
            node->item->toString();
        }
        else
        {
            cout << "SOLD OUT" << endl;
        }
    }
    else if (*i < *(node->item))
    {
        findPrivate(node->left, i, buy); // traverse left
    }
    else if (*(node->item) < *i)
    {
        findPrivate(node->right, i, buy); // traverse right
    }
}

///--------------------------------- display ------------------------------------
// Traverse the customer tree to find the specfic item for buy or sell
// Preconditions: The tree to traverse must be passed in to
// Postconditions: All transactions will be printed inorder of alpha numeric of customer
void SearchTreeItems::display() const
{
    displayPrivate(root);
}

///--------------------------------- displayPrivate------------------------------------
// Private helper methdd to traverse the tree and print all items in order
// Preconditions: custTransactionList is populated with transactions
// Postconditions: All transactions will be printed inorder of alpha numeric of customer
void SearchTreeItems::displayPrivate(Node *node) const
{

    // node is empty
    if (node == nullptr)
    {
        return;
    }

    //inorder traversal
    displayPrivate(node->left);

    cout << "QTY: " << node->qty << "\t";
    node->item->toString();

    displayPrivate(node->right);
}