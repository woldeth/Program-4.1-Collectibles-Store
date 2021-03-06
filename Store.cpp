// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Store.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "Store.h"


//constructor
Store::Store(){}

//destructor
Store::~Store(){}

void Store::buildCustomerList(ifstream &infile) {

    while (infile.peek() != EOF) {
        string fileInput;
        getline(infile, fileInput);

        // Do something to parse the line of input here
    }
}