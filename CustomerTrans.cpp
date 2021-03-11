
#include "CustomerTrans.h"

void CustomerTrans::excute(ifstream &infile, SearchTreeItems inventoryItems[], SearchTreeCustomers &stCustomers, customerNode custTransactionList[], HashTable &H)
{
    string stringID;
    int customerID;


    getline(infile, stringID, '\n'); //get QTY
    customerID = atoi(stringID.c_str());
    
    if(custTransactionList[customerID].head == nullptr){

        if(custTransactionList[customerID].cust != nullptr){
            custTransactionList[customerID].cust->toString();
            cout << "- no transactions" << endl;
            return;
        }else {
            cout << "Customer ID: " << stringID << " " << "Name: UNKNOWN" << endl;
        }
    }


    custTransactionList[customerID].cust->toString();
    transactionNode *cur = custTransactionList[customerID].head;
    while(cur != nullptr){
        cout << "transaction type: " << cur->transType << " --> ";
        cur->item->toString();
        cur = cur->next;
    }

    cout << endl;
    
}