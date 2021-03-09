// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Sell.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once

#include <iostream>

#include "Transaction.h"

using namespace std;


class Sell : public Transaction
{

public:
    Sell() : Transaction() {}
    Sell(char c, int cust) : Transaction(c , cust) {}
    virtual ~Sell() {} 
    virtual void excute(string s, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[]){}
};
