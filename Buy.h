// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Buy.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Buy class:
//   Inherits from transaction class and defines the excute method to
//   increment the amount of items in the searchtree of items.
//---------------------------------------------------------------------------

#pragma once

#include <iostream>

#include "Transaction.h"

using namespace std;

class Buy : public Transaction
{

public:
    Buy() : Transaction('B', -1) {}           // dummy constructor
    Buy(int cust) : Transaction('B', cust) {} // constructor with parameters
    virtual ~Buy() {}                         //destructor

    ///--------------------------------- excute ------------------------------------
    // Buys a items that is passed into the infile stream
    // Preconditions: Item must already exist in the search tree of items
    // Postconditions: The item will be incremented in the searchtree of items
    virtual void excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H);
};
