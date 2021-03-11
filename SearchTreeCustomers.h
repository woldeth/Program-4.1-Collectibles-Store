// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: SearchTreeCustomers.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once

#include <iostream>

#include "Transaction.h"
//#include "Customer.h"

//class Customer;

using namespace std;

class SearchTreeCustomers
{
public:
    //Constructors and destructor
    SearchTreeCustomers() : root(nullptr) {}  // Constructor creates a BST new root
    ~SearchTreeCustomers(); // Destructor

    ///--------------------------------- Insert ------------------------------------
    // Takse ptr to customer and creates node to put in BST
    // Preconditions: unique customer in bst
    // Postconditions: Nodes is inseerted in bst
    bool insert(Customer *ptr);

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

    ///--------------------------------- Insert ------------------------------------
    // Takse ptr to customer and creates node to put in BST
    // Preconditions: unique customer in bst
    // Postconditions: Nodes is inseerted in bst
    void insertPrivate(Customer *ptr, Node *&node, bool &flag);


    ///--------------------------------- clear ------------------------------------
    // clears all dynamicall allocated memory
    // Preconditions: none
    // Postconditions: bst is cleared out completely
    void clear(Node *&node);

    // ///--------------------------------- traverseInorder ------------------------------------
    // // Traverse the customer tree to print out all transactions
    // // Preconditions: custTransactionList is populated with transactions
    // // Postconditions: All transactions will be printed inorder of alpha numeric of customer
    // const void traverseInorder() const;


    void historyPrivate(Node *node, customerNode custTransactionList[]) const;
};