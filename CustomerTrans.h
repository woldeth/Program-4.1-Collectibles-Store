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
    
    CustomerTrans() : Transaction() {}
    CustomerTrans(char c, int cust) : Transaction(c , cust) {}
    virtual ~CustomerTrans() {} 
    virtual void excute(string s, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[]){}
};
