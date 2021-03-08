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
}

//destructor
Store::~Store() {

    for(int i = 0; i < ALPHA; i++){
        inventoryTrees[i].~SearchTreeItems();     
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
    	getline(infile, iT , ',');
	    infile.get(); 	

        char inventoryType = iT[0];	
        Item *dummyPtr = HashMap.get(inventoryType);
        
        if(dummyPtr == nullptr){
            getline(infile, iT);
            continue;
        }

        // for testing only on coins right now 
        if(inventoryType != 'M'){
            getline(infile, iT);
            continue;
        }
    
        Item *newItem = dummyPtr->create(infile);
        dummyPtr = nullptr;

        inventoryTrees[(newItem->id - 'A')].insert(newItem);
        


    }
}
