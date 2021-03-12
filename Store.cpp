// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Store.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Store class:
//   Implements Store class that manages all and stores inventory, customers.
//   and various transactions using the following methods:
//		buildCustomerList(), buildInventory(), processActions()
//  The Store gets passed in an text files in the create format to build
//  all data structures.
//
//  Assumptions:
//	- Text file is in the proper format
//	- No new inventory can be added once inventory is configured
//	- No new customers can be added once customer list has been configured
//---------------------------------------------------------------------------

#include "Store.h"
#include <string>
#include <vector>

///--------------------------------- Store ------------------------------------
// Constructor Initalizes the Store class and placess dummy
// Preconditions: None
// Postconditions: Places all dummy items and commands in hash table
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

    HashMap.initHashTable(v); // initaitlize the vector in HashTable class

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

    HashMap.initHashTransaction(v1); // initaitlize the vector in HashTable class

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

///--------------------------------- ~Store ------------------------------------
// Destructor
// Preconditions: None
// Postconditions: Clears all dynamically allocated memory
Store::~Store()
{
    // Clears up memory for all the search trees
    for (int i = 0; i < ALPHA; i++)
    {
        inventoryTrees[i].~SearchTreeItems();
    }

    // Clears the memory of the transacations nodes
    for (int i = 0; i < 1000; i++)
    {

        if (custTransactionList[i].head == nullptr)
        {
            continue;
        }

        transactionNode *cur = custTransactionList[i].head;

        while (cur != nullptr)
        {
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

        if (id > 1000 || id < 0)
        {
            cout << "invalid customer" << endl;
            return;
        }

        string name = idAndName.substr(idAndName.find(",") + 2);

        Customer *newPtr = new Customer(id, name); // create new customer
       

        if(custTransactionList[id].cust == nullptr){
            custTransactionList[id].cust = newPtr; // insert customer into the transaction position
        }else{
           // cout << "ID has already been used by another customer" << endl;
            delete newPtr;
            newPtr = nullptr;
            return;
        }

         bstCustomers.insert(newPtr);               // insert new customers
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
        getline(infile, iT, ','); // get inventory type
        infile.get();

        char inventoryType = iT[0];
        Item *dummyPtr = HashMap.get(inventoryType);

        // Not found in the hash table
        if (dummyPtr == nullptr)
        {
            getline(infile, iT);
            continue;
        }

        int qty;
        string stringQTY;

        getline(infile, stringQTY, ',');
        qty = atoi(stringQTY.c_str()); // get qty
        infile.get();

        Item *newItem = dummyPtr->create(infile); // create new item

        dummyPtr = nullptr;

        inventoryTrees[(newItem->id - 'A')].insert(newItem, qty); // insert new item into search tree
    }
}

///--------------------------------- ProcessActions ------------------------------------
// Perfrorms the commands from the text file
// Preconditions: infile has been successfully opened and the file contains
//                 properly formated data (according to the program specs)
// Postconditions: All commands will have been performed that are valid
void Store::processActions(ifstream &infile)
{

    while (infile.peek() != EOF)
    {

        string command;

        // Check if Display or history because they have a different format in txt
        if (infile.peek() != 'D' && infile.peek() != 'H')
        {
            getline(infile, command, ',');
            infile.get();
        }
        else
        {
            getline(infile, command);
        }

        Transaction *dummyPtr = HashMap.getTrans(command[0]); // get dummy item

        // command was not found in hash table
        if (dummyPtr == nullptr)
        {
            getline(infile, command, '\n');
            continue;
        }

        cout << "-------------------->" << command[0] << "<--------------------" << endl;

        // Perform the command (Realize I could have passed in This )
        dummyPtr->excute(infile, inventoryTrees, bstCustomers, custTransactionList, HashMap);

        dummyPtr = nullptr;
        cout << endl;
    }
}
