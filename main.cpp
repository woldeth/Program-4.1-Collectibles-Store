// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: main.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>

#include "Store.cpp"

using namespace std;

//-------------------------- main -------------------------------------------

int main()
{
    // Create infile for the inventory
    ifstream infileInventory("hw4inventory.txt");
    if (!infileInventory)
    {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    // Create infile for the customers
    ifstream infileCustomers("hw4customers.txt");
    if (!infileCustomers)
    {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    Store st1; // create the store object

    st1.buildInventory(infileInventory); // creates all customer object and stores in bst
    st1.buildCustomerList(infileCustomers);

    //cout << "hello world" << endl;

    return 0;
}