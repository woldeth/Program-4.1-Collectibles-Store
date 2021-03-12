// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Display.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Display class:
//   Inherits from transaction class and defines the excute method to
//   display all the inventory in that is avaailable in the search tree
//---------------------------------------------------------------------------

#include "Display.h"

///--------------------------------- excute ------------------------------------
// Displays all the inventory
// Preconditions: None
// Postconditions: All items in the inventory will be displayed 
void Display::excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H)
{
    for (int i = 0; i < 26; i++)
    {
        inventoryItems[i].display();
    }
}