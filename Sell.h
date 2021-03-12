// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Sell.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Sell class:
//   Inherits from transaction class and defines the excute method to
//   decrement the amount of items in the searchtree of items.
//---------------------------------------------------------------------------


#pragma once

#include <iostream>

#include "Transaction.h"

using namespace std;


class Sell : public Transaction
{

public:
    Sell() : Transaction('S', -1) {}        // dummy constructor
    Sell(int cust) : Transaction('S' , cust) {} // constructor with parameters
    virtual ~Sell() {}  // destructor

    ///--------------------------------- excute ------------------------------------
    // Sell a items that is passed into the infile stream
    // Preconditions: Item must already exist in the search tree of items
    // Postconditions: The item will be decrement countin the searchtree of items
    virtual void excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H);
};
