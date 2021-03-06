// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: main.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "Store.h"
using namespace std;

//-------------------------- main -------------------------------------------

int main()
{
    ifstream infileInventory("hw4inventory.txt");
    if (!infileInventory)
    {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    ifstream infileCustomers("hw4customers.txt");
    if (!infileCustomers)
    {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    Store st1;

    //Parse through the customer files to create the customer objects.
    while (infileCustomers.peek() != EOF) {

        string fileInput;
        getline(infileCustomers, fileInput);
        // Do something to parse the line of input here

    }

    cout << "hello world" << endl;

    return 0;
}