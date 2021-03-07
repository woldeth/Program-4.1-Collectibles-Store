// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: Feb 11, 2021
// File Name: Store.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <fstream>
#include "Customer.cpp"
#include "SearchTreeCustomers.cpp"
#include "SearchTreeItems.cpp"


using namespace std;

class Store
{

private:
    SearchTreeCustomers bstCustomers;
    SearchTreeItems bstCoin, bstCB, bstSC;

public:
    Store();  //constructor
    ~Store(); //deconstructor

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
};
