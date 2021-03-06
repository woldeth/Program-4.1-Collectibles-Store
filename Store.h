// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: Feb 11, 2021
// File Name: Store.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <fstream>
#include "Customer.cpp"
#include "SearchTreeCustomers.cpp"


using namespace std;

class Store
{

private:
    SearchTreeCustomers bstCustomers;

public:

    Store(); //constructor
    ~Store(); //deconstructor
    void buildCustomerList(ifstream &infile);


    cout << "look at tree" << endl;
 

};