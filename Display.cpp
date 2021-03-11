
#include "Display.h"

void Display::excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H)
{
    for(int i = 0; i < 26; i++){
        inventoryItems[i].display();
    }
}