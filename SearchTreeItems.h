// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: SearchTreeItems.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// SearchTreeItems class:
//   Implements the search tree specifcally for Items using the following
//   methods: insert(), find(), display()
//
//  The search tree is use to keep all the items stored in order by type
//  The search tree will perform various actions to assist transactions methods
//---------------------------------------------------------------------------

#pragma once

#include <iostream>
#include "Item.h"

using namespace std;

class SearchTreeItems
{
public:
    ///--------------------------------- SearchTreeItem ------------------------------------
    // Constructor
    // Preconditions: None
    // Postconditions: Initializes the search tree root
    SearchTreeItems() : root(nullptr) {}

    ///--------------------------------- ~SearchTreeItems ------------------------------------
    // Constructor
    // Preconditions: None
    // Postconditions: Clears all dynamicaly allocated nodes
    ~SearchTreeItems();

    ///--------------------------------- Insert ------------------------------------
    // Takse ptr to customer and creates node to put in BST
    // Preconditions: The tree has been created 
    // Postconditions: Nodes is inseerted in bst of unqiue type
    bool insert(Item *ptr, int qty);

    ///--------------------------------- find ------------------------------------
    // Traverse the item tree to find the specfic item for buy or sell
    // Preconditions: The item must be in the tree
    // Postconditions: The count will be increment or decremened
    void find(Item *i, bool buy);

    ///--------------------------------- display ------------------------------------
    // Traverse the customer tree to find the specfic item for buy or sell
    // Preconditions: The tree to traverse must be passed in to
    // Postconditions: All transactions will be printed inorder of alpha numeric of customer
    void display() const;

private:
    struct Node
    {
        Item *item; // Pointer to customer object
        int qty;
        Node *left;                                               // Pointer to left child
        Node *right;                                              // Pointer to right child
        Node(Item *i) : item(i), left(nullptr), right(nullptr) {} // Constructor to initialize node
    };

    Node *root; // Root Node of custSearchTree

    ///--------------------------------- insertPrivate ------------------------------------
    // Private helper method take ptr to customer and creates node to put in BST
    /// Preconditions: The tree has been created 
    // Postconditions: Nodes is inseerted in bst as long as it does not exist
    void insertPrivate(Item *ptr, Node *&node, bool &flag, int qty);

    ///--------------------------------- clear ------------------------------------
    // clears all dynamicall allocated memory
    // Preconditions: none
    // Postconditions: bst is cleared out completely
    void clear(Node *&node);

    ///--------------------------------- findPrivate ------------------------------------
    // Private helper Traverse the item tree to find node to buy or sell
    // Preconditions: The item must be in the tree to buy or sell
    // Postconditions: The count will decrement for sale or incrementfor buy
    void findPrivate(Node *&node, Item *i, bool buy);

    ///--------------------------------- displayPrivate------------------------------------
    // Private helper methdd to traverse the tree and print all items in order
    // Preconditions: custTransactionList is populated with transactions
    // Postconditions: All transactions will be printed inorder of alpha numeric of customer
    void displayPrivate(Node *node) const;
};