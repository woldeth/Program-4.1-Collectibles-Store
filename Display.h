// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Display.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Display class:
//   Inherits from transaction class and defines the excute method to
//   display to print all the items in the inventory in order
//---------------------------------------------------------------------------
#pragma once

#include <iostream>

#include "Transaction.h"

using namespace std;

class Display : public Transaction
{

public:
    Display() : Transaction('D', -1) {}           // dummy constructor
    Display(int cust) : Transaction('D', cust) {} // construtor with parameters
    virtual ~Display() {}                         // destructor

    ///--------------------------------- excute ------------------------------------
    // Displays all the inventory
    // Preconditions: None
    // Postconditions: All items in the inventory will be displayed
    virtual void excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H);
};
