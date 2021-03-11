// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11th, 2021
// File Name: main.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// This code is the main driver of the program that will create the store
// that will manage the inventory and record the various transactions that
// occur in the program
//
// Assumptions:
//   -- a text file named "hw4inventory.txt", "hw4customers.txt"
//   and "hw4commands.txt" exists in the same directory
//
//   -- Files are in the correct format to properly work
//---------------------------------------------------------------------------

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

    // Creare infile for the commands
    ifstream infileCommands("hw4commands.txt");
    if (!infileCommands)
    {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    Store st1; // create the store object

    st1.buildInventory(infileInventory);    // initatilizes the inventory from text file
    st1.buildCustomerList(infileCustomers); // initatilizes the customer list from text file
    st1.processActions(infileCommands);     // Process various commands from text file

    return 0;
}