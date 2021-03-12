// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: History.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// History class:
//   Prints alls the transactions of every customer in alpha numeric order
//   This uses the search tree of customer to traverse in order and the id
//   to access the transaction nodes.
//---------------------------------------------------------------------------

#include "History.h"

///--------------------------------- excute ------------------------------------
// Prints the history of every customer by customer name
// Preconditions: None
// Postconditions: The item will print the entire history of transaction in alpha order
void History::excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H)
{
    stCustomers.history(custTransactionList);
}