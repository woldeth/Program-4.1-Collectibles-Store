
// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: CustomerTrans.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// CustomerTrans class:
//   Inherits from transaction class and defines the excute method to
//   print all the transactions for a specifc customer based on id
//---------------------------------------------------------------------------

#include "CustomerTrans.h"

///--------------------------------- excute ------------------------------------
// Prints all the customer transactions
// Preconditions: None
// Postconditions: Traverses the transaction nodes and prints the content recorded
void CustomerTrans::excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H)
{
    string stringID;
    int customerID;

    getline(infile, stringID, '\n');        //get id 
    customerID = atoi(stringID.c_str());

    if (custTransactionList[customerID].head == nullptr)
    {

        if (custTransactionList[customerID].cust != nullptr)
        {
            custTransactionList[customerID].cust->toString();
            cout << "- no transactions" << endl;
            return;
        }
        else
        {
            cout << "Customer ID: " << stringID << " "
                 << "Name: UNKNOWN" << endl;
            return;
        }
    }

    custTransactionList[customerID].cust->toString();
    transactionNode *cur = custTransactionList[customerID].head;
    while (cur != nullptr)
    {
        cout << "transaction type: " << cur->transType << " --> ";
        cur->item->toString();
        cur = cur->next;
    }

    cout << endl;
}