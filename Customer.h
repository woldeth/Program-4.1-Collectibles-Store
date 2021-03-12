// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Customer.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Customer class:
//   Defines a the characteristic of a customer within this system.
//---------------------------------------------------------------------------

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
    Customer() : id(-1), name("?") {} // Constructor if nothing is passed in

    Customer(int i, string n) : id(i), name(n) {} // Constror with parameters

    ~Customer() {} // Destructor

    ///--------------------------------- operator< ------------------------------------
    // Defines lesser than operator for Customer
    // Preconditions: Two objects of the same class
    // Postconditions: Determines the lesser than Object from customers
    bool operator<(const Customer &rhs) const;

    ///--------------------------------- operator== ------------------------------------
    // Defines if two customers are equal
    // Preconditions: None
    // Postconditions: Returns a boolean to determine if two obj are equal
    bool operator==(const Customer &rhs) const;

    ///--------------------------------- toString ------------------------------------
    // toString method to print out the contents of the customer
    // Preconditions: None
    // Postconditions: Prints the customer content to the screen
    void toString() const;

    ///--------------------------------- getID ------------------------------------
    // returns the interger id of the customer
    // Preconditions: customer must have an id
    // Postconditions: Returns the interger value of the customers id
    int getID() const;
};
