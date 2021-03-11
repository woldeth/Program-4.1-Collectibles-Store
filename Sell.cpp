
#include "Sell.h"

void Sell::excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H)
{
    string stringID;
    int customerID;

    string inventoryType;

    getline(infile, stringID, ','); //get QTY
    customerID = atoi(stringID.c_str());
    infile.get();

    getline(infile, inventoryType, ','); //get QTY
    //customerID = atoi(stringID.c_str());

    //cout << stringID << " " << inventoryType[0] << endl;

    Item *dummyPtr = H.get(inventoryType[0]);

    if (dummyPtr == nullptr)
    {
        getline(infile, inventoryType, '\n');
        return;
    }

    Item *newItem = dummyPtr->create(infile);

    //getline(infile, stringID); // testing

    inventoryItems[(newItem->id - 'A')].find(newItem, false);

    // delete newItem;
    // newItem = nullptr;

    if(custTransactionList[customerID].head == nullptr){
         custTransactionList[customerID].head = new transactionNode(newItem,'S');
         return;
    }

    transactionNode *cur = custTransactionList[customerID].head;
    
    while(cur->next != nullptr){
        cur = cur->next;
    }
     cur->next = new transactionNode(newItem,'S');
     cur = nullptr;
}