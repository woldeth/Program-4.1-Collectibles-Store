// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: Feb 11, 2021
// File Name: Transaction.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include "SearchTreeItems.h"
#include "SearchTreeCustomers.h"
#include "Store.h"

using namespace std;

struct transactionNode
{
    transactionNode() : item(nullptr) , transType('?'), next(nullptr) {}
    transactionNode(Item* i, char c) : item(i) , transType(c), next(nullptr) {}
    Item *item;               // pointer to item that was sold
    char transType;      // type of transaction (Buy or Sell)
    transactionNode *next; // next transaction for the customer
};

//Node to hold customer obj and Head of transaction list.
struct customerNode
{
    customerNode() : cust(nullptr), head(nullptr){}
    customerNode(Customer* c) : cust(c), head(nullptr) {}
    Customer *cust;        // customer ptr
    transactionNode *head; // first transaction/ head pointer
};

class Transaction
{

public:
    char command;
    int customer;

    Transaction() : command('?'), customer(-1) {}
    Transaction(char c, int cust) : command(c), customer(cust) {}
    virtual ~Transaction() {} // deconstructor

    ///--------------------------------- operator== ------------------------------------
    // creates a new item and returns it.
    // Preconditions: None
    // Postconditions: Create and returns a new item
    virtual void excute(string s, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[]) = 0;
};
