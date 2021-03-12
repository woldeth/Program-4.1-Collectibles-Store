// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Buy.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Buy class:
//   Inherits from transaction class and defines the excute method to
//   increment the amount of items in the searchtree of items.
//---------------------------------------------------------------------------

#include "Buy.h"

///--------------------------------- excute ------------------------------------
// Buys a items that is passed into the infile stream
// Preconditions: Item must already exist in the search tree of items
// Postconditions: The item will be incremented in the searchtree of items
void Buy::excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H)
{
    string stringID;
    int customerID;

    string inventoryType;

    getline(infile, stringID, ','); //get QTY
    customerID = atoi(stringID.c_str());
    infile.get();

    getline(infile, inventoryType, ','); //get QTY

    Item *dummyPtr = H.get(inventoryType[0]);

    if (dummyPtr == nullptr)
    {
        getline(infile, inventoryType, '\n');
        return;
    }

    Item *newItem = dummyPtr->create(infile);

    inventoryItems[(newItem->id - 'A')].find(newItem, true);

    if (custTransactionList[customerID].head == nullptr)
    {
        custTransactionList[customerID].head = new transactionNode(newItem, 'B');
        return;
    }

    transactionNode *cur = custTransactionList[customerID].head;

    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = new transactionNode(newItem, 'B');
    cur = nullptr;
}