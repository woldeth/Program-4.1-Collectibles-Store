// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Transactions.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Transaction class:
//   Implements an abstract class used to perform factory method design
//   pattern excutions. This class is meant to be overridden in the subclass
//   that will define the actual logic
//---------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include "SearchTreeItems.h"
#include "SearchTreeCustomers.h"

class HashTable;
class SearchTreeCustomers;

using namespace std;

// Node to holds the transactions record
struct transactionNode
{
    transactionNode() : item(nullptr), transType('?'), next(nullptr) {}
    transactionNode(Item *i, char c) : item(i), transType(c), next(nullptr) {}
    ~transactionNode() {}
    Item *item;            // pointer to item that was sold
    char transType;        // type of transaction (Buy or Sell)
    transactionNode *next; // next transaction for the customer
};

// Node to hold customer obj and Head of transaction list.
struct customerNode
{
    Customer *cust;        // customer ptr
    transactionNode *head; // first transaction head pointer
    customerNode() : cust(nullptr), head(nullptr) {}
    customerNode(Customer *c) : cust(c), head(nullptr) {}
    ~customerNode() {}
};

class Transaction
{

public:
    char command;
    int customer;

    Transaction() : command('?'), customer(-1) {}                 // dummy constructor
    Transaction(char c, int cust) : command(c), customer(cust) {} // constructor with parameters
    virtual ~Transaction() {}                                     // deconstructor

    ///--------------------------------- excute ------------------------------------
    // Viratual abstract method used to create a new type that inherits fom this class
    // Preconditions: Must be overriden and defined in subclass
    // Postconditions: Creates and returns a new item for nescaru transactions
    virtual void excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H) = 0;
};
