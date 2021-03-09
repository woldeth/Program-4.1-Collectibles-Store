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
    History() : Transaction() {}
    History(char c, int cust) : Transaction(c , cust) {}
    virtual ~History() {} 
    virtual void excute(string s, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[]){}
};
