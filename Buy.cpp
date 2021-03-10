
#include "Buy.h"

void Buy::excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H)
{
    string stringID;
    int customerID;

    string inventoryType;

    getline(infile, stringID, ','); //get QTY
    customerID = atoi(stringID.c_str());
    infile.get();

    getline(infile, inventoryType, ','); //get QTY
    //customerID = atoi(stringID.c_str());

    cout << stringID << " " << inventoryType[0] << endl;

    Item *dummyPtr = H.get(inventoryType[0]);

    if (dummyPtr == nullptr)
    {
        getline(infile, inventoryType);
    }

    Item *newItem = dummyPtr->create(infile);

    //getline(infile, stringID); // testing

    inventoryItems[(newItem->id - 'A')].find(newItem, true);

    delete newItem;
    newItem = nullptr;
}