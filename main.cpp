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
#include "Item.h"
#include "Coin.cpp"



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

    // Store st1;      // create the store object

    // st1.buildCustomerList(infileCustomers); // creates all customer object and stores in bst

    Item *ptr; 
    Item *ptr1; 


    //coin(char i, int q, int y, int g, string t)

    ptr = new Coin('M', 1, 1996, 100, "Tomas coin");
    ptr1 = new Coin('M', 1, 1997, 101, "abc");






    return 0;
}