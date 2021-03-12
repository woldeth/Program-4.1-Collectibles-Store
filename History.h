// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: History.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// History class:
//   Prints alls the transactions of every customer in alpha numeric order
//   This uses the search tree of customer to traverse in order and the id
//   to access the transaction nodes.
//---------------------------------------------------------------------------

#pragma once

#include <iostream>

#include "Transaction.h"

using namespace std;

class History : public Transaction
{

public:
    History() : Transaction('H', -1) {}           // dummy constructor
    History(int cust) : Transaction('H', cust) {} // constructor w/ paramters
    virtual ~History() {}                         // destructor

    ///--------------------------------- excute ------------------------------------
    // Prints the history of every customer by customer name
    // Preconditions: None
    // Postconditions: The item will print the entire history of transaction in alpha order
    virtual void excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H);
};
