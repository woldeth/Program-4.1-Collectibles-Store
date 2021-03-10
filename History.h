// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: History.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once

#include <iostream>

#include "Transaction.h"

using namespace std;


class History : public Transaction
{

public:
    History() : Transaction('H', -1) {}
    History(int cust) : Transaction('H' , cust) {}
    virtual ~History() {} 
    virtual void excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H){}
};
