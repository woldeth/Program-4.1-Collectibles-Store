// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: SearchTreeCustomers.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// SearchTreeCustomers class:
//   Implements the search tree specifcally for customers using the following
//   methods: insert(), clears(), histoy()
//		
//  The search tree is used to keep the customer during traversal. The customer
//  search tree will be use with other items to perfrom various commands
//---------------------------------------------------------------------------
#pragma once

#include <iostream>

#include "Transaction.h"
#include "Customer.h"

using namespace std;

class SearchTreeCustomers
{
public:
    //Constructors and destructor
    SearchTreeCustomers() : root(nullptr) {}
    ~SearchTreeCustomers(); // Destructor

    ///--------------------------------- Insert ------------------------------------
    // Takse ptr to customer and creates node to put in BST
    // Preconditions: unique customer in bst
    // Postconditions: Nodes is inseerted in bst
    bool insert(Customer *ptr);

    ///--------------------------------- history ------------------------------------
    // Traverse the customer tree to print out all transactions
    // Preconditions: custTransactionList is populated with transactions
    // Postconditions: All transactions will be printed inorder of alpha numeric of customer
    void history(customerNode custTransactionList[]) const;

private:
    struct Node
    {
        Customer *item;                                               // Pointer to customer object
        Node *left;                                                   // Pointer to left child
        Node *right;                                                  // Pointer to right child
        Node(Customer *i) : item(i), left(nullptr), right(nullptr) {} // Constructor to initialize node
    };

    Node *root; // Root Node of custSearchTree

    ///--------------------------------- InsertPrivate ------------------------------------
    // Takes ptr to customer and creates node to put in BST
    // Preconditions: unique customer in bst
    // Postconditions: Nodes is inserted in bst
    void insertPrivate(Customer *ptr, Node *&node, bool &flag);

    ///--------------------------------- clear ------------------------------------
    // clears all dynamicall allocated memory
    // Preconditions: none
    // Postconditions: bst is cleared out completely
    void clear(Node *&node);

    ///--------------------------------- historyPrivate ------------------------------------
    // Traverse the customer tree to print out all transactions
    // Preconditions: custTransactionList is populated with transactions
    // Postconditions: All transactions will be printed inorder of alpha numeric of customer
    void historyPrivate(Node *node, customerNode custTransactionList[]) const;
};