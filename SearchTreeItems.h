// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: SearchTreeCustomers.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once

#include <iostream>
#include "Item.h"

using namespace std;

class SearchTreeItems
{
public:
    //Constructors and destructor
    SearchTreeItems() : root(nullptr) {}  // Constructor creates a BST new root
    ~SearchTreeItems(); // Destructor

    ///--------------------------------- Insert ------------------------------------
    // Takse ptr to customer and creates node to put in BST
    // Preconditions: unique customer in bst
    // Postconditions: Nodes is inseerted in bst
    bool insert(Item *ptr, int qty);

    ///--------------------------------- find ------------------------------------
    // Traverse the customer tree to find the specfic item for buy or sell
    // Preconditions: The tree to traverse must be passed in to 
    // Postconditions: All transactions will be printed inorder of alpha numeric of customer
    void find(Item *i, bool buy);

     void display() const;

private:
    struct Node
    {
        Item *item;                                               // Pointer to customer object
        int qty;
        Node *left;                                                   // Pointer to left child
        Node *right;                                                  // Pointer to right child
        Node(Item *i) : item(i), left(nullptr), right(nullptr) {} // Constructor to initialize node
    };

    Node *root; // Root Node of custSearchTree

    ///--------------------------------- Insert ------------------------------------
    // Takse ptr to customer and creates node to put in BST
    // Preconditions: unique customer in bst
    // Postconditions: Nodes is inseerted in bst
    void insertPrivate(Item *ptr, Node *&node, bool &flag, int qty);


    ///--------------------------------- clear ------------------------------------
    // clears all dynamicall allocated memory
    // Preconditions: none
    // Postconditions: bst is cleared out completely
    void clear(Node *&node);

    ///--------------------------------- find ------------------------------------
    // Traverse the customer tree to print out all transactions
    // Preconditions: custTransactionList is populated with transactions
    // Postconditions: All transactions will be printed inorder of alpha numeric of customer
    void findPrivate(Node *&node, Item *i, bool buy);


    void displayPrivate(Node *node) const;

    
};