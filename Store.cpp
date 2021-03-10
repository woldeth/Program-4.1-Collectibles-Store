// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Store.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "Store.h"
#include <string>
#include <vector>

//constructor
Store::Store()
{
    // Dummmy nodes for creations of inventory
    HashNode *ptr1 = new HashNode('M', new Coin);
    HashNode *ptr2 = new HashNode('C', new ComicBook);
    HashNode *ptr3 = new HashNode('S', new SportCard);

    vector<HashNode *> v;
    v.push_back(ptr1);
    v.push_back(ptr2);
    v.push_back(ptr3);

    HashMap.initHashTable(v);

    delete ptr1;
    delete ptr2;
    delete ptr3;
    ptr1 = nullptr;
    ptr2 = nullptr;
    ptr3 = nullptr;

    HashNodeTrans *ptr4 = new HashNodeTrans('B', new Buy);
    HashNodeTrans *ptr5 = new HashNodeTrans('S', new Sell);
    HashNodeTrans *ptr6 = new HashNodeTrans('D', new Display);
    HashNodeTrans *ptr7 = new HashNodeTrans('C', new CustomerTrans);
    HashNodeTrans *ptr8 = new HashNodeTrans('H', new History);

    vector<HashNodeTrans *> v1;
    v1.push_back(ptr4);
    v1.push_back(ptr5);
    v1.push_back(ptr6);
    v1.push_back(ptr7);
    v1.push_back(ptr8);

    HashMap.initHashTransaction(v1);

    delete ptr4;
    delete ptr5;
    delete ptr6;
    delete ptr7;
    delete ptr8;
    ptr4 = nullptr;
    ptr5 = nullptr;
    ptr6 = nullptr;
    ptr7 = nullptr;
    ptr8 = nullptr;
}

//destructor
Store::~Store()
{
    for (int i = 0; i < ALPHA; i++)
    {
        inventoryTrees[i].~SearchTreeItems();
    }

    for (int i = 0; i < 1000; i++)
    {
    
        if(custTransactionList[i].head == nullptr){
            continue;
        }

        transactionNode *cur = custTransactionList[i].head;

        while(cur != nullptr ){
            transactionNode *temp = cur;
            cur = cur->next;
            delete temp->item;
            temp->item = nullptr;
            delete temp;
            temp = nullptr;
        }
    }
 
}

///--------------------------------- BuildCustomerList ------------------------------------
// Initalizes customerList
// Preconditions: infile has been successfully opened and the file contains
//                 properly formated data (according to the program specs)
// Postconditions: All customers have been identifed and put into customerList
void Store::buildCustomerList(ifstream &infile)
{

    while (infile.peek() != EOF)
    {

        string idAndName;
        getline(infile, idAndName);

        int id = stoi(idAndName.substr(0, 3));
        string name = idAndName.substr(idAndName.find(",") + 2);

        Customer *newPtr = new Customer(id, name);
        bstCustomers.insert(newPtr);

        custTransactionList[id].cust = newPtr;
    }
}

///--------------------------------- BuildInventory ------------------------------------
// Initalizes inventoryList
// Preconditions: infile has been successfully opened and the file contains
//                 properly formated data (according to the program specs)
// Postconditions: All inventory is read from infile and stored in the object
void Store::buildInventory(ifstream &infile)
{
    while (infile.peek() != EOF)
    {

        string iT;
        getline(infile, iT, ',');
        infile.get();

        char inventoryType = iT[0];
        Item *dummyPtr = HashMap.get(inventoryType);

        if (dummyPtr == nullptr)
        {
            getline(infile, iT);
            continue;
        }

        int qty;
        string stringQTY;
        getline(infile, stringQTY, ','); //get QTY
        qty = atoi(stringQTY.c_str());
        infile.get();                       //discard space

        // // for testing only on coins right now
        // if(inventoryType != 'S'){
        //     getline(infile, iT);
        //     continue;
        // }

        Item *newItem = dummyPtr->create(infile);

        dummyPtr = nullptr;

        inventoryTrees[(newItem->id - 'A')].insert(newItem, qty);
    }
}

void Store::processActions(ifstream &infile)
{

    cout << "processAction" << endl;

    while (infile.peek() != EOF)
    {

        string command;

        if (infile.peek() != 'D')
        {
            getline(infile, command, ',');
            infile.get();
        }
        else
        {
            getline(infile, command);
        }

        Transaction *dummyPtr = HashMap.getTrans(command[0]);

        if (dummyPtr == nullptr)
        {
            continue;
        }

        dummyPtr->excute(infile, inventoryTrees, bstCustomers, custTransactionList, HashMap);

        getline(infile, command);
        dummyPtr = nullptr;


    }
}
