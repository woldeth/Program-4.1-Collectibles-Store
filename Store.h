// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: Feb 11, 2021
// File Name: Store.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once
#include <iostream>


const int SIZE = 3079;

using namespace std;

class Store
{

private:


public:
    Store() {}  //constructor
    ~Store() {} //deconstructor


    void buildInventory(ifstream &infile)
    {
        // While not end of file
        // 1. get the first char identify the type
        // 2. if M/C/S create new object
        // 3. Store item in bstItem
        // 4. get Index using hashTable
        // 5. store invertory in inventoryList
    }

    void buildCustomerList(ifstream &infile)
    {
        // While not end of file
        // get id, get name
        // create customer obj
        // store customer in bstCustomers
        // update customerNode in custTransactionList[id]
    }

};