// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: customer.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Customer
{

private:
    int id;
    string name;

public:
    // Constructor if nothing is passed in
    Customer() : id(-1), name("?") {}
    // Constror with parameters
    Customer(int i, string n) : id(i), name(n) {}

    // Destructor
    ~Customer(){}

    ///--------------------------------- operator< ------------------------------------
    // Defines lesser than operator for Customer
    // Preconditions: Two objects of the same class
    // Postconditions: Determines the lesser than Object from customers
    bool operator<(const Customer &rhs) const;

    ///--------------------------------- operator== ------------------------------------
    // 
    // Preconditions: 
    // Postconditions: 
    bool operator==(const Customer &rhs) const; 

    void toString() const;

    int getID() const;
};
