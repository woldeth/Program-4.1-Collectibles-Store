// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Store.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Store class:
//   Implements Store class that manages all and stores inventory, customers.
//   and various transactions using the following methods:
//		buildCustomerList(), buildInventory(), processActions()
//  The Store gets passed in an text files in the create format to build
//  all data structures.
//
//  Assumptions:
//	- Text file is in the proper format
//	- No new inventory can be added once inventory is configured
//	- No new customers can be added once customer list has been configured
//---------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <fstream>
#include "Customer.cpp"
#include "SearchTreeCustomers.cpp"
#include "SearchTreeItems.cpp"
#include "HashTable.cpp"
#include "Coin.cpp"
#include "ComicBook.cpp"
#include "SportCard.cpp"
#include "Transaction.h"
#include "Buy.cpp"
#include "Sell.cpp"
#include "Display.cpp"
#include "CustomerTrans.cpp"
#include "History.cpp"

const int ALPHA = 26; //number of letters

using namespace std;

class Store
{

private:
    SearchTreeCustomers bstCustomers;       // Search tree for customers
    SearchTreeItems inventoryTrees[ALPHA];  // Array of Search tree for different items
    customerNode custTransactionList[1000]; // Transaction list to record buy and sells
    HashTable HashMap;                      // HashTable class used for quick access of dummy items in hashtable

public:
    ///--------------------------------- Store ------------------------------------
    // Constructor Initalizes the Store class and placess dummy
    // Preconditions: None
    // Postconditions: Places all dummy items and commands in hash table
    Store();

    ///--------------------------------- ~Store ------------------------------------
    // Destructor
    // Preconditions: None
    // Postconditions: Clears all dynamically allocated memory
    ~Store();

    ///--------------------------------- BuildCustomerList ------------------------------------
    // Initalizes customerList
    // Preconditions: infile has been successfully opened and the file contains
    //                 properly formated data (according to the program specs)
    // Postconditions: All customers have been identifed and put into customerList
    void buildCustomerList(ifstream &infile);

    ///--------------------------------- BuildInventory ------------------------------------
    // Initalizes inventoryList
    // Preconditions: infile has been successfully opened and the file contains
    //                 properly formated data (according to the program specs)
    // Postconditions: All inventory is read from infile and stored in the object
    void buildInventory(ifstream &infile);

    ///--------------------------------- ProcessActions ------------------------------------
    // Perfrorms the commands from the text file
    // Preconditions: infile has been successfully opened and the file contains
    //                 properly formated data (according to the program specs)
    // Postconditions: All commands will have been performed that are valid
    void processActions(ifstream &infile);
};
