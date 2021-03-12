// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: CustomerTrans.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// CustomerTrans class:
//   Inherits from transaction class and defines the excute method to
//   print all the transactions for a specifc customer based on id
//---------------------------------------------------------------------------
#pragma once

#include <iostream>

#include "Transaction.h"

using namespace std;

class CustomerTrans : public Transaction
{

public:
    CustomerTrans() : Transaction('C', -1) {}           // dummy constructor
    CustomerTrans(int cust) : Transaction('C', cust) {} // constructor w/ parameters
    virtual ~CustomerTrans() {}                         // destructor

    ///--------------------------------- excute ------------------------------------
    // Prints all the customer transactions
    // Preconditions: None
    // Postconditions: Traverses the transaction nodes and prints the content recorded
    virtual void excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H);
};
