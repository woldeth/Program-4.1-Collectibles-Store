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

    cout << stringID<< " " << inventoryType[0] << endl;

    getline(infile, stringID); // testing
}