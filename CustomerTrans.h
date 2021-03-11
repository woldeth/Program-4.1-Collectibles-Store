// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: CustomerTrans.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once

#include <iostream>

#include "Transaction.h"

using namespace std;


class CustomerTrans : public Transaction
{

public:
    
    CustomerTrans() : Transaction('C', -1) {}
    CustomerTrans(int cust) : Transaction('C', cust) {}
    virtual ~CustomerTrans() {} 
    virtual void excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H);
};
