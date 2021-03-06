// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Store.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "Store.h"
#include <string>


//constructor
Store::Store(){}

//destructor
Store::~Store(){}

void Store::buildCustomerList(ifstream &infile) {

    while (infile.peek() != EOF) {

        string idAndName;
        getline(infile, idAndName);

        int id = stoi(idAndName.substr(0,3));
        string name = idAndName.substr(idAndName.find(",") + 2);

        Customer *newPtr = new Customer(id, name);

        bstCustomers.insert(newPtr);

    
    }
}