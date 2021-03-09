// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Display.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once

#include <iostream>

#include "Transaction.h"

using namespace std;


class Display : public Transaction
{

public:
    Display() : Transaction() {}
    Display(char c, int cust) : Transaction(c , cust) {}
    virtual ~Display() {} 
    virtual void excute(string s, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[]){}
};
